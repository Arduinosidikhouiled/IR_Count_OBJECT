#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2); 
int IR = 7;
int buzzer = 8; 
int sw = 9; 
int ledG = 5 ;
int ledR = 6 ;
int n = 0;
int oldValue = 1; 

void setup() { 
    lcd.init(); 
    lcd.backlight(); 
    pinMode(IR, INPUT);
    pinMode(sw, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT); 
    pinMode(ledG, OUTPUT);
    pinMode(ledR, OUTPUT);}

void loop() { 
    lcd.setCursor(0, 0); 
    lcd.print("Counter "); 
    lcd.setCursor(0, 1); 
    lcd.print("obeject : "); 
    lcd.setCursor(10,1); 
    lcd.print(n); 
if (digitalRead(IR) == 0 && oldValue == 1) { 
    oldValue = 0; 
    Count(); } 
else if (digitalRead(IR) == 1 && oldValue == 0) { 
    oldValue = 1; } 
if (digitalRead(sw) == 0) { 
    Reset(); } 
delay(100); } 
void Count() { 
    n = n + 1; 
    lcd.clear(); 
    lcd.setCursor(0, 1); 
    lcd.print("obeject"); 
    lcd.setCursor(10,1); 
    lcd.print(n); 
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, LOW);
    delay(200); 
    digitalWrite(buzzer, LOW);
    digitalWrite(ledR, LOW);
    analogWrite(ledG, 50);
    } 
void Reset() { 
    n = 0; 
    lcd.clear(); 
    lcd.setCursor(0, 1);
    lcd.print("obeject");
    lcd.setCursor(10,1); 
}
