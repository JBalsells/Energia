#define Trigger PE_0
#define Echo PB_2
#define Cte 0.017

long Dist;
long Time;

void setup(){
  Serial.begin(9600);
  
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
}

void loop(){
  digitalWrite(Trigger,LOW); 
  delayMicroseconds(5);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  
  Time=pulseIn(Echo, HIGH); 
  Dist= int(Cte*Time);

  Serial.println("Distancia: "+String(Dist)+" cm.");
  delay(300);
}
