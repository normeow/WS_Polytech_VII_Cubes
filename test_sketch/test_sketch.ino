
const double EPS = 0.08;

const int RGBLED_PIN_R = 9;
const int RGBLED_PIN_G = 10;
const int RGBLED_PIN_B = 11;

bool isequal(double v1, double v2){
  return abs(v1 - v2) < EPS;
}

void turnOnDaLight(int r, int g, int b){
  analogWrite(RGBLED_PIN_R, r);
  analogWrite(RGBLED_PIN_G, g);
  analogWrite(RGBLED_PIN_B, b);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(RGBLED_PIN_R, OUTPUT);
  pinMode(RGBLED_PIN_G, OUTPUT);
  pinMode(RGBLED_PIN_B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  5
  4.64
  4.21
  3.93
  */
  double val = analogRead(A0)/204.6;
  
  delay(500);
  if (isequal(val, 5.0)){
    Serial.println("Yellow 5.0");
    turnOnDaLight(255, 50, 0);
  }
  else if (isequal(val, 4.64)){
    Serial.println("GREEN ~4.64");
    turnOnDaLight(0, 255, 0);
  }
  else
  if (isequal(val, 4.2)){
    Serial.println("BLUE ~4.2");
    turnOnDaLight(0, 0, 255);
  }
  else
  if (isequal(val, 3.93)){
    Serial.println("RED 3.93");
    turnOnDaLight(255, 0, 0);
    delay(100);
  }
  else
  {
    turnOnDaLight(0, 0, 0);
  }
  
}
