#include <Wire.h>

// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>

// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);

// Define maximum and minimum number of "ticks" for the servo motors
// Range from 0 to 4095
// This determines the pulse width

#define SDA 26
#define SCL 27 

//Valeur 0° 90° 180° moteur vertical
#define SERVOMIN_1  204  // Minimum value
#define SERVOMAX_1  308  // Maximum value
#define SERVOMID_1  511  // Middle value
#define TICKNUMBER  4095

// Define servo motor connections (expand as required)
#define SER0  0   //Servo Motor 0 on connector 0
#define SER1  1  //Servo Motor 1 on connector 12

// Variables for Servo Motor positions (expand as required)
int pwm0;
int pwm1;

void setup() {

  // Serial monitor setup
  Wire.begin(SDA , SCL);
  Serial.begin(115200);

  // Print to monitor
  Serial.println("PCA9685 Servo Test");

  // Initialize PCA9685
  pca9685.begin();

  // Set PWM Frequency to 50Hz
  pca9685.setPWMFreq(50);

}

void loop() {

  //MIN Moteur vertical
  pca9685.setPWM(SER0, SERVOMIN_1, TICKNUMBER - SERVOMIN_1);
  Serial.println(SERVOMIN_1);
  delay(30000);
  
/*
  //MID Moteur vertical
  pca9685.setPWM(SER0, SERVOMID_1 ,TICKNUMBER - SERVOMID_1 );
  Serial.println(SERVOMID_1);
  delay(5000);
*/
  //MAX Moteur vertical
  pca9685.setPWM(SER0, SERVOMAX_1,TICKNUMBER - SERVOMAX_1 );
  Serial.println(SERVOMAX_1);
  delay(30000);
 
}
