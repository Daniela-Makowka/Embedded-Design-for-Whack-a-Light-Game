#ifndef BUTTON_LCD_H_
#define BUTTON_LCD_H_

extern int start;
extern const int SWITCH_1_PIN;
//extern PORT_Type* global_PORTC;
//extern GPIO_Type* global_PTC;

//Enabling interuppts for SW1
void operate_switch_interrupts();

//Handler for SW1 - helps with starting the game
void PORTC_PORTD_IRQHandler(void);

//Configuration for SW1
void SW1SetUp(void);

//Countdown for the LCD display starting from 5 seconds
void Countdown(void);

//Displays the word Go on LCD
void displayGo(void);

//Displays the word Begin on LCD
void displayBegin(void);

#endif
