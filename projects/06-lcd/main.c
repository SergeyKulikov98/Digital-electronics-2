/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2018-10-16
 * Last update: 2019-10-25
 * Platform:    ATmega328P, 16 MHz, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description:
 *    Decimal counter with data output on LCD display.
 * 
 * Note:
 *    Modified version of Peter Fleury's LCD library with R/W pin 
 *    connected to GND. Newline symbol "\n" is not implemented, use
 *    lcd_gotoxy() function instead.
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>             // itoa() function
#include "timer.h"
#include "lcd.h"

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/**
 *  Brief:  Main program. Shows decimal values ​​on LCD display.
 *  Input:  None
 *  Return: None
 */



int main(void)
{
    /* LCD display
     * TODO: See Peter Fleury's online manual for LCD library 
     * http://homepage.hispeed.ch/peterfleury/avr-software.html
     * Initialize display and test different types of cursor */
    
    lcd_init(LCD_DISP_ON_CURSOR_BLINK);
    // Display string without auto linefeed
    //lcd_puts("LCD testing");
lcd_puts("Counter: ");
    // TODO: Display variable value in decimal, binary, and hexadecimal
lcd_gotoxy(0,1);
lcd_putc('$');

lcd_gotoxy(5,1);
lcd_puts("0b");
    /* Timer1
     * TODO: Configure Timer1 clock source and enable overflow 
     *       interrupt */
    TIM_config_prescaler(TIM1, TIM_PRESC_256);
    TIM_config_interrupt(TIM1, TIM_OVERFLOW_ENABLE);
    /* TODO: Design at least two user characters and store them in 
     *       the display memory */

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    for (;;) {
    }

    // Will never reach this
    return (0);
}

/**
 *  Brief: Timer1 overflow interrupt routine. Increment counter value.
 */
ISR(TIMER1_OVF_vect)
{
    // TODO: Increment counter value form 0 to 255
    static uint8_t value = 0;
    static char lcd_stgdec[4];
    static char lcd_stgex[3];
    static char lcd_stgbin[9];
  
    
    

    lcd_gotoxy(9,0);
    itoa(value, lcd_stgdec,10);
    lcd_puts(lcd_stgdec);

    lcd_gotoxy(1,1);

    itoa(value, lcd_stgex,16);
    
    lcd_puts(lcd_stgex);

   lcd_gotoxy(8,1);
    itoa(value, lcd_stgbin,2);
    
    lcd_puts(lcd_stgbin);
    value ++;
}
