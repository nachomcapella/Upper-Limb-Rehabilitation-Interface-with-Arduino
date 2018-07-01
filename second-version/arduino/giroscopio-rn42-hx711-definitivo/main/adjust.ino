#include<Mouse.h>

void clic() {

  //HX711
  units = 0.00; //Reset the value to avoid false "clicks".
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  Serial.print("Reading: ");
  units = scale.get_units(), 10;
  if (units < 0)
  {
    units = 0.00;
  }
  Serial.print(units);
  Serial.print(" grams");
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();
  
  if (Serial.available())
  {
    char temp = Serial.read();
    if (temp == '+' || temp == 'a')
      calibration_factor += 1;
    else if (temp == '-' || temp == 'z')
      calibration_factor -= 1;
  }
}
