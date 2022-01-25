OBJCOPY		= avr-objcopy
CC			= avr-gcc
CFLAGS		= -pipe -O1 -ffunction-sections -fdata-sections -mmcu=${DEVICE} 

DEVICE		= atmega328p
FCPU		= 16000000


Blink.hex : Blink.elf
	${OBJCOPY} -O ihex -R .eeprom Blink.elf Blink.hex

Blink.elf : Blink.o
	${CC} -Wl --gc-sections ${CFLAGS} Blink.o -o Blink.elf

Blink.o : Main.c
	${CC} -c -std=gnu99 -DF_CPU=${FCPU}-Wall ${CFLAGS} Main.c -o Blink.o


