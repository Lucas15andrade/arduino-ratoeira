#include <Servo.h>

int ldr = A0;
int estadoLdr = 0;
int valorLdr = 0;
int pot = A1;
int valorPot = 0;
int estadoPot = 0;
int buzzer = 4;
int botao = 5;
int botao2 = 7;
int estadoBotao = 0;
//leds
int ledRato = 8;
int ledAtivo = 2;

Servo servo;
int rele = 10;
boolean ativo = false;
int estadoBotao2 = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledRato, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(botao, INPUT);
  pinMode(botao2, INPUT);
  pinMode(ledAtivo, OUTPUT);
  pinMode(rele, OUTPUT);
  servo.attach(9);
  servo.write(180);
  digitalWrite(rele,HIGH);

  
  while(digitalRead(botao2) == LOW){
    Serial.println("LAÇOOOO");
  }
  
}

void loop() {


  Serial.print(analogRead(ldr));
  Serial.print("--");
  Serial.println(analogRead(pot));
  //digitalWrite(rele, LOW);
  //servo.write(90);
  //digitalWrite(rele,HIGH);
  
  digitalWrite(ledRato,HIGH);

  //Lendo valor do potênciometro
  
  valorPot = analogRead(pot);
  estadoPot = map(valorPot,0,1023,0,255);
  //Lendo o estado do LDR (Sensor de luminosidade)
  valorLdr = analogRead(ldr);
  estadoLdr = map(valorLdr,0,1023,0,255);
  

  /*
  estadoBotao2 = digitalRead(botao2);

  if(estadoBotao2 == HIGH){
    
  }else{
     
  }
  */

  /*
  estadoLdr = map(analogRead(ldr))0,1023,0,255));
  estadoPot = map(analogRead(pot)),0,1023,0,255));
  //
  */
  //Serial.println(estadoLdr);
  if(analogRead(ldr) > analogRead(pot)){
    
    digitalWrite(ledAtivo, HIGH);
    //tone(buzzer, 400);
    //ativo = true;
    digitalWrite(rele,LOW);
    //Ligando o cooler
    servo.write(0);
    //digitalWrite(rele,HIGH);
    //return;
  }

  if(digitalRead(botao) == HIGH){
      Serial.println("Parou de tocar");
      estadoPot = 0;
      digitalWrite(ledAtivo, LOW);
      //noTone(buzzer);
      
      //digitalWrite(rele, HIGH);
      servo.write(180);
      ativo = true;
      return;
    }

  if(ativo == true){
    //digitalWrite(rele, HIGH);
  }

  //Serial.println("Estado do LDR");
  //Serial.println(valorLdr);
  //Serial.println("-----------------");
  //Serial.println("Estado do Pot");
  //Serial.println(estadoPot);
 // digitalWrite(led, HIGH);
}
