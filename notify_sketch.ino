#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "ma_auth_token"; 
char ssid[] = "ten_wifi"; 
char pass[] = "ten_matkhau";  

void canhbao()
{
  
  if (151<dustDensity<=250) {
    Blynk.notify("Nong do bui la %f .Chat luong khong khi kem", dustDensity);
  }
  else if (250<dustDensity<=500)
  {
    Blynk.notify("Nong do bui la %f. Chat luong khong khi xau", dustDensity);
  }
  else if ( dustDensity>500){
    Blynk.notify("Nong do bui la %f. Chat luong khong khi doc hai", dustDensity);
  }
}
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
timer.setInterval(1000L,canhbao); 
}
void loop()
{
  Blynk.run();
  timer.run();
}
