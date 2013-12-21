#include <MIDI.h>

void setup() {
  Serial.begin(115200);
  for(int i = 0; i < numTracks; i++){
    pinMode(albumPins[i], OUTPUT);
    // Set pins to Pull-Up
    digitalWrite(albumPins[i], HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(int i = 0; i < numTracks; i++) {
    int pinState = digitalRead(albumPins[i]);
    int pin = albumPins[i];
    if(pinState==LOW){
      ToggleClip(i, 0);
    }
  }
}
void ToggleClip(int track, int scene){
  MIDI.sendControlChange(8, track, 1);   // Select Track (Column)
  MIDI.sendControlChange(2, scene, 1);   // Select Scene (Row)
  MIDI.sendNoteOn(73,127,1);  // Send a Toggle Clip Message
  MIDI.sendNoteOff(73,0,1);   // Stop Message
}
