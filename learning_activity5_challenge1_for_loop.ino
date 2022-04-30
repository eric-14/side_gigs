 
int led_pin = 7;

int i =0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while(1){
    digitalWrite(led_pin,HIGH);
    delay(500);
    digitalWrite(led_pin,LOW);
    delay(500);
    }
    
  
   
    
    
}
