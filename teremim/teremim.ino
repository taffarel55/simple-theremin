#include "Ultrasonic.h" 
const int echoPin = 6; 
const int trigPin = 7;
const int buzzer = 2;

Ultrasonic ultrasonic(trigPin,echoPin); 

int distancia; 
String result;

void setup(){
  pinMode(echoPin, INPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
 
void loop(){
  hcsr04(); 
  Serial.print("Distancia "); 
  Serial.print(result); 
  Serial.println("cm");
  tone(buzzer, 500+20*result.toInt());
}

void hcsr04() {
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
    distancia = (ultrasonic.Ranging(CM)); 
    result = String(distancia); 
    delay(10);
 }
