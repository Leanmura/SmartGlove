#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Inicializamos la comunicacion serial
Serial.begin(9600);
mySerial.begin(9600);
}

void loop() {
  mySerial.write('1'); Serial.println("Led: ON");
  delay(200);
  mySerial.write('0'); Serial.println("Led: OFF");
  delay(200);
}
