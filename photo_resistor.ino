#include <Servo.h>
#include <LiquidCrystal_I2C.h>
int resistor_pin = A0;
int servo_pin = A1;

Servo myservo;
int light_value;

LiquidCrystal_I2C lcd(0x27, 16,2);

void setup() {
  // put your setup code here, to run once:
  pinMode(resistor_pin,INPUT);
  myservo.attach(servo_pin);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Photo resistor :");
}

void loop() {
  // put your main code here, to run repeatedly:
  light_value = analogRead(resistor_pin);
  lcd.setCursor(2,1);
  lcd.print(light_value);

  if(light_value > 0){
    myservo.write(light_value);
    Serial.println("Inside if");
   
  }
  
  
  Serial.println("Light  in the room");
  Serial.print(light_value);
  
}
