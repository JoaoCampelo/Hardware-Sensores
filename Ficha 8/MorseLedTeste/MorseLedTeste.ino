//Declaração de variaveis
int led = 2;
int push = 3;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(push, INPUT_PULLUP);
}

//codigo para ligar e desligar o led conforme o estado do botão
void loop() {
  if (digitalRead(push)== LOW)
  {
    digitalWrite(led, HIGH);
  }
  else 
  {
    digitalWrite(led, LOW);
  }
}
