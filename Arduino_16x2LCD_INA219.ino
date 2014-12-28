//Arduino_16x2LCD_INA219

// trinket pro + ina219 + lcd 16x2 
//test current with multimeter

#include <Wire.h>
#include <Adafruit_INA219.h>
#include <LiquidCrystal.h>
Adafruit_INA219 ina219;


LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

void setup(void) 
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("LV");
  lcd.setCursor(9,0);
  lcd.print("SV");
  lcd.setCursor(6,1);
  lcd.print("mA");
  lcd.setCursor(15,1);
  lcd.print("W");
  uint32_t currentFrequency;
  
  ina219.begin();
  analogWrite(10, 20); //This repalces the need for a potentiometer! 
  //connect pin 10 of the trinket to pin 3 of the LCD 
}

void loop(void) 
{

  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  
  lcd.setCursor(2,0);
  lcd.print(loadvoltage);
  lcd.setCursor(11,0);
  lcd.print(shuntvoltage);
  lcd.setCursor(0,1);
  lcd.print(current_mA);
  lcd.setCursor(9,1);
  lcd.print((current_mA*loadvoltage)/1000);

  delay(1000);
}
