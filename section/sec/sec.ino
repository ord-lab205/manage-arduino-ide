void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // 센서 2개, a : 소리, b : 진동
  int a = analogRead(A0);
  int b = analogRead(A1);
  
  int sensors[2] = {a, b};

  for(int sensor = 0; sensor<2; sensor++)
  {
    // 값은 400이상 받아오는게 적당해 보임
    if(sensors[sensor] > 400)
    {
      if(sensor==0)
      {
        Serial.print("소리 : ");
        Serial.println(sensors[sensor]);
        delay(100);
      }
    }
    // 차체가 지나갈때 평균적으로 50~60정도 되는것 같다.
    if(sensors[sensor] > 10)
    {
      if(sensor==1)
      {
        Serial.print("진동 : ");
        Serial.println(sensors[sensor]);
        delay(100);
      }
    }
    
  }
}
