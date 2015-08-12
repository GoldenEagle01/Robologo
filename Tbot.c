#pragma config(Hubs, S1, HTMotor, HTServo, none, none)
#pragma config(Sensor, S1, , sensorI2CMuxController)
#pragma config(Motor, mtr_S1_C1_1, motorD, tmotorTetrix, openLoop)
#pragma config(Motor, mtr_S1_C1_2, motorE, tmotorTetrix, openLoop, reversed)
#pragma config(Servo, srvo_S1_C2_1, servo1, tServoNone)
#pragma config(Servo, srvo_S1_C2_2, servo2, tServoNone)
#pragma config(Servo, srvo_S1_C2_3, servo3, tServoNone)
#pragma config(Servo, srvo_S1_C2_4, servo4, tServoNone)
#pragma config(Servo, srvo_S1_C2_5, servo5, tServoNone)
#pragma config(Servo, srvo_S1_C2_6, servo6, tServoNone)

#include "JoystickDriver.c"

task main()
{
int eroare = 5; //erori joystick

while(true)

{
getJoystickSettings(joystick);

if(abs(joystick.joy1_y2) > eroare) // pentru valoare analog mai mare decat eroarea
{
motor[motorD] = joystick.joy1_y2/10; // analogul da valoarea motorului D
}
else
{
motor[motorD] = 0; // motor D oprit
}

if(abs(joystick.joy1_y1) > eroare) // daca valoare absoluta analog e mai mare ca eroarea
{
motor[motorE] = joystick.joy1_y1/10; // motor E primeste valoarea datei analog joystick
}
else
{
motor[motorE] = 0; // motor E e oprit
}

// control Butoane brat

int a = ServoValue[servo1];
int b = ServoValue[servo2];

if(joy1Btn(3) && a <= 245) // daca buton 3 e apasat
{
a = a + 10;
servo[servo1] = a;
}

if(joy1Btn(1) && a >=10) // daca Buton 1 e apasat
{
a = a - 10;
}
servo[servo1] = a;

wait1Msec (50);

//Butoane joystick control mana

if(joy1Btn(2) && b <= 245) // daca Buton 2 e apasat
{
b = b + 10;
servo[servo2] = a;
}

if(joy1Btn(4) && a >=10) // daca Buton 4 e apasat
{
b = b - 10;
}
servo[servo2] = b;

wait1Msec (50);
}
}
