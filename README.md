# MP6550_Ardunio_Driver
_Library for Arduino MP6650 DC-Motor driver_

## 1. Setup:
	
**1. Move "MP6550_driver.cpp" and "MP6550_driver.hpp" to your project folder:** <br />
	a) If you're using Arduino IDE -> folder where your .ino is located. <br />
 	   IMPORTANT: delete the line #include "Ardunio.h" at the beginning of "MP6550_driver.cpp" <br />
	b) If you're using VSCode+Platform.io -> create folder inside /lib folder named after the library (i.e. "MP6550_driver") <br />

**2. Include the library into your main file:** <br />

	> #include "MP6500_driver.hpp" 
	
**3. Create object where you want to use it:** <br />

	> motor objectname(int IN1-Port,int IN2-Port,int SLP-Port); 

<ul>
<li>motor: Class name to create object with</li>
<li>objectname: name your object as you wish (in complex projects its recommended to give it a describing name)</li>
<li>IN1-Port: Port number connected to IN1 of the MP6550 driver</li>
<li>IN2-Port: Port number connected to IN2 of the MP6550 driver</li>
<li>SLP-Port: Port number connected to SLP of the MP6550 driver</li>
</ul>

----------------------------------------------------------------------------------------------------
## 2. Attributes:
	
<ul>
<li>int Speed: (0 min, 255 max)</li>
<li>int Break Speed: (0 min, 255 max)</li>
<li>int Direction: (1 forwards, 0 idle, -1 backwards)</li>
</ul>

<ul>
<li>int IN1: stores the IN1-Pin given when object is created</li>
<li>int IN2: stores the IN2-Pin given when object is created</li>
<li>int SLP: stores the SLP-Pin given when object is created</li>
</ul>

----------------------------------------------------------------------------------------------------
## 3. Methods:

**Using Methods (example -> Moves forward with speed of 100):**

    > objectname.forwards(100); 
		
**List of methods:**
<ul>
<li>forwards(): Motor moves forwards with already set speed</li>
<li>forwards(int speed): Motor moves forwards with a given speed (int speed)</li>
<li>backwards(): Motor moves backwards with already set speed</li>
<li>backwards(int speed): Motor moves backwards with a given speed (int speed)</li>
<li>setSpeed(int speed): Sets speed for Motor (int speed = 0 to 255)</li>
<li>getSpeed(): Gets speed of Motor</li>
<li>brake(): Motor brakes with already set braking speed</li>
<li>brake(int br_speed): Motor brakes with a given braking speed (int br_speed)</li>
<li>setBrakeSpeed(int br_speed): Sets Brake speed of Motor (int br_speed = 0 to 255)</li>
<li>getBrakeSpeed(): Gets brake speed of Motor</li>
<li>toggleDir(): Toggle direction of Motor</li>
<li>sleep(): Puts Driver to Sleep (SLP == 1)</li>
<li>sleep(int secs): puts Driver to Sleep for int secs</li>
<li>wakeUp(): Wakes Driver up</li>
<li>getStbyStat(): Gets Sleep State of Motor (0 = Operating | 1 = Sleeping)</li>
</ul>
