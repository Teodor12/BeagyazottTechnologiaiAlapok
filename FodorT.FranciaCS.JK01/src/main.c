//=========================================================
// src/beta_kilometerora_main.c: generated by Hardware Configurator
//
// This file will be updated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Display.h"


// $[Generated Includes]
// [Generated Includes]$

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{
  // $[SiLabs Startup]
  // [SiLabs Startup]$

}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------

#define TIMER2_FREQ_HZ   ((uint16_t ) 63802)

#define TIMER2_PERIOD_S  ((float)     (1.0 / TIMER2_FREQ_HZ))

#define M_PI ((float) 3.14159265358979323846)

#define WHEEL_RADIUS_M ((float) 0.035)

#define WHEEL_CIRCUMFERENCE_M (2 * WHEEL_RADIUS_M * M_PI)

volatile uint8_t digit_array[4];
volatile bool g_digits_ready = false;

volatile bool g_time_measurement_ready = false;
volatile uint16_t g_tick_counter = 0;
volatile bool g_moving = false;

volatile bool g_button_pressed = false;

int main (void)
{
  static float period = 0.0;
  static float temp_period = 0.0;
  static float speed = 0.0;

  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();

  IE_EA = 0;
  decoder_init();
  shift_register_init();
  IE_EA = 1;

  while (1) 
  {
      if(g_button_pressed == true)
      {
          P1_B4 = !P1_B4;
          g_button_pressed = false;
      }

      if(g_time_measurement_ready == true)
      {
          period = g_tick_counter * TIMER2_PERIOD_S;
          g_time_measurement_ready = false;
      }

      if(g_digits_ready == false)
      {
          temp_period = period;

          if(g_moving)
          {
        	  //Convert period (s) to km/h
        	  speed = ((WHEEL_CIRCUMFERENCE_M / temp_period) * 3.6);
          }
          else
          {
        	  speed = 0.0;
          }

          get_digits_of_number(speed, digit_array);
          g_digits_ready = true;
      }
  }                             
}
