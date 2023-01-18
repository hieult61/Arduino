#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
WidgetLED led1(V0);   // LED
char auth[] = " ma_auth_token ";
char ssid[] = " ten_wifi ";
char pass[] = " mat_khau ";

void sendSensor()
{
  if (led1.getValue()){
    led1.off();
  }
  else {
    led1.on();
  }
  Blynk.virtualWrite(V5,h);
  Blynk.virtualWrite(V6,t);
  Blynk.virtualWrite(V7,dustDensity);
}

void setup()
{
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
