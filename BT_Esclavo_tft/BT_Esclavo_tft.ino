int led = 13;
int DATO = 0;

void setup() {
  pinMode (led, OUTPUT);
  digitalWrite (led, LOW);
  Serial.begin(9600);

}

void loop() {
  //Si el modulo a manda dato, guardarlo en estado.
  if (Serial.available()>0){
    DATO = Serial.read();
  }//Esta parte del codigo es para solo 1 caracter o unidad

  if (DATO == '0'){
    digitalWrite (led, LOW);
  }

if (DATO == '1'){
    digitalWrite (led, HIGH);
  }

}
