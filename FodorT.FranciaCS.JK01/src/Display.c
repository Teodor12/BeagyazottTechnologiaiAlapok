#include <SI_EFM8BB1_Register_Enums.h>

#include "Display.h"

#define DECODER_A P1_B1
#define DECODER_B P1_B2
#define DECODER_C P0_B4

void decoder_init(void)
{

  /* Setting the pins to outputmode "push-pull" */
  P1MDOUT |= (1U << P0MDOUT_B1__SHIFT);
  P1MDOUT |= (1U << P0MDOUT_B2__SHIFT);
  P0MDOUT |= (1U << P0MDOUT_B4__SHIFT);

  DECODER_A = 0;
  DECODER_B = 0;
  DECODER_C = 0;
}

static const uint8_t BCD_CODES[11] = {
      0x3F, // 0
      0x06, // 1
      0x5B, // 2
      0x4F, // 3
      0x66, // 4
      0x6D, // 5
      0x7D, // 6
      0x07, // 7
      0x7F, // 8
      0x6F, // 9
};

#define DISP_CLK P0_B0
#define DISP_DATA P0_B2
#define DISP_OE_RCLK P0_B3

void shift_register_init(void)
{
  /* Setting the pins to outputmode "push-pull" */
  P0MDOUT |= (1U << P0MDOUT_B0__SHIFT);
  P0MDOUT |= (1U << P0MDOUT_B2__SHIFT);
  P0MDOUT |= (1U << P0MDOUT_B3__SHIFT);

  DISP_CLK = 0;
  DISP_DATA = 0;
  DISP_OE_RCLK = 1;
}

void select_display(uint8_t display_idx)
{
    switch(display_idx)
    {
      case 0:
      {
        DECODER_A = 0;
        DECODER_B = 0;
        break;
      }
      case 1:
      {
        DECODER_A = 1;
        DECODER_B = 0;
        break;
      }
      case 2:
      {
        DECODER_A = 0;
        DECODER_B = 1;
        break;
      }
      case 3:
      {
        DECODER_A = 1;
        DECODER_B = 1;
        break;
      }
    }
}




void send_to_shift_register (uint8_t value)
{
  uint8_t idx;
  uint8_t bcd_code = BCD_CODES[value];
  for (idx = 0; idx < 8; idx++)
   {
        DISP_DATA = ((~(bcd_code) >> (7 - idx)) & 1U); //getting the bits 1-by-1 from THE MSB
        DISP_CLK = 1; //rising edge
        DISP_CLK = 0;
    }
    //Creating a clock pulse on the output enable line
    DISP_OE_RCLK = 1; //rising edge for RCLK
    DISP_OE_RCLK = 0; //reset the data line
}

#define TEN_POW_3 ((uint16_t) 1000U)
#define TEN_POW_2 ((uint16_t) 100U)
#define TEN_POW_1 ((uint16_t) 10U)

uint8_t get_digit_of_number(uint16_t number, uint8_t digit_index)
{
    uint8_t value = 0U;
    switch (digit_index)
    {
      case 0:
      {
        value = ((uint8_t) (number / TEN_POW_3));
        break;
      }
      case 1:
      {
        value = ((uint8_t) ((number % TEN_POW_3) / TEN_POW_2));
        break;
      }
      case 2:
      {
        value = ((uint8_t) ((number % TEN_POW_2) / TEN_POW_1));
        break;
      }
      case 3:
      {
        value =  ((uint8_t) (number % TEN_POW_1));
        break;
      }

    }

    return value;
}

void get_digits_of_number(uint16_t number, uint8_t digit_array[4])
{
  digit_array[3] = ((uint8_t) number % TEN_POW_1);
  number /= TEN_POW_1;

  digit_array[2] = ((uint8_t) number % TEN_POW_1);
  number /= TEN_POW_1;

  digit_array[1] = ((uint8_t) number % TEN_POW_1);
  number /= TEN_POW_1;

  digit_array[0] = ((uint8_t) number % TEN_POW_1);
}




