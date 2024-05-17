void setup()
{
  // pins vast stellen waarop de 8 led lampjes worden aangesloten
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  
}

void loop()
{
 
  //functie van rechts naar links aangeroepen, met een delay van 30 miliseconden tussen het aan en uit gaan van een lampje.
   left(30);
  //functie van links naar rechts aangeroepen, met een delay van 30 miliseconden tussen het aan en uit gaan van een lampje.
   left(30);
   right(30);
 
}

// functie die de lampjes een voor een van rechts naar links laat aan en uit gaan. met daar bij de variabele tijd zodat ik deze in de functie kan gebruiken.
void left(int time){

  //lampje gaat aan
  digitalWrite(1, HIGH);
  //de delay met de variabele tijd. de daadwerkelijke tijd word in de loop gespecificeerd.
  delay(time);
  //lamp gaat uit 
  digitalWrite(1, LOW);
  delay(time); 
  
  // bovenstaande geld ook voor onderstaande lampjes
  digitalWrite(2, HIGH);
  delay(time); 
  digitalWrite(2, LOW);
  delay(time); 
  
  digitalWrite(4, HIGH);
  delay(time); 
  digitalWrite(4, LOW);
  delay(time); 
  
  digitalWrite(7, HIGH);
  delay(time); 
  digitalWrite(7, LOW);
  delay(time); 
  
  
  digitalWrite(8, HIGH);
  delay(time); 
  digitalWrite(8, LOW);
  delay(time); 
  
 
  
  digitalWrite(11, HIGH);
  delay(time); 
  digitalWrite(11, LOW);
  delay(time); 
  
  
  digitalWrite(12, HIGH);
  delay(time); 
  digitalWrite(12, LOW);
  delay(time); 
  
  }

// functie die de lampjes een voor een van links naar rechts laat aan en uit gaan.
void right(int time){


  digitalWrite(13, HIGH);
  delay(time); 
  digitalWrite(13, LOW);
  delay(time); 
  
  digitalWrite(12, HIGH);
  delay(time); 
  digitalWrite(12, LOW);
  delay(time); 
  
  
  digitalWrite(11, HIGH);
  delay(time); 
  digitalWrite(11, LOW);
  delay(time); 
  
  digitalWrite(8, HIGH);
  delay(time); 
  digitalWrite(8, LOW);
  delay(time); 
  
  digitalWrite(7, HIGH);
  delay(time); 
  digitalWrite(7, LOW);
  delay(time);
  
  
  digitalWrite(4, HIGH);
  delay(time); 
  digitalWrite(4, LOW);
  delay(time); 
  
  digitalWrite(2, HIGH);
  delay(time); 
  digitalWrite(2, LOW);
  delay(time); 

}