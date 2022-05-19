#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <TM1637Display.h>     //
 
#define CLK 2                       // Define the connections pins:
#define DIO 0
 
TM1637Display display = TM1637Display(CLK, DIO);              // Create display object of type TM1637Display:
 
const char *ssid     = "Dinh Xuan Hau";
const char *password = "0981181400";
 
const long utcOffsetInSeconds = 19802;  
 
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "0.vn.pool.ntp.org", utcOffsetInSeconds);
 
void setup(){
  Serial.begin(115200);
   // Clear the display:
  display.clear();
  
  WiFi.begin(ssid, password);
 
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
 
  timeClient.begin();
  timeClient.setTimeOffset(+7*60*60);
}
 
void loop() {
  int A,B;
  
  timeClient.update();
  display.setBrightness(7);                   // Set the brightness:
  
  A = timeClient.getHours() * 100 + timeClient.getMinutes();
  B = timeClient.getSeconds();
  
  if((B % 2) == 0)
  {
    display.showNumberDecEx(A, 0b01000000 , false, 4, 0); 
  }
  else
  {
    display.showNumberDecEx(A, 0b00000000 , false, 4, 0); 
  }
  
}
