//Code for Controling a Tumbler RC car

// with Arduino Uno and Seeed Motor Shield V2.0

// Chris 8/12/14

/*----Ardunio to Shield Pinout Controls-----

Are using a Seeed motor shield to drive 2 DC motors

Seeed motor shield uses Arduino pins 8->13

Pin 9 sets the enable and speed of shield outputs 1 & 2

Pin 10 sets the enable and speed of shield outputs 3 & 4

Pin 8 from Uno controls the state of shield output 1

Pin 11 from Uno controls the state of shield output 2

Pin 12 from Uno controls the state of shield output 3

Pin 13 from Uno controls the state of shiled output 4

*/
#include <math.h>
//--- Declared variables

int leftmotorForward = 8; // pin 8 --- left motor (+) green wire

int leftmotorBackward = 11; // pin 11 --- left motor (-) black wire

int leftmotorspeed = 9; // pin 9 --- left motor speed signal

int rightmotorForward = 12; // pin 12 --- right motor (+) green wire

int rightmotorBackward = 13; // pin 13 --- right motor (-) black

int rightmotorspeed = 10; // pin 10 --- right motor speed signal

//--- Speeds and Timers

int Think = 200; //Long delay time between steps

int Runtime = 500; // How long Runtime actions will last

int TurningTime = 2000;

int Slow = 150; // slow speed (of 255 max)

int Fast = 255; // fast speed (of 255 max)

//------------------------------------------------------

const int trigPin = 2;
const int echoPin = 3;
int currentSpeed = 125;
double distance = 255;  
void setup() //---6 Pins being used are outputs--- 
{
  Serial.begin(9600);
  pinMode(leftmotorForward, OUTPUT);
  pinMode(leftmotorBackward, OUTPUT);
  pinMode(leftmotorspeed, OUTPUT);
  pinMode(rightmotorForward, OUTPUT);
  pinMode(rightmotorBackward, OUTPUT);
  pinMode(rightmotorspeed, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// ---Main Program Loop -----------------------------

void loop()

{

  
  long duration;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance,2);
  Serial.print(" cm");

  currentSpeed = 50 * atan(distance);
  if(distance <= 4 )
  {
    Stop();
    goBackward();
    delay(TurningTime);
    Stop();
    turnLeft();

        delay(TurningTime);
        
        Stop();
  }
  Serial.print(" Current Speed:" );
  Serial.println(currentSpeed);

  goForward( );
  /*if(distance > 255)
    currentSpeed = 255;
  else
    currentSpeed = atan(distance);
*/
  //Serial.println(String(currentSpeed));
  
    //currentSpeed = (int) distance;  
/*  if (distance < 4) {  // This is where the LED On/Off happens

        Stop();

        goBackward();

        delay(TurningTime);

        Stop();

        delay(Think);

        turnLeft();

        delay(TurningTime);
        
        Stop();
        
        delay(Think);

  }

  else if(distance < 8 )
  {
    goSlower();  
  }

  
  else
  {

   goForward();

   //delay(TurningTime);
  
  }
*/
}

//----- "Sub-rutine" Voids called by the main loop
void goSlower()
{
analogWrite(leftmotorspeed,Slow); //Enable left motor by setting speed

analogWrite(rightmotorspeed,Slow); //Enable left motor by setting speed

digitalWrite(leftmotorBackward,LOW); // Drives LOW outputs down first to avoid damage

digitalWrite(rightmotorBackward,LOW);

digitalWrite(leftmotorForward,HIGH);

digitalWrite(rightmotorForward,HIGH);

}

void goFaster()
{
analogWrite(leftmotorspeed,Fast); //Enable left motor by setting speed

analogWrite(rightmotorspeed,Fast); //Enable left motor by setting speed

digitalWrite(leftmotorBackward,LOW); // Drives LOW outputs down first to avoid damage

digitalWrite(rightmotorBackward,LOW);

digitalWrite(leftmotorForward,HIGH);

digitalWrite(rightmotorForward,HIGH);
  
}

void goForward()

{

analogWrite(leftmotorspeed,currentSpeed); //Enable left motor by setting speed

analogWrite(rightmotorspeed,currentSpeed); //Enable left motor by setting speed

digitalWrite(leftmotorBackward,LOW); // Drives LOW outputs down first to avoid damage

digitalWrite(rightmotorBackward,LOW);

digitalWrite(leftmotorForward,HIGH);

digitalWrite(rightmotorForward,HIGH);

}
void turnLeft()
{
  analogWrite(leftmotorspeed,Fast); 
  
  analogWrite(rightmotorspeed,Slow); 
  
  digitalWrite(leftmotorBackward,LOW); 
  
  digitalWrite(rightmotorBackward,LOW);
  
  digitalWrite(leftmotorForward,HIGH);
  
  digitalWrite(rightmotorForward,HIGH);

}

void turnRight()
{
  analogWrite(leftmotorspeed,Slow); 
  
  analogWrite(rightmotorspeed,Fast); 
  
  digitalWrite(leftmotorBackward,LOW); 
  
  digitalWrite(rightmotorBackward,LOW);
  
  digitalWrite(leftmotorForward,HIGH);
  
  digitalWrite(rightmotorForward,HIGH);

}

void goBackward()

{

analogWrite(leftmotorspeed,Fast);

analogWrite(rightmotorspeed,Fast);

digitalWrite(leftmotorForward,LOW);

digitalWrite(rightmotorForward,LOW);

digitalWrite(leftmotorBackward,HIGH);

digitalWrite(rightmotorBackward,HIGH);

}

void Stop() // Sets speed pins to LOW disabling both motors

{

digitalWrite(leftmotorspeed,LOW);

digitalWrite(rightmotorspeed,LOW);

}


