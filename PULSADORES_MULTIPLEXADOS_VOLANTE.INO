// Definición de los valores de resistencia de cada pulsador
#define R1 100  // Resistencia para pulsador 1
#define R2 200  // Resistencia para pulsador 2
#define R3 300  // Resistencia para pulsador 3
#define R4 400  // Resistencia para pulsador 4
#define R5 500  // Resistencia del divisor de tensión

// Pin de entrada analógica para la lectura del divisor resistivo
#define PIN_ANALOG A0

// Definir los pines de salida correspondientes a cada pulsador
#define LED1_PIN 2
#define LED2_PIN 3
#define LED3_PIN 4
#define LED4_PIN 5

// Cálculo de las tensiones posibles para cada combinación de pulsadores
#define V_REF 5.0  // Voltaje de referencia

// Tolerancia para la comparación de valores de voltaje
#define TOLERANCE 0.05  // Margen de error permitido (+/-)

// Cálculo del valor de tensión para cada combinación cuando los pulsadores cortocircuitan resistencias
#define V_0000 (R5 * V_REF / (R1 + R2 + R3 + R4 + R5))  // Ningún pulsador presionado
#define V_0001 (R5 * V_REF / (R1 + R2 + R3 + R5))       // Pulsador 4 presionado
#define V_0010 (R5 * V_REF / (R1 + R2 + R4 + R5))       // Pulsador 3 presionado
#define V_0011 (R5 * V_REF / (R1 + R2 + R5))            // Pulsadores 3 y 4 presionados
#define V_0100 (R5 * V_REF / (R1 + R3 + R4 + R5))       // Pulsador 2 presionado
#define V_0101 (R5 * V_REF / (R1 + R3 + R5))            // Pulsadores 2 y 4 presionados
#define V_0110 (R5 * V_REF / (R1 + R4 + R5))            // Pulsadores 2 y 3 presionados
#define V_0111 (R5 * V_REF / (R1 + R5))                 // Pulsadores 2, 3 y 4 presionados
#define V_1000 (R5 * V_REF / (R2 + R3 + R4 + R5))       // Pulsador 1 presionado
#define V_1001 (R5 * V_REF / (R2 + R3 + R5))            // Pulsadores 1 y 4 presionados
#define V_1010 (R5 * V_REF / (R2 + R4 + R5))            // Pulsadores 1 y 3 presionados
#define V_1011 (R5 * V_REF / (R2 + R5))                 // Pulsadores 1, 3 y 4 presionados
#define V_1100 (R5 * V_REF / (R3 + R4 + R5))            // Pulsadores 1 y 2 presionados
#define V_1101 (R5 * V_REF / (R3 + R5))                 // Pulsadores 1, 2 y 4 presionados
#define V_1110 (R5 * V_REF / (R4 + R5))                 // Pulsadores 1, 2 y 3 presionados
#define V_1111 (R5 * V_REF / R5)                        // Todos los pulsadores presionados (cortocircuito total)

void setup() {
  // Configuración de los pines de salida
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  
  // Configuración del pin de entrada analógica
  pinMode(PIN_ANALOG, INPUT);
}

void loop() {
  // Leer el valor de la entrada analógica
  int analogValue = analogRead(PIN_ANALOG);
  
  // Convertir el valor leído a voltaje
  float voltage = (analogValue * V_REF) / 1023.0;

  // Determinar la combinación de pulsadores activa usando select case con tolerancia aplicada individualmente
  switch (true) {
    case (voltage >= V_0000 - TOLERANCE && voltage < V_0000 + TOLERANCE):
      // Ningún pulsador presionado
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, LOW);
      break;

    case (voltage >= V_0001 - TOLERANCE && voltage < V_0001 + TOLERANCE):
      // Solo pulsador 4 presionado
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, HIGH);
      break;

    case (voltage >= V_0010 - TOLERANCE && voltage < V_0010 + TOLERANCE):
      // Solo pulsador 3 presionado
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, LOW);
      break;

    case (voltage >= V_0011 - TOLERANCE && voltage < V_0011 + TOLERANCE):
      // Pulsadores 3 y 4 presionados
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, HIGH);
      break;

case (voltage >= V_0100 - TOLERANCE && voltage < V_0100 + TOLERANCE):
      // Solo pulsador 2 presionado
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, LOW);
      break;

    case (voltage >= V_0101 - TOLERANCE && voltage < V_0101 + TOLERANCE):
      // Pulsadores 2 y 4 presionados
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, HIGH);
      break;

    case (voltage >= V_0110 - TOLERANCE && voltage < V_0110 + TOLERANCE):
      // Pulsadores 2 y 3 presionados
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, LOW);
      break;

    case (voltage >= V_0111 - TOLERANCE && voltage < V_0111 + TOLERANCE):
      // Pulsadores 2, 3 y 4 presionados
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, HIGH);
      break;

    case (voltage >= V_1000 - TOLERANCE && voltage < V_1000 + TOLERANCE):
      // Solo pulsador 1 presionado
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, LOW);
      break;

    case (voltage >= V_1001 - TOLERANCE && voltage < V_1001 + TOLERANCE):
      // Pulsadores 1 y 4 presionados
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, HIGH);
      break;

    case (voltage >= V_1010 - TOLERANCE && voltage < V_1010 + TOLERANCE):
      // Pulsadores 1 y 3 presionados
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, LOW);
      break;

    case (voltage >= V_1011 - TOLERANCE && voltage < V_1011 + TOLERANCE):
     
      // Pulsadores 1, 3 y 4 presionados
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, HIGH);
      break;

    case (voltage >= V_1100 - TOLERANCE && voltage < V_1100 + TOLERANCE):
      // Pulsadores 1 y 2 presionados
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, LOW);
      break;

    case (voltage >= V_1101 - TOLERANCE && voltage < V_1101 + TOLERANCE):
      // Pulsadores 1, 2 y 4 presionados
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, HIGH);
      break;

    case (voltage >= V_1110 - TOLERANCE && voltage < V_1110 + TOLERANCE):
      // Pulsadores 1, 2 y 3 presionados
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, LOW);
      break;

    case (voltage >= V_1111 - TOLERANCE && voltage < V_1111 + TOLERANCE):
      // Todos los pulsadores presionados
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, HIGH);
      break;

    default:
      // En caso de que no coincida ningún caso
      break;
  }
}
