#include <Servo.h> //Importação da library do servo motor

Servo myservo; //Declaração do motor

//Definição dos periodos para cada nota (*0.0000001)
#define C    1911
#define C1    1804
#define D    1703
#define Eb    1607
#define E    1517
#define F    1432
#define F1    1352
#define G    1276
#define Ab    1204
#define A    1136
#define Bb    1073
#define B    1012
#define c       955
#define c1      902
#define d       851
#define eb      803
#define e       758
#define f       716
#define f1      676
#define g       638
#define ab      602
#define a       568
#define bb      536
#define b       506 
#define p       0  //pausa

//Declaração de vairaveis
int ledGreen = 3;
int ledRed = 4;
int randNumber;
int randNumber2;
int correcta=0;
int flag = 0;
int buzzer = 5;
long vel = 20000;

void setup() {
  Serial.begin(9600); //Inicialização do Serial
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  myservo.attach(2); //Dizer a porta onde o motor vaisestar ligado
  myservo.write(0); //Colocar o motor na posição de 0º
}

int melod[] = {e, e, e, c, e, g, G, c, G, E, A, B, Bb, A, G, e, g, a, f, g, e, c, d, B, c};
int ritmo[] = {6, 12, 12, 6, 12, 24, 24, 18, 18, 18, 12, 12, 6, 12, 8, 8, 8, 12, 6, 12, 12, 6, 6, 6, 12};

void loop() {
  
  flag = 0;
  
  //Utilização da funçaõ random para sortear aleatoriamente valores
  randNumber=random(10);
  randNumber2=random(10);
  
  int gerada=randNumber+randNumber2; //Gurdar a soma dos dois valores sorteados
  
  //Codigo para colcar a pergunta ao jogador
  Serial.print("Quanto da a seguinte conta: ");
  Serial.print(randNumber);
  Serial.print("+");
  Serial.println(randNumber2);
  Serial.println('\n');
  
  int resposta=Serial.read(); //Recolher a resposta do jogador
 
  while(!flag)
  {
    while(Serial.available() > 0) 
    {
      resposta=Serial.parseInt(); //Converter a resposta do utilizador de char para inteiros
      
      //Verificar se a resposta do utilizador esta certa e executar o codigo se a resposta estiver correcta
      if(resposta==gerada)
      {
        correcta+=1;
        Serial.print("Acertou em ");
        Serial.print(correcta);
        Serial.println(" resposta(s) consecutivamente!\n");
        myservo.write(22.5*correcta);
        digitalWrite(ledGreen, HIGH);
        delay(3000);
        digitalWrite(ledGreen, LOW);
        if(correcta == 8)
        {
          Serial.println("Parabens!!!\nGanhou o jogo!\nJogue novamente.");
          
          for (int i=0; i<42; i++) 
          {
            int tom = melod[i];
            int tempo = ritmo[i];
 
            long tvalue = tempo * vel;
 
            tocar(tom, tvalue); //Chamada da função para tocar a musica
 
            delayMicroseconds(1000); //pausa entre notas!
          }
          
          delay(1000);
          correcta=0;
          myservo.write(0);
        }
        flag=1;
      }
      else //Executa o seguinte codigo se a resposta estiver errada
      {
        Serial.println("Errou!\nVai ter de começar o jogo de novo.\n");
        correcta=0;
        myservo.write(0);
        digitalWrite(ledRed, HIGH);
        delay(3000);
        digitalWrite(ledRed, LOW);
        flag=1;
      } 
    }
  }
}

//Função para reproduzir a musica
void tocar(int tom, long tempo_value) {
  long tempo_gasto = 0;
  while (tempo_gasto < tempo_value) 
  {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(tom / 2);
 
    digitalWrite(buzzer, LOW);
    delayMicroseconds(tom/2);
 
    tempo_gasto += tom;
  }
}

