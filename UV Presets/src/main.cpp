#include <Arduino.h>
#include "sdSettings.h"

SPIClass spiSD(FSPI); // C3 używa magistrali FSPI

void setup()
{
  Serial.begin(115200);
  delay(1000);

  logger(initSdCard(spiSD));
  logger(readFile());

}

void loop()
{
}