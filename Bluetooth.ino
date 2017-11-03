// Basic Bluetooth sketch HC-06_01
// Connect the Hc-06 module and communicate using the serial monitor
//
// The HC-06 defaults to AT mode when first powered on.
// The default baud rate is 9600
// The Hc-06 requires all AT commands to be in uppercase. NL+CR should not be added to the command string
//

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Config.h"
#include "VoltMeter.h"
#include "Output.h"

SoftwareSerial BTserial(CONFIG::BT_RX, CONFIG::BT_TX); // RX | TX
// Connect the HC-05 TX to the Arduino RX on pin 12.
// Connect the HC-05 RX to the Arduino TX on pin 3 through a voltage divider.
VoltMeter Meter;



unsigned long waitMillis = millis() + 1000;
int delayTime = 500;
int count = 0;

void setup()
{
    Serial.begin(9600);
    Serial.println("Enter AT commands:");

    // HC-05 default serial speed is 9600
    BTserial.begin(9600);
    BTserial.write("ready to receive");

    String name = "output object";
    Serial.println("example of string: ");
    Serial.println(name);
    Output Output(1);
}

void loop()
{

    /*if ((long) (millis() - waitMillis) >= 0) {

        waitMillis = millis() + delayTime;
        Meter.serialOutAll();
    }*/

    while (BTserial.available())
    {
        char c = BTserial.read();
        Serial.write("we have bluetoth reeption");
        Serial.write(c);
    }


    // Keep reading from Arduino Serial Monitor and send to HC-06
    while (Serial.available())
    {

        String command = Serial.readStringUntil('\n');
        writeWord(command);
    }



}


void writeWord(String data) {
    int wordIndex = 0;
    String command[5] ;
    data.trim();

    int charIndex = data.indexOf(' ');
    while (charIndex > -1) {
        command[wordIndex] = data.substring(0, charIndex);
        data.remove(0, charIndex + 1);
        data.trim();
        wordIndex++;
        charIndex = data.indexOf(' ');
    }
    command[wordIndex] = data;

        Serial.println(command[0]);
        Serial.println(command[1]);
        Serial.println(command[2]);
        Serial.println(command[3]);
        Serial.println(command[4]);
        BTserial.println(command[0]);
        BTserial.println(command[1]);
        BTserial.println(command[2]);
        BTserial.println(command[3]);
        BTserial.println(command[4]);
}
