#include <Ultrasonic.h>   //Carrega a biblioteca Ultrasonic  
#include <NewTone.h>    //Carrega a biblioteca Newtone  
   
//Dados do buzzer  
#define tempo 500  
int frequencia = 2000;   
int Pinofalante = 2;   
    
int atraso = 1000;  
   
//Inicializa o sensor ultrasonico  
Ultrasonic ultrasonic(10, 11);   
   
void setup()  
{  
  pinMode(Pinofalante,OUTPUT); //Pino do buzzer   
  Serial.begin(9600); //Inicializa a serial  
}  
   
void loop()  
{  
  float cmMsec, inMsec;  
    
  //Le os dados do sensor, com o tempo de retorno do sinal  
  long microsec = ultrasonic.timing();   
   
  //Calcula a distancia em centimetros  
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);   
    
  //Ajusta o atraso de acordo com a distancia  
  if (cmMsec < 30 && cmMsec > 20)
  {
  NewTone(Pinofalante, frequencia, tempo);
  }
  
  //Apresenta os dados, em centimetros, na Serial  
  Serial.print("Cent: ");  
  Serial.print(cmMsec);  
  Serial.print(" atraso : ");  
  Serial.println(atraso); 
  //Emite o bip     
  delay(500);  
} 
