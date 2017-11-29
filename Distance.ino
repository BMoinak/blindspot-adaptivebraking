 int trigPin1 = 2;
 int echoPin1= 3;
 int trigPin2 = 8;
 int echoPin2 = 9;
 int mot1=5;
int mot2=6;
int led= 4;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(mot1,OUTPUT);
pinMode(mot2,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  long duration , cm;
//Blind-Spot Detection
  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  pinMode(echoPin1, INPUT);
  duration = pulseIn(echoPin1, HIGH);
  cm = microsecondsToCentimeters(duration);
  if(cm<60)
 { digitalWrite(led,HIGH);
  delay(cm*10);
  digitalWrite(led,LOW);
 delay(cm*10);
 }


//Adaptive Braking System
 long duration2 , cm2;
//Blind-Spot Detection
  pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);
  cm2 = microsecondsToCentimeters(duration2);
  if(cm2<12)
 { digitalWrite(mot1,LOW);
 digitalWrite(mot2,LOW);
 }



 
 //motor
 else{
 digitalWrite(mot1,HIGH);
 digitalWrite(mot2,LOW);
 }

 Serial.println(cm);
  delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
