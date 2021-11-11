// 현재 코드는 사운드 센서 하나를 감지하고 Seiral Monitor에 출력하는 코드.
void setup()
{
  Serial.begin(9600);
}

void loop()
{
	a = analogRead(A0);
  if (a > 50) {
    Seiral.println(a);
    delay(100);
  }
}
