int ldr = A0;
int estadoLdr = 0;
int valorLdr = 0;
int pot = A1;
int valorPot = 0;
int estadoPot = 0;
int buzzer = 4;
int botao = 5;
int estadoBotao = 0;
//leds
int ledRato = 2;
void setup() {
  Serial.begin(9600);
  pinMode(ledRato, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(botao, 5);
  digitalWrite(ledRato, LOW);
}

void loop() {

  //Lendo valor do potênciometro
  valorPot = analogRead(pot);
  estadoPot = map(valorPot,0,1023,0,255);
  //Lendo o estado do LDR (Sensor de luminosidade)
  valorLdr = analogRead(ldr);
  estadoLdr = map(valorLdr,0,1023,0,255);

  estadoBotao = digitalRead(botao);

  if(estadoLdr > estadoPot){
    Serial.println(estadoLdr);
    Serial.println(estadoPot);
    digitalWrite(ledRato, HIGH);
    tone(buzzer, 400);
    
  }

  if(estadoBotao == HIGH){
      Serial.println("Parou de tocar");
      estadoPot = 0;
      digitalWrite(ledRato, LOW);
      noTone(buzzer);
      return;
    }



  //Serial.println("Estado do LDR");
  //Serial.println(valorLdr);
  //Serial.println("-----------------");
  //Serial.println("Estado do Pot");
  //Serial.println(estadoPot);
 // digitalWrite(led, HIGH);
}
