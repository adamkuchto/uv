#include "main.hpp"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

bool ledState = false;

void onWsEvent(AsyncWebSocket *server,
               AsyncWebSocketClient *client,
               AwsEventType type,
               void *arg,
               uint8_t *data,
               size_t len)
{

  if (type == WS_EVT_DATA)
  {
    String msg = "";
    for (size_t i = 0; i < len; i++)
      msg += (char)data[i];

    if (msg == "toggle")
    {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      ws.textAll(ledState ? "ON" : "OFF");
    }
  }
}

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

  ws.onEvent(onWsEvent);
  server.addHandler(&ws);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/index.html", "text/html"); });

  server.begin();
}

void loop()
{
  ws.cleanupClients();
}
