//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// ficha3_ex2
// 
// Made by 26392@ufp.edu.pt 26392@ufp.edu.pt
// License: CC-BY-SA 3.0
// Downloaded from: http://123d.circuits.io/circuits/729569-the-unnamed-circuit

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 2;
int push = 3;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(push, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
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
