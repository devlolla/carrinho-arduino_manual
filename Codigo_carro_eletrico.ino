//APS_ATIVIDADE_PRATICA_SUPERVIONADA_CARRO_ELETRICO
#include "SoftwareSerial.h" //inclui a blibioteca do bluetooth
//Define os pinos da ponte H
#define IN1 3 
#define IN2 5
#define IN3 6
#define IN4 11
//Define os pinos das leds
#define LED1 2
#define LED2 4
SoftwareSerial bluetooth(12, 13); //define os pinos 12 e 13 como TX, RX
int incomingByte;

void setup() 

{
  //define os pinos da ponte H como saida
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  //define os pinos das leds como saida
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  
  Serial.begin(115200); //inicia o monitor serial em 115200
  //demonstra no monitor serial os comandos disponiveis
  Serial.println("Envie 'a' para Acelerar");
  Serial.println("Envie 'f' para Freiar");
  Serial.println("Envie 'd' para girar a direita");
  Serial.println("Envie 'e' para girar a esquerda");
  Serial.println("Envie 'r' para acionar a r� e a lampada de r�");
  Serial.println("Envie 'L' para ligar o farol");
  Serial.println("Envie 'D' para desligar o farol");
  bluetooth.begin(9600);//inicia o serial do bluetooth em 9600 
}

void loop() 

{
char incomingByte = 0;//cria uma variavel character chamada incomingByte que inicia em 0

  if (bluetooth.available()) //Verifica se h� algo a receber na serial virtual
  {
    incomingByte = bluetooth.read(); //faz a variavel incomingByte ler o que foi recebido pelo bluetooth
    Serial.println(incomingByte);//demonstra o que foi lido pelo incomingByte no monitor
  }
  
  if (incomingByte == 'e')//se receber o comando 'e' o carrinho vira para a esquerda, freia e desliga a lampada de r� se estiver acionada
  {
    Serial.println("Esquerda");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, HIGH);
    delay (120);
    Serial.println("Freiar");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    digitalWrite(LED2, LOW);
  }

  if (incomingByte == 'f')//se receber o comando 'f' o carrinho freia e desliga a lampada de r� se estiver acionada
  {
    Serial.println("Freiar");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    digitalWrite(LED2, LOW);
  }

  if (incomingByte == 'd')//se receber o comando 'd' o carrinho vira para a direita, freia e desliga a lampada de r� se estiver acionada
  {
    Serial.println("Girar a direita");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay (120);
    Serial.println("Freiar");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    digitalWrite(LED2, LOW);
  }

  if (incomingByte == 'a')//se receber o comando 'a' o carrinho acelera e desliga a lampada de r� se estiver acionada
  {
    Serial.println("ACELERA");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(LED2, LOW);
  }
  
  if (incomingByte == 'r')//se receber o comando 'r' o carrinho aciona a r� e liga a lampada de r� 
  {
    Serial.println("R�");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(LED2, HIGH);
  }
  if (incomingByte == 'L')//se receber o comando 'L' liga o farol 
  {
    Serial.println("FAROL");
    digitalWrite(LED1, HIGH);

  }  
  if (incomingByte == 'D')//se receber o comando 'D' desliga o farol 
  {
    Serial.println("FAROL");
    digitalWrite(LED1, LOW);

  }
    
}