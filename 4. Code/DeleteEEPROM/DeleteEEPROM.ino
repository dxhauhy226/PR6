#include <EEPROM.h>

void setup()
{
  Serial.begin(115200);
  EEPROM.begin(512);
  delay(10);
  // xóa các giá trị tại các ô nhớ EEPROM từ 0-511 (có 512 ô nhớ)
  for (int i = 0; i < 512; i++) {
    EEPROM.write(i, 0);
    delay(5); //Phải có delay tối thiểu 5 mili giây giữa mối lần write
  }
  Serial.println("Reading EEPROM ssid");
 
  String esid;
  for (int i = 0; i < 32; ++i)
  {
    esid += char(EEPROM.read(i));
  }
  Serial.println();
  Serial.print("SSID: ");
  Serial.println(esid);
  Serial.println("Reading EEPROM pass");
 
  String epass = "";
  for (int i = 32; i < 96; ++i)
  {
    epass += char(EEPROM.read(i));
  }
  Serial.print("PASS: ");
  Serial.println(epass);
}

void loop()
{
}
