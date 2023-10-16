#include "sensor.h"
#include <MKL46Z4.h>

//All sensors on port A
//const int SENS1_PIN = 2;//2
const int SENS2_PIN = 7;
const int SENS3_PIN = 12;
const int SENS4_PIN = 5;
const int SENS5_PIN = 13;
const int SENS6_PIN = 6;
const int SENS7_PIN = 14;
const int SENS8_PIN = 15;
const int SENS9_PIN = 17;

//All LEDs are on port E
//const int LED1_PIN = 31;//31
const int LED2_PIN = 19;
const int LED3_PIN = 18;
const int LED4_PIN = 17;
const int LED5_PIN = 16;
const int LED6_PIN = 6;
const int LED7_PIN = 3;
const int LED8_PIN = 2;
const int LED9_PIN = 20;


void operate_sensor_interrupts();
void PORTC_PORTD_IRQHandler();
void operate_sensor_polling();

void external_LED_Initalize(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK; //Enable the clock to port E

//	//LED1
//	PORTE->PCR[LED1_PIN] = PORT_PCR_MUX(0b001);
//	PTE->PDDR |= GPIO_PDDR_PDD(1 << LED1_PIN);
//	PTE->PCOR |= GPIO_PCOR_PTCO(1 << LED1_PIN);  // turn it off

	//LED2
	PORTE->PCR[LED2_PIN] = PORT_PCR_MUX(0b001);
	PTE->PDDR |= GPIO_PDDR_PDD(1 << LED2_PIN);
	PTE->PCOR |= GPIO_PCOR_PTCO(1 << LED2_PIN);  // turn it off

	//LED3
	PORTE->PCR[LED3_PIN] = PORT_PCR_MUX(0b001);
	PTE->PDDR |= GPIO_PDDR_PDD(1 << LED3_PIN);
	PTE->PCOR |= GPIO_PCOR_PTCO(1 << LED3_PIN);  // turn it off

	//LED4
	PORTE->PCR[LED4_PIN] = PORT_PCR_MUX(0b001);
	PTE->PDDR |= GPIO_PDDR_PDD(1 << LED4_PIN);
	PTE->PCOR |= GPIO_PCOR_PTCO(1 << LED4_PIN);  // turn it off

	//LED5
	PORTE->PCR[LED5_PIN] = PORT_PCR_MUX(0b001);
	PTE->PDDR |= GPIO_PDDR_PDD(1 << LED5_PIN);
	PTE->PCOR |= GPIO_PCOR_PTCO(1 << LED5_PIN);  // turn it off

	//LED6
	PORTE->PCR[LED6_PIN] = PORT_PCR_MUX(0b001);
	PTE->PDDR |= GPIO_PDDR_PDD(1 << LED6_PIN);
	PTE->PCOR |= GPIO_PCOR_PTCO(1 << LED6_PIN);  // turn it off

	//LED7
	PORTE->PCR[LED7_PIN] = PORT_PCR_MUX(0b001);
	PTE->PDDR |= GPIO_PDDR_PDD(1 << LED7_PIN);
	PTE->PCOR |= GPIO_PCOR_PTCO(1 << LED7_PIN);  // turn it off

	//LED8
	PORTE->PCR[LED8_PIN] = PORT_PCR_MUX(0b001);
	PTE->PDDR |= GPIO_PDDR_PDD(1 << LED8_PIN);
	PTE->PCOR |= GPIO_PCOR_PTCO(1 << LED8_PIN);  // turn it off

	//LED9
	PORTE->PCR[LED9_PIN] = PORT_PCR_MUX(0b001);
	PTE->PDDR |= GPIO_PDDR_PDD(1 << LED9_PIN);
	PTE->PCOR |= GPIO_PCOR_PTCO(1 << LED9_PIN);  // turn it off

}

