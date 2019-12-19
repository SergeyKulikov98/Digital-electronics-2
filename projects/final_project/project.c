//Digital Electronics 2 - CMPT
//******Final Project******
//Authors : Sergey Kulikov, Salih Erbalta, Hüseyin Temizkan

#include <stdlib.h> 
#include <avr/io.h>
#include "gpio.h"
#include "timer.h"
#include "segment.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "uart.h"

#define TRIG PD0
#define ECHO PD1
#define UART_BAUD_RATE 9600




    


void sendT(uint8_t pin){

    PORTD ^= _BV(pin);
    _delay_us(10);
    PORTD ^= _BV(pin);
    
 


}
    volatile uint16_t dur= 0;
    static uint8_t dist =0;
    char uart_string[3];


int main(){

     DDRD |= _BV(TRIG);
    PORTD &= ~_BV(TRIG);    
    _delay_us(2);

    

    //uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
    DDRD&= ~_BV(ECHO);
    PORTD |= _BV(ECHO);

    GPIO_config_output(&DDRB, SEGMENT_DATA );
    GPIO_config_output(&DDRD, SEGMENT_CLK );
    GPIO_config_output(&DDRD, SEGMENT_LATCH );

    TIM_config_prescaler(TIM1, TIM_PRESC_8);
	TIM_config_interrupt(TIM1, TIM_OVERFLOW_ENABLE);

    TIM_config_prescaler(TIM0, TIM_PRESC_256);
    TIM_config_interrupt(TIM0, TIM_OVERFLOW_ENABLE);
    
   
    sei();
   
    
    
    // Infinite loop
    for (;;) {

   
    
    // PORTD ^= _BV(TRIG);
    // _delay_us(10);
    // PORTD ^= _BV(TRIG);
   
    

    dist = dur / 58.31;

   SEG_putc(dist, 0);
    SEG_putc(dur, 3);

		
		
		
    }

    // Will never reach this
    return (0);
 



}

ISR(TIMER1_OVF_vect){
    
uint8_t LVL=0;


 sendT(TRIG);

    while(LVL==0){
        if(GPIO_read(&PIND,ECHO)){
            dur++;
            LVL= 1;
        }
    }
}


ISR(TIMER0_OVF_vect){

    
}


