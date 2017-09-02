#include <Ultrasonic.h>



#include <Servo.h>

Servo motor;
int ledVermelho = 6;
int ledVerde=2;
int echo = 5;
int trigger = 4;
long microsec = 0;
int distancia =0;

Ultrasonic sensor(trigger,echo);

void setup() {

  Serial.begin(9600);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(trigger, OUTPUT); 
  pinMode(echo, INPUT);
 
  motor.attach(3);
  

}

void loop() {

 giraMotor();



}

void giraMotor(){
for(int angulo = 14; angulo < 160; angulo++) 
  {                                  
    motor.write(angulo);
    delay(5); 
    distancia =  scan();         
    Serial.print(angulo);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print(".");
                     
  } 


  for(int angulo = 160; angulo > 14; angulo--) 
  {                                  
    motor.write(angulo);              
    delay(5);  
     distancia = scan();  
  Serial.print(angulo);
  Serial.print(",");
  Serial.print(distancia);
  Serial.print(".");                   
  } 

  
}


int scan(){


  digitalWrite(trigger, LOW); 
  delayMicroseconds(2);

  digitalWrite(trigger, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  microsec = pulseIn(echo, HIGH);
   microsec= microsec *0.034/2;
  if(microsec>40) {
  digitalWrite(ledVermelho,LOW);  
  digitalWrite(ledVerde,HIGH);   
  }
  else {
  digitalWrite(ledVermelho,HIGH); 
  digitalWrite(ledVerde,LOW); 
  tone(9,1000);
  delay(100);
  noTone(9);
  }

  return microsec;
  
}


