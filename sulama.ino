#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// LCD adresini kontrol et (0x27 veya 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int nemSensorPin = A0;   
const int rolePin = 8;         
const int esikDegeri = 800;    

int sonDurum = -1; 

void setup() {
  Serial.begin(9600); // Seri iletişimi başlatır (Monitör için ŞART)
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
  
  // Seri Monitöre yazdır
  Serial.print("Toprak Nem Degeri: ");
  Serial.println(nemDegeri);

  // --- SULAMA MANTIĞI ---
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

  // Eğer ekranda garip karakterler çıkarsa resetlemek için bir güvenlik önlemi
  // Her 100 okumada bir LCD'yi tazeler
  static int sayac = 0;
  sayac++;
  if(sayac > 100){
    lcd.init(); // LCD'yi gizlice yeniden başlatır, paraziti siler
    lcd.backlight();
    sayac = 0;
    sonDurum = -1; // Ekranın tekrar yazılmasını sağlar
  }

  delay(300); 
}
