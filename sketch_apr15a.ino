#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define MOISTURE_PIN A0
#define PIR_PIN 6
#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();

  pinMode(PIR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("SILO MONITOR");
  lcd.setCursor(0, 1);
  lcd.print("INITIATING...");
  
  delay(5000); 
  lcd.clear();
}

void loop() {
  bool isDangerous = false;
  String warningMsg = "";

  // 1. Data Acquisition
  int moisture = analogRead(MOISTURE_PIN);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int motion = digitalRead(PIR_PIN);

  // Ultrasonic logic
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;

  // 2. Threshold Logic
  if (moisture < 800) {      
    isDangerous = true; 
    warningMsg = "WET DETECTED!"; 
  } 
  else if (temp > 38) { 
    isDangerous = true; 
    warningMsg = "HIGH TEMP!"; 
  }
  else if (motion == HIGH) {
    isDangerous = true;
    warningMsg = "MOTION ALERT!";
  }

  // 3. Display Logic
  if (isDangerous) {
    // Flash for exactly 5 seconds
    // 5 cycles * (500ms ON + 500ms OFF) = 5000ms
    for(int i = 0; i < 5; i++) {
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("!!! WARNING !!!");
        lcd.setCursor(0, 1);
        lcd.print(warningMsg);
        delay(500);
        
        lcd.noBacklight();
        delay(500);
    }
    lcd.backlight(); 
  } 
  else {
    // Normal Mode Screen 1
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Moist:"); lcd.print(moisture);
    lcd.setCursor(0, 1);
    lcd.print("T:"); lcd.print(temp, 1); 
    lcd.print("C H:"); lcd.print(hum, 0); lcd.print("%");
    delay(2500);

    // Normal Mode Screen 2
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Silo Lvl:"); lcd.print(distance); lcd.print("cm");
    lcd.setCursor(0, 1);
    lcd.print("Status: SAFE");
    delay(2500);
  }
}