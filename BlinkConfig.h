/* Define configurables for the blink timer
 * Conditional #defines are tuned for the ATmega328p, alter for other targets */


/* The number of clock ticks before the output pin is flipped
 * Calculate as 16MHz/(2 * CLOCK_PRESCALE * FREQUENCY) - 1
 * Prescaler macro can contain values of 0, 1, 8 ,64 ,256 or 1024 */
#define TIMER_COMPARE_PERIOD        (31249u)
#define CLOCK_PRESCALE              (256u)

#if (CLOCK_PRESCALE == 1024u)
    #define PRESCALE_SELECT (0x05u)
#elif (CLOCK_PRESCALE == 256u)
    #define PRESCALE_SELECT (0x04u)
#elif (CLOCK_PRESCALE == 64u)
    #define PRESCALE_SELECT (0x03u)
#elif (CLOCK_PRESCALE == 8u)
    #define PRESCALE_SELECT (0x02u)
#elif (CLOCK_PRESCALE == 1u)
    #define PRESCALE_SELECT (0x01u)
#elif (CLOCK_PRESCALE == 0u)
    #define PRESCALE_SELECT (0x00u)
#else
    #error "Please select a prescaler of 0, 1, 8, 64, 256 or 1024"
#endif

/* See device pin - port mapping */
#define TOGGLE_PIN			PB5
#define CONFIG_PORT			('B')

/* Auto config depending on prior macro - do not touch */
#if ('B' == CONFIG_PORT) 
	#define TOGGLE_PORT		PORTB
	#define TOGGLE_DDR		DDRB
#elif ('C' == CONFIG_PORT) 
	#define TOGGLE_PORT		PORTC
	#define TOGGLE_DDR		DDRC
#elif ('D' == CONFIG_PORT) 
	#define TOGGLE_PORT		PORTD
	#define TOGGLE_DDR		DDRD
#else
	#error "Please define a port A, B, or C"
#endif
