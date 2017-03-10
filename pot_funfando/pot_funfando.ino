#include <AFMotor.h>
#include <Ultrasonic.h>

#define potPin 2
int valPot = 0

AF_DCMotor motor1(1); // Roda Direita
AF_DCMotor motor2(4); // Roda Esquerda
AF_DCMotor motor3(3); // Motor da vassoura

int pecho = 14;            
int ptrig = 15;            
int duracao, distancia;

void setup()  {  
pinMode(pecho, INPUT); 
pinMode(ptrig,OUTPUT);
motor1.setSpeed(valPot); 
motor2.setSpeed(valPot);
motor3.setSpeed(130); // Controle de velocidade da vassoura
} 

void loop()  { 
  
valPot =  analogRead(potPin); //Faz a leitura analógica do pino em que o potenciômetro esta ligado 
valPot = map(valPot,0,1023,0,255); //Utilizando a função map() para transformar uma escala de 0-1023 em uma escala 0 a 255

digitalWrite(ptrig, HIGH);  
delay(0.01);
digitalWrite(ptrig, LOW);
     
duracao = pulseIn(pecho, HIGH);             
distancia = (duracao/2) / 29;            
delay(10); 
     
if (distancia <= 15 && distancia >=2){   //Calcular distancia, se menor que 15cm dar ré e fazer curva 
motor1.run(RELEASE); 
motor2.run(RELEASE);
motor3.run(RELEASE); 
        delay (500);          //Dar ré
motor1.run(BACKWARD);               
motor2.run(BACKWARD);
motor3.run(BACKWARD); 
        delay(300);           //Cada roda girar girar em sentido
motor1.run(FORWARD); 
motor2.run(BACKWARD);
motor3.run(RELEASE);   
        delay(1100);                         
}
else{                         // Se não tiver obstaculos, seguir em frente.
motor1.run(FORWARD);
motor2.run(FORWARD);
motor3.run(FORWARD); 
 }
 }
