OBJCOPY		= avr-objcopy
CC			= avr-gcc
CFLAGS		= -pipe -O1 -flto -ffunction-sections -fdata-sections -mmcu=${DEVICE} 

DEVICE		= atmega328p
FCPU		= 16000000
PORT		= /dev/ttyUSB0

PROG		= Blink


${PROG}.hex : ${PROG}.elf
	${OBJCOPY} -O ihex -R .eeprom ${PROG}.elf ${PROG}.hex

${PROG}.elf : ${PROG}.o avr8-stub.o
	${CC}  ${CFLAGS} ${PROG}.o avr8-stub.o -o ${PROG}.elf

${PROG}.o : ${PROG}.c ${PROG}Config.h
	${CC} -c -std=gnu99 -DF_CPU=${FCPU} -Wall ${CFLAGS} ${PROG}.c -o ${PROG}.o

avr8-stub.o : ./avr_debug/avr8-stub/avr8-stub.c
	${CC} -c -std=gnu99 -DF_CPU=${FCPU} -Wall ${CFLAGS} ./avr_debug/avr8-stub/avr8-stub.c -o avr8-stub.o

install : ${PROG}.hex
	avrdude -F -V -c arduino -p ${DEVICE} -P ${PORT} -b 115200 -U flash:w:${PROG}.hex

clean:
	rm *.hex *.elf *.o
