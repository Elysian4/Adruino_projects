int trig=12;
int echo=11;
int led=13;
float time_duration;
float distance;

void setup() {
                      //code runs once:
  Serial.begin(9600); //115200
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
                      // code runs repeatdly
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  time_duration=pulseIn(echo,HIGH);
  distance=0.034*time_duration/2;
  if (distance < 10)
  { digitalWrite(led,LOW);
  delay(10);
  }
  else {
    digitalWrite(led,HIGH);
    delay(10);
  }
  Serial.print("Distance in cm: ");
  Serial.println(distance);
  delay(500);
}
