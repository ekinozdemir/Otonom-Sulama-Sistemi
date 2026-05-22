#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

const int nemSensorPin = A0;   
const int rolePin = 8;         
const int esikDegeri = 800;    

int sonDurum = -1; 

void setup() {
  Serial.begin(9600); 
  pinMode(rolePin, OUTPUT);
  digitalWrite(rolePin, HIGH); 
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Sistem Hazir");
  delay(2000);
  Serial.println("Sistem baslatildi...");
}

void loop() {
  int nemDegeri = analogRead(nemSensorPin);
  

  Serial.print("Toprak Nem Degeri: ");
  Serial.println(nemDegeri);


  if (nemDegeri > esikDegeri) { 
    digitalWrite(rolePin, LOW); 
    
    if (sonDurum != 1) { 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SULAMA");
      lcd.setCursor(0, 1);
      lcd.print("YAPILIYOR...");
      sonDurum = 1;
    }
  } 
  else {
    digitalWrite(rolePin, HIGH); 
    
    if (sonDurum != 0) { 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("TOPRAK NEMLI");
      lcd.setCursor(0, 1);
      lcd.print("SULAMA DURDU");
      sonDurum = 0;
    }
  }


  static int sayac = 0;
  sayac++;
  if(sayac > 100){
    lcd.init(); 
    lcd.backlight();
    sayac = 0;
    sonDurum = -1; 
  }

  delay(300); 
}
