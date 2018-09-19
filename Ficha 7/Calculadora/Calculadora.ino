//Import das Library necessarias
#include <Keypad.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd; //Declarar o LCD

const byte ROWS = 4; //Defenir numero de linhas para a matriz do keypad
const byte COLS = 3; //Defenir numero de colunas para a matriz do keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {7, 2, 3, 5}; //Dizer a porta onde esta ligada cada linha do keypad
byte colPins[COLS] = {6, 8, 4}; //Dizer a porta onde esta ligada cada coluna do keypad

//Declaração de variaveis
int num1 = 0;
int num2 = 0;
int res = 0;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //Declarar o keypad

void setup() {
  Serial.begin(9600); //Inicializar o Serial
  lcd.begin(16, 2); //Configurar o numero de colunas e de linhas do LCD
}

void loop() {
  char key = keypad.getKey(); //Dizer em que variavel vai ser guardado o que é lido do keypad

  //Codigo para tratar os numeros e fazer a multiplicação dos mesmos
  switch (key)
  {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      num1 = num1 * 10 + (key - '0');
      lcd.setCursor(0, 0);
      lcd.print(num1);
      break;

    case '*':
      //Condiçao que diz que se o resultado for diferente de 0 o num 1 vai ser igual ao resultado
      if (res != 0)
      {
        num1 = res;
      }
      else
      {
        num1 = num1;
      }
      lcd.setCursor(0, 1);
      lcd.print(" * ");
      num2 = SecondNumber();
      res = num1 * num2;
      lcd.setCursor(0, 3);
      lcd.print(" = ");
      lcd.setCursor(0, 4);
      lcd.print(res);
      num1 = 0;
      num2 = 0;
      res = 0;
      delay(2000);
      lcd.clear();
      break;
  }

  delay(600);
}

//Função para recolher o 2º numero para multiplicar pelo outro anteriormente guardado
int SecondNumber()
{
  while (1)
  {
    char key = keypad.getKey();
    if (key >= '0' && key <= '9')
    {
      num2 = num2 * 10 + (key - '0');
      lcd.setCursor(0, 2);
      lcd.print(num2);
      delay(1000);
    }

    if (key == '#') break; //return second;
  }
  return num2;
}
