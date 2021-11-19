#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <ArduinoJson.h>

#include "config.h"  // Sustituir con datos con la red
#include "API.hpp"
#include "Websockets.hpp"
#include "Server.hpp"
#include "ESP8266_Utils.hpp"
#include "ESP8266_Utils_AWS.hpp"
#include "ReactiveArduinoLib.h"

auto obsD0 = Reactive::FromDigitalInput(D0);
auto obsD5 = Reactive::FromDigitalInput(D5);
auto obsD6 = Reactive::FromDigitalInput(D6);
auto obsD7 = Reactive::FromDigitalInput(D7);
auto obsD1 = Reactive::FromDigitalInput(D0);
auto obsD2 = Reactive::FromDigitalInput(D5);
auto obsD3 = Reactive::FromDigitalInput(D6);
auto obsD4 = Reactive::FromDigitalInput(D7);


void setup(void)
{
  Serial.begin(115200);
  SPIFFS.begin();

  ConnectWiFi_STA();

  InitServer();
  InitWebSockets();

  obsD0.Distinct().Do([](int i) { updateGPIO("D0", i); });
  obsD5.Distinct().Do([](int i) { updateGPIO("D5", i); });
  obsD6.Distinct().Do([](int i) { updateGPIO("D6", i); });
  obsD7.Distinct().Do([](int i) { updateGPIO("D7", i); });
  obsD1.Distinct().Do([](int i) { updateGPIO("D0", i); });
  obsD2.Distinct().Do([](int i) { updateGPIO("D1", i); });
  obsD3.Distinct().Do([](int i) { updateGPIO("D2", i); });
  obsD4.Distinct().Do([](int i) { updateGPIO("D3", i); });

}

void loop(void)
{
  obsD0.Next();
  obsD5.Next();
  obsD6.Next();
  obsD7.Next();
  obsD0.Next();
  obsD1.Next();
  obsD2.Next();
  obsD3.Next();
}
