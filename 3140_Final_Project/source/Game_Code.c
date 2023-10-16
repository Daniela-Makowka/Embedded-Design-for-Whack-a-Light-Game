
// include the files for the sensors and the files for the LCD
#include "button_LCD.h"
#include "LED.h"
#include "sensor.h"
#include "lcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <MKL46Z4.h>

//global variables:
int score = 0; //score of the player
int sensor_first = 0; //first sensor that is on
int sensor_second = 0; //second sensor that is on
int first_on = 0; // if first light is on, the variable is 1
int second_on = 0; // if second light is on, the variable is 1
volatile int secs = 0;//how many seconds the game has been running

void Decrease_Score (void);
void Display_Score (void);

//Helper Functions:

/*
 * Selects a random LED to turn on that is not already on and returns the LED
 * that is being turned on
 */
int Rand_LED_ON(void){

	int rand_LED = (rand() % (8)) + 1; //the random LED that will be selected

	if (rand_LED==1){
		return LED8_PIN;
	}
	else if (rand_LED==2){
		return LED2_PIN;
	}
	else if (rand_LED==3){
		return LED3_PIN;
	}
	else if (rand_LED==4){
		return LED4_PIN;
	}
	else if (rand_LED==5){
		return LED5_PIN;
	}
	else if (rand_LED==6){
		return LED6_PIN;
	}
	else if (rand_LED==7){
		return LED7_PIN;
	}
	else{
		return LED9_PIN;
	}
}

/*
 * IRQ Handler for checking whether the user waved their hand in front of the light
 */
void PORTA_IRQHandler(void){
	if(PORTA->PCR[SENS2_PIN] & PORT_PCR_ISF(1)){
		// check if the any of the sensors detected motion:
				if (LED2_PIN == sensor_first && start==1){ //user activates the first correct sensor
					score = score +5;
					LEDOff(LED2_PIN);
					first_on = 0; //first light is off
					Display_Score();
				}
				else if (LED2_PIN == sensor_second && start==1){//user activates the second correct sensor
					score = score +5;
					LEDOff(LED2_PIN);
					second_on = 0; //second light is off
					Display_Score();
				}
				else if(start==1){ //user activated wrong sensor
					Decrease_Score();
					Display_Score();
				}
				PORTA->PCR[SENS2_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS3_PIN] & PORT_PCR_ISF(1)){
		// check if the any of the sensors detected motion:
				if (LED3_PIN == sensor_first && start==1){ //user activates the first correct sensor
					score = score +5;
					LEDOff(LED3_PIN);
					first_on = 0; //first light is off
					Display_Score();
				}
				else if (LED3_PIN == sensor_second && start==1){//user activates the second correct sensor
					score = score +5;
					LEDOff(LED3_PIN);
					second_on = 0; //second light is off
					Display_Score();
				}
				else if (start==1){ //user activated wrong sensor
					Decrease_Score();
					Display_Score();
				}
				PORTA->PCR[SENS3_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS4_PIN] & PORT_PCR_ISF(1)){
		// check if the any of the sensors detected motion:
				if (LED4_PIN == sensor_first && start==1){ //user activates the first correct sensor
					score = score +5;
					LEDOff(LED4_PIN);
					first_on = 0; //first light is off
					Display_Score();
				}
				else if (LED4_PIN == sensor_second && start==1){//user activates the second correct sensor
					score = score +5;
					LEDOff(LED4_PIN);
					second_on = 0; //second light is off
					Display_Score();
				}
				else if(start==1){ //user activated wrong sensor
					Decrease_Score();
					Display_Score();
				}
				PORTA->PCR[SENS4_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS5_PIN] & PORT_PCR_ISF(1)){
		// check if the any of the sensors detected motion:
				if (LED5_PIN == sensor_first && start==1){ //user activates the first correct sensor
					score = score +5;
					LEDOff(LED5_PIN);
					first_on = 0; //first light is off
					Display_Score();
				}
				else if (LED5_PIN == sensor_second && start==1){//user activates the second correct sensor
					score = score +5;
					LEDOff(LED5_PIN);
					second_on = 0; //second light is off
					Display_Score();
				}
				else if(start==1){ //user activated wrong sensor
					Decrease_Score();
					Display_Score();
				}
				PORTA->PCR[SENS5_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS6_PIN] & PORT_PCR_ISF(1)){
		// check if the any of the sensors detected motion:
				if (LED6_PIN == sensor_first && start==1){ //user activates the first correct sensor
					score = score +5;
					LEDOff(LED6_PIN);
					first_on = 0; //first light is off
					Display_Score();
				}
				else if (LED6_PIN == sensor_second && start==1){//user activates the second correct sensor
					score = score +5;
					LEDOff(LED6_PIN);
					second_on = 0; //second light is off
					Display_Score();
				}
				else if (start==1){ //user activated wrong sensor
					Decrease_Score();
					Display_Score();
				}
				PORTA->PCR[SENS6_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS7_PIN] & PORT_PCR_ISF(1)){
		// check if the any of the sensors detected motion:
				if (LED7_PIN == sensor_first && start==1){ //user activates the first correct sensor
					score = score +5;
					LEDOff(LED7_PIN);
					first_on = 0; //first light is off
					Display_Score();
				}
				else if (LED7_PIN == sensor_second && start==1){//user activates the second correct sensor
					score = score +5;
					LEDOff(LED7_PIN);
					second_on = 0; //second light is off
					Display_Score();
				}
				else if(start==1){ //user activated wrong sensor
					Decrease_Score();
					Display_Score();
				}
				PORTA->PCR[SENS7_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS8_PIN] & PORT_PCR_ISF(1)){
		// check if the any of the sensors detected motion:
				if (LED8_PIN == sensor_first && start==1){ //user activates the first correct sensor
					score = score +5;
					LEDOff(LED8_PIN);
					first_on = 0; //first light is off
					Display_Score();
				}
				else if (LED8_PIN == sensor_second && start==1){//user activates the second correct sensor
					score = score +5;
					LEDOff(LED8_PIN);
					second_on = 0; //second light is off
					Display_Score();
				}
				else if(start==1){ //user activated wrong sensor
					Decrease_Score();
					Display_Score();
				}
				PORTA->PCR[SENS8_PIN] |= PORT_PCR_ISF(1);
	}
	else if(PORTA->PCR[SENS9_PIN] & PORT_PCR_ISF(1)){
		// check if the any of the sensors detected motion:
				if (LED9_PIN == sensor_first && start==1){ //user activates the first correct sensor
					score = score +5;
					LEDOff(LED9_PIN);
					first_on = 0; //first light is off
					Display_Score();
				}
				else if (LED9_PIN == sensor_second && start==1){//user activates the second correct sensor
					score = score +5;
					LEDOff(LED9_PIN);
					second_on = 0; //second light is off
					Display_Score();
				}
				else if(start==1){ //user activated wrong sensor
					Decrease_Score();
					Display_Score();
				}
				PORTA->PCR[SENS9_PIN] |= PORT_PCR_ISF(1);
	}
}

