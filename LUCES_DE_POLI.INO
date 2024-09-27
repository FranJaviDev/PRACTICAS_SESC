// Configuración de los pines mediante directivas del preprocesador
#define LED1_PIN 2      // Pin del primer LED (izquierda)
#define LED2_PIN 3      // Pin del segundo LED (derecha)
#define BUTTON_PIN 4    // Pin del pulsador

// Variables para controlar el estado de las luces
bool policeLightsOn = false; // Estado de las luces de policía

void setup() {
  // Configuración de pines de salida
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  
  // Configuración de pin de entrada
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Activar resistencia de pull-up interna

  // Configuración de interrupción para el pulsador
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), togglePoliceLights, FALLING);
}

void loop() {
  // Si las luces de policía están encendidas, realizar el parpadeo
  if (policeLightsOn) {
    blinkLights();
    policeLightsOn = false; // Apagar las luces después de parpadear
  }
}

// Función de interrupción para alternar el estado de las luces
void togglePoliceLights() {
  policeLightsOn = true; // Activar las luces de policía
}

// Función para hacer parpadear las luces
void blinkLights() {
  // Parpadeo a la izquierda (LED1)
  for (int i = 0; i < 3; i++) { // Tres parpadeos
    digitalWrite(LED1_PIN, HIGH);
    delay(200); // Encendido
    digitalWrite(LED1_PIN, LOW);
    delay(200); // Apagado
  }
  
  // Parpadeo a la derecha (LED2)
  for (int i = 0; i < 3; i++) { // Tres parpadeos
    digitalWrite(LED2_PIN, HIGH);
    delay(200); // Encendido
    digitalWrite(LED2_PIN, LOW);
    delay(200); // Apagado
  }
}
