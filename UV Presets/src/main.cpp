#include <Arduino.h>
#include "sdSettings.h"

SPIClass spiSD(FSPI); // C3 używa magistrali FSPI

void setup()
{
  Serial.begin(115200);
  delay(1000);

  SD_STAT status_sd;
  status_sd = initSdCard(spiSD);

  switch (status_sd)
  {
  case SD_INIT:
    Serial.println("START");
    Serial.printf("Rozmiar: %llu MB\n\r", SD.cardSize() / (1024 * 1024));
    break;
  case SD_CARD_NONE:
    Serial.println("BRAK KARTY");
    break;
  case SD_ERROR:
    Serial.println("FAIL");
    break;

  default:
    Serial.println("FAIL");
    break;
  }
}

void loop()
{
}