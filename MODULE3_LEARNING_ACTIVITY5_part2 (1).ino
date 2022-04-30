#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE DHT11
int temperature;
int humidity;

int room_temp = 23;
int room_hum = 28;

#define ledpin_red 5
#define ledpin_green 3
LiquidCrystal_I2C lcd(0x27, 20,4);

int dhtpin = 2;

DHT_Unified dht(dhtpin,DHTTYPE);



void setup()
{
pinMode(ledpin_red,OUTPUT);
pinMode(ledpin_green,OUTPUT);

Serial.begin(9600);

dht.begin();

sensor_t sensor;

dht.temperature().getSensor(&sensor);


Serial.println(sensor.name);


lcd.init();
lcd.backlight();
//lcd.setBacklight(1);

lcd.setContrast(80);

}
void loop()
{
  sensors_event_t event;
  dht.humidity().getEvent(&event);
  dht.temperature().getEvent(&event);
  
  temperature = event.temperature;
  humidity = event.relative_humidity;
 
  //lcd.print(event.temperature);

  //lcd.print(event.relative_humidity);

  
  Serial.println("Humidity");
  Serial.print(humidity);

  Serial.println("Temperature");
  Serial.print(temperature);
  
  if(temperature > room_temp ){
    Serial.println("inside if for temp");
    digitalWrite(ledpin_red,HIGH);
   }
  if(humidity > room_hum)
  {
    Serial.println("inside if for hum");
    digitalWrite(ledpin_green,HIGH);
  }
  lcd.setCursor(0,0);
  
  lcd.print("Temperature :");
  lcd.print(temperature);

  lcd.setCursor(2,1);
  lcd.print("Humidity :");
  lcd.print(humidity);
  //Serial.println(event.temperature);
 
 // 
}
