//char msg;
//int th; //Threslhold.
//int sensor1 = 5;
//int sensor2 = 4;
//int led1 = 13;
//int sensor1Reading;
//int sensor2Reading;
//int delay1 = 100;
//
//void setup()
//{
//  Serial1.begin(9600);  // Begin the serial monitor at 9600bps
//  delay(100);
//  Serial1.println("Hello from Arduino"); // Send test message to other device.
//  pinMode(led1, OUTPUT);
//  th = 1023;
//}
//void loop() {
//  //BT message.
//  if (Serial1.available()) { //If text arrived in from BT serial...
//    msg = (Serial1.read());
//    if (msg == '1')
//    {
//      digitalWrite(led1, HIGH);
//    }
//
//    if (msg == '2')
//    {
//      digitalWrite(led1, LOW);
//    }
//  }
//}
#include<Mouse.h>
char msg;
int th; //Threslhold.
int sensor1 = 5;
int sensor2 = 4;
int led1 = 13;
int sensor1Reading;
int sensor2Reading;
int delay1 = 100;

void setup() {
  Serial1.begin(9600);
  Mouse.begin(); //Enables mouse control.
  Serial1.println("Hello from Arduino"); // Send test message to other device.
  pinMode(led1, OUTPUT);
  th = 1023;
  delay(10 * delay1);
}

void loop() {
  //BT message.
  if (Serial1.available()) { //If text arrived in from BT serial...
    msg = (Serial1.read());
    if (msg == '1')
    {
      th = 400;
      Serial1.println("");
      Serial1.print("Threshold updated: ");
      Serial1.println(th);
      Serial1.println("");
      delay(3 * delay1);
    }
    if (msg == '2')
    {
      th = 800;
      Serial1.println("");
      Serial1.print("Threshold updated: ");
      Serial1.println(th);
      Serial1.println("");
      delay(3 * delay1);

    }
    if (msg == '?')
    {
      Serial1.println("");
      Serial1.println("Send '1' to set the threshold to 400.");
      Serial1.println("Send '2' to set the threshold to 800.");
      Serial1.print("Actual threshold: ");
      Serial1.println(th);
      Serial1.println("");
      delay(3 * delay1);
    }
  }

  //SENSOR
  sensor1Reading = analogRead(sensor1);
  sensor2Reading = analogRead(sensor2);
  Serial1.print("Sensor 1 = ");
  Serial1.println(sensor1Reading);
  Serial1.print("Sensor 2 = ");
  Serial1.println(sensor2Reading);
  Serial1.println("");
  if (sensor1Reading > th) {
    digitalWrite(led1, HIGH);
    Mouse.click(MOUSE_LEFT);
    delay(delay1);
  } else {
    digitalWrite(led1, LOW);
  }
  if (sensor2Reading > th) {
    digitalWrite(led1, HIGH);
    Mouse.click(MOUSE_RIGHT);
    delay(delay1);
  } else {
    analogWrite(led1, LOW);
  }
  delay(delay1);
}
