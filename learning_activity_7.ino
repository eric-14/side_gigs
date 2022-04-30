#include <Servo.h>
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x27, 16,2 );
Servo myservo;

int pin_motor = 9;

int value;

void setup() {
  // put your setup code here, to run once:
  
  myservo.attach(pin_motor);
  lcd.init();
  lcd.backlight();
  
  
  Serial.begin(9600);
  lcd.setCursor(1,0);
 
  lcd.print("Servo motor degree : ");
 
}

void loop() {
  
    myservo.write(60);
    
    //lcd.print(i);
    for(int i =0;i < 360;i++){
       myservo.write(i);
       value = analogRead(pin_motor);
       value = map(value, 690,785,0,360);
       Serial.println("Value of servo");
       Serial.print(value);

        lcd.setCursor(2,1);
        lcd.print(value);
   
   }
   
    


}
