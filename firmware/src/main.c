#include <stdint.h>
#include <xc.h>
#include "main.h"
#include "system_config/microstick3vk_pic24f16kl402/system_config.h"

#define LIGHT_ON    1
#define LIGHT_OFF   0

int count = 0;

enum
{
    RED, RED_YELLOW, YELLOW, GREEN, DISABLE // Add other states here...
} semaphoreState;

void __attribute__((interrupt, auto_psv)) _INT1Interrupt(void) {
    
    if(semaphoreState != DISABLE) semaphoreState = DISABLE;
    else semaphoreState = YELLOW;
    count = 0;
    
    // Reset interrupt
    IFS1bits.INT1IF = 0;
}

int main() 
{

    // Initialize the LED. This symbol is defined in system_config.h
    LED_TRIS = 0;
    SWITCH_TRIS = 1;
    LED_RED_TRIS = 0;
    LED_YELLOW_TRIS = 0;
    LED_GREEN_TRIS = 0;

    /* Very imporant to set the input port as Digital */
    _ANSA1 = 0;

    /* Set Interrupt */
    _TRISB14 = 1;
    _ANSB14 = 0;
    // Make interrupt 1 trigger on a rising edge
    INTCON2bits.INT1EP = 0; //INTCON2 &= ~(0x0001);
    // Clear the interrupt just to be safe
    IFS1bits.INT1IF = 0;
    // Assign priority level 6
    IPC5bits.INT1IP = 6;
    // Enable external interrupt 1
    IEC1bits.INT1IE = 1; //IEC0 |= 0x0001;


    /* Initialize Timer 1
     * Each configuration sets the MCU's oscillator to 32MHz (see the respective
     * "system.c" for configuration bits).  For the LED to blink
     * at a rate of 1Hz, it must be toggled at 2Hz.
     *
     * Calculation:
     * Fcy = Fosc / 2 = 16E6 [Hz]
     * T1CONbits.TCKPS = 3 divides the input clock by 256.
     * PR1 = Fcy[Hz] / 256 / 2[Hz] = 0x7A12;
     */
    _T1IF = 0;
    _T1IE = 0;
    TMR1 = 0x0000;
    PR1 = 0x7A12;
    T1CONbits.TCKPS = 3;
    T1CONbits.TON = 1;

    enum 
    {
        IDLE, BLINK_LED // Add other states here...
    } demoState;

    while (1)
    {
        /*
        if (_T1IF == 1)
        {
            if(SWITCH) {
                count = 0;
                if(semaphoreState != DISABLE) semaphoreState = DISABLE;
                else semaphoreState = YELLOW;
            }
        }
        */

        /*
         *
        switch (demoState) 
        {
            case IDLE:
                if (_T1IF == 1) 
                {
                    _T1IF = 0;
                    count++;
                    demoState = BLINK_LED;
                }
                // Add other idle tasks here...
                break;

            case BLINK_LED:
                LED ^= 1; // Toggle the LED
                demoState = IDLE;
                break;

            // Add other case states here...
            default:
                demoState = IDLE;
                break;
        }
        */
        switch (semaphoreState)
        {
            case RED:
                LED_RED = LIGHT_ON;
                LED_YELLOW = LIGHT_OFF;
                LED_GREEN = LIGHT_OFF;
                if (_T1IF == 1)
                {
                    _T1IF = 0;
                    if(++count == 5) {
                        count = 0;
                        semaphoreState = RED_YELLOW;
                    }
                }
                break;
            case RED_YELLOW:
                LED_RED = LIGHT_ON;
                LED_YELLOW = LIGHT_ON;
                LED_GREEN = LIGHT_OFF;
                if (_T1IF == 1)
                {
                    _T1IF = 0;
                    if(++count == 2) {
                        count = 0;
                        semaphoreState = GREEN;
                    }
                }
                break;
            case YELLOW:
                LED_RED = LIGHT_OFF;
                LED_YELLOW = LIGHT_ON;
                LED_GREEN = LIGHT_OFF;
                if (_T1IF == 1)
                {
                    _T1IF = 0;
                    if(++count == 3) {
                        count = 0;
                        semaphoreState = RED;
                    }
                }
                break;
            case GREEN:
                LED_RED = LIGHT_OFF;
                LED_YELLOW = LIGHT_OFF;
                LED_GREEN = LIGHT_ON;
                if (_T1IF == 1)
                {
                    _T1IF = 0;
                    if(++count == 7) {
                        count = 0;
                        semaphoreState = YELLOW;
                    }
                }
                break;
            case DISABLE:
                LED_RED = LIGHT_OFF;
                LED_GREEN = LIGHT_OFF;
                if (_T1IF == 1)
                {
                    _T1IF = 0;
                    LED_YELLOW ^= LIGHT_ON;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
