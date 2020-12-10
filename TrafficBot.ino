#include <Servo.h>
Servo servo_test; 
String led=""; 
int angle=0;
int potpin=0;
int val;
int LED=13;
int obspin1=6;
int obspin2=7;
int hasobstacle1=HIGH;
int hasobstacle2=HIGH;
void setup()
{
  // put your setup code here, to run once:
  servo_test.attach(9);
  pinMode(LED,OUTPUT);
  pinMode(obspin1,INPUT);
  pinMode(obspin2,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(2,HIGH);
  servo_test.write(0);
  delay(10000);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
}


void loop() 
{
  // put your main code here, to run repeatedly:
    hasobstacle1=digitalRead(obspin1);
    hasobstacle2=digitalRead(obspin2);
    
   
    if(hasobstacle1==LOW || (hasobstacle1==LOW && hasobstacle2==LOW)||(hasobstacle2==LOW))
    {
        digitalWrite(4,LOW);
        delay(90);
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        delay(115);
        digitalWrite(5,HIGH);
        digitalWrite(10,LOW);
        delay(70);
        digitalWrite(10,HIGH);
        delay(0);
        
    }
    if((hasobstacle1==LOW && hasobstacle2==LOW)||(hasobstacle2==LOW))
    { 
      servo_test.write(90);
      delay(10); 
    }
    else if((hasobstacle1==LOW && hasobstacle2==HIGH)||(hasobstacle1==HIGH && hasobstacle2==HIGH))
    {
      digitalWrite(LED,HIGH);
      servo_test.write(0);
      delay(10); 
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(10,LOW);
    }
  
    
}
