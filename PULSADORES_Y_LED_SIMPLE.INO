/*
 Enciende y apaga dos LED cuando se presiona un pulsador.


*/
#define LED_AMARILLO_1 11
#define LED_AMARILLO_2 12


#define PULSADOR_1 A0
#define PULSADOR_2 A1




// Configuramos la palca
void setup() {
 // initialize digital pin LED_BUILTIN as an output.
 pinMode(LED_AMARILLO_1, OUTPUT);
 pinMode(LED_AMARILLO_2, OUTPUT);


 pinMode(PULSADOR_1, INPUT);
 pinMode(PULSADOR_2, INPUT);


 Serial.begin(115200);
}


// the loop function runs over and over again forever
void loop() {
  if(digitalRead(PULSADOR_1)==HIGH){
       digitalWrite(LED_AMARILLO_1, HIGH);
       Serial.println("Pulsador 1 ON \n");
 }else{
       digitalWrite(LED_AMARILLO_1, LOW);
       Serial.println("Pulsador 1 ON \n");
 }


 if(digitalRead(PULSADOR_2)==LOW){
       digitalWrite(LED_AMARILLO_2, HIGH);
       Serial.println("Pulsador 1 ON \n");
 }else{
       digitalWrite(LED_AMARILLO_2, LOW);
       Serial.println("Pulsador 1 ON \n");
 }
