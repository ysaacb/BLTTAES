#include "cmdline.h"
#include "driver/gpio.h"
//*****************************************************************************
//
// Defines the maximum number of arguments that can be parsed.
//
//*****************************************************************************
#ifndef CMDLINE_MAX_ARGS
#define CMDLINE_MAX_ARGS        8
#endif



static void blink_led(void);
static uint8_t s_led_state = 0;

tCmdLineEntry g_psCmdTable[] =
{
 {"load\r\n",        blink_led,           " : Turn On/Of The load" },

 { 0,            0,                  0 }
};

//*****************************************************************************
//
// Command: load
//
// Turn on/off the loads.
//
//*****************************************************************************

static void blink_led(void)
{
    /* Set the GPIO level according to the state (LOW or HIGH)*/
    s_led_state = !s_led_state;
    gpio_set_level(2, s_led_state);
}
