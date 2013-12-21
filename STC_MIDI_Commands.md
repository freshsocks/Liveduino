Ableton Live Selected Track Control
===================================

These are some commands I'm using with the [selected track control plugin](http://stc.wiffbi.com/), along with liens of code that can be pasted into Arduino IDE.

You also need the **MIDI Library for Arduino**. If I remember correctly, it doesn't come with the default libraries. You need to [download](http://sourceforge.net/projects/arduinomidilib/files/Releases/Arduino_MIDI_Library_v3.2.zip/download) & [install](http://arduinomidilib.sourceforge.net/a00001.html) it on your own.

I am also using [Hairless Serial - MIDI Bridge](http://projectgus.github.io/hairless-midiserial/) to get the MIDI in to Ableton Live.

MIDI Commands I'm Using
=======================

#### Track Control

* __Select Track #__
	
	MIDI CC 8 (#)

```
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
```   
* __Select Prev Track__
	
	MIDI Note 84 (C5)

```
    MIDI.sendNoteOn(85,127,1);  // Send a Previous Track Message
    MIDI.sendNoteOff(85,0,1);   // Stop Message
```   
* __Select Next Track__
	MIDI Note 85 (C#5)
* __Stop Current Track__
	MIDI Note 48 (C2)
* __Stop All Tracks__
	MIDI Note 49 (C#2)

#### Scene Control

* __Select Scene #__
	MIDI CC 2 (#)  
* __Select Prev Scene__
	MIDI Note 82 (A#4)
* __Select Next Scene__
	MIDI Note 83 (B4)


#### Clip Control

* __Play Selected Clip__ 	MIDI Note 43 (G1)
* __Toggle Selected Clip__ 	MIDI Note 73 (C#4)
```
    MIDI.sendNoteOn(73,127,1);  // Send a Toggle Clip Message
    MIDI.sendNoteOff(73,0,1);   // Stop Message
```

* __Select Playing Clip__ 	MIDI Note 50 (D2)
* __Auto-Select Playing Clip__ 	MIDI Note 51 (D#2)
    (When track selected)

* __Play Next Clip__ 	MIDI Note 45 (A1)
* __Play Prev Clip__ 	MIDI Note 41 (F1)
  
__________________________________________________________

All MIDI commands tested with OSCulator
(http://www.osculator.net/download/)

MIDI Code Values from Selected Track Control Plugin docs
(http://stc.wiffbi.com/midi-implementation-chart/)

Code for sending MIDI Messages from Arduino MIDI docs
(http://arduinomidilib.sourceforge.net/a00001.html)

