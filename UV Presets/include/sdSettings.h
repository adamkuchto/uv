#pragma once

#include <SPI.h>
#include <SD.h>

#define SD_MISO 2
#define SD_MOSI 3
#define SD_SCLK 4
#define SD_CS 7
#define SPI_SPEED_FOR_SD 4000000
#define JSON_FILE "/settings.json"

typedef enum
{
    SD_INIT = 0,
    SD_ERROR = 1,
    SD_CARD_NONE = 2,
    SD_FILE_ERROR = 3,
    SD_FILE_OK = 4
} SD_STAT;

/**
 * @brief Inicjalizuje połączenie SD przez SPI.
 *
 * @param mainLine Magistrala SPI.
 * @return SD_STAT ENUM informacja o przebiegu połączenia.
 */
SD_STAT initSdCard(SPIClass &mainLine);

/**
 * @brief Czyta plik z ustawieniami.
 *
 * @return SD_STAT ENUM informacja o przebiegu odczytu pliku.
 */
SD_STAT readFile();

/**
 * @brief Wyświetla komunikaty odnośnie dzałań na karcie SD.
 *
 * @param[in] status_sd Status zwracany przez funkcję.
 */
void logger(SD_STAT status_sd);
