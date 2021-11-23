void setup()
{
  Serial.begin(9600);
  int a = analogRead(A0);
  int b = analogRead(A1);
  int c = analogRead(A2);
}

void loop()
{
  delay(100);
  int sensors[3] = {a, b, c};

  for(int sensor = 0; sensor<3; sensor++)
  {
    if(sensors[sensor] > 60 || sensors[sensor] == 0)
    {
      // 0으로 뜨는게 센서가 값을 읽지 못한것인지 진짜 감지된 소리가 없는 것인지 확인 필요
        Serial.print(sensors[sensor]);
        Serial.print(" ");
    }
  }
  Serial.println();
}
