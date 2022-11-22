#include <SPI.h> 
#include <Wire.h> 
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h> 
#include "DHT.h"

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire); 
#define SCREEN_ADDRESS 0x3C 

#define DHTPIN D3 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 

void setup() {
Serial.begin(9600); 
Serial.println("OLED FeatherWing test");

//Memastikan OLED dapat berjalan atau tidak
if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
{
Serial.println(F("SSD1306 allocation failed"));
for(;;);
}


display.setTextSize(2); 
display.setTextColor(SSD1306_WHITE); 
display.clearDisplay(); 
dht.begin();
}

void loop() {
float h = dht.readHumidity(); 
float t = dht.readTemperature(); 
display.setTextSize(1); 
display.setCursor(0,0); 
display.print ("Kelembaban"); 
display.setTextSize(2); 
display.setCursor(0,10); 
display.print(h); 
display.print(" %"); 
display.setTextSize(1); 
display.setCursor(0,35); 
display.print("Temperatur"); 
display.setTextSize(2); 
display.setCursor(0,45); 
display.print(t); 
display.print(" C");

delay(10); 
display.display(); 
display.clearDisplay(); 
}