#include <Arduino.h>      //If using Arduino IDE -> comment this line out.
#include "MP6550_driver.hpp"

#define DELAY 1000

#define SERIAL_BPS 115200 // Bits per second serial port -> Gerätemanager -> COM -> Arduino -> Rechtsklick -> Eigenschaften -> Port Einstellungen -> Bits pro Sekunde (Default: 9600)

motor mdc1(9,11,13);

void testroutine1();
void testroutine2();

void setup() {
  //mdc1.setSpeed(speed); //sets motor speed
  //mdc1.setBrakeSpeed(brakeSpeed); //sets motor braking speed
  Serial.begin(SERIAL_BPS);
}

void loop() {
  
  //*Testroutine 1:
  testroutine1();

  //*Testroutine 2:
  //testroutine2();
  
}


void testroutine1(){

  mdc1.forwards(100);   //Moves forward with speed of 100
  Serial.print("Moving forwards with speed of: "); Serial.println(mdc1.getSpeed());
  delay(2*DELAY);

  mdc1.brake(100);      //Brakes with speed of 100
  Serial.print("Braking with speed of: "); Serial.println(mdc1.getBrakeSpeed());
  delay(DELAY);

  mdc1.backwards(100); //Moves back with speed of 100
  Serial.print("Moving backwards with speed of: "); Serial.println(mdc1.getSpeed());
  delay(2*DELAY);

  mdc1.brake(100); //Brakes with speed of 100
  Serial.print("Braking with speed of: "); Serial.println(mdc1.getBrakeSpeed());
  delay(DELAY);

  mdc1.sleep();
  Serial.println("Entering Sleep mode");
  delay(2*DELAY);

}

void testroutine2(){
  
  for(int i = 0; i < 255; i++){
    mdc1.forwards(i);
    delay(5);
  }

  mdc1.brake(150);
  delay(DELAY);

  for(int i = 0; i < 255; i++){
    mdc1.backwards(i);
    delay(5);
  }

  mdc1.brake(150);
  delay(DELAY);
}

