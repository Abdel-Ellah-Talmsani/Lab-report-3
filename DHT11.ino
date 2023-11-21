//The goal of this program is to display the DHT to the LCD 
//define lcd pinout 
const int en = 2, rw = 1, rs = 0, d4 = 4, d5 =5  
#include "DHT.h" 
//arduino pin 2 connected to DHT-11's data pin
#define DHTPIN 2
// The type of DHT is DHT 11
#define DHTTYPE DHT11
//Initialize DHT sensor.
DHT dht(dht2, dht11);
void setup() {
  // put your setup code here, to run once:
// set display type as 16 char, 2 rows
lcd.begin(16,2); 
//start the sensor
dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
// wait a few seconds between measurements
delay(2000);
//read humidity
float h = dht.readHumidity();
// Read temprature as celsius 
float h = dht readTemperature();
// clear the display 
lcd.clear();
// print temperature on top line 
lcd.setCursor(0.0);
lcd.print("Temp: "); 
lcd.print(temp);
lcd.print(" C")
// print humidity on bottom line
lcd.setCursor(0.1);
lcd.print("Humid: ");
lcd.print(hum);
lcd.print(" %");

}
