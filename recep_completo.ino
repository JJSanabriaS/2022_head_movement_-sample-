#include <SoftwareSerial.h>
SoftwareSerial HC05(10, 11);/* RX pino 11 , TX pino 10 */
const int DIR   = 2;
const int STEP  = 3;
 
void setup() 
{
  pinMode(DIR , OUTPUT);
  pinMode(STEP, OUTPUT);
  Serial.begin(9600); /* Porta Serial do computador */
  HC05.begin(38400);    /* Porta Serial do HC05 */
  Serial.println("Aguardando AT para configurar HC05");
}
void loop() 
{
if (HC05.available()) {
       while (HC05.available()) /* recebendo dados HC05 */
      {
       char c = HC05.read(); /* Leitura  */
       Serial.write(c); /* Escreve na porta Serial */
            if (c=='L')        {
                 digitalWrite(DIR, LOW);    //Define sentido de Rotação
                digitalWrite(STEP, HIGH);
               delayMicroseconds(500);
              digitalWrite(STEP, LOW);
             delayMicroseconds(500);
                } else if (c =='R') {
                 digitalWrite(DIR, HIGH);
            digitalWrite(STEP, HIGH);
               delayMicroseconds(500);
              digitalWrite(STEP, LOW);
             delayMicroseconds(500);
               }
      }
   }
}
