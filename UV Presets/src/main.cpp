#include <Arduino.h>
#include "sdSettings.h"

#define TEST

SPIClass spiSD(FSPI); // C3 używa magistrali FSPI
Settings params;

void setup()
{
  Serial.begin(115200);
  delay(1000);

  logger(initSdCard(spiSD));
  logger(readFile(params));

#ifdef TEST
  Serial.printf("czas: %i\n\r", params.time);
  Serial.printf("moc: %i\n\r", params.power);
  Serial.printf("safe: %i\n\r", params.safe);
#endif //TEST


}

void loop()
{
}