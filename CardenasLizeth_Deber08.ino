/*
  * UNIVERSIDAD TECNICA DEL NORTE 
  * FACULTAD DE INGENIERIA EN CIENCIAS APLICADAS
  * TAREA 08
  * Cardenas Lizeth
  */
#include<avr/power.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include<MsTimer2.h>

int on=0; // modos del sistema
int tiempo=0; //tiempo de toma de datos
int cont=0; //conteo de timer

 void setup() {
  Serial.begin(9600);
  MsTimer2::set(1000,reloj);
  attachInterrupt(0,activacion,LOW);
}

 void loop() {
  delay(1000);
}

 void reloj(){
  power_adc_disable();
  cont++;
  Serial.println(String("Sistema regresivo: ")+String(tiempo-cont));
  if(cont==tiempo){
  power_adc_enable();
  delay(10);
  Serial.println(analogRead(0));
  cont=0;
  }
}

void activacion(){
  switch(on){
    case 0:
      Serial.println("INICIANDO DEL SISTEMA");
      power_adc_disable();
      tiempo=60;
      on++;
    break;
    case 1:
      Serial.println(String("Sistema funciona en:")+String(tiempo)+String(" segundos"));
      MsTimer2::start();
      on++;
    break;
    case 2:
      Serial.println("SISTEMA APAGADO");
      power_adc_disable();
      MsTimer2::stop();
      tiempo=0;
     on=0;
    break;
  }
}
