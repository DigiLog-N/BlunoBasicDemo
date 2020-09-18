#include <Arduino.h>
#include <SPI.h>
#include <MultiLCD.h>

LCD_R61581 lcd;

void setup(){
  lcd.begin();
  lcd.setFontSize(FONT_SIZE_MEDIUM);  //set font size
  lcd.setColor(RGB16_RED);  //set strings color
  lcd.println();
  lcd.println();
  lcd.println("TELEMATICS LCD SHIELD V1.0");
  lcd.println();
  lcd.setColor(RGB16_WHITE);
  Serial.begin(115200);               //initial the Serial
}

void loop()
{
    int incomingByte = 0; // for incoming serial data
    if(Serial.available())
    {
        incomingByte = Serial.read();
        lcd.print(char(incomingByte));
        Serial.write(incomingByte);    //send what has been received
    }
}
