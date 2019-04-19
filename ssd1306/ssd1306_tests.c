#include "ssd1306.h"
#include <string.h>
#include "stdio.h"
#include "bmp.h"

void ssd1306_TestBorder(void) {
    ssd1306_Fill(Black);
   
    uint32_t start = HAL_GetTick();
    uint32_t end = start;
    uint8_t x = 0;
    uint8_t y = 0;
    do {
        ssd1306_DrawPixel(x, y, Black);

        if((y == 0) && (x < 127))
            x++;
        else if((x == 127) && (y < 63))
            y++;
        else if((y == 63) && (x > 0)) 
            x--;
        else
            y--;

        ssd1306_DrawPixel(x, y, White);
        ssd1306_UpdateScreen();
    
        HAL_Delay(5);
        end = HAL_GetTick();
    } while((end - start) < 8000);
   
    HAL_Delay(1000);
}

void ssd1306_TestFonts() {
    ssd1306_Fill(Black);
    ssd1306_SetCursor(2, 0);
    ssd1306_WriteString("Font 16x26", Font_16x26, White);
    ssd1306_SetCursor(2, 26);
    ssd1306_WriteString("Font 11x18", Font_11x18, White);
    ssd1306_SetCursor(2, 26+18);
    ssd1306_WriteString("Font 7x10", Font_7x10, White);
    ssd1306_UpdateScreen();
}

void ssd1306_TestFPS() {
    ssd1306_Fill(White);
   
    uint32_t start = HAL_GetTick();
    uint32_t end = start;
    int fps = 0;
    char message[] = "ABCDEFGHIJK";
   
    ssd1306_SetCursor(2,0);
    ssd1306_WriteString("Testing...", Font_11x18, Black);
   
    do {
        ssd1306_SetCursor(2, 18);
        ssd1306_WriteString(message, Font_11x18, Black);
        ssd1306_UpdateScreen();
       
        char ch = message[0];
        memmove(message, message+1, sizeof(message)-2);
        message[sizeof(message)-2] = ch;

        fps++;
        end = HAL_GetTick();
    } while((end - start) < 5000);
   
    HAL_Delay(1000);

    char buff[64];
    fps = (float)fps / ((end - start) / 1000.0);
    snprintf(buff, sizeof(buff), "~%d FPS", fps);
   
    ssd1306_Fill(White);
    ssd1306_SetCursor(2, 18);
    ssd1306_WriteString(buff, Font_11x18, Black);
    ssd1306_UpdateScreen();
}

void ssd1306_TestAll() 
	{
		BmpDef bat0;
		BmpDef p0;
		
		//point_0
		
		
		bat0.data = (uint8_t*)battery_5;
		bat0.height = 16;
		bat0.width = 32;
		
		p0.data = (uint8_t*)point_0;
		p0.height = 32;
		p0.width = 32;
		
    ssd1306_Init();
		
		ssd1306_Fill(White);
		ssd1306_SetCursor(0, 10);
		ssd1306_WriteString("Spidersens", Font_11x18, Black);
		ssd1306_UpdateScreen();
		
		HAL_Delay(3000);
    //ssd1306_TestFPS();
    //HAL_Delay(3000);
		ssd1306_Fill(Black);
		ssd1306_SetCursor(1, 2);
		ssd1306_WriteBMP(&bat0, White);
		
		
		//p0
		
		ssd1306_SetCursor(35, 2);
		ssd1306_WriteString("1/6", Font_11x18, White);
		ssd1306_SetCursor(1, 23);
		ssd1306_WriteString("ABCDEFGH", Font_11x18, White);
		ssd1306_SetCursor(1, 44);
		ssd1306_WriteString("12345678", Font_11x18, White);
		
		ssd1306_SetCursor(93, 2);
		ssd1306_WriteString("99", Font_16x26, White);
		
		
		ssd1306_line(0,0, 128, 1, White);
		ssd1306_line(0,63, 128, 1, White);
		
		ssd1306_line(0,21, 90, 1, White);
		ssd1306_line(0,42, 90, 1, White);
		
		ssd1306_line(90,30, 38, 1, White);
		
		ssd1306_line(0,0, 64, 0, White);
		ssd1306_line(127,0, 64, 0, White);
		ssd1306_line(90,0, 64, 0, White);
		
		
		ssd1306_SetCursor(91, 31);
		ssd1306_WriteBMP(&p0, White);
		
		ssd1306_UpdateScreen();
		
		HAL_Delay(30000);
		
//    ssd1306_TestBorder();
//    ssd1306_TestFonts();
//	
//	
//	HAL_Delay(3000);
//	ssd1306_Fill(Black);
//	//ssd1306_UpdateScreen();
//	ssd1306_SetCursor(2, 0);
//	ssd1306_WriteString("1/6", Font_11x18, White);
//	//ssd1306_UpdateScreen();
//	
//	ssd1306_SetCursor(0, 16);
//	ssd1306_WriteString("12345678", Font_16x26, White);
//	ssd1306_UpdateScreen();
}
