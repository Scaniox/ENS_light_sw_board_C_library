ENS_LED_Button Library (ENS_LBB.c)
This library provides functions for interfacing with an LED and Button board for your ENS coursework.

## Features
- Configures LED and Button pins on Ports A, B, C, or D
- Controls individual LED status (on/off)
- Reads individual button state (pressed/not pressed)
- Performs basic sanity checks on pin numbers
## Usage
### Initialization:
1) Copy the ```ens_LBB.c``` and ```ens_LBB.h``` files to your project directory.
2) Include ```ens_LBB.h``` in your code files where you want to use the library functions.
```C
#include "ens_LBB.h"

int main(void) {
    lbb_setup(&PORTA);
    ...
}
```
### LED Control:
```C
// Turn on LED 2
lbb_set_led_status(2, true);

// Turn off LED 1
lbb_set_led_status(1, false);

// Check if LED 3 is on
bool led_3_on = lbb_get_led_status(3);
```

### Button Reading:
```C
// Check if button 1 is pressed
bool button_1_pressed = lbb_get_button_state(1);

// Check if button 4 is pressed
bool button_4_pressed = lbb_get_button_state(4);
```