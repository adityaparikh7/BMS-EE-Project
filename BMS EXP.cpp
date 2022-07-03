/*Parking Sensor Assistant*/
#define LEDG1 7
#define LEDG2 6
#define LEDY1 5
#define LEDY2 4
#define LEDR1 3
#define LEDR2 2
#define trigPin 10
#define echoPin 9
#define buzzer 8

int sound = 0;

void setup() {
    Serial.begin(9600);
    pinMode(LEDG1,OUTPUT);
    pinMode(LEDG2,OUTPUT);
    pinMode(LEDY1,OUTPUT);
    pinMode(LEDY2,OUTPUT);
    pinMode(LEDR1,OUTPUT);
    pinMode(LEDR2,OUTPUT);
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,OUTPUT);
    pinMode(buzzer,OUTPUT);
}

void loop() {
    long timeTaken, distance;
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    timeTaken = pulseIn(echoPin,HIGH);
    distance = (timeTaken/2)/ 29.1;

    if(distance<81){
        digitalWrite(LEDG1,HIGH); sound = 600;
    }else{
        digitalWrite(LEDG1,LOW);
    }

    if(distance<71){
        digitalWrite(LEDG2,HIGH); sound = 800;
    }else{
        digitalWrite(LEDG2,LOW);
    }

    if(distance<61){
        digitalWrite(LEDY1,HIGH); sound = 1000;
    }else{
        digitalWrite(LEDY1,LOW);
    }

    if(distance<51){
        digitalWrite(LEDY2,HIGH); sound = 1200;
    }else{
        digitalWrite(LEDY2,LOW);
    }

    if(distance<41){
        digitalWrite(LEDR1,HIGH); sound = 1400;
    }else{
        digitalWrite(LEDR1,LOW);
    }

    if(distance<31){
        digitalWrite(LEDR2,HIGH); sound = 1600;
    }else{
        digitalWrite(LEDR2,LOW);
    }

    /*buzzer tone*/
      if(distance>80||distance<=0){
          noTone(buzzer);
         
        }else{
          tone(buzzer, sound);
         
        }
        
      
      delay(500);



}