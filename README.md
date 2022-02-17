### Blink - The AVR-GCC Way ###

#### Why? ####

Blinking an LED or toggling a pin is the canonical 'hello world' of embedded programming.
The Arduino IDE provides a built in Blink program designed with Arduino C++ in mind, which is a good beginner resource, but I hope to illustrate how to do the same in a more 'low-level' way, using bare AVR-GCC and embedded C instead of C++ and the Arduino libraries.
Use this as a learning example regarding how to do something very basic with a high degree of control.

#### How? ####

ATmega chips typically contain at least one Timer/Counter peripheral, and this peripheral can be used to trigger a periodic interrupt service routine (ISR).
By default, this project attaches an ISR to the ATmega328's Timer 1 peripheral, a 16 bit timer. 
For accurate timing, it is probably best to read the datasheet of the device you're using, as you'll need to understand the timer's prescaling options.
See `BlinkConfig.h` for how this is configured out the box, I've commented the relevant `#define`s with the general formula, and as a rule, if you could choose multiple prescalers, choose the smallest, it'll give you a slightly better resolution.
Also bear in mind that the maximum timer period for an 8 bit timer is 255, and a 16 bit timer 65535.
Setting up the timer is another dive into the datasheet, the relevant register settings are all contained within `Blink_Timer1Setup()`, which should hopefully be usefully commented to explain decisions made.

Setting up the output pin is much easier.
Each pin belongs to a port, for which you'll need to check the chip or dev board's pinout to connect it how you want.
Each port has its own data direction register (`DDRx`), input pin register (`PINx`), and output register (`PORTx`). 
`BlinkConfig.h` contains some macro magic to allow for compile time setting of the output pin, though this could always be hard-coded.
Out of the box only one pin is toggled, Pin B5, aka D13 on most Arduino dev boards, which typically has an attached LED, though this could be extended to multiple ports and pins, provided the desired pins aren't required for anything else.
The output pin is of course toggled within the body of the ISR.

When `main` finishes setting up timers and pins it loops `nop` forever.
This isn't strictly necessary, but it makes a good placeholder in the event someone would like to add code to the while loop.
Beware that adding code to this 'superloop' will be periodically interrupted by the ISR, as the name suggests, but as long as you keep the ISR short and snappy you'll be fine.
