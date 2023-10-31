#include <Ultrasonic.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define pino_trigger 4 // recebe o eco
#define pino_echo 5 // envia o eco
#define porta_rele_bomba 2

Ultrasonic ultrasonic(pino_trigger, pino_echo);
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

char c;

void setup()
{
  Serial.begin(9600); // Habilita Comunicação Serial a uma taxa de 9600 bauds.
  
  pinMode(porta_rele_bomba, OUTPUT);

  lcd.begin (16,2); // Inicializa o LCD
  lcd.setBacklight(HIGH); // Liga o BackLight do LCD com brilho ALTO

  c = 'd'; // variavel de inicio de comunicação
}

// Função que se repete infinitamente quando a placa é ligada
void loop()
{
  while (c == 'a') // AUTOMATICO
  {
    lcd.setCursor(0,0);
    lcd.print("Automatico: ON  "); // a função print mostra em tela o seu argumento

    if (Serial.available())
      c = Serial.read();

    if (c == 's') // SECAR POÇO AUTOMATICAMENTE
      c = 'd';
      
    else if (c == 'm') // MANUAL
    {
      manual(); 
      c = 'a';
    }
    else
    {
      automatico();
      c = 'a';
    }
  }
  
  while (c == 'd')
  {    
    lcd.setCursor(0,0);
    lcd.print("Automatico: OFF ");
    
    if (Serial.available())
      c = Serial.read();
    
    if (c == 's')
      c = 'a';
    
    else if (c == 'm')
    {
      manual();  
      c = 'd';
    }
    else
    {
      desligado();
      c = 'd';
    }
  }
}

void manual()
{
  long microsec = ultrasonic.timing(); // TEMPO DE REC DE ECO
  float cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); //DISTANCIA DO ULTRASSOM P AGUA 

  if (cmMsec < 12)
  {
    lcd.setCursor(0,0);
    lcd.print("Esvaziando Recipiente");
    digitalWrite(porta_rele_bomba, LOW);
    
    while (cmMsec < 12)
    {
      microsec = ultrasonic.timing();
      cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
      
      nivel(cmMsec, 'm');
    }
  }
  else
  {
    digitalWrite(porta_rele_bomba, HIGH);
    nivel(cmMsec, 'm');
  }
}

void nivel(float cmMsec, char t)
{  
  lcd.setCursor(0,1);
  lcd.print("Nivel: ");
  
  lcd.setCursor(7,1);
  lcd.print("          ");
  
  lcd.setCursor(7,1);
  lcd.print(((100 * (12 - cmMsec)) / 8), 0);
  lcd.print("%");

  if (t == 'd')
  {
    Serial.print(int((100 * (12 - cmMsec)) / 8));
    Serial.print(",");
    Serial.print("d");
    Serial.print(",");
    Serial.flush();
  }
  else if (t == 'a')
  {
    Serial.print(int((100 * (12 - cmMsec)) / 8));
    Serial.print(",");
    Serial.print("a");
    Serial.print(",");
    Serial.flush();
  }
  else if (t == 'm')
  {
    Serial.print(int((100 * (12 - cmMsec)) / 8));
    Serial.print(",");
    Serial.print("m");
    Serial.print(",");
    Serial.flush();
  }
  
  delay(1000);
}

void automatico()
{
  long microsec = ultrasonic.timing();
  float cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  if (cmMsec < 4)
  {
    lcd.setCursor(0,0);
    lcd.print("Secando Poco !   ");
    digitalWrite(porta_rele_bomba, LOW);
    
    while (cmMsec < 12)
    {
      microsec = ultrasonic.timing();
      cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

      nivel(cmMsec, 'm');
    }
  }
  else
  {
    digitalWrite(porta_rele_bomba, HIGH);
    nivel(cmMsec, 'a');
  }
}

void desligado()
{
  long microsec = ultrasonic.timing();
  float cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  digitalWrite(porta_rele_bomba, HIGH);
  nivel(cmMsec, 'd');
}
