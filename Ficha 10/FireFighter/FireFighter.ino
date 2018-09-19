#include <Servo.h> //Importação da library do servo motor

//Declaração dos motores
Servo servoy;
Servo servox;

//Declaração de variaveis
int botaoy = 0;
int botaox = 1;
int valy;
int valx;
int botao=2;

void setup() {
  Serial.begin(9600); //Inicialização do Serial
  //declarar a porta onde cada motor vai estar ligado
  servoy.attach(4);
  servox.attach(3);
  pinMode(botaoy, INPUT);
  pinMode(botaox, INPUT);
  pinMode(botao, INPUT);
}

void loop() {
  //Ler os valores dos recolhidos dos motores, mapear esses mesmo valores, e guarda-los nas respectivas variaveis
  valy=180-map(analogRead(botaoy), 0, 1023, 0, 180);
  valx=180-map(analogRead(botaox), 0, 1023, 0, 180);
  
  //Escrever para os motores os valores recolhidos anteriormente
  servoy.write(valy);
  servox.write(valx);
  delay(500);
}
