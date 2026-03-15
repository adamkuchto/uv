#include <Arduino.h>
#include "LTR390.h"

LTR390 uv;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  if (uv.begin() == false)
  {
    Serial.println("Could not connect, fix and reboot");
  }
  else
  {
    Serial.println("Device found.");
  }

  uv.setUVSMode();
  // uv.setGain(3);
  // uv.setResolution(20);
  uv.enable();
}


void loop()
{
  delay(1000);
  Serial.print("UV Data: ");
  Serial.println(uv.getUVSData());

  Serial.print("UV Index: ");
  Serial.println(uv.getUVIndex());

}