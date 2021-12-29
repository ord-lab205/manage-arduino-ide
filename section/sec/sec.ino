#include <SoftwareSerial.h>  
SoftwareSerial mySerial(7,6); // Arudino Uno port RX, TX  
  
#define START_1 0x42  
#define START_2 0x4d  
#define DATA_LENGTH_H        0  
#define DATA_LENGTH_L        1  
#define PM1_0_ATMOSPHERE_H   8  
#define PM1_0_ATMOSPHERE_L   9  
#define PM2_5_ATMOSPHERE_H   10  
#define PM2_5_ATMOSPHERE_L   11  
#define PM10_ATMOSPHERE_H    12  
#define PM10_ATMOSPHERE_L    13  
#define PM2_5_PARTICLE_H   16  
#define PM2_5_PARTICLE_L   17  
#define VERSION              26  
#define ERROR_CODE           27  
#define CHECKSUM             29  
byte bytCount1 = 0;  
byte bytCount2 = 0;  
unsigned char chrRecv;  
unsigned char chrData[30];  
int PM01;  
int PM25;  
int PM10;  

int sound_A, sound_B, sound_C, vib_A, vib_B, vib_C;

unsigned int GetPM_Data(unsigned char chrSrc[], byte bytHigh, byte bytLow)  
{  
   return (chrSrc[bytHigh] << 8) + chrSrc[bytLow];  
}

void setup()
{
    Serial.begin(115200);
    mySerial.begin(9600); 
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
  
  // 미세먼지 센서
  if (mySerial.available())   {  
    for(int i = 0; i < 32; i++)     {  
      chrRecv = mySerial.read();  
      if (chrRecv == START_2 ) {   
      bytCount1 = 2;  
      break;  
    }  
    }   
    if (bytCount1 == 2)  
    {  
      bytCount1 = 0;  
      for(int i = 0; i < 30; i++){  
        chrData[i] = mySerial.read();  
    }   
  
    if ( (unsigned int) chrData[ERROR_CODE] == 0 ) {  
      PM01  = GetPM_Data(chrData, PM1_0_ATMOSPHERE_H, PM1_0_ATMOSPHERE_L);  
      PM25  = GetPM_Data(chrData, PM2_5_ATMOSPHERE_H, PM2_5_ATMOSPHERE_L);  
      PM10  = GetPM_Data(chrData, PM10_ATMOSPHERE_H, PM10_ATMOSPHERE_L);  
      Serial.print(PM01);
      Serial.print(" ");
      Serial.print(PM25);
      Serial.print(" ");  
      Serial.println(PM10);  
    }  
    }   
  }  
  delay(1000);
}
