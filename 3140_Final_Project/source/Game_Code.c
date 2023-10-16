
// include the files for the sensors and the files for the LCD
#include <timer.h>

//global variables:
int score = 0; //score of the player


/*
 * Main function implements the functions that give the instructions for the game
 */
main (){

	timer_setiup(); //sets up the timers

	//lcd.h functions:
	init_lcd();
	LED_Initialize();
	LEDGreen_Off();
	displayBegin();
	LEDRed_On();
	SW1SetUp();
	operate_switch_interrupts();

	/*
	 * if the user pressed the start button, the a count down occurs which is
	 * displayed on the display
	 */
	if (start == 1){
		Countdown(); //countsdown when start button is pressed
	}

	clock_t cycle_start = clock(); //the current clock cycle when started
	int secs = 0; //how many seconds the game has been running
	int sec_end = 120; //game lasts 120 seconds or 2 minutes


	do {
	  /*
	   * while the game is running, the lights of the sensors will go on and
	   * off for specific amounts of time until the timer for the game has
	   * reached 2 minutes
	   */

		//game mechanics:
		if (secs%6 ==0){
			//turn random light on
			if (secs !=0){
				//if light is still on, turn light off and decrease score
			}
		}

		if (secs%3 ==0 && secs>=3 && secs<=117){ //second light can't turn on at the beginning or end
			//turn another random light on
		}

		//if motion is detected from correct sensor, light turns off and score increases

		//if motion is detected from wrong sensor light turns off and score decreases

		//updating clock:
		clock_t difference = clock() - cycle_start;
		msec = difference * CLOCKS_PER_SEC;
		iterations++;

	} while ( msec < sec_end );




	//turn on light for end of game

	//display score variable - Display Digit

}
