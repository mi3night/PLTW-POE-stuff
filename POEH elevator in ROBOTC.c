#pragma config(Sensor, in1,    lf1,            sensorLineFollower)
#pragma config(Sensor, in2,    lf2,            sensorLineFollower)
#pragma config(Sensor, in3,    lf3,            sensorLineFollower)
#pragma config(Sensor, dgtl1,  switch1,        sensorTouch)
#pragma config(Sensor, dgtl2,  switch2,        sensorTouch)
#pragma config(Sensor, dgtl3,  switch3,        sensorTouch)
#pragma config(Sensor, dgtl4,  ebump,          sensorTouch)
#pragma config(Sensor, dgtl5,  led1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl6,  led2,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  led3,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  redLed,         sensorLEDtoVCC)
#pragma config(Motor,  port2,           mainmotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           door,          tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void floor1();
void floor2();
void floor3();
task estop();
int currentfloor = 3;


task main()
{

	if (currentfloor == 3) {
		floor1();
	}
	startTask(estop);
		clearTimer(T1);
		while (1 == 1 )
		{
		if (time1[T1] < 5000)
			{
			if (SensorValue(switch1) == 1)
			{
				floor1();
			}
			if (SensorValue(switch2) == 1)
			{
				floor2();
			}
			if (SensorValue(switch3) == 1)
			{
				floor3();
			}
		}
		else
			{
				clearTimer(T1);
	if (currentfloor == 2 || currentfloor == 3)
	{
		turnLEDOff(led2);
		turnLEDOff(led3);
		turnLEDOn(redLed);
		setServo(door, 55);
		startMotor(mainmotor, -25);
		while (currentfloor == 2 || currentfloor == 3)
		{
			if (SensorValue(lf1) < 200)
			{
				stopMotor(mainmotor);
						setServo(door, 55);
				currentfloor = 1;
				turnLEDOff(redLed);
				turnLEDOn(led1);
			}
			else
			{
			}
		}
	}
	else
	{
		setServo(door, 55);
	}
}
		}
	}




void floor1()
{

	clearTimer(T1);
	if (currentfloor == 2 || currentfloor == 3)
	{
		turnLEDOff(led2);
		turnLEDOff(led3);
		turnLEDOn(redLed);
		setServo(door, 55);
		startMotor(mainmotor, -25);
		while (currentfloor == 2 || currentfloor == 3)
		{
			if (SensorValue(lf1) < 200)
			{
				stopMotor(mainmotor);
				setServo(door, -107);
				currentfloor = 1;
				turnLEDOff(redLed);
				turnLEDOn(led1);
			}
			else
			{
			}
		}
	}
	else {
				setServo(door, -107);
	}
}




void floor2()
{
	clearTimer(T1);
	if (currentfloor == 1)
	{
		turnLEDOn(redLed);
		turnLEDOff(led1);
		setServo(door, 55);
		while (currentfloor == 1)
		{
			startMotor(mainmotor, 25);
			if (SensorValue(lf2) < 200 )
			{
				stopMotor(mainmotor);
				setServo(door, -107);
				currentfloor = 2;
				turnLEDOff(redLed);
				turnLEDOn(led2);
			}
			else
			{
			}
		}
	}
	else if (currentfloor == 3)
	{
		turnLEDOff(led3);
		turnLEDOn(redLed);
		setServo(door, 55);
		while (currentfloor == 3)
		{
			startMotor(mainmotor, -25);
			if (SensorValue(lf2) < 200)
			{
				stopMotor(mainmotor);
				setServo(door, -107);
				currentfloor = 2;
				turnLEDOff(redLed);
				turnLEDOn(led2);
			}
			else
			{
			}
		}
	}
	if (currentfloor == 2)
	{
	}
}



void floor3()
{
	clearTimer(T1);
	if (currentfloor == 1 || currentfloor == 2)
	{
		turnLEDOn(redLed);
		turnLEDOff(led1);
		turnLEDOff(led2);
		setServo(door, 55);
		while (currentfloor == 1 || currentfloor == 2)
		{
			startMotor(mainmotor, 50);
			if (SensorValue(lf3) < 500)
			{
				stopMotor(mainmotor);
				setServo(door, -107);
				currentfloor = 3;
				turnLEDOff(redLed);
				turnLEDOn(led3);
			}
			else
			{
			}
		}
	}
	else if (currentfloor == 3)
	{
	}
}



task estop ()
{
	while (true)
	{
		if (SensorValue [ebump] == 1)
		{
      	stopAllTasks ();
		}
    	waitInMilliseconds(10);
	}
}
