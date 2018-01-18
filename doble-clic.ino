#include<Mouse.h>

void clic() {
  if (Serial.available()) { //If text arrived in from BT Serial...
    msg = (Serial.read());
    if (msg == '1')
    {
      th1 = 400;
      th2 = 300;
      Serial.println("");
      Serial.print("Threshold updated: ");
      Serial.print(th1);
      Serial.print(" - ");
      Serial.println(th2);
      Serial.println("");
      delay(5 * delay1);
    }
    if (msg == '2')
    {
      th1 = 800;
      th2 = 700;
      Serial.println("");
      Serial.print("Threshold updated: ");
      Serial.print(th1);
      Serial.print(" - ");
      Serial.println(th2);
      Serial.println("");
      delay(5 * delay1);

    }
    if (msg == '?')
    {
      Serial.println("");
      Serial.println("Send '1' to set the thresholds to 400 and 300.");
      Serial.println("Send '2' to set the thresholds to 800 and 700.");
      Serial.print("Actual thresholds: ");
      Serial.print(th1);
      Serial.print(" - ");
      Serial.println(th2);
      Serial.println("");
      delay(5 * delay1);
    }
  }

  //SENSOR
  sensor1Reading = analogRead(sensor1);
  sensor2Reading = analogRead(sensor2);
  Serial.print("Sensor 1 = ");
  Serial.println(sensor1Reading);
  Serial.print("Sensor 2 = ");
  Serial.println(sensor2Reading);
  Serial.println("");
  if (sensor1Reading > th1) {
    digitalWrite(led1, HIGH);
    //Mouse.click(MOUSE_LEFT);
    Keyboard.write('x');
    delay(2*delay1);
  } else {
    digitalWrite(led1, LOW);
  }
  if (sensor2Reading > th2) {
    digitalWrite(led1, HIGH);
    //Mouse.click(MOUSE_RIGHT);
    Keyboard.write('z');
    delay(2*delay1);
  } else {
    digitalWrite(led1, LOW);
  }
}
