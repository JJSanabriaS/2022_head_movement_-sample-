#include <SoftwareSerial.h>
SoftwareSerial HC05(10, 11); /* Simula TX e RX nas portas 10 e 11*/
void setup()
{  HC05.begin(38400);      /* transmissão do Módulo */
  Serial.begin(9600);     /* Taxa de transmissão na serial */
}
void loop()
{
    Serial.println("ON");        /* Sinaliza com a palavra "ON" */
    HC05.println('L');             /* HC05 escreve o valor 2 na serial */
    delay(60);
    HC05.flush();                 /* Limpa a memória */
    delay(20);                    /* Aguarda 20 ms antes de retornar ao loop */
}
