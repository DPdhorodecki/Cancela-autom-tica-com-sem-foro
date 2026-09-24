#include <Servo.h>

// ===============================
// SEMÁFORO 01
// =================== ============
const int vermelhoS01 = 2;
const int amareloS01  = 3;
const int verdeS01    = 4;

// ===============================
// SEMÁFORO 02
// ===============================
const int vermelhoS02 = 11;
const int amareloS02  = 12;
const int verdeS02    = 13;

// ===============================
// SERVOS
// ===============================
Servo servo01;
Servo servo02;

const int pinoServo01 = 9;
const int pinoServo02 = 5;

// ===============================
// BUZZER
// ===============================
const int buzzer = 8;

// ===============================
// POSIÇÕES DOS SERVOS
// ===============================
const int FECHADA = 0;
const int ABERTA = 90;


// ==================================================
// FUNÇÃO PARA TOCAR UMA NOTA
// ==================================================
void tocarNota(int frequencia, int duracao) {
  tone(buzzer, frequencia);
  delay(duracao);
  noTone(buzzer);
  delay(30);
}


// ==================================================
// SOM DA LARGADA
// ==================================================
void largadaF1() {

  // Sequência rápida e aguda
  tocarNota(523, 120);   // Dó
  tocarNota(659, 120);   // Mi
  tocarNota(784, 120);   // Sol
  tocarNota(988, 180);   // Si

  // Nota final mais longa
  tocarNota(1047, 500);  // Dó agudo

  noTone(buzzer);
}


// ==================================================
// SETUP
// ==================================================
void setup() {

  // LEDs Semáforo 01
  pinMode(vermelhoS01, OUTPUT);
  pinMode(amareloS01, OUTPUT);
  pinMode(verdeS01, OUTPUT);

  // LEDs Semáforo 02
  pinMode(vermelhoS02, OUTPUT);
  pinMode(amareloS02, OUTPUT);
  pinMode(verdeS02, OUTPUT);

  // Buzzer
  pinMode(buzzer, OUTPUT);

  // Servos
  servo01.attach(pinoServo01);
  servo02.attach(pinoServo02);

  // Começam fechadas
  servo01.write(FECHADA);
  servo02.write(FECHADA);

  // Todos os LEDs desligados inicialmente
  digitalWrite(vermelhoS01, LOW);
  digitalWrite(amareloS01, LOW);
  digitalWrite(verdeS01, LOW);

  digitalWrite(vermelhoS02, LOW);
  digitalWrite(amareloS02, LOW);
  digitalWrite(verdeS02, LOW);
}


// ==================================================
// LOOP
// ==================================================
void loop() {

  // ==================================================
  // SEMÁFORO 01 VERDE
  // SEMÁFORO 02 VERMELHO
  // ==================================================

  digitalWrite(vermelhoS01, LOW);
  digitalWrite(amareloS01, LOW);
  digitalWrite(verdeS01, HIGH);

  digitalWrite(vermelhoS02, HIGH);
  digitalWrite(amareloS02, LOW);
  digitalWrite(verdeS02, LOW);

  // Servo 01 abre
  servo01.write(ABERTA);

  // Servo 02 permanece fechado
  servo02.write(FECHADA);

  // ===============================
  // LARGADA
  // ===============================
  largadaF1();

  // Continua aberto por mais tempo
  delay(2500);


  // ==================================================
  // SEMÁFORO 01 AMARELO
  // ==================================================

  digitalWrite(verdeS01, LOW);
  digitalWrite(amareloS01, HIGH);

  // Servo 01 fecha
  servo01.write(FECHADA);

  delay(1000);

  digitalWrite(amareloS01, LOW);


  // ==================================================
  // SEMÁFORO 01 VERMELHO
  // SEMÁFORO 02 VERDE
  // ==================================================

  digitalWrite(vermelhoS01, HIGH);
  digitalWrite(vermelhoS02, LOW);

  digitalWrite(verdeS02, HIGH);

  // Servo 01 permanece fechado
  servo01.write(FECHADA);

  // Servo 02 abre
  servo02.write(ABERTA);

  // ===============================
  // LARGADA
  // ===============================
  largadaF1();

  // Continua aberto
  delay(2500);


  // ==================================================
  // SEMÁFORO 02 AMARELO
  // ==================================================

  digitalWrite(verdeS02, LOW);
  digitalWrite(amareloS02, HIGH);

  // Servo 02 fecha
  servo02.write(FECHADA);

  delay(1000);

  digitalWrite(amareloS02, LOW);


  // ==================================================
  // VOLTA AO SEMÁFORO 01
  // ==================================================

  digitalWrite(vermelhoS01, LOW);
}


