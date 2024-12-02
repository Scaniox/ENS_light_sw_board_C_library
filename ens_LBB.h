/*******************************************************************************
 *         File: lib\ENS_LED_Button_lib\ens_LBB.h
 *       Author: Alexander Mills (am9g22)
 *         Date: 2024-12-02 17:37:34
 *  Description: main header file that declares the interface for the LED
 *               button board
 ******************************************************************************/

#ifndef LIB_ENS_LED_BUTTON_LIB_ENS_LBB_H_
#define LIB_ENS_LED_BUTTON_LIB_ENS_LBB_H_

#include <stdbool.h>
#include <stdint.h>


/**
 *  @brief set up the led button board on a paticular port eg port a: ```lbb_setup(&PORTA)```
 *  @param port device port the ENS LB Board is attached to 
 *  @warning give the pointer to the port register, not the value of the register by using &
 */
void lbb_setup(uint8_t* port);


/**
 * @brief turn on or off an LED on the board
 * @param led_num the led number, as listed on the board's silk screen (1 based counting)
 * @param value bool to set the LED to on or off
 */
void lbb_set_led_status(int led_num, bool value);

/**
 * @brief get the current state of an LED on the board
 * @param led_num the led number, as listed on the board's silk screen (1 based counting)
 * @return returns bool of if LED is on or not
 */
bool lbb_get_led_status(int led_num);

/**
 * @brief get the current state of a button on the board
 * @param led_num the button number, as listed on the board's silk screen (1 based counting)
 * @return returns bool of if button is pressed or not
 */
bool lbb_get_button_state(int button_num);

#endif // LIB_ENS_LED_BUTTON_LIB_ENS_LBB_H_