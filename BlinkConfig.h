/* Define configurables for the blink timer
 * Conditional #defines are tuned for the ATmega328p, alter for other targets */


/* The number of clock ticks before the output pin is flipped
 * Calculate as 16MHz/(CLOCK_PRESCALE * FREQUENCY) - 1
 * Prescaler macro can contain values of 0, 1, 8 ,64 ,256 or 1024 */
#define TIMER_COMPARE_PERIOD        (62499u)
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


/* The port and pin to be toggled, see datasheet */
#define TOGGLE_PORT				PORTB
#define TOGGLE_PIN              PB5

#if (TOGGLE_PORT == PORTA)
	#define PORT_DDR  DDRA
#elif (TOGGLE_PORT == PORTB)
	#define PORT_DDR  DDRB
#elif (TOGGLE_PORT == PORTC)
	#define PORT_DDR  DDRC
#else
	#error "Define a valid GPIO port of either PORTA, PORTB, or PORTC"
#endif

