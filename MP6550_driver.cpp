/* 
		Library for MP6550 DC-Motordriver
				Last updated: 29.10.2023
					created by: Timo Steinhilber
				last modified by: Timo Steinhilber

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1. Setup:
	
	-Initalize: 
	-Deconstruction:
	-CurrentSensing:

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2. Attributes:
	
	-Speed: 
	-Break Speed:
	-Direction:
	-Standby:

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3. Methods:

	-forwards():
	-backwards():
	-brake():
	-setBrakeSpeed(int br_speed):
	-toggleDir();
	-setSpeed(int speed):
	-getSpeed();
	-getStbyStat():
	-sleep()/sleep(int secs):
	-wakeUp:

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "MP6550_driver.hpp"

motor::motor(int IN1pin, int IN2pin, int SLPpin){
	
 IN1 = IN1pin;
	IN2 = IN2pin;
	SLP = SLPpin;
	
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(SLP, OUTPUT);
	
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(SLP, HIGH);
	speed_ = 0;
	dir_ = 0;
	standby_ = 1;
}

void motor::forwards(){
	if(standby_ == 1)wakeUp();
	digitalWrite(IN1, HIGH);
	analogWrite(IN2, speed_);
	dir_	=  1;
}

void motor::backwards(){
	if(standby_ == 1)wakeUp();
	digitalWrite(IN2, HIGH);
	analogWrite(IN1, speed_);
	dir_ = -1;
}

void motor::brake(){
	if(dir_ == 1){
		digitalWrite(IN1, HIGH);
		analogWrite(IN2, br_speed_);
	}
	else if(dir_ == -1){
		digitalWrite(IN2, HIGH);
		analogWrite(IN2, br_speed_);
  }
	else{
		digitalWrite(IN1, HIGH);
		digitalWrite(IN2, HIGH);
	}
	delay(100);
	dir_ = 0;
}

void motor::setBrakeSpeed(int br_speed){
	if(br_speed>255)br_speed = 255;
	else if(br_speed<0)br_speed = 0;
	
	br_speed_ = br_speed;
}

void motor::toggleDir(){
	if(standby_ ==	0){
		if(dir_ == 1) backwards();
		else if(dir_ == -1) forwards();
		else brake();
 }
	else dir_ =	-dir_;
}
		
void motor::setSpeed(int speed){
	if(speed>255)speed =	255;
	else if(speed<0)speed = 0;
	speed_ =	255- speed;	//One Pin High and One Pin Low is highest speed - thus 255 - speed -> speed input = 255 -> speed_ = 0 -> max speed
}

int motor::getSpeed(){
	return 255-speed_;
}

int motor::getStbyStat(){
	return standby_;
}

void motor::sleep(){
	brake();
	digitalWrite(SLP,HIGH);
	standby_ = 1;
}

void motor::sleep(int secs){
	brake();
	digitalWrite(SLP, HIGH);
	standby_ = 1;
	delay(secs*1000);
	wakeUp();
}

/*void wakeUp(){
	digitalWrite(SLP, LOW);
	standby_ = 0;
}*/
	
motor::~motor(){
	brake();
	delay(500);
	digitalWrite(SLP, HIGH);
}
