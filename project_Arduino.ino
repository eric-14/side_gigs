

#include <DHT.h>
#include <DHT_U.h>
#include <Stepper.h>
#define DHTTYPE    DHT11

int DHTPIN = 2;
int ldrpin = A0;
int ldrstatus;
float temp;
float hum;
float output;

DHT_Unified dht(DHTPIN, DHTTYPE);
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;         // number of steps the motor has taken

void setup() {
  // initialize the serial port:
  pinMode(ldrpin,INPUT);
  pinMode(DHTPIN,INPUT);
  
  Serial.begin(9600);
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  
  
  dht.humidity().getSensor(&sensor);
  
  
}

void loop() {

  ldrstatus = analogRead(ldrpin);

  sensors_event_t event;
  dht.temperature().getEvent(&event);

  Serial.println("Temperarure ");
  Serial.print(event.temperature);
  temp = event.temperature;


  dht.humidity().getEvent(&event);

  Serial.println("Humidity ");
  Serial.print(event.relative_humidity);
  hum = event.relative_humidity;

  if(ldrstatus > 200 && hum > 23 && temp > 45){
    //rotate motor
       myStepper.step(1);
      myStepper.setSpeed(70);
      Serial.print("steps:");
      Serial.println(stepCount);
      stepCount++;
    }

  




  
  // step one step:
 
 // delay(00  );
}
