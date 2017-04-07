//www.elegoo.com
//2016.09.23

#include <Servo.h> //servo library
Servo myservo; // create servo object to control servo
int Echo = A4;  
int Trig = A5;
int in1=6;
int in2=7;
int in3=8;
int in4=9;
int ENA=5;
int ENB=11;
int ABS=115;
int distance = 0,sonarPosition = 0; 
 void _mForward()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);//digital output
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go forward!");
}

void _mBack()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("go back!");
}

void _mLeft()
{
   analogWrite(ENA,ABS);
   analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
   Serial.println("go left!");
}

void _mRight()
{
   analogWrite(ENA,ABS);
   analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
   Serial.println("go right!");
} 
void _mStop()
{
   digitalWrite(ENA,LOW);
   digitalWrite(ENB,LOW);
   Serial.println("Stop!");
}

int Distance_test()   
{
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance/58;       
  return (int)Fdistance;
}  

void setup() 
{
  Serial.begin(9600);
  myservo.write(15);
  sonarPosition = 15;
}

void loop() {
  int num1,num2,num3;
  num1=digitalRead(10);// Left sensor  
  num2=digitalRead(4); // Center sensor
  num3=digitalRead(2); // Right sensor
   if(num2==0) //'0' means a line is not sensed 
   {
     _mLeft();
   }    

  else if(num3!=0)
   {
    _mRight();
   }
  else
  {
    _mForward(); 
  }
  if(sonarPosition<=15)
  {
    myservo.write(sonarPosition+5);
    sonarPosition=sonarPosition+5;
  }
  else if(sonarPosition>=85)
  {
    myservo.write(sonarPosition-5);
    sonarPosition=sonarPosition-5;
  }
  distance = Distance_test();
  //if(distance<=
  delay(2);
  _mStop();
  delay(1);
}

