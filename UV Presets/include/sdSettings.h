#pragma once

#include <SPI.h>
#include <SD.h>

#define SD_MISO  2
#define SD_MOSI  3
#define SD_SCLK  4
#define SD_CS    7
#define SPI_SPEED_FOR_SD 4000000

typedef enum {
    SD_INIT = 0,
    SD_ERROR = 1,
    SD_CARD_NONE = 2
} SD_STAT;

/**
 * @brief Inicjalizuje połączenie SD przez SPI.
 * 
 * @param mainLine Magistrala SPI.
 * @return SD_STAT ENUM informacja o przebiegu połączenia.
 */
SD_STAT initSdCard(SPIClass &mainLine);