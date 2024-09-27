// Configuración de los pines mediante directivas del preprocesador
#define LEFT_LED_PIN 2      // Pin del LED izquierdo
#define RIGHT_LED_PIN 3     // Pin del LED derecho
#define LEFT_BUTTON_PIN 4   // Pin del pulsador para el LED izquierdo
#define RIGHT_BUTTON_PIN 5  // Pin del pulsador para el LED derecho
#define STOP_BUTTON_PIN 6    // Pin del pulsador para detener parpadeo

// Variables para controlar el estado del parpadeo
volatile bool leftBlinking = false; // Estado del parpadeo a la izquierda
volatile bool rightBlinking = false; // Estado del parpadeo a la derecha

void setup() {
  // Configuración de pines de salida
  pinMode(LEFT_LED_PIN, OUTPUT);
  pinMode(RIGHT_LED_PIN, OUTPUT);
  
  // Configuración de pines de entrada
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP); // Activar resistencia de pull-up interna
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP); // Activar resistencia de pull-up interna
  pinMode(STOP_BUTTON_PIN, INPUT_PULLUP); // Activar resistencia de pull-up interna

  // Configuración de interrupciones para los pulsadores
  attachInterrupt(digitalPinToInterrupt(LEFT_BUTTON_PIN), startLeftBlinking, FALLING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_BUTTON_PIN), startRightBlinking, FALLING);
  attachInterrupt(digitalPinToInterrupt(STOP_BUTTON_PIN), stopBlinking, FALLING);
}

void loop() {
  // Controlar el parpadeo de los LEDs
  if (leftBlinking) {
    digitalWrite(LEFT_LED_PIN, HIGH);
    delay(500);
    digitalWrite(LEFT_LED_PIN, LOW);
    delay(500);
  }
  if (rightBlinking) {
    digitalWrite(RIGHT_LED_PIN, HIGH);
    delay(500);
    digitalWrite(RIGHT_LED_PIN, LOW);
    delay(500);
  }
}

// Funciones de interrupción
void startLeftBlinking() {
  leftBlinking = true; // Iniciar parpadeo a la izquierda
  rightBlinking = false; // Detener parpadeo a la derecha
}

void startRightBlinking() {
  rightBlinking = true; // Iniciar parpadeo a la derecha
  leftBlinking = false; // Detener parpadeo a la izquierda
}

void stopBlinking() {
  leftBlinking = false; // Detener parpadeo a la izquierda
  rightBlinking = false; // Detener parpadeo a la derecha
}
