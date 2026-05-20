#include <Wire.h> 
  #include <LiquidCrystal_I2C.h>


  LiquidCrystal_I2C lcd(0x27, 16, 2); 

  int nemPin = A0;
  int rolePin = 2;

  void setup() {
    Serial.begin(9600);
    pinMode(rolePin, OUTPUT);
    
    
    digitalWrite(rolePin, HIGH); 

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Sistem Hazir");
    delay(2000);
    lcd.clear();
  }

  void loop() {
    int nem = analogRead(nemPin);
    
    lcd.setCursor(0, 0);
    lcd.print("Nem Degeri: ");
    lcd.print(nem);
    lcd.print("   "); 

    
    if (nem > 800) { 
      // POMPA AÇILMASI GEREKİYOR
      digitalWrite(rolePin, LOW); 
      lcd.setCursor(0, 1);
      lcd.print("POMPA ACILDI    ");
    } else {
      // POMPA KAPANMASI GEREKİYOR
      digitalWrite(rolePin, HIGH); 
      lcd.setCursor(0, 1);
      lcd.print("POMPA KAPANDI   ");
    }
    
    delay(500); 
  }