/*
 * Displays the current score
 */
void Display_Score(void){
	int thousands_place = score/1000;
	int hundreds_place = (score - thousands_place*1000)/100;
	int tens_place = (score- thousands_place*1000 - hundreds_place*100)/10;
	int ones_place = (score- thousands_place*1000 - hundreds_place*100- tens_place*10);

	displayDigit(1, thousands_place);
	displayDigit(2, hundreds_place);
	displayDigit(3, tens_place);
	displayDigit(4, ones_place);
}

/*
 * Decreases the score
 * Checks if score is 0; If score is already 0, leave score as 0
 */
void Decrease_Score (void){
	if (score != 0){
		score = score -1;
	}
	else{ // there can't be negative score
		score = 0;
	}
}

/*
 * Occurs when time is up for the first light
 * Checks whether the user has turned off the light in time
 * Turns on the next light
 */
void First_Light_Change(){
	if (first_on !=0){ //user failed to turn light off in time
		//Decrease_Score();
		LEDOff(sensor_first);
		Display_Score();
	}
	int temp_sensor=Rand_LED_ON();
	while(temp_sensor == sensor_second){ //ensures that both sensor_second and sensor_first are not equal
		temp_sensor =Rand_LED_ON();
	}
	sensor_first = temp_sensor;//turn random first light on
	toggleLED(sensor_first);
	first_on =1;
}

/*
 * Occurs when time is up for the second light
 * Checks whether the user has turned off the light in time
 * Turns on the next light
 */
void Second_Light_Change(){
	if (second_on !=0){ //user failed to turn light off in time
		//Decrease_Score();
		LEDOff(sensor_second);
		Display_Score();
	}
	int temp_sensor=Rand_LED_ON();
	while(temp_sensor == sensor_first){ //ensures that both sensor_second and sensor_first are not equal
		temp_sensor =Rand_LED_ON();
	}
	sensor_second = temp_sensor;//turn random second light on
	toggleLED(sensor_second);
	second_on =1;
}




/*
 * Main function implements the functions that give the instructions for the game
 */
void main (){

	//lcd.h functions:
  	init_lcd();
	LED_Initialize();
	LEDGreen_Off();
	displayBegin();
	LEDRed_On();
	SW1SetUp();
	operate_switch_interrupts();

	  NVIC_EnableIRQ(PIT_IRQn);
	  /* enable PIT Interrupts (for part 3) */

	  //Enable the PIT
	  SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
	  PIT->MCR &= ~(1 << 1);   //Enable Clock for PIT Timers
	  //0x989680 fast
	  PIT->CHANNEL[0].LDVAL = 0x688F80; // Set load value of zeroth PIT (.9 seconds)
	  PIT->CHANNEL[0].TCTRL |= (1 << 0); //Enable Timer
	  PIT->CHANNEL[0].TCTRL |= (1 << 1); //Enable Timer

	//initialize sensors:
	external_LED_Initalize();
	sensor_Initialize();


	while (start == 0){ //count down is displayed when start button is pressed
	}

	int sec_end =160; //game lasts 120 seconds or 2 minutes

	/*
	* while the game is running, the lights of the sensors will go on and
	* off for specific amounts of time until the timer for the game has
	* reached 2 minutes
	*/
	while(secs < sec_end){
		//game mechanics:
		if (secs%6 ==0){ //first light
			First_Light_Change();
		}
		else if (secs%3 ==0 && secs<157){ //second light; can't turn on at the last three seconds
			Second_Light_Change();
		}
	}

	//Green light turns off and red light turns on, signaling the game is no longer running:
	LEDGreen_Off ();
	LEDRed_On();

	Display_Score();

	LEDOff(LED2_PIN);
	LEDOff(LED3_PIN);
	LEDOff(LED4_PIN);
	LEDOff(LED5_PIN);
	LEDOff(LED6_PIN);
	LEDOff(LED7_PIN);
	LEDOff(LED8_PIN);
	LEDOff(LED9_PIN);
	start=0;
	while(1){}

}

void PIT_IRQHandler(void)
{
	if (start==1){
		secs ++;
	}
	PIT->CHANNEL[0].TFLG |= (1 << 0); //Reset Flag
}


