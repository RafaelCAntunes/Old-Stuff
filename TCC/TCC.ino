#include "DHT.h"
#include <TimerOne.h>
 
#define DHTPIN 7 // define pino de dados do DHT como pin7
#define DHTTYPE DHT22 // Define o tipo do sensor usado

DHT dht(DHTPIN, DHTTYPE);

float umidade [145]; //vetor que guardará informação de umidade a cada 30min
float temperatura [145]; //vetor que guardará informação de temperatura a cada 30min
float temp = 0;
float umid = 0;

int contador = 0;
int _5segundos = 0;
int _meiahora = 0;
int _meiahoraant = 0;

int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

int rele = 6;
int ventilador = 4;
int exaustor = 5;

void setup() {
 
Serial.begin(9600); // Liga comunicação serial

attachInterrupt(digitalPinToInterrupt(2), escreve_serial, FALLING); // interrupção por borda de descida (pino 2)


Timer1.initialize(5000000); // Inicializa o Timer1 e configura para interrupcao a cada 5 segundos

Timer1.attachInterrupt(tempo); // Configura a função tempo como a função para ser chamada a cada interrupção do Timer1

// IN1 a IN4 são as entradas do motor de passo
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

pinMode(rele,OUTPUT);

pinMode(exaustor,OUTPUT);
pinMode(ventilador,OUTPUT);
 
delay(3000);
umidade [0] = dht.readHumidity(); // lê valor inicial de umidade
temperatura [0] = dht.readTemperature(); //lê valor inicial de temperatura

}


void tempo()
{

_5segundos++; // adiciona 1 ao contador de "5 segundos"

  if (_5segundos == 360) //Quando passarem 30minutos
  {
  _meiahora++; // adiciona 1 ao contador de meia hora
  
  umidade [_meiahora] = dht.readHumidity(); // guarda o valor de umidade na posição do vetor equivalente à quantas "meia hora" passaram
  temperatura [_meiahora] = dht.readTemperature(); // guarda o valor de temperatura na posição do vetor equivalente à quantas "meia hora" passaram
  
  _5segundos = 0; // zera o contador de 5 segundos
  }

}
  



void loop() {

umid = dht.readHumidity(); // lê valor inicial de umidade
temp = dht.readTemperature();

if (temp >= 54) // se temperatura for maior ou igual a 54 ºC
{
   digitalWrite(exaustor, 1); // liga exaustor
   digitalWrite(rele, 0); // desliga resistência
}

else
{
digitalWrite(exaustor, 0);
}

if (temp <= 51) // se temperatura for menor ou igual a 51 ºC
{
digitalWrite(rele, 1);
}

if (umid >= 55) // se umidade for maior ou igual a 55%
{
digitalWrite(ventilador, 1);
}

else
{
digitalWrite(ventilador, 0);
}


if (_meiahora - _meiahoraant == 1) // quando tiver passado meia hora desde a última meia hora
{

_meiahoraant = _meiahora; // atribui o valor do contador de "meia hora" à variável "meia hora anterior"

liga_motor ();

}


}



void escreve_serial() // transmite temperatura e umidade pela porta serial, usada exclusivamente para coleta de dados
{
Serial.println("temperatura");

for (volatile int i = 0; i < 145; i++)
{
Serial.println(temperatura[i]);
}

Serial.println("umidade");

for (volatile int i = 0; i < 145; i++)
{
Serial.println(umidade[i]);
}
Serial.println ("variavel temp e umid");
Serial.println(temp);

Serial.println(umid);

delay (1000);

}



void liga_motor () // rotina de movimentação do motor de passo
{

while (1)
  {
 // Passo 1
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  delay(500);  

  // Passo 2
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  delay(500);

  // Passo 3
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  delay(500);

  // Passo 4
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  delay(500);

contador++;

    if (contador == 100){ // quando o motor executar 100 ciclos completos
    contador = 0; // zera contador de ciclos
    return; // retorna ao loop
    }
  
  } 
}

