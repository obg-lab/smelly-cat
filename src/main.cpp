#include <secrets.h>

#include <wifi.h>
#include <ntp.h>
#include <mqtt.h>
#include <scale.h>

void checkWiFiThenMQTT(void)
{
  connectToWiFi("Checking WiFi");
  connectToMqtt();
}

void setup() {
  Serial.begin(115200);
  delay(5000);
  Serial.println();
  Serial.println();

  setupWifi();
  NTPConnect();
  setupSSL();
  setupMQTT();
  setupScale();

  connectToMqtt();
}

void loop() {
  now = time(nullptr);
  if (!client.connected())
  {
    checkWiFiThenMQTT();
  }
  else
  {
    client.loop();
    if (millis() - lastMillis > 18e5)
    {
      lastMillis = millis();
      long data = getScale();
      sendData(data);
    }
  }
}
