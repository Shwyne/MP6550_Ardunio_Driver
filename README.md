# MP6550_Ardunio_Driver
Library for Arduino MP6650 DC-Motor driver - Work in Progress!
---------------------------------------------------------------------------------------------------
1. Setup:
	
	motor objectname(int IN1-Port,int IN2-Port,int SLP-Port);

----------------------------------------------------------------------------------------------------
2. Attributes:
	
	-Speed: (0 min, 255 max)
	-Break Speed:   (0 min, 255 max)
	-Direction:     (1 forwards, 0 idle, -1 backwards)
	-Standby:       (1 SLP enabled, 0 SLP disabled);

----------------------------------------------------------------------------------------------------
3. Methods:

    i.e.: objectname.forwards(100) -> Moves forward with speed of 100

	-forwards();/forwards(int speed);
	-backwards();/backwards(int speed);
	-brake();/brake(int br_speed);
	-setBrakeSpeed(int br_speed);
	-toggleDir();
	-setSpeed(int speed);
	-getSpeed();
	-getStbyStat();
	-sleep();/sleep(int secs);
	-wakeUp;

----------------------------------------------------------------------------------------------------