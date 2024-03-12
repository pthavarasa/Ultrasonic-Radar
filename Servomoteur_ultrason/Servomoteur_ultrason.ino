#include <Servo.h>

Servo servoMoteur;
int trig = 12; 
int echo = 11; 
long lecture_echo; 
long cm;

void setup() {
  servoMoteur.attach(2);
  servoMoteur.write(1);
  pinMode(trig, OUTPUT); 
  digitalWrite(trig, LOW); 
  pinMode(echo, INPUT); 
  Serial.begin(9600);
  delay(3000); 

}

int get_distance(){
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  lecture_echo = pulseIn(echo, HIGH); 
  cm = lecture_echo / 58; 
  Serial.print("Distance : "); 
  Serial.println(cm); 
}

void loop() {
  // tour de 0 à 180º
  for (int i = 1; i <= 180; i++){
    servoMoteur.write(i);
    Serial.print("Angle:  ");
    Serial.println(i);
    delay(30);
    get_distance();
  }
 // tour de 180 a 0º
  for (int i = 179; i >= 0; i--){
    servoMoteur.write(i);
    Serial.print("Angle:  ");
    Serial.println(i);
    delay(30);
    get_distance();
  }
}
