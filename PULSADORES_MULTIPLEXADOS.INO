// Definición de macros para las resistencias y el voltaje de referencia
#define V_IN 5.0            // Voltaje de entrada (VCC)
#define R_REF 10000.0       // Resistencia de referencia en ohmios (10kΩ)

// Resistencias de cada botón en ohmios
#define R_BTN1 10000.0      // Botón 1
#define R_BTN2 20000.0      // Botón 2
#define R_BTN3 30000.0      // Botón 3
#define R_BTN4 40000.0      // Botón 4

// Cálculo del voltaje esperado para cada pulsador
#define V_BTN1 (V_IN * (R_BTN1 / (R_BTN1 + R_REF)))
#define V_BTN2 (V_IN * (R_BTN2 / (R_BTN2 + R_REF)))
#define V_BTN3 (V_IN * (R_BTN3 / (R_BTN3 + R_REF)))
#define V_BTN4 (V_IN * (R_BTN4 / (R_BTN4 + R_REF)))

// Umbral de comparación (margen de tolerancia para variaciones)
#define TOLERANCE 0.1       // Tolerancia de 0.1V

void setup() {
  Serial.begin(9600);        // Iniciar comunicación serial
  pinMode(A0, INPUT);        // Configurar el pin A0 como entrada
}

void loop() {
  // Leer el voltaje en A0
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (V_IN / 1023.0);  // Convertir el valor analógico en voltaje

  Serial.print("Voltaje leído: ");
  Serial.println(voltage);

  // Comparar con los valores de cada botón
  if (abs(voltage - V_BTN1) < TOLERANCE) {
    Serial.println("Botón 1 presionado");
  } else if (abs(voltage - V_BTN2) < TOLERANCE) {
    Serial.println("Botón 2 presionado");
  } else if (abs(voltage - V_BTN3) < TOLERANCE) {
    Serial.println("Botón 3 presionado");
  } else if (abs(voltage - V_BTN4) < TOLERANCE) {
    Serial.println("Botón 4 presionado");
  } else {
    Serial.println("Ningún botón presionado o fuera de rango");
  }

  delay(500); // Esperar medio segundo antes de leer de nuevo
}
