#include <MKL46Z4.h>
/* ----------------------------------------------------------------------
 Note the different characters around the library names.
 The <> characters are used to include system libraries
 The "" characters are used to include your own libraries
 ------------------------------------------------------------------------*/
const int RED_LED_PIN = 29;
const int GREEN_LED_PIN = 5;
SIM_Type* global_SIM = SIM;
PORT_Type* global_PORTE = PORTE;
GPIO_Type* global_PTE = PTE;
/*
 Main program: entry point
 */
// setup variables so we can see them in debugger
// if you get rid of this it seems the compiler just optimizes the variables away
// this is for educational purposes

// setup green led

void LED_Initialize(void)
{
SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK; //Enable the clock to port E
PORTE->PCR[RED_LED_PIN] = PORT_PCR_MUX(001);
PTE->PDDR |= GPIO_PDDR_PDD(1 << RED_LED_PIN);

SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
PORTD->PCR[GREEN_LED_PIN] = PORT_PCR_MUX(001);
PTD->PDDR |= GPIO_PDDR_PDD(1 << GREEN_LED_PIN);

}//Set up PTE29 and PTD5 as GPIO
 // make it output
void LEDGreen_On (void){
	PTD->PCOR |= GPIO_PCOR_PTCO(1 << GREEN_LED_PIN);  // turn it on
}

void LEDGreen_Off (void){
PTD->PSOR |= GPIO_PSOR_PTSO(1 << GREEN_LED_PIN); // turn it off
}

void LEDGreen_Toggle (void){
PTD->PTOR |= GPIO_PTOR_PTTO(1 << GREEN_LED_PIN); // toggle it
}

void LEDRed_On (void){
	PTE->PCOR |= GPIO_PCOR_PTCO(1 << RED_LED_PIN);  // turn it on
}

void LEDRed_Off (void){
PTE->PSOR |= GPIO_PSOR_PTSO(1 << RED_LED_PIN); // turn it off
}

void LEDRed_Toggle (void){
PTE->PTOR |= GPIO_PTOR_PTTO(1 << RED_LED_PIN); // toggle it
}

void LED_Off (void){
	LEDGreen_Off(); // turn it off
	LEDRed_Off(); // turn it off
}
