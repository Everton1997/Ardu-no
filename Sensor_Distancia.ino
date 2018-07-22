#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>

#define pino_trigger 4
#define pino_echo 5

const int buzzer = 13;
int LED1 = 12;
int LED2 = 11;
int LED3 = 10;

LiquidCrystal_I2C lcd (0x3F, 20 ,4);
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  // put your setup code here, to run once:
lcd.begin();
lcd.clear();

pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(buzzer, OUTPUT);

Serial.begin(9600);
Serial.println("Lendo dados do sensor...");
}

void loop() {
{
float cmMsec;
long microsec = ultrasonic.timing();
cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);


lcd.setCursor(4,0);
lcd.print("Distancia:");
lcd.setCursor(1,1);
lcd.print(cmMsec);
lcd.setCursor(8,1);
lcd.print("Centimetros");

 Serial.print("Distancia: ");
  Serial.print(cmMsec);
  Serial.println(" Centimetros");


{
if(cmMsec < 5.0)
digitalWrite(LED1, HIGH);
else
  digitalWrite(LED1, LOW);
if(cmMsec > 5.0 && cmMsec < 8.0)
digitalWrite(LED2, HIGH);
else
digitalWrite(LED2, LOW);
if(cmMsec > 8.0)
digitalWrite(LED3, HIGH);
else
digitalWrite(LED3, LOW);
}
{
  if(cmMsec < 5.0)
  tone(buzzer, 1500);
  else
  noTone(buzzer);
  }

}
delay(1500);
}

