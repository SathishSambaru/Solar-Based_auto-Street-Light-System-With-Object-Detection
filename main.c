#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // 8-RS, 9-EN, 10-D4, 11-D5, 12-D6, 13-D7
#define ldr5
#define ir6
#define light1
7
void title(void)
{
lcd.clear();
lcd.print("SMART STREET LITE");
lcd.setCursor(0,1);
lcd.print("FR ENERGY CONSERV");
}
void setup()
{
lcd.begin(16, 2);
pinMode(ldr, INPUT);
pinMode(ir, INPUT);
pinMode(light1, OUTPUT);
title();
delay(3000);
lcd.clear();
}
void loop()
{
if ((digitalRead(ldr)==LOW)&&(digitalRead(ir)==LOW))
{
lcd.setCursor(0,0);
lcd.print("VEHICLE_STS:YES ");
lcd.setCursor(0,1);
lcd.print("LIGHT_STATS:YES ");
digitalWrite(light1,LOW);
}
else if((digitalRead(ldr)==LOW)&&(digitalRead(ir)==HIGH))
{
lcd.setCursor(0,0);
lcd.print("VEHICLE_STS:NO ");
lcd.setCursor(0,1);
lcd.print("LIGHT_STATS:YES ");
digitalWrite(light1,LOW);
}
else if ((digitalRead(ldr)==HIGH)&&(digitalRead(ir)==LOW))
{
lcd.setCursor(0,0);
lcd.print("VEHICLE_STS:YES ");
lcd.setCursor(0,1);
lcd.print("LIGHT_STATS:NO ");
digitalWrite(light1,HIGH);
delay(3000);
digitalWrite(light1,LOW);
}
else
{
lcd.setCursor(0,0);
lcd.print("VEHICLE_STS:NO ");
lcd.setCursor(0,1);
lcd.print("LIGHT_STATS:NO ");
digitalWrite(light1,LOW);
}
}
