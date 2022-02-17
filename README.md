### Blink - The AVR-GCC Way ###

#### Why? ####

Blinking an LED or toggling a pin is the canonical 'hello world' of embedded programming.
The Arduino IDE provides a built in Blink program designed with Arduino C++ in mind, which is a good beginner resource, but I hope to illustrate how to do the same in a more 'low-level' way, using bare AVR-GCC and embedded C instead of C++ and the Arduino libraries.
Use this as a learning example regarding how to do something very basic with a high degree of control.

### Debug? ###

After running `avr-gdb`, issue the following commands: `(gdb) file Blink.elf`, `(gdb) set serial baud 115200`, `(gdb) target remote <port>`. Port in my case is `/dev/ttyUSB0`.
The gdb stub is provided via [Jan Dolinay's `avr_debug`](https://github.com/jdolinay/avr_debug).
