
#include <IRremote.h>
int ledpin1 = 11;
int ledpin2 = 12;
int ledpin3 = 10;
int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);

  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    irrecv.resume(); // Receive the next value
  }
  {
    if(results.value == 16753245)  // Valor referente ao botão 1
    digitalWrite(ledpin1, HIGH);
  }
  {
    if(results.value == 16736925)  // Valor referente ao botao 2
    digitalWrite(ledpin2, HIGH);
    }
    {
    if(results.value == 16720605)  // Valor referente ao botão 4
    digitalWrite(ledpin1, LOW);
  }
  {
    if(results.value == 16712445)  // Valor referente ao botao 5
    digitalWrite(ledpin2, LOW);
    }
     {
    if(results.value == 16769565)  // Valor referente ao botão 3
    digitalWrite(ledpin3, HIGH);
  }
  {
    if(results.value == 16761405)  // Valor referente ao botao 6
    digitalWrite(ledpin3, LOW);
    }
  delay(100);
}
