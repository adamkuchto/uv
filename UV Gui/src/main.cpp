#include "main.hpp"
#include "buttons.hpp"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  if (!LittleFS.begin())
  {
    Serial.println("LittleFS error");
    return;
  }

  WiFi.softAP(MY_SSID, MY_PASSWORD);
  Serial.println(WiFi.softAPIP());
  setupButtons(server);

  server.addHandler(&ws);
  server.serveStatic("/", LittleFS, "/")
         .setDefaultFile("index.html")
         .setCacheControl("no-cache");

  server.begin();
}

void loop()
{
  ws.cleanupClients();
}