void sensor_Initialize(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK; //Enable the clock to port A

//	//SENS1
//	PORTA->PCR[SENS1_PIN] &= ~PORT_PCR_MUX(0b001); // Clear PCR Mux bits for PTC3
//	PORTA->PCR[SENS1_PIN] |= PORT_PCR_MUX(1); // Set up PTC3 as GPIO
//	PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SENS1_PIN); // make it input
//	PORTA->PCR[SENS1_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
//	PORTA->PCR[SENS1_PIN] |= PORT_PCR_IRQC(0b1001); // Set up the IRQC to interrupt rising edge

	//SENS2
	PORTA->PCR[SENS2_PIN] &= ~PORT_PCR_MUX(0b001); // Clear PCR Mux bits for PTC3
	PORTA->PCR[SENS2_PIN] |= PORT_PCR_MUX(1); // Set up PTC3 as GPIO
	PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SENS2_PIN); // make it input
	PORTA->PCR[SENS2_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
	PORTA->PCR[SENS2_PIN] |= PORT_PCR_IRQC(0b1001); // Set up the IRQC to interrupt rising edge

	//SENS3
	PORTA->PCR[SENS3_PIN] &= ~PORT_PCR_MUX(0b001); // Clear PCR Mux bits for PTC3
	PORTA->PCR[SENS3_PIN] |= PORT_PCR_MUX(1); // Set up PTC3 as GPIO
	PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SENS3_PIN); // make it input
	PORTA->PCR[SENS3_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
	PORTA->PCR[SENS3_PIN] |= PORT_PCR_IRQC(0b1001); // Set up the IRQC to interrupt rising edge

	//SENS4
	PORTA->PCR[SENS4_PIN] &= ~PORT_PCR_MUX(0b001); // Clear PCR Mux bits for PTC3
	PORTA->PCR[SENS4_PIN] |= PORT_PCR_MUX(1); // Set up PTC3 as GPIO
	PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SENS4_PIN); // make it input
	PORTA->PCR[SENS4_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
	PORTA->PCR[SENS4_PIN] |= PORT_PCR_IRQC(0b1001); // Set up the IRQC to interrupt rising edge

	//SENS5
	PORTA->PCR[SENS5_PIN] &= ~PORT_PCR_MUX(0b001); // Clear PCR Mux bits for PTC3
	PORTA->PCR[SENS5_PIN] |= PORT_PCR_MUX(1); // Set up PTC3 as GPIO
	PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SENS5_PIN); // make it input
	PORTA->PCR[SENS5_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
	PORTA->PCR[SENS5_PIN] |= PORT_PCR_IRQC(0b1001); // Set up the IRQC to interrupt rising edge

	//SENS6
	PORTA->PCR[SENS6_PIN] &= ~PORT_PCR_MUX(0b001); // Clear PCR Mux bits for PTC3
	PORTA->PCR[SENS6_PIN] |= PORT_PCR_MUX(1); // Set up PTC3 as GPIO
	PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SENS6_PIN); // make it input
	PORTA->PCR[SENS6_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
	PORTA->PCR[SENS6_PIN] |= PORT_PCR_IRQC(0b1001); // Set up the IRQC to interrupt rising edge

	//SENS7
	PORTA->PCR[SENS7_PIN] &= ~PORT_PCR_MUX(0b001); // Clear PCR Mux bits for PTC3
	PORTA->PCR[SENS7_PIN] |= PORT_PCR_MUX(1); // Set up PTC3 as GPIO
	PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SENS7_PIN); // make it input
	PORTA->PCR[SENS7_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
	PORTA->PCR[SENS7_PIN] |= PORT_PCR_IRQC(0b1001); // Set up the IRQC to interrupt rising edge

	//SENS8
	PORTA->PCR[SENS8_PIN] &= ~PORT_PCR_MUX(0b001); // Clear PCR Mux bits for PTC3
	PORTA->PCR[SENS8_PIN] |= PORT_PCR_MUX(1); // Set up PTC3 as GPIO
	PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SENS8_PIN); // make it input
	PORTA->PCR[SENS8_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
	PORTA->PCR[SENS8_PIN] |= PORT_PCR_IRQC(0b1001); // Set up the IRQC to interrupt rising edge

	//SENS9
	PORTA->PCR[SENS9_PIN] &= ~PORT_PCR_MUX(0b001); // Clear PCR Mux bits for PTC3
	PORTA->PCR[SENS9_PIN] |= PORT_PCR_MUX(1); // Set up PTC3 as GPIO
	PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SENS9_PIN); // make it input
	PORTA->PCR[SENS9_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
	PORTA->PCR[SENS9_PIN] |= PORT_PCR_IRQC(0b1001); // Set up the IRQC to interrupt rising edge

	NVIC_EnableIRQ(PORTA_IRQn);
}

void toggleLED(int LED_number){
	PTE->PTOR |= GPIO_PTOR_PTTO(1 << LED_number); // toggle it
}

void LEDOff(int LED_number){
	PTE->PCOR |= GPIO_PCOR_PTCO(1 << LED_number); //turn it off
}
/*
 Used for testing the sensor interrupts

void PORTA_IRQHandler(void){
	if(PORTA->PCR[SENS1_PIN] & PORT_PCR_ISF(1)){
		toggleLED(LED1_PIN);
		PORTA->PCR[SENS1_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS2_PIN] & PORT_PCR_ISF(1)){
		toggleLED(LED2_PIN);
		PORTA->PCR[SENS2_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS3_PIN] & PORT_PCR_ISF(1)){
		toggleLED(LED3_PIN);
		PORTA->PCR[SENS3_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS4_PIN] & PORT_PCR_ISF(1)){
		toggleLED(LED4_PIN);
		PORTA->PCR[SENS4_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS5_PIN] & PORT_PCR_ISF(1)){
		toggleLED(LED5_PIN);
		PORTA->PCR[SENS5_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS6_PIN] & PORT_PCR_ISF(1)){
		toggleLED(LED6_PIN);
		PORTA->PCR[SENS6_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS7_PIN] & PORT_PCR_ISF(1)){
		toggleLED(LED7_PIN);
		PORTA->PCR[SENS7_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS8_PIN] & PORT_PCR_ISF(1)){
		toggleLED(LED8_PIN);
		PORTA->PCR[SENS8_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS9_PIN] & PORT_PCR_ISF(1)){
		toggleLED(LED9_PIN);
		PORTA->PCR[SENS9_PIN] |= PORT_PCR_ISF(1);
	}
}

int main(){
	external_LED_Initalize();
	sensor_Initialize();
	while(1){
		__WFI();
	}

	return 0;
}
*/
