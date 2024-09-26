#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

/**
 * @brief Initializes the decoder-IC.
 *
 * This function initializes the decoder, bringing it back to its default state.
 *
 */
void decoder_init(void);

/**
 * @brief Initializes the shift register.
 *
 * This function initializes the shift register, clearing its
 * contents and bringing it back to its initial state.
 *
 */
void shift_register_init(void);

/**
 * @brief Selects the display for output.
 *
 * This function selects the display specified by the index, allowing
 * data to be sent to that particular display. The display index refers to
 * the specific display being targeted when using a multiplexed setup.
 *
 * @param display_idx The index of the display to be selected.
 */
void select_display(uint8_t display_idx);

/**
 * @brief Sends data to the shift register.
 *
 * This function sends an 8-bit value to the shift register for output. The
 * value is typically used to control which segments of a display are activated.
 *
 * @param value The 8-bit value to send to the shift register.
 */
void send_to_shift_register (uint8_t value);

/**
 * @brief Retrieves a specific digit from a number.
 *
 * This function extracts a digit from a given number based on the digit index.
 * The digit index starts from 0 for the least significant digit.
 *
 * @param number The number from which to extract the digit.
 * @param digit_idx The index of the digit to retrieve (0 for least significant digit).
 * @return The digit at the specified index.
 */
uint8_t get_digit_of_number(uint16_t number, uint8_t digit_idx);

/**
 * @brief Extracts all digits from a number.
 *
 * This function extracts up to 4 digits from a given number and stores them
 * in the provided array.
 *
 * @param number The number from which to extract the digits (up to 4 digits).
 * @param digit_array An array of size 4 to store the extracted digits.
 */
void get_digits_of_number(uint16_t number, uint8_t digit_array[4]);

#endif
