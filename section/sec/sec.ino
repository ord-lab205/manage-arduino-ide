int a, b, c;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  a = analogRead(A0);
  //b = analogRead(A0);
 // c = analogRead(A0);
  b = analogRead(A1);
  c = analogRead(A2);
  
  int sensors[3] = {a, b, c};

  /*for (int i = 0; i < 3; ++i)
  {
    if (sensors[i] > 60 || sensors[i] == 0)
    {
      Serial.print(sensors[i]);
      Serial.print(" ");
    }
    else
    {
      Serial.print(sensors[i]);
      Serial.print(" ");
    }
  }*/

  Serial.println((String) a+" "+b+" "+c);
  
  delay(200);
}
