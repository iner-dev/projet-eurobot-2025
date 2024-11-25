/*****************************
 DAGU MOTEUR *****************
 *****************************/
const byte pinVitesseG =  5;      // déclaration broche moteur
const byte pinVitesseD =  6;
const byte pinDirectionG =  10;
const byte pinDirectionD =  11;


//********************DEPLACEMENTS*************************************************************

void avance(byte vitesse){
  digitalWrite(pinDirectionG, HIGH);
  digitalWrite(pinDirectionD, HIGH);
  analogWrite(pinVitesseG, vitesse);
  analogWrite(pinVitesseD, vitesse);
  delay(30);
}

void recule(byte vitesse){
  digitalWrite(pinDirectionG, LOW);
  digitalWrite(pinDirectionD, LOW);
  analogWrite(pinVitesseG, vitesse);
  analogWrite(pinVitesseD, vitesse);
  delay(30);
}

void droite (byte vitesse){
  digitalWrite(pinDirectionG, HIGH);
  digitalWrite(pinDirectionD, LOW);
  analogWrite(pinVitesseG, vitesse);
  analogWrite(pinVitesseD, vitesse);
  delay(30);
}
//********************INIT*************************************************************

void setup() {
  Serial.begin(115200);						//INIT MONITEUR SERIE
  pinMode(pinVitesseG, OUTPUT);				//INIT BROCHE MOTEUR
  pinMode(pinVitesseD, OUTPUT);
  pinMode(pinDirectionG, OUTPUT);
  pinMode(pinDirectionD, OUTPUT);
  delay(2000);
}


//********************PROGRAMME PRINCIPAL*************************************************************
void loop() {
  avance(50);
  delay(3000);
    droite (50);
  delay(1000);

}
