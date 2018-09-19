#include <Servo.h>//Import da library do servo motor

Servo motor; //Declaração do motor

//Declaração de variaveis
int sonar = 2;
int infred = 0;
int inf =0;
int son = 0;
int ledR = 8;
int ledB = 9;
int pessoa = 0;
int entra=0;

void setup() {
  Serial.begin(9600); //Inicialização do Serial
  pinMode(ledR,OUTPUT);
  pinMode(ledB,OUTPUT);
  motor.attach(2); //Dizer onde o motor vai estar ligado
}

void loop() {
  motor.write(90); //Defenir a posição do motor a 90º
  
  //Codigo para o sensor de infra-vermelhos
  inf = analogRead(A0);
  if (inf > 400) 
  { 
    motor.write(180); 
    digitalWrite(ledB, HIGH);
    entra=1; 
    delay(150);
  } 
  else 
  {
    digitalWrite(ledB, LOW);
  }
  delay (500);
  
  //Codigo para o sensor do sonar
  son = analogRead(A2);
  if (son < 25) 
  { 
    motor.write(0); 
    digitalWrite(ledR, HIGH);
    if(entra==1)
    {
      pessoa++;
    }
    else
    {
      if(pessoa!=0)
      {
        pessoa--;
      }
    }
    delay(150);
  } 
  else 
  {
    digitalWrite(ledR, LOW);
  }
  delay (1000);
  
  Serial.print("Pessoas no shopping: ");
  Serial.println(pessoa);
  entra=0;
}
