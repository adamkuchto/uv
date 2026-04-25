#pragma once

#include <ESPAsyncWebServer.h>

/**
 * @brief Rejestruje endpointy obsługi przycisków na stronie konfiguracyjnej.
 *
 * @param[in] server Referencja do obiektu AsyncWebServer.
 */
void setupButtons(AsyncWebServer &server);
