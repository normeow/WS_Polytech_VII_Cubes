const double EPS = 0.08;

const int RGBLED_PIN_R = 9;
const int RGBLED_PIN_G = 10;
const int RGBLED_PIN_B = 11;

const String TAG_5_0 = "THE SUN. YELLOW 5V";
const String TAG_4_6 = "THE HEART. RED ~4.64V";
const String TAG_4_2 = "THE WHALE. BLUE ~4.2V";
const String TAG_3_9 = "THE TREE. GREEN ~3.93V";

int r = 0, g = 0, b = 0;
bool i = 1;
//track current face
bool f1, f3;

bool isequal(double v1, double v2){
  return abs(v1 - v2) < EPS;
}

void turnOnDaLight(int r, int g, int b){
  analogWrite(RGBLED_PIN_R, r);
  analogWrite(RGBLED_PIN_G, g);
  analogWrite(RGBLED_PIN_B, b);
}


void turnOnDaLight(){
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
  double val = analogRead(A0)/204.6;
  
  if (isequal(val, 5.0)){
    Serial.println(TAG_5_0);
    if (f1) {
      r = (r + 5) % 256 + 5; 
      g = r/ 6 + 1;
      
    }
    else{
    r = 10;
    g = 1;
    b = 0;
    
    f1 = true;
    f3 = false;
    
    }
    turnOnDaLight();
    //turnOnDaLight(255, 50, 0);
  }
  else if (isequal(val, 4.64)){
    Serial.println(TAG_4_6);
    
    turnOnDaLight(255*i, 0, 0);
    i = ! i;
  }
  else
  if (isequal(val, 4.2)){
    Serial.println(TAG_4_2);
    if (f3)
      b = (b + 30) % 256;
    else{
      r = 0;
      g = 0;
      b = 10;
      
      f3 = true;
      f1 = false;
    }
    turnOnDaLight();
    //turnOnDaLight(0, 0, 255);
  }
  else
  if (isequal(val, 3.93)){
    Serial.println(TAG_3_9);
    turnOnDaLight(0, 255, 0);
  }
  else
  {
    turnOnDaLight(0, 0, 0);
  }
  delay(1500);
  
}
