//=========================================================
// src/Interrupts.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB1_Register_Enums.h>
#include <LIMITS.h>
#include "Display.h"


volatile uint16_t timer2_counter = 0;
extern bool g_moving;
SI_INTERRUPT (TIMER2_ISR, TIMER2_IRQn)
{
	TMR2CN0_TF2H = 0;
	timer2_counter++;

	if(timer2_counter == UINT_MAX)
	{
		g_moving = false;
	}
}

extern bool g_time_measurement_ready;
extern uint16_t g_tick_counter;
SI_INTERRUPT (INT0_ISR, INT0_IRQn)
{
  static bool first_run = true;
	uint16_t temp_timer2_counter = 0;
	IE_ET2 = 0;
	temp_timer2_counter = timer2_counter;
	timer2_counter = 0;
	g_moving = true;
	IE_ET2 = 1;

	TCON_IE0 = 0;

	if (g_time_measurement_ready == false && first_run == false)
	{
		g_tick_counter = temp_timer2_counter;
		g_time_measurement_ready = true;
	}
  first_run = false;

}

extern volatile uint8_t digit_array[4];
extern volatile bool g_digits_ready;
SI_INTERRUPT (TIMER0_ISR, TIMER0_IRQn)
{
	static uint16_t timer_0_counter = 0U;
	static uint8_t current_digit;
	static uint8_t idx = 1;

	TCON_TF0 = 0;

	timer_0_counter++;
	if(timer_0_counter == 5 && g_digits_ready == true)
	{
	  send_to_shift_register(CLEAR_DISP_BCD);
		current_digit = digit_array[idx];
		select_display(idx);
		send_to_shift_register(current_digit);
		idx++;
		if(idx > 3)
		{
			idx = 2;
			g_digits_ready = false;
		}
		timer_0_counter = 0;
	}
}

#define SW2 P0_B7
#define DEBOUNCE_DELAY ((uint16_t) 50)
extern volatile bool g_button_pressed;

SI_INTERRUPT (TIMER1_ISR, TIMER1_IRQn)
{
	static uint16_t debounce_counter = 0U;
	static bool push_detected = false;

	TCON_TF1 = 0;

	if (SW2 == 0)
	{
	    if (debounce_counter < DEBOUNCE_DELAY)
	    {
	        debounce_counter++;
	    }
	    else if (push_detected == false)
	    {
	        g_button_pressed = true;
	        push_detected = true;
	    }
	}
	else
	{
	    debounce_counter = 0U;
	    push_detected = false;
	}

}
