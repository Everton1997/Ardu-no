
#include <Servo.h>

Servo base;
Servo direita;
Servo esquerda;
Servo mao;

int pos = 0;    

void setup() {
  base.attach(3);  
  direita.attach(6);
  esquerda.attach(5);
  mao.attach(9);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {   // Movimenta a base em 180 graus
    // in steps of 1 degree
    base.write(pos);             
    delay(20); 
  }   
    delay(2000);   // Aguarda 2 segundos               

  for (pos = 80; pos <= 147; pos += 1) {   // Abaixa o braço 
    // in steps of 1 degree
    direita.write(pos);             
    delay(20); 
  }
  
  for (pos = 110; pos <= 140; pos += 1) {   // Leva o braço para frente 
    // in steps of 1 degree
    esquerda.write(pos);             
    delay(20); 
  }
  for (pos = 130; pos >= 0; pos -= 1) {    // abre a garra
    // in steps of 1 degree
    mao.write(pos);           
    delay(15);                      
  }
/*  for (pos = 0; pos >= 130; pos += 1) {     // Fecha a garra
    mao.write(pos);             
    delay(15);                      
  }*/
 delay(2000);   // Aguarda 2 segundos
   for (pos = 140; pos >= 110; pos -= 1) {   // Leva o braço para traz 
    // in steps of 1 degree
    esquerda.write(pos);             
    delay(25); 
  }

 
    for (pos = 147; pos >= 80; pos -= 1) {   // Levanta o braço 
    // in steps of 1 degree
    direita.write(pos);             
    delay(25); 
  }


  for (pos = 180; pos >= 0; pos -= 1) {    // Movimenta a base em 180 graus retornando
    base.write(pos);              
    delay(20);                       
  }
    delay(2000);
     for (pos = 80; pos <= 147; pos += 1) {   // Abaixa o braço 
    // in steps of 1 degree
    direita.write(pos);             
    delay(20); 
  }

  for (pos = 110; pos <= 140; pos += 1) {   // Leva o braço para frente 
    // in steps of 1 degree
    esquerda.write(pos);             
    delay(20); 
  }
 /* for (pos = 130; pos >= 0; pos -= 1) {    // abre a garra
    // in steps of 1 degree
    mao.write(pos);           
    delay(15);                      
  }*/
  for (pos = 0; pos <= 130; pos += 1) {     // Fecha a garra
    mao.write(pos);             
    delay(15);                      
  }
  delay(2000);  // Aguarda 2 segundos
  
    for (pos = 140; pos >= 110; pos -= 1) {   // Leva o braço para traz 
    // in steps of 1 degree
    esquerda.write(pos);             
    delay(25); 
  }

    for (pos = 147; pos >= 80; pos -= 1) {   // Levanta o braço 
    // in steps of 1 degree
    direita.write(pos);             
    delay(25); 
  }
  
}

