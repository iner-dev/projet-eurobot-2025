// Charger les paramètres PID depuis l'EEPROM
void loadPIDParameters() {
  // Charger les paramètres de la régulation de la vitesse
  EEPROM.get(KP_SPEED_ADDRESS, Kp_speed);
  EEPROM.get(KI_SPEED_ADDRESS, Ki_speed);
  EEPROM.get(KD_SPEED_ADDRESS, Kd_speed);
  speedPID.SetTunings(Kp_speed, Ki_speed, Kd_speed);

  // Charger les paramètres de la régulation du courant
  EEPROM.get(KP_CURRENT_ADDRESS, Kp_current);
  EEPROM.get(KI_CURRENT_ADDRESS, Ki_current);
  EEPROM.get(KD_CURRENT_ADDRESS, Kd_current);
  currentPID.SetTunings(Kp_current, Ki_current, Kd_current);
}

// Sauvegarder les paramètres PID dans l'EEPROM
void savePIDParameters() {
  // Sauvegarder les paramètres de la régulation de la vitesse
  EEPROM.put(KP_SPEED_ADDRESS, Kp_speed);
  EEPROM.put(KI_SPEED_ADDRESS, Ki_speed);
  EEPROM.put(KD_SPEED_ADDRESS, Kd_speed);

  // Sauvegarder les paramètres de la régulation du courant
  EEPROM.put(KP_CURRENT_ADDRESS, Kp_current);
  EEPROM.put(KI_CURRENT_ADDRESS, Ki_current);
  EEPROM.put(KD_CURRENT_ADDRESS, Kd_current);
}
