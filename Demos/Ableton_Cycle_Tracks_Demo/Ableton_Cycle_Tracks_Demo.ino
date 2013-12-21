#include <MIDI.h>
/*
  Author: Steve Mason

  Custom Ableton Live Track Controller
  ====================================
  
  This demo cycles through 12 tracks in Ableton Live
  and toggles the first clip on/off.
  
  Here's what's happening:
  
  * MIDI Output from Arduino to Computer over USB 
  * Using Hairless Serial <-> MIDI Bridge on OSX 10.9
  * Using MIDI Library for Arduino
  * Hairless is routed to IAC Driver Bus 1 
      (Using Audio MIDI Setup app on OSX)
  * Ableton Live reading MIDI from IAC Driver
      (using Selected Track Control library)

  Sources:
  
  * Arduino MIDI Library http://arduinomidilib.sourceforge.net/a00001.html
  * Selected Track Control Plugin for Ableton Live http://stc.wiffbi.com/download/
  * Hairless MIDI<-> Serial Bridge http://projectgus.github.io/hairless-midiserial/
  
*/

#define LED 13   		// LED pin on Arduino board
#define TRACKS 12               // Number of Tracks

int selectedTrack = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);         // Set the BAUD RATE for MIDI
 
  //MIDI.begin(4);            	// If you set this value, Hairless
                                // will give you errors and you
                                // can't send MIDI properly.
}


void loop() {
    digitalWrite(LED,HIGH);                              // Blink the LED
    
    /* 
     * Cycle through Tracks
     */
     
    ToggleClip(selectedTrack, 0);                        // Toggle the clip at scene 1
    selectedTrack = (selectedTrack+1) % (TRACKS-1);      // Increment track
                                                         // using % loop
                                                         	
    delay(100);		                                 // Wait for .1 seconds
    digitalWrite(LED,LOW);                               // LED off
    delay(1000);		                         // Wait for a second

}

void ToggleClip(int track, int scene){
  MIDI.sendControlChange(8, track, 1);   // Select Track (Column)
  MIDI.sendControlChange(2, scene, 1);   // Select Scene (Row)
  MIDI.sendNoteOn(73,127,1);  // Send a Toggle Clip Message
  MIDI.sendNoteOff(73,0,1);   // Stop Message
}

/*
  MIDI Codes for Ableton Track Control
  ====================================

  Select Track #               MIDI CC 8 (#)
    MIDI.sendControlChange(8, 0, 1); // Select Track 1
    MIDI.sendControlChange(8, 1, 1); // Select Track 2
    MIDI.sendControlChange(8, 2, 1); // Select Track 3
    MIDI.sendControlChange(8, 3, 1); // Select Track 4
    MIDI.sendControlChange(8, 4, 1); // Select Track 5
    MIDI.sendControlChange(8, 5, 1); // Select Track 6
    MIDI.sendControlChange(8, 6, 1); // Select Track 7
    MIDI.sendControlChange(8, 7, 1); // Select Track 8
    MIDI.sendControlChange(8, 8, 1); // Select Track 9
    MIDI.sendControlChange(8, 9, 1); // Select Track 10
    MIDI.sendControlChange(8, 10, 1); // Select Track 11
    MIDI.sendControlChange(8, 11, 1); // Select Track 12
    
  Select Prev Track            MIDI Note 84 (C5)
    MIDI.sendNoteOn(85,127,1);  // Send a Previous Track Message
    MIDI.sendNoteOff(85,0,1);   // Stop Message
    
  Select Next Track            MIDI Note 85 (C#5)
  
  Select Scene #               MIDI CC 2 (#)  
  Select Prev Scene            MIDI Note 82 (A#4)
  Select Next Scene            MIDI Note 83 (B4)

  Play Selected Clip           MIDI Note 43 (G1)
  Toggle Selected Clip         MIDI Note 73 (C#4)
    MIDI.sendNoteOn(73,127,1);  // Send a Toggle Clip Message
    MIDI.sendNoteOff(73,0,1);   // Stop Message

  Select Playing Clip          MIDI Note 50 (D2)
  Auto-Select Playing Clip     MIDI Note 51 (D#2)
    (When track selected)
  
  Stop Current Track           MIDI Note 48 (C2)
  Stop All Tracks              MIDI Note 49 (C#2)

  Play Next Clip               MIDI Note 45 (A1)
  Play Prev Clip               MIDI Note 41 (F1)
  
  =======================================
  
  All MIDI commands tested with OSCulator
  http://www.osculator.net/download/
  
  MIDI Code Values from Selected Track Control Plugin docs
  http://stc.wiffbi.com/midi-implementation-chart/
  
*/
