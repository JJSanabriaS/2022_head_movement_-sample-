#include <SoftwareSerial.h>
/* Comunicação Serial */
SoftwareSerial HC05(10, 11); /* Simula TX e RX nas portas 10 e 11 */
char  state ;  /* Variável para avaliar os comando recebidos */
void setup()
{
  HC05.begin(38400);     /* Taxa de transmissão do Módulo */
  Serial.begin(9600);    /* Taxa de transmissão na serial */
}

void loop()
{
 if (HC05.available() != ' ')
{ /* Se o sinal recebido no HC05 for maior que 0 */
  state = HC05.read(); /* state será igual ao valor no Serial */
  Serial.write(state); /* Escreve na porta Serial */
  delay(10);               /* Aguarda 10 ms */
}
}
