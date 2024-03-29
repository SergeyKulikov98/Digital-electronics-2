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
#include "gpio.h"
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
    GPIO_config_output(&DDRB, LED1);
    GPIO_config_output(&DDRB, LED2);
    GPIO_input_pullup(&PORTD, PUSH);
    

    GPIO_write(&PORTB, LED1);
    GPIO_write(&PORTB, LED2);



    /* Infinite loop */
    for (;;)
    {
        /* Invert LED and delay */
     if (GPIO_read(&PIND, PUSH)){

     GPIO_toggle(&PORTB, LED1);
     GPIO_toggle(&PORTB, LED2);
     _delay_ms(BLINK_DELAY);
     }   
        
        
    }

    return (0);
}
