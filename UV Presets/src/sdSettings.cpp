#include "sdSettings.h"

SD_STAT initSdCard(SPIClass &mainLine)
{
    mainLine.begin(SD_SCLK, SD_MISO, SD_MOSI, SD_CS);

    if (!SD.begin(SD_CS, mainLine, SPI_SPEED_FOR_SD))
    {
        return SD_ERROR;
    }

    if (SD.cardType() == CARD_NONE)
    {
        return SD_CARD_NONE;
    }

    return SD_INIT;
}