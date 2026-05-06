#pragma once

#include <ArduinoJson.h>
#include "sdSettings.h"

#define TIME "czas"
#define POWER "moc"
#define SAFE "safe"

/**
 * @brief Zapisuje parametry w strukturze.
 * 
 * @param[in] configFile Uchwyt do pliku.
 * @param[out] param struktura danych.
 */
void loadConfig(File &configFile, Settings &param);