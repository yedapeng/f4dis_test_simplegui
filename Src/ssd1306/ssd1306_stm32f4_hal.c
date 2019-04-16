


#include "stm32f4xx_hal.h"
#include "main.h"

extern SPI_HandleTypeDef hspi2;

#define		SPI_TIMEOUT				100



void write_command(uint8_t comm)
{
	HAL_StatusTypeDef state;
	state = HAL_SPI_Transmit(&hspi2, &comm, 1, SPI_TIMEOUT);
}



void write_data(uint8_t *p_data, uint16_t len)
{
	HAL_StatusTypeDef state;
	HAL_SPI_Transmit(&hspi2, p_data, len, SPI_TIMEOUT);
}


//#define CS_Pin GPIO_PIN_12
//#define CS_GPIO_Port GPIOB
//#define RST_Pin GPIO_PIN_14
//#define RST_GPIO_Port GPIOB

void ssd1306_cs_low()
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
}


void ssd1306_cs_high()
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
}

void ssd1306_dc_low()
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
}


void ssd1306_dc_high()
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
}

void ssd1306_rst_low()
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
}


void ssd1306_rst_high()
{
	HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_SET);
}


