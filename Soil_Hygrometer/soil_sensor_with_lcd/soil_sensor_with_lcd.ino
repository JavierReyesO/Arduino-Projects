#define soil_moisture A6
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int percentValue;
char formattedValue[5];
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  //lcd.begin(16, 2);
}

void loop() {
  percentValue = map(analogRead(soil_moisture), 1023, 0, 0, 100);
  sprintf(formattedValue, "%02d", percentValue);
  
  //Serial.print("Humidity Percent: ");
  //Serial.print(percentValue);
  
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  
  lcd.setCursor(9,1);
  lcd.print(formattedValue);
  lcd.print("%");
  
  delay(1000); // on miliseconds
}
