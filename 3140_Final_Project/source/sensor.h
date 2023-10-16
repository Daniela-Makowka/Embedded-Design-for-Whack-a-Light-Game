//All sensors are on port A (PTA)
const extern int SENS1_PIN;
const extern int SENS2_PIN;
const extern int SENS3_PIN;
const extern int SENS4_PIN;
const extern int SENS5_PIN;
const extern int SENS6_PIN;
const extern int SENS7_PIN;
const extern int SENS8_PIN;
const extern int SENS9_PIN;

//All LEDs are on port E
const extern int LED1_PIN;
const extern int LED2_PIN;
const extern int LED3_PIN;
const extern int LED4_PIN;
const extern int LED5_PIN;
const extern int LED6_PIN;
const extern int LED7_PIN;
const extern int LED8_PIN;
const extern int LED9_PIN;

/*
Method to initialize all of the sensors
Sensors are on pins 2,7,12,5,13,6,14,15,17 of port A
*/
void sensor_Initialize(void);

/*
Method to initialize all of the LEDS
Lets are on pin 31,19,18,17,16,6,3,2,20 of port E
 */
void external_LED_Initalize(void);

/*
 * Toggles LED with pin number LED_number
 */
void toggleLED(int LED_number);

/*
 * Turns an LED off
 */
void LEDOff(int LED_number);
