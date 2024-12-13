/*****************************
 DAGU MOTEUR *****************
 *****************************/
const byte pinVitesseG =  5;      // déclaration broche moteur
const byte pinVitesseD =  6;
const byte pinDirectionG =  10;
const byte pinDirectionD =  11;
unsigned int tick_codeuse = 0;     // Compteur de tick de la codeuse

//********************DEPLACEMENTS*************************************************************

void avance(byte vitesse){
  digitalWrite(pinDirectionG, HIGH);
  analogWrite(pinVitesseG, vitesse);
}

void recule(byte vitesse){
  digitalWrite(pinDirectionG, LOW);
  analogWrite(pinVitesseG, vitesse);
}

void gauche (byte vitesse){
  digitalWrite(pinDirectionG, LOW);
  analogWrite(pinVitesseG, vitesse);
}
//********************INIT*************************************************************

void setup() {
  Serial.begin(115200);				
  pinMode(pinVitesseG, OUTPUT);				
  pinMode(pinDirectionG, OUTPUT);
  attachInterrupt(0, compteur, CHANGE);    // Interruption sur tick de la codeuse (interruption 0 = pin2 arduino mega)
}


//********************PROGRAMME PRINCIPAL*************************************************************
void loop() {
  avance(50);
  Serial.println (tick_codeuse);
  delay(3000);
  gauche (50);
   Serial.println (tick_codeuse);
  delay(1000);

}



 


void compteur(){
    tick_codeuse++;  // On incrémente le nombre de tick de la codeuse
}
