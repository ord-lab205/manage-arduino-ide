void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int a = analogRead(A0);
  int b = analogRead(A1);
  int c = analogRead(A2);
  
  int sensors[3] = {a, b, c};

  for(int sensor = 0; sensor<3; sensor++)
  {
    if(sensors[sensor] > 60 || sensors[sensor] == 0)
    {
        Serial.print(sensors[sensor]);
        Serial.print(" ");
    }
  }
  Serial.println();
  delay(100);
}
