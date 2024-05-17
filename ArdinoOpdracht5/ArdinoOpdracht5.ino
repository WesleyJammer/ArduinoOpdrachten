// de servo libary toevoegen zodat het makkelijker word om de bewegingen van de servo motor te bepalen.
#include <Servo.h>

// de servomotor een naam geven
Servo servoWes;
// de basispositie van de servomotor op 0 zetten
int basePos = 0;

// de pin van knop 1 bepalen
const int btn1 = 2;
// status van de knop op laag zetten
int btn1State = LOW;

// de pin van knop 2 bepalen 
const int btn2 = 7;
// de status van de knop op laag zetten
int btn2State = LOW;


void setup()
{
  // de servomotor aan een pin koppelen
  servoWes.attach(11);
  // de 2 knoppen defineren als input voor de opdrachten die uitgevoerd moeten worden.
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  
 

}

void loop()
{

// de status van de 2 knoppen uitlezen ze kunnen LOW of HIGH zijn
  btn1State = digitalRead(btn1);
  btn2State = digitalRead(btn2);
 
  
  // als knop 1 is ingedrukt en dus HIGH is en knop 2 niet is ingedrukt en dus LOW is dan word de serFlow functie aangeroepen met een snelheid van 1 seconden waarin de servomotor tot 120graden en terug beweegt.
  if(btn1State == HIGH && btn2State == LOW){


  serFlow(1000);

 } 
  
  // als knop 2 is ingedrukt en dus HIGH is en knop 1 niet is ingedrukt en dus LOW is dan word de serFlow functie aangeroepen met een snelheid van 0.5 seconden waarin de servomotor tot 120graden en terug beweegt.
  else if(btn1State == LOW && btn2State == HIGH){
  
  serFlow(500);

  }
  
  // als bijde knoppen HIGH zijn en dus ingedrukt beweegt de servomotor ook op en neer in 1 seconden maar zoals je in de latere functie gaat zien zit bij deze status nog een extra delay bij
  else if(btn1State == HIGH && btn2State == HIGH){
  
  serFlow(1000);
  }
}

// de functie serflow met de variabele dur die ik hierboven heb omgezet in een daadwerkelijke tijd. door het in de functie als een variabele aan te roepen ben ik vrij om overal de functie te gebruiken alleen dan met een andere waarde.
void serFlow(int dur){
  

 // berekent hoegroot de delay tussen elke graden dat de servo opschuift moet zijn op basis van de tijd dat de servo nodig heeft om heen en weer te gaan 
    int delayMove = dur/120;

    // deze for loop berekent of de basispositie kleiner is dan 120. zo ja dan mag de servo basispositie een graden opschuiven per beweging.
    for(basePos = 0; basePos <= 120; basePos += 1){
    
    // de opdracht word uitgeschreven met de basispositie eraangekoppeld
     servoWes.write(basePos);
     // de delayMove variabele die hierboven wordt berekent koppelen aan de delay functie.
     delay(delayMove);
    }
  
  // als bijde knoppen zijn ingedrukt en de duratie van beweging is 1 seconden dan komt er voordat de servo mag terug bewegen een pauze van 2 seconden
  if(dur == 1000 && btn1State == HIGH && btn2State == HIGH){
  
   delay(2000);
  }
    
    // zelfde als bovenstaande for loop alleen nu zal hij elke keer 1 graden afnemen
    for(basePos = 120; basePos >= 0; basePos -= 1){
     
      servoWes.write(basePos);
      delay(delayMove);
    
    }

}