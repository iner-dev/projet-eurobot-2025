// Cette fonction est appelée lorsqu'une commande est reçue via I2C
void receiveEvent(int howMany) {
  if (howMany >= 2) {
    // Première valeur : code de la commande
    byte command = Wire.read();

    switch (command) {
      case 0x01:  // Commande pour changer la vitesse du moteur
        if (howMany >= 3) {
          int newSpeed = Wire.read();
          motorSpeed = newSpeed;
          speedSetpoint = motorSpeed;  // Mise à jour du Setpoint du PID de vitesse
        }
        break;

      case 0x02:  // Commande pour changer Kp, Ki, Kd (vitesse)
        if (howMany >= 6) {
          byte param = Wire.read();
          double newKp = Wire.read();
          double newKi = Wire.read();
          double newKd = Wire.read();

          // Mettre à jour les valeurs et les sauvegarder dans l'EEPROM
          if (param == 0) {  // Si param = 0, changer Kp pour la vitesse
            Kp_speed = newKp;
            savePIDParameters();
            speedPID.SetTunings(Kp_speed, Ki_speed, Kd_speed);
          } else if (param == 1) {  // Si param = 1, changer Ki pour la vitesse
            Ki_speed = newKi;
            savePIDParameters();
            speedPID.SetTunings(Kp_speed, Ki_speed, Kd_speed);
          } else if (param == 2) {  // Si param = 2, changer Kd pour la vitesse
            Kd_speed = newKd;
            savePIDParameters();
            speedPID.SetTunings(Kp_speed, Ki_speed, Kd_speed);
          }
        }
        break;

      case 0x03:  // Commande pour changer Kp, Ki, Kd (courant)
        if (howMany >= 6) {
          byte param = Wire.read();
          double newKp = Wire.read();
          double newKi = Wire.read();
          double newKd = Wire.read();

          // Mettre à jour les valeurs et les sauvegarder dans l'EEPROM
          if (param == 0) {  // Si param = 0, changer Kp pour le courant
            Kp_current = newKp;
            savePIDParameters();
            currentPID.SetTunings(Kp_current, Ki_current, Kd_current);
          } else if (param == 1) {  // Si param = 1, changer Ki pour le courant
            Ki_current = newKi;
            savePIDParameters();
            currentPID.SetTunings(Kp_current, Ki_current, Kd_current);
          } else if (param == 2) {  // Si param = 2, changer Kd pour le courant
            Kd_current = newKd;
            savePIDParameters();
            currentPID.SetTunings(Kp_current, Ki_current, Kd_current);
          }
        }
        break;

      case 0x04:  // Commande pour changer la consigne de courant
        if (howMany >= 3) {
          double newCurrentSetpoint = Wire.read();
          currentSetpoint = newCurrentSetpoint;  // Mise à jour du Setpoint du PID de courant
        }
        break;

      default:
        break;
    }
  }
}
