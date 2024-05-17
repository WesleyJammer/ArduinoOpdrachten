 
 // de pull down knop doorverbinden aan pin 4 voor de input.
 const int pinBtn = 4;
 //het led lampje doorverbinden aan pin 11;
 const int pinLed = 11;
  
 // de orginele staat van de button bepalen die is nu LOW of in cijfer termen 0. wat betekent dat de knop niet ingedrukt is.
 int btnState = LOW;
 // de laatste status van de button op LOW zetten zodat de de status niet blijft veranderen als je de knop indrukt houd.
 int btnLastState = LOW;
 // de orginele status van het led lampje is LOW wat betekent dat hij uit staat, want er komt geen stroom doorheen.
 int ledState = LOW;

  
  
void setup()
{
  
  // de button specificeren als een input want je drukt hem in dus daarmee breng je een opdracht om stroom naar een bepaald punt te leiden in.
  pinMode(pinBtn, INPUT);
  // het ledlampje specificeren als een OUTPUT wasnt daar word de opdracht van het stroom uitgevoerd. in dit geval het laten branden van het licht.
  pinMode(pinLed, OUTPUT);

}

void loop()
{
  
  //de status van de button is verbonden het uitlezen van de pin waarop de button is geïnstalleerd. er zijn 2 mogelijkheden hij word ingedrukt(HIGH) of hij word niet ingedrukt.(LOW);
  btnState = digitalRead(pinBtn);
  
  // een if statement die checked of de status van de button HIGH is en de status daarvoor LOW was zodat hij alleen reageert op 1 indruk van de knop en niet op het ingedrukt houden van de knop.
  if(btnState == HIGH && btnLastState == LOW){
  
  
  // de status van het led Lampje is of LOW of niet LOW(HIGH). en andersom ook. zoweet het programma of het ledlampje aan moet staan of niet. 
    ledState = !ledState;
    
    
    //de opdracht om het ledlampje aan en uit teschrijven en toeverwijzen aan het juiste ledlampje ook daad werkelijk uit te voeren. en het is digitaal want hij kan alleen aan of uit staan.
    digitalWrite(pinLed, ledState);
    
    // een delay uitvoeren zodat er geen conflicten kunnen ontstaan het aan en uitgaan van het ledlampje. er wordt eerst 300 milisec gewacht zodat de volgende opdracht veilig kan worden uitgevoerd.
    delay(300);
  
  
  }
  
  //zorgen dat de vorige status van het indrukken van de knop overeenkomt met de huidige status van het indrukken van de knop zodat het programma weet dat de knop niet weer van hoog naar laag moet gaan.
  btnLastState = btnState;
  
}
