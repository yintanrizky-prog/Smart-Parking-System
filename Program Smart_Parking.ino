#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// --- KONFIGURASI PIN ---
const int PIN_BUTTON    = 2;
const int PIN_MOTOR     = 3;
const int PIN_SERVO     = 9;
const int PIN_POT       = A0;
const int PIN_LED_HIJAU = 13;
const int PIN_LED_KUNING = 11;
const int PIN_LED_MERAH  = 12;

LiquidCrystal_I2C lcd(0x27, 16, 2); 
Servo palang;

void setup() {
  lcd.init();
  lcd.backlight();
  
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_LED_HIJAU, OUTPUT);
  pinMode(PIN_LED_KUNING, OUTPUT);
  pinMode(PIN_LED_MERAH, OUTPUT);
  pinMode(PIN_MOTOR, OUTPUT);
  
  palang.attach(PIN_SERVO);
  
  // --- LOGIKA DIBALIK: POSISI AWAL TUTUP DI 90 DERAJAT ---
  palang.write(90); 
  
  lcd.setCursor(0, 0);
  lcd.print("SISTEM");
  lcd.setCursor(0, 1);
  lcd.print("PARKIR");
  delay(2000);
  lcd.clear();
}

void loop() {
  int nilaiPot = analogRead(PIN_POT);
  int terisi = map(nilaiPot, 0, 1023, 0, 10);
  int sisa = 10 - terisi;

  // Tampilan LCD & LED
  lcd.setCursor(0, 0);
  lcd.print("Terisi: ");
  lcd.print(terisi);
  lcd.print("/10  ");

  lcd.setCursor(0, 1);
  if (sisa > 3) {
    lcd.print("Stat: TERSEDIA ");
    digitalWrite(PIN_LED_HIJAU, HIGH);
    digitalWrite(PIN_LED_KUNING, LOW);
    digitalWrite(PIN_LED_MERAH, LOW);
  } 
  else if (sisa > 0) {
    lcd.print("Stat: WASPADA  ");
    digitalWrite(PIN_LED_HIJAU, LOW);
    digitalWrite(PIN_LED_KUNING, HIGH);
    digitalWrite(PIN_LED_MERAH, LOW);
  } 
  else {
    lcd.print("Stat: PENUH!!  ");
    digitalWrite(PIN_LED_HIJAU, LOW);
    digitalWrite(PIN_LED_KUNING, LOW);
    digitalWrite(PIN_LED_MERAH, HIGH);
  }

  // --- LOGIKA TOMBOL (DIBALIK) ---
  if (digitalRead(PIN_BUTTON) == LOW) {
    if (sisa > 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BUKA PALANG...");
      
      palang.write(0);  // SEKARANG 0 ADALAH BUKA
      
      delay(3000);
      
      palang.write(90); // SEKARANG 90 ADALAH TUTUP
      lcd.clear();
    } 
    else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("MAAF, PENUH!");
      
      palang.write(90); // TETAP DIPAKSA TUTUP DI 90
      
      digitalWrite(PIN_LED_MERAH, LOW); delay(200);
      digitalWrite(PIN_LED_MERAH, HIGH);
      delay(1500);
      lcd.clear();
    }
  }

  // Logika Kipas
  if (terisi >= 8) analogWrite(PIN_MOTOR, 255);
  else if (terisi >= 5) analogWrite(PIN_MOTOR, 150);
  else analogWrite(PIN_MOTOR, 0);

  delay(200); 
}
