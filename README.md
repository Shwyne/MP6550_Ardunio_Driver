# MP6550_Ardunio_Driver
Library for Arduino MP6650 DC-Motor driver - Work in Progress!
---------------------------------------------------------------------------------------------------
1. Setup:
	
	motor objectname(int IN1-Port,int IN2-Port,int SLP-Port);

----------------------------------------------------------------------------------------------------
2. Attributes:
	
	-Speed: (0 min, 255 max) <br />
	-Break Speed:   (0 min, 255 max) <br />
	-Direction:     (1 forwards, 0 idle, -1 backwards) <br />
	-Standby:       (1 SLP enabled, 0 SLP disabled); <br />

----------------------------------------------------------------------------------------------------
3. Methods:

    i.e.: objectname.forwards(100) -> Moves forward with speed of 100

	-forwards();/forwards(int speed); <br />
	-backwards();/backwards(int speed); <br />
	-brake();/brake(int br_speed); <br />
	-setBrakeSpeed(int br_speed); <br />
	-toggleDir(); <br />
	-setSpeed(int speed); <br />
	-getSpeed(); <br />
	-getStbyStat(); <br />
	-sleep();/sleep(int secs); <br />
	-wakeUp; <br />

----------------------------------------------------------------------------------------------------
