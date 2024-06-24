/*
    Project name : ESP32 IR Receiver Module
    Modified Date: 24-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp32-ir-receiver-module
*/

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t RECV_PIN = 4; // Pin connected to the output of the IR receiver module

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // Print the received IR code in hexadecimal
    irrecv.resume(); // Receive the next value
  }
  delay(100); // Small delay to prevent flooding the serial port
}
