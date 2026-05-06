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

SD_STAT readFile()
{
    File fileSettings = SD.open(JSON_FILE);

    if (fileSettings)
    {
        while (fileSettings.available())
        {
            Serial.write(fileSettings.read());
        }
        fileSettings.close();
    }
    else
    {
        return SD_FILE_ERROR;
    }
    return SD_FILE_OK;
}

void logger(SD_STAT status_sd)
{
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
        Serial.println("BŁĄD");
        break;
    case SD_FILE_OK:
        Serial.println("PLIK OK");
        break;
    case SD_FILE_ERROR:
        Serial.println("BŁĄD PLIKU");
        break;

    default:
        Serial.println("BŁĄD");
        break;
    }
}