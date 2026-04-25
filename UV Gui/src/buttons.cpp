#include "buttons.hpp"

void setupButtons(AsyncWebServer &server)
{
    server.on("/30", HTTP_GET, [](AsyncWebServerRequest *request){
        Serial.println("30");
        request->send(200, "text/plain", "OK");
    });

    server.on("/60", HTTP_GET, [](AsyncWebServerRequest *request){
        Serial.println("60");
        request->send(200, "text/plain", "OK");
    });

    server.on("/90", HTTP_GET, [](AsyncWebServerRequest *request){
        Serial.println("90");
        request->send(200, "text/plain", "OK");
    });

    server.on("/inf", HTTP_GET, [](AsyncWebServerRequest *request){
        Serial.println("INF");
        request->send(200, "text/plain", "OK");
    });

    server.on("/stop", HTTP_GET, [](AsyncWebServerRequest *request){
        Serial.println("STOP");
        request->send(200, "text/plain", "OK");
    });
}