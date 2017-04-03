//www.elegoo.com
//2016.09.23

#include <Servo.h> //servo library
Servo myservo; // create servo object to control servo
int Echo = A4;  
int Trig = A5; 
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int ENA = 5;
int ENB = 11;
int ABS = 150;
int shortestDistance = 10000,shortestWrite = 15,readDistance = 0 ;
//void _mForward()
//{
// analogWrite(ENA,ABS);
// analogWrite(ENB,ABS);
//  digitalWrite(in1,HIGH);//digital output
//  digitalWrite(in2,LOW);
//  digitalWrite(in3,LOW);
//  digitalWrite(in4,HIGH);
// Serial.println("go forward!");
//}

//void _mBack()
//{
// analogWrite(ENA,ABS);
// analogWrite(ENB,ABS);
//  digitalWrite(in1,LOW);
//  digitalWrite(in2,HIGH);
//  digitalWrite(in3,HIGH);
//  digitalWrite(in4,LOW);
// Serial.println("go back!");
//}

void _mleft()
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
 Serial.println("go left!");
}

void _mright()
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
 /*Ultrasonic distance measurement Sub function*/
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
  myservo.attach(3);// attach servo on pin 3 to servo object
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
//  shortestDistance = 10000;
//  shortestWrite = 90;
  myservo.write(15); //set servo position to face right
  _mStop();
} 

void loop() 
{ 
    readDistance = Distance_test(); //Reads in current distance from sonar's current position
    #ifdef send
      Serial.print("readDistance=");
      Serial.println(readDistance);
      #endif
    if(readDistance<shortestDistance) //If that distance is the shortest distance, store it, as well as the servo's current position
    {
      shortestDistance = readDistance;
      shortestWrite = myservo.read();
    }
    if(myservo.read()<180)
    {
      myservo.write(myservo.read()+5); //Turn servo slightly left
      delay(75); 
    }
    else
    {
      if(shortestWrite<90)
      {
        _mright();
      }
      else if(shortestWrite>90)
      {
        _mleft();
      }
      delay(abs((shortestWrite-90)*2));
      _mStop();
      shortestDistance = 10000; //Resets the "shortest" variables back to defaults
      shortestWrite = 90;
      myservo.write(15);
    }
}

    
