int r1 = 13;
int r2 = 12;
int y1 = 11;
int y2 = 10;
int g1 = 9;
int g2 = 8;

int trig=3;
int echo=2;

int buzzer=5;

long duration;
int distance;


void setup() {
  // put your setup code here, to run once:
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  calDistance();
  Serial.println(distance);
  if(distance<=20){
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(y1, HIGH);
    digitalWrite(y2, HIGH);
    digitalWrite(g1, HIGH);
    digitalWrite(g2, HIGH);
    tone(buzzer, 1000);
  }
  else if(distance<=30 && distance>20){
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(y1, HIGH);
    digitalWrite(y2, HIGH);
    digitalWrite(g1, HIGH);
    digitalWrite(g2, HIGH);
    tone(buzzer, 800);
    delay(200);
    noTone(buzzer);
    delay(200);
  }
  else if(distance<=40 && distance>30){
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(y1, HIGH);
    digitalWrite(y2, HIGH);
    digitalWrite(g1, HIGH);
    digitalWrite(g2, HIGH);
    tone(buzzer, 600);
    delay(400);
    noTone(buzzer);
    delay(400);
  }
  else if(distance<=50 && distance>40){
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(y1, LOW);
    digitalWrite(y2, HIGH);
    digitalWrite(g1, HIGH);
    digitalWrite(g2, HIGH);
    tone(buzzer, 400);
    delay(600);
    noTone(buzzer);
    delay(600);
  }
  else if(distance<=60 && distance>50){
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(g1, HIGH);
    digitalWrite(g2, HIGH);
    tone(buzzer, 200);
    delay(800);
    noTone(buzzer);
    delay(800);
  }
  else if(distance<=70 && distance>60){
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(g2, HIGH);
    tone(buzzer, 100);
    delay(1000);
    noTone(buzzer);
    delay(1000);
  }
  else if(distance<=80 && distance>70){
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(g2, LOW);
    tone(buzzer, 50);
    delay(1000);
    noTone(buzzer);
    delay(1000);
  }
  else if(distance>80){
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(g2, LOW);
    tone(buzzer,0);
    noTone(buzzer);
    
  }
}

void calDistance(){  
 digitalWrite(trig, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trig, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trig, LOW); 
 duration = pulseIn(echo, HIGH); 
 distance = duration * 0.034 / 2; 
 
}
