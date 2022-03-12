int trig=9;
int echo=8;
int buzz = 2;
int duration;
float distance;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  pinMode(echo, INPUT);
  delay(6000);
  pinMode(buzz, OUTPUT);
  Serial.println("Distancia:");
}

void loop()
{
  int i=5;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration/58.2;//converte a o pulso de retorno em distancia em cm
  Serial.println(distance);
    Serial.print("cm");
    Serial.print("/n");
  
  if(distance<=150 && distance >=1)
  {
    i=distance*i;
    digitalWrite(buzz, HIGH);
    delay(i);
    digitalWrite(buzz, LOW);
    delay(i);
  }
  delay(10);
}

