#include "jsonParser.h"

void loadConfig(File &configFile, Settings &param)
{
    JsonDocument doc;

    DeserializationError error = deserializeJson(doc, configFile);

    if (error)
    {
        return;
    }

    param.time = doc[TIME];
    param.power = doc[POWER];
    param.safe = doc[SAFE];
}
