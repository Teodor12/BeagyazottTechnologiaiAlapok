//=========================================================
// src/FodorTFranciaCS.JK01.Display_main.c: generated by Hardware Configurator
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
#include "Display.h"
// $[Generated Includes]
// [Generated Includes]$

static uint16_t number = 12U;
volatile uint8_t digit_array[4];
volatile bool g_digits_ready = false;

void SiLabs_Startup (void)
{
  // $[SiLabs Startup]
  // [SiLabs Startup]$
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();

  IE_EA = 0;
  decoder_init();
  shift_register_init();
  IE_EA = 1;

  while (1) 
  {
      if(g_digits_ready == false)
      {
          get_digits_of_number(number, digit_array);
          g_digits_ready = true;
      }

  }                             
}
