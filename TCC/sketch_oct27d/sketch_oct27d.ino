const int pingPin = 7;
int verde=4;
int amarelo=5;
int vermelho=6;


void setup() {
  Serial.begin(9600);
}

void loop()
{
  long duration, inches, cm;
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.println("cm");
  delay(10);
if(cm <=120 && cm>=87){ 
    digitalWrite(verde, HIGH);
    tone(8,5);
    delay(500);
    digitalWrite(verde, LOW);
    noTone(8);
}
if(cm <=87 && cm>=54){
   digitalWrite(verde, HIGH);
    digitalWrite(amarelo, HIGH);
    tone(8,10);
    delay(250);
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, LOW);
    noTone(8);  
}
if(cm <=54 && cm>=20){
   digitalWrite(verde, HIGH);
    digitalWrite(amarelo, HIGH);
    digitalWrite(vermelho, HIGH);
    tone(8,10);
    delay(150);
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(vermelho, LOW);
    noTone(8);
      
}}


long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
