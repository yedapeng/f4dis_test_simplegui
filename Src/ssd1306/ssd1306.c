
#include "ssd1306.h"



#define	SSD1306_DRV_STM32F4_HAL



#ifdef	SSD1306_DRV_STM32F4_HAL
#include "ssd1306_stm32f4_hal.h"
#endif

#define	OLED_COLOR_FRG		1

#define SET_PAGE_BIT(PAGE, Bit) ((PAGE) = (PAGE) | (0x01 << (Bit)))
#define CLR_PAGE_BIT(PAGE, Bit) ((PAGE) = (PAGE) & (~(0x01 << (Bit))))
#define	GET_PAGE_BIT(PAGE, Bit)	((PAGE>>Bit)&0x01)


#define	SSD1306_DISPLAY_SIZE_WIDTH		128
#define	SSD1306_DISPLAY_SIZE_PAGE			8
#define	SSD1306_DISPLAY_SIZE_HEIGHT		(SSD1306_DISPLAY_SIZE_PAGE*8)

static uint8_t ssd1306_display_buffer[SSD1306_DISPLAY_SIZE_WIDTH][SSD1306_DISPLAY_SIZE_PAGE];


static void ssd1306_WriteCommand(uint8_t command)
{
	//HAL_I2C_Mem_Write(&hi2c1,SSD1306_I2C_ADDR,0x00,1,&command,1,10);
	write_command(command);
}



