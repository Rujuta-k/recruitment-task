#define TRIG D1
#define ECHO D2
#define LED D0
long duration; 
int distance; 
void setup(){
  pinMode(TRIG, OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(ECHO,INPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delay(10);
  digitalWrite(TRIG,LOW);
  duration= pulseIn(ECHO,HIGH); 
  distance = duration*(0.034 / 2.0);
  int coordinates = map(distance,0,1023,255,0);
  analogWrite(LED,coordinates); 
  Serial.print(distance);
  Serial.println("cm");
  Serial.println();
  
  delay(100);

}
