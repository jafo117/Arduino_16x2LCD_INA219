// trinkey pro + ina219 + lcd 20x4
//test current with multimeter

#include <Wire.h>
#include <Adafruit_INA219.h>
#include <LiquidCrystal.h>
Adafruit_INA219 ina219;


LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

void setup(void) 
{
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("LOAD:");
  lcd.setCursor(10,0);
  lcd.print("Volts");
  lcd.setCursor(0,1);
  lcd.print("SHUNT:");
  lcd.setCursor(12,1);
  lcd.print("Volts");
  lcd.setCursor(0,2);
  lcd.print("CURRENT:");
  lcd.setCursor(14,2);
  lcd.print("mA");
  lcd.setCursor(0,3);
  lcd.print("POWER:");
  lcd.setCursor(12,3);
  lcd.print("Watts");
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
  
  
  lcd.setCursor(5,0);
  lcd.print(loadvoltage);
  lcd.setCursor(6,1);
  lcd.print(shuntvoltage);
  lcd.setCursor(8,2);
  lcd.print(current_mA);
  lcd.setCursor(6,3);
  lcd.print((current_mA*loadvoltage)/1000);

  delay(1000);
}
