void setup() {

  
// pins 11 en 12 vast stellen als stroom uitvoer voor leds
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

}

void loop() {

// led lamp van pin 11 gaat aan.
digitalWrite(11, HIGH);
// blijft 1 seconden aan
delay(1000);
// lamp gaat uit
digitalWrite(11, LOW);
// 1 seconden delay voordat lamp gekoppeld aan pin 12 aangaat
delay(1000);

// led lamp van pin 12 gaat aan.
digitalWrite(12, HIGH);
// blijft 1 seconden aan
delay(1000);
// lamp gaat uit
digitalWrite(12, LOW);
// 1 seconden delay voordat lamp gekoppeld aan pin 11 aangaat en daarmee begint de cyclus opnieuw.
delay(1000);

}
