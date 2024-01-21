// arduino uno code for dual talon motor controller box
// with analog channels for control -100 -> 100

#include "Servo.h"

int analog1Pin = A0; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int analog2Pin = A1;

int val1 = 0;  // variable to store the value read
int val2 = 0;  // variable to store the value read

Servo controller1;
Servo controller2;
int pwm1pin = 9;
int pwm2pin = 10;


void setup() {
  // put your setup code here, to run once:
  controller2.attach(pwm2pin);
  Serial.begin(9600);
  controller1.attach(pwm1pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  val1 = analogRead(analog1Pin);  // read the input pin
  val2 = analogRead(analog2Pin);  // read the input pin

  val1 = map(val1,0,1024,-100,100);
  val2 = map(val2,0,1024,-100,100);


  int PWMvalue1 = val1 * 5 + 1500; //scale up to 1000-2000
  controller1.writeMicroseconds(PWMvalue1);
  int PWMvalue2 = val2 * 5 + 1500; //scale up to 1000-2000
  controller2.writeMicroseconds(PWMvalue2);


  Serial.print("Analog0 ");
  Serial.print(val1);
  Serial.print(" PWMOut1 ");
  Serial.println(PWMvalue1);
  Serial.print("Analog1 ");
  Serial.print(val2);
  Serial.print(" PWMOut2 ");
  Serial.println(PWMvalue2);

}
