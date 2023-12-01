
#include "keypad.h"

#include "main.h"

uint8_t keypad_map[4][4] = {
		{'1', '2', '3', 'A'},
		{'4', '5', '6', 'B'},
		{'7', '8', '9', 'C'},
		{'*', '0', '#', 'D'},
};

/**
 * @brief This functions initialize the functionality of the keypad
 */
void keypad_init(void)
{
	/* Set the rows high to be detected in the columns by rising interrupt */
	ROW_1_GPIO_Port->BSRR = ROW_1_Pin;
	ROW_2_GPIO_Port->BSRR = ROW_2_Pin;
	ROW_3_GPIO_Port->BSRR = ROW_3_Pin;
	ROW_4_GPIO_Port->BSRR = ROW_4_Pin;
}

uint8_t keypad_get_row(GPIO_TypeDef *COLUMN_x_GPIO_Port, uint16_t COLUMN_x_Pin)
{
	uint8_t row_pressed = 0xFF;

	ROW_1_GPIO_Port->BSRR = ROW_1_Pin; // turn on row 1
	ROW_2_GPIO_Port->BRR = ROW_2_Pin;  // turn off row 2
	ROW_3_GPIO_Port->BRR = ROW_3_Pin;  // turn off row 3
	ROW_4_GPIO_Port->BRR = ROW_4_Pin;  // turn off row 4
	HAL_Delay(2); // wait for voltage to establish
	if (COLUMN_x_GPIO_Port->IDR & COLUMN_x_Pin) {
		row_pressed = 0x00; // if column 1 is still high -> column 1 + row 1 = key 1
	}

	ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
	ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2
	HAL_Delay(2); // wait for voltage to establish
	if (COLUMN_x_GPIO_Port->IDR & COLUMN_x_Pin) {
		row_pressed = 0x01; // if column 1 is still high -> column 1 + row 2 = key 4
	}

	ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
	ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3
	HAL_Delay(2); // wait for voltage to establish
	if (COLUMN_x_GPIO_Port->IDR & COLUMN_x_Pin) {
		row_pressed = 0x02; // if column 1 is still high -> column 1 + row 3 = key 7
	}

	ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
	ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4
	HAL_Delay(2); // wait for voltage to establish
	if (COLUMN_x_GPIO_Port->IDR & COLUMN_x_Pin) {
		row_pressed = 0x03; // if column 1 is still high -> column 1 + row 4 = key *
	}

	keypad_init(); // set the columns high again
	return row_pressed;
}

/**
 * @brief  This function debounces and identify keypad events.
 * @param  column_to_evaluate: the column where the event happened.
 * @retval 0xFF -> invalid key. [0x00 - 0x0F] -> valid key.
 */
uint8_t keypad_handler(uint16_t column_to_evaluate)
{
	uint8_t key_pressed = 0xFF; // Value to return

	/*** Debounce the key press (remove noise in the key) ***/
#define KEY_DEBOUNCE_MS 300 /*!> Minimum time required for since last press */
	static uint32_t last_pressed_tick = 0;
	if (HAL_GetTick() <= (last_pressed_tick + KEY_DEBOUNCE_MS)) {
		// less than KEY_DEBOUNCE_MS since last press. Probably noise
		return key_pressed; // return 0xFF
	}
	last_pressed_tick = HAL_GetTick();

	uint8_t row = 0xFF;

	/*** Check in which column the event happened ***/
	switch (column_to_evaluate) {
	case COL_1_Pin:
		row = keypad_get_row(COL_1_GPIO_Port, COL_1_Pin);
		if (row != 0xFF) {
			key_pressed = keypad_map[row][0];
		}
	  break;

	case COL_2_Pin:
		row = keypad_get_row(COL_2_GPIO_Port, COL_2_Pin);
		if (row != 0xFF) {
			key_pressed = keypad_map[row][1];
		}
		break;

	case COL_3_Pin:
		row = keypad_get_row(COL_3_GPIO_Port, COL_3_Pin);
		if (row != 0xFF) {
			key_pressed = keypad_map[row][2];
		}
		break;

	case COL_4_Pin:
		row = keypad_get_row(COL_4_GPIO_Port, COL_4_Pin);
		if (row != 0xFF) {
			key_pressed = keypad_map[row][3];
		}
		break;

	/*!\ TODO: Implement other column cases here */

	default:
		/* This should not be reached */
	  break;
	}

	return key_pressed; // invalid: 0xFF, valid:[0x00-0x0F]
}
