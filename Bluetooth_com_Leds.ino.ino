#include <SoftwareSerial.h>
int ledPin1 = 3;
int ledPin2 = 5;
int ledPin3 = 6;
SoftwareSerial bluetooth(10, 11);    // 10 = RX e 11 = TX
char caracter;  //Variavel que armazenará letras/números para o acionamento dos leds.
void setup() {

  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(ledPin1, OUTPUT) ;
  pinMode(ledPin2, OUTPUT) ;
  pinMode(ledPin3, OUTPUT) ;
}
void loop() {

  // TRoca de informações entre a Porta Serial e o Bluetooth.
  if (bluetooth.available())
  {
    caracter = bluetooth.read();
    Serial.write(caracter);
    bluetooth.write(caracter);
    /*
      if(Serial.available())
      bluetooth.write(Serial.read());
    */
  }
  // Condições para a porta Serial estiver disponivel para ser usada.
  if (Serial.available())
  {
    caracter = Serial.read();
    Serial.print("Dado Obtido: ");
    Serial.println(caracter);
    bluetooth.write(caracter);
  }
  //  Caracteristicas para acionar os Led's
  if (caracter == 'a')
  {
    digitalWrite(ledPin1, HIGH);
  }
  if (caracter == 'b')
  {
    digitalWrite(ledPin2, HIGH);
  }
  if (caracter == 'c')
  {
    digitalWrite(ledPin3, HIGH);
  }
  if (caracter == 'f')
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
  delay(200);
}
