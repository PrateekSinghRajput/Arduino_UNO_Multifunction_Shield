const int red=11;

void setup() {

  Serial.begin(9600);
  pinMode(red,OUTPUT);
}

void loop() {

  int poten=analogRead(A0);
  Serial.println(poten);
  analogWrite(red,poten);
  
}
