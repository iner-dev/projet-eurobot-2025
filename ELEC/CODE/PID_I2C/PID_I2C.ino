#include <Wire.h>
#include <PID_v1_bc.h>
#include <EEPROM.h>  // Utilisation de l'EEPROM pour stocker les paramètres PID

#include "I2C_event.h"
#include "eeprom_functions.h"

#define IN1 3                // Pin de direction 1
#define IN2 4                // Pin de direction 2
#define PWM_PIN 5            // Pin PWM
#define ENCODER_A_PIN 6      // Encodeur A
#define ENCODER_B_PIN 7      // Encodeur B
#define CURRENT_SENSOR_PIN A1 // Pin pour le capteur de courant

// Adresses EEPROM pour les PID (vitesse et courant)
#define KP_SPEED_ADDRESS 0         // Adresse pour Kp (vitesse)
#define KI_SPEED_ADDRESS 4         // Adresse pour Ki (vitesse)
#define KD_SPEED_ADDRESS 8         // Adresse pour Kd (vitesse)
#define KP_CURRENT_ADDRESS 12      // Adresse pour Kp (courant)
#define KI_CURRENT_ADDRESS 16      // Adresse pour Ki (courant)
#define KD_CURRENT_ADDRESS 20      // Adresse pour Kd (courant)

// Paramètres PID pour la vitesse
double speedSetpoint, speedInput, speedOutput;
double Kp_speed, Ki_speed, Kd_speed;

// Paramètres PID pour le courant
double currentSetpoint = 5.0;  // Consigne initiale du courant (modifiable via I2C)
double currentInput, currentOutput;
double Kp_current, Ki_current, Kd_current;

// Instances PID
PID speedPID(&speedInput, &speedOutput, &speedSetpoint, Kp_speed, Ki_speed, Kd_speed, DIRECT);
PID currentPID(&currentInput, &currentOutput, &currentSetpoint, Kp_current, Ki_current, Kd_current, DIRECT);

// Variables pour le contrôle du moteur et l'encodeur
volatile long encoderPosition = 0;      // Position de l'encodeur
long previousEncoderPosition = 0;       // Position précédente
unsigned long lastTime = 0;             // Pour calculer la vitesse
int motorSpeed = 0;                     // Vitesse désirée du moteur

// Adresses et identifiants I2C
#define I2C_ADDRESS 0x08   // Adresse de l'esclave I2C

void setup() {
  // Configuration des broches du moteur
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);

  // Configuration des broches de l'encodeur
  pinMode(ENCODER_A_PIN, INPUT);
  pinMode(ENCODER_B_PIN, INPUT);

  // Interruption sur les broches de l'encodeur
  attachInterrupt(digitalPinToInterrupt(ENCODER_A_PIN), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B_PIN), updateEncoder, CHANGE);

  // Initialisation de l'I2C
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);

  // Initialisation des PID
  loadPIDParameters(); // Charger les paramètres PID depuis l'EEPROM
  speedPID.SetMode(AUTOMATIC);
  speedPID.SetOutputLimits(-255, 255);  // Sortie de PID pour PWM (contrôle de la vitesse du moteur)
  currentPID.SetMode(AUTOMATIC);
  currentPID.SetOutputLimits(0, 255);    // Limites pour la sortie de courant
}

void loop() {
  // Mettre à jour la vitesse actuelle du moteur
  speedInput = readMotorSpeed();

  // Calcul du PID pour la vitesse
  speedPID.Compute();

  // Lire le courant du moteur
  currentInput = readMotorCurrent();

  // Calcul du PID pour le courant
  currentPID.Compute();

  // Appliquer le contrôle du moteur en tenant compte des deux PID
  controlMotor(speedOutput, currentOutput);
}

// Fonction pour contrôler le moteur avec la sortie PID
void controlMotor(double speedOutput, double currentOutput) {
  double finalOutput = speedOutput;

  // Logique de compromis entre vitesse et courant
  if (currentOutput < 255) {
    finalOutput = constrain(finalOutput, 0, currentOutput); // Limiter la vitesse par le courant
  } else {
    finalOutput = constrain(finalOutput, 0, 255); // Limiter la vitesse maximale
  }

  if (finalOutput > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (finalOutput < 0) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    finalOutput = -finalOutput;  // rendre l'output positif pour le PWM
  }

  analogWrite(PWM_PIN, constrain(finalOutput, 0, 255));
}

// Calculer la vitesse du moteur à partir de l'encodeur
double readMotorSpeed() {
  unsigned long currentTime = millis();
  long currentPosition = encoderPosition;
  long deltaPosition = currentPosition - previousEncoderPosition;
  previousEncoderPosition = currentPosition;

  // Calcul de la vitesse (en impulsions par milliseconde)
  double speed = deltaPosition / (double)(currentTime - lastTime);
  lastTime = currentTime;

  return speed;  // Retourne la vitesse actuelle
}

// Lire le courant du moteur
double readMotorCurrent() {
  int analogValue = analogRead(CURRENT_SENSOR_PIN);
  double voltage = (analogValue / 1023.0) * 5.0; // Convertir en tension (si Vcc = 5V)
  double current = voltage; // Calibrer selon le capteur utilisé
  return current;  // Retourner la valeur du courant
}



// Interruption pour l'encodeur
void updateEncoder() {
  int a = digitalRead(ENCODER_A_PIN);
  int b = digitalRead(ENCODER_B_PIN);
  
  if (a == b) {
    encoderPosition++;
  } else {
    encoderPosition--;
  }
}
