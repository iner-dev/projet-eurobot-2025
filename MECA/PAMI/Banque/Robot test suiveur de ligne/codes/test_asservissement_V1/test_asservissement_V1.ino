const byte pinVitesseG =  5;      // déclaration broche moteur
const byte pinVitesseD =  6;
const byte pinDirectionG =  10;
const byte pinDirectionD =  11;

const int pinCG = 4;
const int pinCD = 7;

volatile long posG = 0, posD = 0;          // Position (en nombre de pas) du codeur
volatile float vitG = 0,vitD = 0;          // Vitesse (en nombre de pas par seconde) du codeur
volatile unsigned long teG = 0, teD = 0;   // temps écoulé (en microsecondes)
long aposG, aposD;
unsigned long dtG, dtD ,t,tp;
int u;
float cons,erreur, intErreurD, intErreurG, derErreurG, derErreurD, erreurPrecG, erreurPrecD;


void avance(int vitesse){            //vitesse en tr/mn    vitesse maxi entre  300tr/mn  
  digitalWrite(pinDirectionG, HIGH);
  digitalWrite(pinDirectionD, HIGH);
    erreur=vitesse-vitG;
 //   intErreurG += erreur;
 //   derErreurG= erreur - erreurPrecG;
 //   erreurPrecG=erreur;
    u=vitesse+erreur*0.5 ;                                   
  map(u,0, 300,0,255);  
  analogWrite(pinVitesseG, u);
     erreur=vitesse-vitD;
 //   intErreurD += erreur;
 //   derErreurD = erreur - erreurPrecD;
 //   erreurPrecD=erreur;
    u=vitesse+erreur*0.5;                                
  map(u,0, 300,0,255);  
  analogWrite(pinVitesseD, u);  
}

void recule(int vitesse){
  digitalWrite(pinDirectionG, LOW);
  analogWrite(pinVitesseG, vitesse);
  digitalWrite(pinDirectionD, LOW);
  analogWrite(pinVitesseD, vitesse);   
}

void gauche (int vitesse){
  digitalWrite(pinDirectionG, LOW);
  analogWrite(pinVitesseG, vitesse);
  digitalWrite(pinDirectionD, HIGH);
  analogWrite(pinVitesseD, vitesse); 
  }
//********************INIT*************************************************************

void setup() {
   Serial.begin(115200);				
  pinMode(pinVitesseG, OUTPUT);        //INIT BROCHE MOTEUR
  pinMode(pinVitesseD, OUTPUT);
  pinMode(pinDirectionG, OUTPUT);
  pinMode(pinDirectionD, OUTPUT);
  pinMode(pinCG, INPUT);
  pinMode(pinCD, INPUT);  
  attachInterrupt(0, asservissementMG, RISING);    // Interruption sur tick de la codeuse (interruption 0 = pin2 arduino mega)
  attachInterrupt(1, asservissementMD, RISING);    // Interruption sur tick de la codeuse (interruption 1 = pin3 arduino mega)
  teG = micros();                                  // Initialisation du temps écoulé
  teD = micros();
  tp=micros();
  u=0; 
  }


//********************PROGRAMME PRINCIPAL*************************************************************
void loop() {

  avance(20);
  delay(3000);
  recule(0);
  delay(5000); 

 
}

void asservissementMD()   
{
   dtD = micros() - teD;   // Temps écoulé depuis le dernier front
   teD += dtD;
   aposD = posD;                    // Mémorisation de la position précédente
   if (digitalRead(pinCD))   
         {  posD++ ; 
            vitD = 285714.286/dtD;         // Calcul de la vitesse (ici en pas par seconde)
          }
   else   
         {  posD-- ;  
            vitD = -285714.286/dtD;         // Calcul de la vitesse (ici en pas par seconde)
         }
   
}



void asservissementMG()   
{
   dtG = micros() - teG;   // Temps écoulé depuis le dernier front
   teG += dtG;
   aposG = posG;                    // Mémorisation de la position précédente
   if (digitalRead(pinCG))   
         {  posG++ ; 
            vitG = 285714.286/dtG;         // Calcul de la vitesse de la roue (ici en tour/mn)60*1 000 000 /( 7 *30)
          }
   else   
         {  posG-- ;  
            vitG = -285714.286/dtG;         // Calcul de la vitesse de la roue (ici en tour/mn)60*1 000 000 /( 7 *30)
          }
   
}
