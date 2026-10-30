/**
 * @file main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 1

int main(void) {
  if (0 > BTN_init()) {
    return 0;
  }
  if (0 > LED_init()) {
    return 0;
  }

  // Exercise: combine serial output with breakpoints
  // ------------------------------CODE START------------------------------
  int one = 1;
  int two = 2;

  printk("one current value is: %d\n", one);
  one += two;
  printk("one after calc. value is: %d??? /j XD\n", one);
  // ------------------------------CODE END-------------------------------- 

  while (1) {
    printk("Entered loop!\n");

    // Example: finding a null string pointer
    // Q. What happened?
    // A. The printk statement below printed "(null)"
    // - This is dependent on:the C library and console implementation
    // ------------------------------CODE START------------------------------
    // const char *status = NULL;
    // bool button_pressed = false; // added this to initialize variable

    // if (button_pressed) {
    //   status = "Button pressed";
    // }
    // ------------------------------CODE END-------------------------------- 


    // Fixing Example: finding a null string pointer
    // Q. How did I fix?
    // A. Initialized "status" to "Idle", so no null reference error happens!
    // ------------------------------CODE START------------------------------
    const char *status = "Idle";
    bool button_pressed = false; // added this to initialize variable

    if (button_pressed) {
      status = "Button pressed";
    }

    printk("Status: %s\n", status);
    // ------------------------------CODE END-------------------------------- 

    k_msleep(SLEEP_MS);
  }
  return 0;
}
