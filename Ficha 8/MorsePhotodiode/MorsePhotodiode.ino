//Declaração de variaveis
int led = 5;
int branco = 4;
int castanho1 = 2;
int castanho2 = 3;
long tempo;

void setup() {
  Serial.begin(9600); //Inicialização do Serial
  pinMode(branco, INPUT);
  pinMode(castanho1, OUTPUT);
  pinMode(castanho2, OUTPUT);
  pinMode(led, OUTPUT);
  //Defenir a sensibilidade do photodiode
  digitalWrite(castanho1, HIGH);
  digitalWrite(castanho2, HIGH);
}

void loop() 
{
  tempo = pulseIn(branco, HIGH); //Guardar os valores lidos pelo photodiode
  if(tempo < 500)
  {
    digitalWrite(led, HIGH);  
  }
  else
  {
    digitalWrite(led, LOW);  
  }
}
