
#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(10, 11); // RX | TX

void setup()
{

  Serial.begin(9600);
  Bluetooth.begin(9600);  //Default Baud for comm, it may be different for your Module.
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
  Serial3.begin(9600);   // serial port 3
}
    byte rxByte;
void loop()
{

  // Feed any data from bluetooth to Terminal.
    if (Bluetooth.available()){
        rxByte = Bluetooth.read();
        Serial.write(rxByte);
        Serial3.write(rxByte);
    }


  // Feed all data from termial to bluetooth
    if (Serial.available()){
        rxByte = Serial.read();
        Bluetooth.write(rxByte);

    }
}
