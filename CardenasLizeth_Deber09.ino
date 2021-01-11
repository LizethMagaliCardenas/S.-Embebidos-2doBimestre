 /*
  * UNIVERSIDAD TECNICA DEL NORTE 
  * FACULTAD DE INGENIERIA EN CIENCIAS APLICADAS
  * TAREA 09
  * Cardenas Lizeth
  */
#include <avr/wdt.h>
#include<MsTimer2.h>

int conversor; 
int tiempo=0;
int cont=0;
int on=0;
int i=0;

void setup(){
  Serial.begin(9600);
  attachInterrupt(0,activacion,LOW);
  MsTimer2::set(1000, resetear);
  
}

void loop(){
  if(on==1){
  conversor=analogRead(0);
  tiempo=map(conversor,0,1023,0,60);
  Serial.println(String(tiempo)+String(" segundos"));
  delay(1000);
 }
}
 
void resetear(){
  cont++;
  Serial.println(cont);
  if(cont==tiempo){
    Serial.println("RESET");
    wdt_disable();
    wdt_enable(WDTO_15MS); 
  }
}
 
void activacion(){
  switch(on){
    case 0:
      Serial.println("----INICIANDO SISTEMA-----");
      Serial.println("Ajustar el tiempo para reinicio: ");
      on++;
    break;
    case 1:
      Serial.println(String("El sistema se reinicia en: ")+String(tiempo)+String(" segundos"));
      MsTimer2::start();
      on++;
    break;
  }
}
