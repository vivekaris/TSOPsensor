/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv

 * Copyright 2009 Ken Shirriff
 
 */

#include <IRremote.h>

int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
 pinMode(13,OUTPUT);
}

void loop() {

long on=16236607;
long off=16203967;


  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    Serial.println(results.value);
    if(results.value==on)
    {
      digitalWrite(13,HIGH);
      Serial.println("ON");
    }

    if(results.value==off)
    {
      digitalWrite(13,LOW);
      Serial.println("OFF");
    }
    
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}




