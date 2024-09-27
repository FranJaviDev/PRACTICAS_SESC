/*
 Lee el valor de luz mediante una LDR.


*/


#define LDR A0


// Configuramos la palca
void setup() {
 // LDR.
 pinMode(LDR, INPUT);
  Serial.begin(115200);
}


// the loop function runs over and over again forever
void loop() {
  int valor;
 float porcentaje;


 valor = analogRead(LDR);


 Serial.print("\n Valor leído: ");
 Serial.print(valor);


 porcentaje=100.0*((float)valor)/1023.0;


 Serial.print("\n Porcentaje de oscuridad: ");
 Serial.print(porcentaje);


 delay(1000);
}
