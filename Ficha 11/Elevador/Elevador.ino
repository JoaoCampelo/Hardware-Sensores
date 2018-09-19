//Declaração de variaveis
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int g = 7;
int botao1 = 8;
int botao2 = 9;
int botao3 = 10;
volatile int state1;
volatile int state2;
volatile int state3;
int ultimostate1;
int ultimostate2;
int ultimostate3;
int resultado = 0;
int vel = 11;
int drt = 12;
int esq = 13;

void setup() {
  // Declarar o tipo de funcionamento dos componentes
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(botao1, INPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(botao2, INPUT);
  pinMode(10, INPUT_PULLUP);
  pinMode(botao3, INPUT);
  pinMode(vel, OUTPUT);
  pinMode(drt, OUTPUT);
  pinMode(esq, OUTPUT);
}

void loop() {
  //codigo para o funcionamento do elevador
  ultimostate1;
  ultimostate2;
  ultimostate3;
  //codigo para ler o estado dos push button e gurdar nas respectivas variaveis
  state1 = digitalRead(botao1);
  state2 = digitalRead(botao2);
  state3 = digitalRead(botao3);

  if (state1 == HIGH || ultimostate1 == HIGH)
  {
    liga1();
    //linhas de codigo para saber qual o numero que tem de estar ligado enquanto nao carregamos noutro numero
    ultimostate1 = HIGH;
    ultimostate2 =  LOW;
    ultimostate3 =  LOW;
    if ( resultado == 3) {
      //codigo para defenir o lado para o qual o motor vai rodar
      digitalWrite(drt, HIGH);
      digitalWrite(esq, LOW);
      analogWrite(vel, 75);//!codigo para dar energia ao motor para ele redar, e defenir a velocidade de rotaçao
      //chamada das funçoes para ligar e desligar os numeros no 7 segmentos
      liga2();
      delay(1000);
      desliga2();
      liga1();
      digitalWrite(vel, LOW);//codigo para desligar o motor
    }
    else if (resultado = 2) {
      //codigo para defenir o lado para o qual o motor vai rodar
      digitalWrite(drt, HIGH);
      digitalWrite(esq, LOW);
      analogWrite(vel, 75); //!codigo para dar energia ao motor para ele redar, e defenir a velocidade de rotaçao
      //chamada das funçoes para ligar e desligar os numeros no 7 segmentos
      desliga2();
      liga1();
      delay(1000);
      digitalWrite(vel, LOW);//codigo para desligar o motor
    }
    resultado = 1;//codigo para gurdar o ultimo andar que foi carregado
  }
  else
  {
    desliga1();
  }


  if (state2 == HIGH || ultimostate2 == HIGH)
  {
    liga2();
    //linhas de codigo para saber qual o numero que tem de estar ligado enquanto nao carregamos noutro numero
    ultimostate2 = HIGH;
    ultimostate3 =  LOW;
    ultimostate1 =  LOW;
    if ( resultado == 1) {
      //codigo para defenir o lado para o qual o motor vai rodar
      digitalWrite(drt, LOW);
      digitalWrite(esq, HIGH);
      analogWrite(vel, 75); //!codigo para dar energia ao motor para ele redar, e defenir a velocidade de rotaçao
      //chamada das funçoes para ligar e desligar os numeros no 7 segmentos
      desliga1();
      liga2();
      delay(1000);
      digitalWrite(vel, LOW); //codigo para desligar o motor
    }
    else if (resultado = 3) {
      digitalWrite(drt, HIGH);
      digitalWrite(esq, LOW);
      analogWrite(vel, 75); //!codigo para dar energia ao motor para ele redar, e defenir a velocidade de rotaçao
      //chamada das funçoes para ligar e desligar os numeros no 7 segmentos
      desliga3();
      liga2();
      delay(1000);
      digitalWrite(vel, LOW);//codigo para desligar o motor
    }
    resultado = 2; //codigo para gurdar o ultimo andar que foi carregado
  }
  else
  {

    desliga2();
  }

  if (state3 == HIGH || ultimostate3 == HIGH)
  {
    liga3();
    //linhas de codigo para saber qual o numero que tem de estar ligado enquanto nao carregamos noutro numero
    ultimostate3 = HIGH;
    ultimostate2 =  LOW;
    ultimostate1 =  LOW;
    if ( resultado == 1) {
      //codigo para defenir o lado para o qual o motor vai rodar
      digitalWrite(drt, LOW);
      digitalWrite(esq, HIGH);
      analogWrite(vel, 75); //!codigo para dar energia ao motor para ele redar, e defenir a velocidade de rotaçao
      //chamada das funçoes para ligar e desligar os numeros no 7 segmentos
      liga2();
      delay(1000);
      desliga2();
      liga3();
      digitalWrite(vel, LOW);//codigo para desligar o motor
    }
    else if (resultado = 2) {
      //codigo para defenir o lado para o qual o motor vai rodar
      digitalWrite(drt, LOW); 
      digitalWrite(esq, HIGH);
      analogWrite(vel, 75); //!codigo para dar energia ao motor para ele redar, e defenir a velocidade de rotaçao
      //chamada das funçoes para ligar e desligar os numeros no 7 segmentos
      desliga2();
      liga3();
      delay(1000);
      digitalWrite(vel, LOW); //codigo para desligar o motor
    }
    resultado = 3; //codigo para gurdar o ultimo andar que foi carregado
  }
  else
  {
    desliga3();
  }
}
//Funçoes com codigo para ligar e desligar os numeros no 7 segmentos
void liga1() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(g, HIGH);
}

void desliga1() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(g, HIGH);
}

void liga2() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(g, LOW);
}

void desliga2() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(g, HIGH);
}

void liga3() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(g, LOW);
}

void desliga3() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(g, HIGH);
}
