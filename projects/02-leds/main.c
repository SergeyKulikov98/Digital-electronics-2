/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2018-09-27
 * Last update: 2019-09-26
 * Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description: Blink a LED with delay function.
 * TODO: Verify functionality of LED blinker.
 * NOTE: Macro _BV converts a bit number into a byte value (see AVR Libc
 * Reference Manual).
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>
#include <util/delay.h>

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
#define LED1   PB5
#define LED2   PB0
#define BLINK_DELAY 250
#define PUSH   PD2

/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/**
  * Brief:  Main program. Blink a LED with delay function.
  * Input:  None
  * Return: None
  */
int main(void)
{
    /* Set output pin */
    DDRB |= _BV(LED2);         /* DDRB = DDRB or (0010 0000) */
    DDRB |= _BV(LED1);
    DDRD |= _BV(PUSH);
    PORTD |= _BV(PUSH);

    /* Turn LED off */
    PORTB &= ~_BV(LED1);       /* PORTB = PORTB and (0010 0000) */
    PORTB &= ~_BV(LED2);

    /* Infinite loop */
    for (;;)
    {
        /* Invert LED and delay */
        
        
        if(bit_is_clear(PIND,PUSH)){
          PORTB ^= _BV(LED1);    /* PORTB = PORTB xor (0010 0000) */
          PORTB ^= _BV(LED2);
          _delay_ms(BLINK_DELAY);     /* Wait for several milisecs */
        }

        
    }

    return (0);
}
