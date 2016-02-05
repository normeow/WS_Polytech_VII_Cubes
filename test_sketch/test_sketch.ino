const int PIN_1 = 11;
const double EPS = 0.08;
bool isequal(double v1, double v2){
  return abs(v1 - v2) < EPS;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  5
  4.64
  4.21
  3.93
  eps = 20
  */
  double val = analogRead(A0)/204.6;
  
  Serial.println("Achtung:");
  Serial.println(val);
  Serial.println();
  delay(500);
  if (isequal(val, 4.64)){
    Serial.println("~4.64");
    //digitalWrite(PIN_1, HIGH);
    analogWrite(PIN_1, 200);
  }
  else
  if (isequal(val, 4.2)){
    Serial.println("~4.2");
    /*digitalWrite(PIN_1, HIGH);
    delay(500);
    digitalWrite(PIN_1, LOW);
    delay(500);*/
    analogWrite(PIN_1, 10);
  }
  else
  if (isequal(val, 3.93)){
    Serial.println("~3.93");
    digitalWrite(PIN_1, HIGH);
    delay(100);
    digitalWrite(PIN_1, LOW);
    delay(100);
    //analogWrite(PIN_1, 50);
  }
  else
  {
    digitalWrite(PIN_1, LOW);
  }
  
}
