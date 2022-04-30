 
int led_pin = 7;
int led_pin2 = 2;
int led_pin3 = 4;
int i =0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int k=0;
  while(k<4){
    if(k ==1 ){
      digitalWrite(led_pin2,LOW);
      digitalWrite(led_pin3,LOW);
       digitalWrite(led_pin,HIGH);
       
      delay(1000);
      }else if(k ==2){
        digitalWrite(led_pin,LOW);
        digitalWrite(led_pin3,LOW);
        digitalWrite(led_pin2,HIGH);
        
        delay(1000);
     }else if( k == 3){
      digitalWrite(led_pin,LOW);
       digitalWrite(led_pin2,LOW);
      digitalWrite(led_pin3,HIGH);
      
        delay(1000);
      }
      k=k+1;
    
    }
   
   
    
    
}
