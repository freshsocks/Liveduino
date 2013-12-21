TODO
=====

Current Version: v0.0.1 Alpha


## v0.1.0 Beta release requirements

* Post instructions on building the buttons. _I'm looking into better materials for large area membrane buttons._
* Post circuit schematics.
* Add debouncing to buttons.
* Include royalty-free samples and an Ableton Live project file to start from.

__________________________________________

## Experiments for the future

### Circuit Design

_How can I scale up the amount of tracks & buttons on the circuit?_

I have a few ideas for ways to scale out the amount of buttons you have without occupying all of the pinouts on the Arduino.

* __Shift Registers__: I ordered some free samples from Texas Instruments and got 3 16-channel shift registers. You can chain them together, so I could potentially get 48 pins (bits) out of only 3 of the Arduino pinouts. The downside of this method is that I need a lot of wires running out of each of hte pads.

* __Resistor Ladder__: By placing a resistor between all of the buttons and just connecting them in serial, you could potentially get a stepped voltage reading for each button. It is then possible to identify individual buttons through a single analog-in pin on the Arduino. The upside of this is less pins taken up and less wires to connect, making a cleaner circuit. The downside is that I haven't figured out a way to determine if more than one button is being pressed at once since it will just read the "path of least resistance".

* __Computer Keyboard Membrane Circuit__: I'm still trying to figure out how computer keyboard membrane-button circuits work. If you take apart a keyboard, you'll see that they are pretty crazy looking. They might be the _key_(lol pun) to minimizing the number of pins, optimizing the circuit layout, and recognizing buttons independantly to allow for multiple button presses at once.

* __Resistor Matrix__: I recently stumbled across resistor grid/matrix circuits, and these might also be very useful. I haven't built one yet so I can't say what the positives and negatives are yet, but it looks like a worthy contender. I read that they are commonly used for the keys on old-school analog synthesizers. Sounds promising. [Here's a reference on resistor matrix circuits.](http://www.mathpages.com/home/kmath670/kmath670.htm)

### Software Features

* __Multiple scenes per track__: Currently, Liveduino only lets you trigger the first clip (scene) per track, and each button represents a single track. I would like to add the ability to scroll through a list of clips (scenes) per track with each button press. So every time you push a button to play a track after it's been stopped, it will advance to the next clip in that track, and loop back to the beginning after it's reach the end of the list.

* __Drum machine mode__: I'd like to add a coupel of modes that change the behavior of the buttons, probably through a rotary encoder mounted on a separate piece of hardware on the circuit. It could also be done by a secret button combo, which would be kind of fun. The drum machine mode would just activate the MIDI for a single drum machine instrument on a separate track, which would then allow you to play the buttons like a big drum machine. Instead of the samples playing and looping on the first beat of a bar, they would just trigger as one-shots immediatel when you hit the pad.

* __Filter mode__: Button pads enable/disable filters on the master track.

* __Synth mode__: Same as drum machine mode, only yo uare playing a synth. Some sort of synth-selecting mechanism would also be handy. Just a thought for now.