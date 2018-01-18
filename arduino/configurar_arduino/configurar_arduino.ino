
char nombre[21] = "arduino";
char bps = '4';
char contrasena[5] = "1234";
int led1 = 13;
int delay1 = 10000;
int delay2 = 1000;
int delay3 = 500;

void setup() {
Serial1.begin(9600); //Serial1 works with Arduino Micro as SofwareSerial does with Uno.
pinMode(led1,OUTPUT);
digitalWrite(led1,HIGH);
delay(delay1);
digitalWrite(led1,LOW);

Serial1.print("AT"); //Comienza la configuración.
delay(delay2);

Serial1.print("AT+NAME"); //Da nombre al bluetooth.
Serial1.print(nombre);
delay(delay2);

Serial1.print("AT+BAUD"); //Define una velocidad de trabajo.
Serial1.print(bps);
delay(delay2);

Serial1.print("AT+PIN"); //Establece la contraseña.
Serial1.print(contrasena);
delay(delay2);
}

void loop() {
  digitalWrite(led1, !digitalRead(led1)); //El led parpadea.
  delay(delay3);
}
