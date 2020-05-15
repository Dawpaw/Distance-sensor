//Its either INO or CPP I don't remember to be honest

#define trigPin 6
#define echoPin 7


int pausa;
const int buzzer = 3;
const int led = 9;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  delay(500);
  if (distance >= 100 || distance <= 0){
    Serial.println("Fuera de rango");
    digitalWrite (buzzer, LOW);
    digitalWrite (led, LOW);
  }
  else{
    pausa = distance/2;
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(buzzer, HIGH);
      delay(pausa);
    digitalWrite(led,  HIGH);
      delay(pausa);
    digitalWrite(buzzer,LOW);
      delay(pausa);
    digitalWrite(led, LOW);
      delay(pausa);
    
   }
    

 

  
}
