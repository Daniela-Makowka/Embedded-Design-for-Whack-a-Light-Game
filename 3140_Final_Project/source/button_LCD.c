/*
 * lcd_demo.c
 *
 *  Created on: May 6, 2022
 *      Author: Aaron Wilhelm
 */
#include <MKL46Z4.h>
#include <stdint.h>
#include "lcd.h"
#include "LED.h"

//Global Variables
const int SWITCH_1_PIN = 3;
//SIM_Type* global_SIM = SIM;
//PORT_Type* global_PORTE = PORTE;
//GPIO_Type* global_PTE = PTE;
PORT_Type* global_PORTC = PORTC;
GPIO_Type* global_PTC = PTC;
int Counter = 1000000;
//Function Declarations
void operate_switch_interrupts();

void displayGo(void){
		turnOnSegment(3,'A');
	    turnOnSegment(3,'F');
	    turnOnSegment(3,'G');
	    turnOnSegment(3,'E');
	    turnOnSegment(3,'D');
	    turnOnSegment(3,'C');
	    turnOnSegment(4,'A');
	    turnOnSegment(4,'B');
	    turnOnSegment(4,'F');
	    turnOnSegment(4,'E');
	    turnOnSegment(4,'D');
	    turnOnSegment(4,'C');
	    LCD_TimeDelay(0xFFFFFFU);
	    clearDisplay();
}

void displayBegin(void){
		turnOnSegment(1,'A');
		turnOnSegment(1,'B');
		turnOnSegment(1,'G');
		turnOnSegment(1,'F');
		turnOnSegment(1,'E');
		turnOnSegment(1,'D');
		turnOnSegment(1,'C');

		turnOnSegment(2,'A');
		turnOnSegment(2,'G');
		turnOnSegment(2,'F');
		turnOnSegment(2,'E');
		turnOnSegment(2,'D');

		turnOnSegment(3,'A');
		turnOnSegment(3,'F');
		turnOnSegment(3,'G');
		turnOnSegment(3,'E');
		turnOnSegment(3,'D');
		turnOnSegment(3,'C');

		turnOnSegment(4,'E');
		turnOnSegment(4,'F');

	    LCD_TimeDelay(0xFFFFFFU);
	    clearDisplay();
}
void Countdown(void){
	 for(int iteration = 5; iteration >=0; iteration--) {
	    	displayDigit(1,0);
	    	displayDigit(2,0);
	    	displayDigit(3,0);
	        displayColon();
	        displayDigit(4, iteration);
	    	LCD_TimeDelay(0xFFFFFFU);
	}
	    	clearDisplay();
}

void SW1SetUp(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; //Enable the clock to port C
	    PORTC->PCR[SWITCH_1_PIN] &= ~PORT_PCR_MUX(0b111); // Clear PCR Mux bits for PTC3
	    PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_MUX(0b001); // Set up PTC3 as GPIO
	    PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SWITCH_1_PIN); // make it input
	    PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_PE(1); // Turn on the pull enable
	    PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_PS(1); // Enable the pullup resistor
	    PORTC->PCR[SWITCH_1_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
	    PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_IRQC(0b1011); // Set up the IRQC to interrupt on either edge (i.e. from high to low or low to high)
}

//int main(void)
//{
//    /* Starts LCD display. */
//    init_lcd();
//    LED_Initialize();
//    LEDGreen_Off();
//    displayBegin();
//    LEDRed_On();
//    // setup switch 1
//    SW1SetUp();
//    operate_switch_interrupts();
//
//
//
//
//    return -1;
//}

void operate_switch_interrupts() {
    	NVIC_EnableIRQ(PORTC_PORTD_IRQn); // configure NVIC so that interrupt is enabled

    	while(1){}
    }

void PORTC_PORTD_IRQHandler(void) {
		LEDRed_Off();
		Countdown();
    	displayGo();
    	LEDGreen_On();
    	PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_ISF(1);  // clear the interrupt status flag by writing 1 to it
    }

