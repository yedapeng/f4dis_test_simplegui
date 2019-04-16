


#ifndef	__SSD1306_STM32F4_HAL_H
#define __SSD1306_STM32F4_HAL_H



void write_command(uint8_t comm);
void write_data(uint8_t *p_data, uint16_t len);


#endif		/* __SSD1306_STM32F4_HAL_H */



