//de analoge pin waaraan de potmeter is gekoppeld.
const int potPin = A1;
// een array om de 7 ledlampjes te koppelen aan de de ledpins
const int ledPins[] = {1,2,4,7,8,12,13};
// specificeren hoevel leds er zijn
const int numLeds = 7;



void setup()
{
  
  // een for loop die bij in de eerste plaats i op 0 zet en daarna bepaald dat het numLeds(7) groter moet zijn dan i als dat zo is kan i groeien.
  for(int i = 0; i < numLeds; i++){
  
  // i meegeven aan ledpins dus in dit geval 6 want er zijn 7 ledPins en 0 word ook meegerekend. 6 is het aantal lichtjes om vast stellen als de output waar stroom omgezet wordt in licht.
    pinMode(ledPins[i], OUTPUT);
   
   
  }
 
}

void loop()
{
  
  // variabale aanmaken voor de waarde van de potmeter en die koppelen aan het uitlezen van de status van de analoge pin van de potmeter.
 int potValue = analogRead(potPin);
 // een variabele light aanmaken en die koppelen aan de map functie waarbij ik het berijk van de pot meter(1023) koppel aan het aantal ledlichtjes.
 int light = map(potValue,0, 1023, 0, numLeds);
  
  // een for loop die controleerd of de light variabele groter is dan i als dat zo i mag i blijven doortellen
  for(int i = 0; i < light; i++){

   // i is in ditgeval dus 6 dus 7 ledlichtjes worden maximaal vorzien van 255(dit houd de maximale stroom kracht in, dus het lichtje brand op zijn felste) 
  analogWrite(ledPins[i], 255);
  
  }
  

// for loop die kijkt of het aantal ledlightjes groter is als light. als dat zo is mag i blijven door tellen en dus een light uitzetten
  for(int i = light ; i < numLeds; i++){
  
  // in dit geval is het maximaal 7 lichtjes die uit kunnen worden gezet
    analogWrite(ledPins[i], 0);
  
  }
  


}