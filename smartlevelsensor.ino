
int ledpinred = 2;    //my pump red LED
int ledpinblue = 8;  //my fan blu blue

int pot_setpoint = 1;

int setpoint = 0;

int triggerpin = 4;

int echopin = 7;

long duration; //variable for the time the ultraonic sensor is on 

int waterlevel;


//
void setup() {
  // put your setup code here, to run once:
  //Initializing port modes
  pinMode(ledpinred,OUTPUT);
  pinMode(ledpinblue,OUTPUT);
  pinMode(triggerpin,OUTPUT);
  pinMode(echopin,INPUT);

  Serial.begin(9600);
  Serial.println("This is assignment");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  //Reading the water level added

  //clearing the water level sensor
  digitalWrite(triggerpin,LOW);
  delayMicroseconds(3);

  //Starting the water level sensor
  digitalWrite(triggerpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin,LOW);

  duration = pulseIn(echopin,HIGH);
  setpoint = analogRead(pot_setpoint);

  //calculating the water level
  waterlevel = duration * 0.0034 / 2;

  Serial.print("water level setpoint");

  Serial.print(setpoint);

  Serial.println("mm");
 
  if(waterlevel > setpoint + 5){
    digitalWrite(ledpinblue,HIGH);
    digitalWrite(ledpinred,LOW);
    }
    else if(waterlevel < setpoint- 5){
      digitalWrite(ledpinred,HIGH);
      digitalWrite(ledpinblue,LOW);
      }


  //the loop should await every 5 seconds

   delay(5000);
}
