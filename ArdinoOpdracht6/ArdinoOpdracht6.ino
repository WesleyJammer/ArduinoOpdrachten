
// Servo libary aanroepen die het makkelijker maakt de bewegingen van de servo te bepalen
#include <Servo.h>

// naam aan servo geven
Servo servoWes;
// basis positie vast stellen
int basePos = 0;

// de y as verbinden met een analoge pin om zo met de y as bewegingen te kunnen gaan maken met de joystick
const int yPin = A1;
// de beginwaarde van de y as vast stellen op 0
int yBase = 0;
// pin verbinden met de indrukknop functie van de joystick
const int joyButt = 13;
// in dit geval is het een pull up button dus is de status op het begin niet LOW maar HIGH
int buttState = HIGH;


void setup()
{
  
  // servo vastmaken aan pin 11
  servoWes.attach(11);
  pinMode(joyButt, INPUT);
  
}

void loop()
{
 
 // de serState functie aanroepen in de loop
serState();

 
 
  
}

void serState(){
  // de y as uitlezen doormiddel van de yPin mee te geven dit is een analogRead omdat hij meer kan uitlezen dan alleen aan of uit. namelijk ook de bewegingen.
 int yVal = analogRead(yPin); 
 // status van de knop word uitgelezen
 buttState = digitalRead(joyButt);

// als de knop ingedrukt is 
 if(buttState == LOW){

// word er een for loop uitgevoerd die zolang de basis positie kleiner of gelijk is dan 120 1 graden opschuift
for(basePos = 0; basePos <= 120; basePos += 1){
    
    // basispositie uitschijven zodat deze wordt uitgevoerd
     servoWes.write(basePos);
     // een delay van 5 miliseconden toepassen tussen elke graden die word opschoven
     delay(5);
    }

// als de servo dus zijn uiterste stand heeft berijkt wordt de zelfde loop uitgevoerd alleen dan in omgekeerde richting en dus zel er elke beweging 1 graden worden afgehaald.
     for(basePos = 120; basePos >= 0; basePos -= 1){
     
      servoWes.write(basePos);
      delay(5);
    
    }

 }
 else{

// als er geen knop word ingedrukt zal de servo bewegen op basis van de stand van de yas
// de basispositie is gelijk aan een map functie waarbij de y waarde word meegegeven en de bewegings ruimte van de joystick.(0 - 1023)
// ook word het aantal graden dat de servo mag bewegen meegegeven(in dit geval 0-180)
 basePos = map(yVal, 0, 1023, 0, 180);
 // de basispositie die elke keer wordt aangepast door hierboven vastgestelde waardes wordt meegegeven.
  servoWes.write(basePos);
  delay(5);

 }


}
