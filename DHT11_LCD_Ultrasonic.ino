//The goal of this program is to display the DHT to the LCD when an object is detected with the ultrasonic sensor. Th
// the ultrasonic sensor also informs of the distance of the object.
define ultrasonic pins
#define trigPin 10
#define echoPin 13
//define lcd pinout 
const int en = 2, rw = 1, rs = 0, d4 = 4, d5 =5  
// include wire library for I2C
#include <Wire.h> 
// define I2C address - change if required 
const int i2c 
//include DHT library from Adafruit
#include "DHT.h" 
//arduino pin 2 connected to DHT-11's data pin
#define DHTPIN 2
//include NewLiquidCrystal library for I2C
#include <liquidCrystal_I2c.h>
// The type of DHT is DHT 11
#define DHTTYPE DHT11
//Initialize DHT sensor.
DHT dht(dht2, dht11);
void setup() {
  // put your setup code here, to run once:
// announce the ultrasonic pins
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
// set display type as 16 char, 2 rows
lcd.begin(16,2); 
//start the sensor
dht.begin();
// Print a message to the LCD. 
  lcd.print("distance="); 
}

void loop() {
  // put your main code here, to run repeatedly:
// wait a few seconds between measurements
// the lines of program explaining if the sensor is on or not
digitalWrite(trigPin, LOW); 
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW); 
duration = pulseIn(echoPin, HIGH);
distance = (duration / 2) * 0.0343;
//send results to LCD display
if (distance >=400 || distance <=2) {
  lcd.print("distance=Out of range");
}
else {
   lcd.print(distance);
  lcd.print("cm");
  delay(500);
}
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
