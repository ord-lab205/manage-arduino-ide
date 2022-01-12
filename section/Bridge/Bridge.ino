const int xPin = 0;
const int yPin = 1;
const int zPin = 2;

int minVal = 265;
int maxVal = 402;

double x;
double y;
double z;

void setup()
{
  Serial.begin(9600); 
}


void loop()
{
  // 소음 진동 센서
  sound_A = analogRead(A0);
  sound_B = analogRead(A1);
  sound_C = analogRead(A2);
  
  vib_A = analogRead(A3);
  vib_B = analogRead(A4);
  vib_C = analogRead(A5);
  
  Serial.print((String) sound_A+" "+sound_B+" "+sound_C+" ");
  Serial.print((String) vib_A+" "+vib_B+" "+vib_C);
  Serial.print(" ");

  int xRead = analogRead(xPin);
  int yRead = analogRead(yPin);
  int zRead = analogRead(zPin);

  int xAng = map(xRead, minVal, maxVal, -90, 90);
  int yAng = map(yRead, minVal, maxVal, -90, 90);
  int zAng = map(zRead, minVal, maxVal, -90, 90);

  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

  Serial.print(x+" ");
  Serial.print(y+" ");
  Serial.println(z+" ");

  delay(1000);
}
