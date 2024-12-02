/*******************************************************************************
 *         File: lib\ENS_LED_Button_lib\ens_LBB.c
 *       Author: Alexander Mills (am9g22)
 *         Date: 2024-12-02 17:37:34
 *  Description: main file that defines the interface for the LED
 *               button board
 ******************************************************************************/
#include "ens_LBB.h"
#include "avr/common.h"
#include "avr/io.h"
#include <stdbool.h>

volatile uint8_t* lbb_port_reg;
volatile uint8_t* lbb_pin_reg;
volatile uint8_t* lbb_ddr_reg;

bool is_valid_pin(int dev_num) {
    if ((dev_num > 4) || (dev_num < 1)) {
        // not a valid number
        return false;
    } else {
        return true;
    }
}

void lbb_setup(uint8_t* port) {
    lbb_port_reg = port;

    switch ((uint16_t)lbb_port_reg)
    {
    case (uint16_t)&PORTA:
        lbb_pin_reg = &PINA;
        lbb_ddr_reg = &DDRA;
        break;
    case (uint16_t)&PORTB:
        lbb_pin_reg = &PINB;
        lbb_ddr_reg = &DDRB;
        break;
    case (uint16_t)&PORTC:
        lbb_pin_reg = &PINC;
        lbb_ddr_reg = &DDRC;
        break;
    case (uint16_t)&PORTD:
        lbb_pin_reg = &PIND;
        lbb_ddr_reg = &DDRD;
        break;
    
    default:
        break;
    }

    *lbb_ddr_reg = _BV(PINA0) | _BV(PINA2) | _BV(PINA4) | _BV(PINA6);
    *lbb_port_reg = 0xff;
}

void lbb_set_led_status(int led_num, bool value) {
    if (!is_valid_pin(led_num)) return;

    if (!value) {
        *lbb_port_reg |= 1 << ((led_num - 1) * 2);
    } else {
        *lbb_port_reg &= ~(1 << ((led_num - 1) * 2));
    }
}

bool lbb_get_led_status(int led_num) {
    if (!is_valid_pin(led_num)) return false;

    return (*lbb_port_reg & (1 << ((led_num - 1) * 2))) ? false : true;
}

bool lbb_get_button_state(int button_num) {
    if (!is_valid_pin(button_num)) return false;

    return (*lbb_pin_reg & (1 << ((button_num-1) * 2 + 1))) ? false : true;
}