uint8_t ssd1306_Init(void)
{	
	// Even wachten zodat het scherm zeker opgestart is
	//HAL_Delay(10);
	
	/* Init LCD */
	ssd1306_WriteCommand(0xAE); //display off
	ssd1306_WriteCommand(0x20); //Set Memory Addressing Mode   
	ssd1306_WriteCommand(0x10); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	ssd1306_WriteCommand(0xB0); //Set Page Start Address for Page Addressing Mode,0-7
	ssd1306_WriteCommand(0xC8); //Set COM Output Scan Direction
	ssd1306_WriteCommand(0x00); //---set low column address
	ssd1306_WriteCommand(0x10); //---set high column address
	ssd1306_WriteCommand(0x40); //--set start line address
	ssd1306_WriteCommand(0x81); //--set contrast control register
	ssd1306_WriteCommand(0xFF);
	ssd1306_WriteCommand(0xA1); //--set segment re-map 0 to 127
	ssd1306_WriteCommand(0xA6); //--set normal display
	ssd1306_WriteCommand(0xA8); //--set multiplex ratio(1 to 64)
	ssd1306_WriteCommand(0x3F); //
	ssd1306_WriteCommand(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	ssd1306_WriteCommand(0xD3); //-set display offset
	ssd1306_WriteCommand(0x00); //-not offset
	ssd1306_WriteCommand(0xD5); //--set display clock divide ratio/oscillator frequency
	ssd1306_WriteCommand(0xF0); //--set divide ratio
	ssd1306_WriteCommand(0xD9); //--set pre-charge period
	ssd1306_WriteCommand(0x22); //
	ssd1306_WriteCommand(0xDA); //--set com pins hardware configuration
	ssd1306_WriteCommand(0x12);
	ssd1306_WriteCommand(0xDB); //--set vcomh
	ssd1306_WriteCommand(0x20); //0x20,0.77xVcc
	ssd1306_WriteCommand(0x8D); //--set DC-DC enable
	ssd1306_WriteCommand(0x14); //
	ssd1306_WriteCommand(0xAF); //--turn on SSD1306 panel
	
	/* Clearen scherm */
	ssd1306_SetDisplay();
	
	/* Update screen */
	//ssd1306_UpdateScreen();
	
//	/* Set default values */
//	SSD1306.CurrentX = 0;
//	SSD1306.CurrentY = 0;
//	
//	/* Initialized OK */
//	SSD1306.Initialized = 1;
	
	/* Return OK */
	return 1;
}

void ssd1306_SetDisplay(void)
{
	uint32_t count = 0;
	uint8_t *p_data = (uint8_t*)ssd1306_display_buffer;
	for (; count < (SSD1306_DISPLAY_SIZE_WIDTH*SSD1306_DISPLAY_SIZE_PAGE); count ++)
	{
		p_data[count] = 0xFF;
	}
}

void ssd1306_ClearDisplay(void)
{
	uint32_t count = 0;
	uint8_t *p_data = (uint8_t*)ssd1306_display_buffer;
	for (; count < (SSD1306_DISPLAY_SIZE_WIDTH*SSD1306_DISPLAY_SIZE_PAGE); count ++)
	{
		p_data[count] = 0xff;
	}
}


void ssd1306_RefreshScreen(void)
{	
	uint8_t count;
	
	for (count = 0; count < SSD1306_DISPLAY_SIZE_PAGE; count++) 
	{
		ssd1306_WriteCommand(0xB0 + count);
		ssd1306_WriteCommand(0x00);
		ssd1306_WriteCommand(0x10);
		write_data(&ssd1306_display_buffer[0][count], SSD1306_DISPLAY_SIZE_WIDTH);
	}
}

void ssd1306_SetPixel(int uiPosX, int uiPosY, int eColor)
{
	if((uiPosX < SSD1306_DISPLAY_SIZE_WIDTH) && (uiPosY < SSD1306_DISPLAY_SIZE_HEIGHT))
	{
		// Set point data.
		if(OLED_COLOR_FRG == eColor)
		{
			SET_PAGE_BIT(ssd1306_display_buffer[uiPosY/8][uiPosX], uiPosY%8);
		}
		else
		{
			CLR_PAGE_BIT(ssd1306_display_buffer[uiPosY/8][uiPosX], uiPosY%8);
		}
	}
}

int ssd1306_GetPixel(int uiPosX, int uiPosY)
{
	if((uiPosX < SSD1306_DISPLAY_SIZE_WIDTH) && (uiPosY < SSD1306_DISPLAY_SIZE_HEIGHT))
	{
		return GET_PAGE_BIT(ssd1306_display_buffer[uiPosY/8][uiPosX], uiPosY%8);
	}
	else
	{
		return 0;
	}
}





//
//	We willen 1 char naar het scherm sturen
//	ch 		=> char om weg te schrijven
//	Font 	=> Font waarmee we gaan schrijven
//	color 	=> Black or White
//
//char ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color)
//{
//	uint32_t i, b, j;
//	
//	// Kijken of er nog plaats is op deze lijn
//	if (SSD1306_WIDTH <= (SSD1306.CurrentX + Font.FontWidth) ||
//		SSD1306_HEIGHT <= (SSD1306.CurrentY + Font.FontHeight))
//	{
//		// Er is geen plaats meer
//		return 0;
//	}
//	
//	// We gaan door het font
//	for (i = 0; i < Font.FontHeight; i++)
//	{
//		b = Font.data[(ch - 32) * Font.FontHeight + i];
//		for (j = 0; j < Font.FontWidth; j++)
//		{
//			if ((b << j) & 0x8000) 
//			{
//				ssd1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR) color);
//			} 
//			else 
//			{
//				ssd1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR)!color);
//			}
//		}
//	}
//	
//	// De huidige positie is nu verplaatst
//	SSD1306.CurrentX += Font.FontWidth;
//	
//	// We geven het geschreven char terug voor validatie
//	return ch;
//}

//
//	Functie voor het wegschrijven van een hele string
// 	str => string om op het scherm te schrijven
//	Font => Het font dat gebruikt moet worden
//	color => Black or White
//
//char ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color)
//{
//	// We schrijven alle char tot een nulbyte
//	while (*str) 
//	{
//		if (ssd1306_WriteChar(*str, Font, color) != *str)
//		{
//			// Het karakter is niet juist weggeschreven
//			return *str;
//		}
//		
//		// Volgende char
//		str++;
//	}
//	
//	// Alles gelukt, we sturen dus 0 terug
//	return *str;
//}

//
//	Zet de cursor op een coordinaat
//
//void ssd1306_SetCursor(uint8_t x, uint8_t y) 
//{
//	/* Set write pointers */
//	SSD1306.CurrentX = x;
//	SSD1306.CurrentY = y;
//}
