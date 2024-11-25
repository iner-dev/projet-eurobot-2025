
#include <SimpleTimer.h>

SimpleTimer timer;                 // Timer pour échantillonnage

unsigned int tick_codeuse_G = 0;     // Compteur de tick de la codeuse G
int tick_Total_G = 0;
int vitMoteurG = 0;                       // Commande du moteur
unsigned int tick_codeuse_D = 0;     // Compteur de tick de la codeuse D
int tick_Total_D = 0;
int vitMoteurD = 0;                       // Commande du moteur
const int frequence_echantillonnage = 100;  // Fréquence d'exécution de l'asservissement
const int rapport_reducteur = 29;          // Rapport entre le nombre de tours de l'arbre moteur et de la roue
const int tick_par_tour_codeuse = 32;  //64 tick sur deux capteurs hall, ici on a pris un seul capteur

//definition des entrées
const int pinInputG = 10; // Commande de sens moteur G
const int pinPowerG = 5; // Commande de vitesse moteur G
const int pinInputD = 11; // Commande de sens moteur D
const int pinPowerD = 6; // Commande de vitesse moteur D

//consigne en tour/s                               (928 ticks/tr)
float consigne_moteur_G= 0.1;  //  Consigne nombre de tours de roue par seconde du moteur G
float consigne_moteur_D= 0.1;  //  Consigne nombre de tours de roue par seconde du moteur D

// init calculs asservissement PID
float erreur_precedente_G = consigne_moteur_G; // (en tour/s)
float somme_erreur_G = 0;
float erreur_precedente_D = consigne_moteur_D; // (en tour/s)
float somme_erreur_D = 0;


//Definition des constantes du correcteur PID
float kp = 300;           // 300 Coefficient proportionnel    choisis par tatonnement sur le moniteur. Ce sont les valeurs qui donnaient les meilleures performances
float ki = 30; //5.5;      // Coefficient intégrateur
float kd = 0;           // Coefficient dérivateur


/* Routine d'initialisation */
void setup() {
  Serial.begin(115200);         // Initialisation port COM
  pinMode(pinPowerG, OUTPUT);   // Sorties commande moteur
  pinMode(pinInputG, OUTPUT );
  pinMode(pinPowerD, OUTPUT);   // Sorties commande moteur
  pinMode(pinInputD, OUTPUT );

  analogWrite(pinPowerG, 0);  // Initialisation sortie moteur à 0 
  analogWrite(pinPowerD, 0);
  delay(300);                // Pause de 0,3 sec pour laisser le temps au moteur de s'arréter si celui-ci est en marche

  attachInterrupt(0, compteurG, CHANGE);    // Interruption sur tick de la codeuse  (interruption 0 = pin2 arduino)
  attachInterrupt(1, compteurD, CHANGE);    // Interruption sur tick de la codeuse  (interruption 1 = pin3 arduino)
  timer.setInterval(1000/frequence_echantillonnage, asservissement);  // Interruption pour calcul du PID et asservissement; toutes les 10ms, on recommence la routine
}

/* Déplacements */

void Avancer( int powerRateG, int powerRateD ){
  digitalWrite( pinInputG, HIGH );
  analogWrite( pinPowerG, powerRateG );
  digitalWrite( pinInputD, HIGH );
  analogWrite( pinPowerD, powerRateD );
}

/* Interruption sur tick de la codeuse */
void compteurG(){
  tick_codeuse_G++; // On incrémente le nombre de tick de la codeuse.   un seul sens
  }
void compteurD(){
  tick_codeuse_D++; // On incrémente le nombre de tick de la codeuse.   un seul sens
  }

/* Interruption pour calcul du P */
void asservissement()
{
  // Calcul de l'erreur G
  int frequence_codeuse_G = frequence_echantillonnage*tick_codeuse_G; //100*tick_codeuse
  float vit_roue_tour_sec_G = (float)frequence_codeuse_G/(float)tick_par_tour_codeuse/(float)rapport_reducteur;    //(100*tick_codeuse)/32/19 
  float erreur_G = consigne_moteur_G - vit_roue_tour_sec_G; // pour le proportionnel
  somme_erreur_G += erreur_G; // pour l'intégrateur
  float delta_erreur_G = erreur_G-erreur_precedente_G;  // pour le dérivateur
  erreur_precedente_G = erreur_G;
  
  // Réinitialisation du nombre de tick de la codeuse
  tick_Total_G = tick_codeuse_G + tick_Total_G;
  tick_codeuse_G=0;

  // P : calcul de la commande
  vitMoteurG = kp*erreur_G + ki*somme_erreur_G + kd*delta_erreur_G;  //somme des tois erreurs

  // Normalisation et contrôle du moteur
  if (vitMoteurG > 255) {
    vitMoteurG = 255;  // sachant que l'on est branché sur un pont en H L293D
  } 
  else if (vitMoteurG <0) {
    vitMoteurG = 0;
  }
  
  // Calcul de l'erreur D
  int frequence_codeuse_D = frequence_echantillonnage*tick_codeuse_D; //100*tick_codeuse
  float vit_roue_tour_sec_D = (float)frequence_codeuse_D/(float)tick_par_tour_codeuse/(float)rapport_reducteur;    //(100*tick_codeuse)/32/19 
  float erreur_D = consigne_moteur_D - vit_roue_tour_sec_D; // pour le proportionnel
  somme_erreur_D += erreur_D; // pour l'intégrateur
  float delta_erreur_D = erreur_D-erreur_precedente_D;  // pour le dérivateur
  erreur_precedente_D = erreur_D;
  
  // Réinitialisation du nombre de tick de la codeuse
  tick_Total_D = tick_codeuse_D + tick_Total_D;
  tick_codeuse_D=0;

  // P : calcul de la commande
  vitMoteurD = kp*erreur_D + ki*somme_erreur_D + kd*delta_erreur_D;  //somme des tois erreurs

  // Normalisation et contrôle du moteur
  if (vitMoteurD > 255) {
    vitMoteurD = 255;  // sachant que l'on est branché sur un pont en H L293D
  } 
  else if (vitMoteurD <0) {
    vitMoteurD = 0;
  }

Avancer (vitMoteurG,vitMoteurD);

 // DEBUG
  Serial.print(vit_roue_tour_sec_G,8);  // affiche à gauche la vitesse et à droite l'erreur
  Serial.print(" : ");
  Serial.print(erreur_G,4);
  Serial.print(" : ");
  Serial.print(vitMoteurG);
  Serial.print(" : ");
  Serial.print(tick_Total_G);
  Serial.print(" : ");
  Serial.print(vit_roue_tour_sec_D,8);  // affiche à gauche la vitesse et à droite l'erreur
  Serial.print(" : ");
  Serial.print(erreur_D,4);
  Serial.print(" : ");
  Serial.print(vitMoteurD);
  Serial.print(" : ");
  Serial.print(tick_Total_D);
  Serial.print(" : ");
  Serial.println();
}

/* Fonction principale */
void loop(){
  timer.run();  //on fait tourner l'horloge
  //delay(10);
}
