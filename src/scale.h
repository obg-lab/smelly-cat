#include "HX711.h"
HX711 loadcell;

const int BUTTON_PIN = D2;

// 1. HX711 conexões
const int LOADCELL_DOUT_PIN = D3;
const int LOADCELL_SCK_PIN = D4;

// 2. Configurações de calibragem
const long LOADCELL_OFFSET = 50682624;
const long LOADCELL_DIVIDER = -24;

void setupScale() {
  Serial.println("Configurando sensor de peso HX711");

  // 3. Inicializa o sensor
  loadcell.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  loadcell.set_scale(LOADCELL_DIVIDER);
  // loadcell.set_offset(LOADCELL_OFFSET);

  // Sera o sensor
  // loadcell.set_scale();
  loadcell.tare();
}

int tareButton() {
  int buttonState = digitalRead(BUTTON_PIN);
  //
  if (buttonState == 1) {
    Serial.println("HX711 tara ativado.");
    loadcell.tare();
    delay(200);
  }

  return buttonState;
}

long getScale() {
  long wt1 = 0;

  if (loadcell.wait_ready_timeout(1000)) {
    wt1 = loadcell.get_units(10) / 1000;
    Serial.print("HX711 lendo: ");
    Serial.println(wt1);
  } else {
    Serial.println("HX711 no encontrado.");
  }

  return wt1;
}
