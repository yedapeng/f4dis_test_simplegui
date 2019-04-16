
#ifndef _SSD1306_H
#define _SSD1306_H

#include "stdint.h"







#define BLACK 0
#define WHITE 1
#define INVERSE 2

#define SSD1306_I2C_ADDRESS   0x3C	// 011110+SA0+RW - 0x3C or 0x3D
// Address for 128x32 is 0x3C
// Address for 128x64 is 0x3D (default) or 0x3C (if SA0 is grounded)

/*=========================================================================
    SSD1306 Displays
    -----------------------------------------------------------------------
    The driver is used in multiple displays (128x64, 128x32, etc.).
    Select the appropriate display below to create an appropriately
    sized framebuffer, etc.

    SSD1306_128_64  128x64 pixel display

    SSD1306_128_32  128x32 pixel display

    SSD1306_96_16

    -----------------------------------------------------------------------*/
#define SSD1306_128_64
//   #define SSD1306_128_32
//   #define SSD1306_96_16
/*=========================================================================*/

#if defined SSD1306_128_32
        #define WIDTH 128
        #define HEIGHT 32
#endif

#if defined SSD1306_128_64
        #define WIDTH 128
        #define HEIGHT 64
#endif

#if defined SSD1306_96_16
        #define WIDTH 96
        #define HEIGHT 16
#endif

#if defined SSD1306_128_64 && defined SSD1306_128_32
        #error "Only one SSD1306 display can be specified at once in SSD1306.h"
#endif
#if !defined SSD1306_128_64 && !defined SSD1306_128_32 && !defined SSD1306_96_16
        #error "At least one SSD1306 display must be specified in SSD1306.h"
#endif

#if defined SSD1306_128_64
        #define SSD1306_LCDWIDTH                  128
        #define SSD1306_LCDHEIGHT                 64
#endif
#if defined SSD1306_128_32
        #define SSD1306_LCDWIDTH                  128
        #define SSD1306_LCDHEIGHT                 32
#endif
#if defined SSD1306_96_16
        #define SSD1306_LCDWIDTH                  96
        #define SSD1306_LCDHEIGHT                 16
#endif

#define SSD1306_SETCONTRAST 							0x81
#define SSD1306_DISPLAYALLON_RESUME 			0xA4
#define SSD1306_DISPLAYALLON 							0xA5
#define SSD1306_NORMALDISPLAY 						0xA6
#define SSD1306_INVERTDISPLAY 						0xA7
#define SSD1306_DISPLAYOFF 								0xAE
#define SSD1306_DISPLAYON 								0xAF

#define SSD1306_SETDISPLAYOFFSET 					0xD3
#define SSD1306_SETCOMPINS 								0xDA

#define SSD1306_SETVCOMDETECT 						0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 				0xD5
#define SSD1306_SETPRECHARGE 							0xD9

#define SSD1306_SETMULTIPLEX 							0xA8

#define SSD1306_SETLOWCOLUMN 							0x00
#define SSD1306_SETHIGHCOLUMN 						0x10

#define SSD1306_SETSTARTLINE 							0x40

#define SSD1306_MEMORYMODE 								0x20
#define SSD1306_COLUMNADDR 								0x21
#define SSD1306_PAGEADDR   								0x22

#define SSD1306_COMSCANINC 								0xC0
#define SSD1306_COMSCANDEC 								0xC8

#define SSD1306_SEGREMAP 									0xA0

#define SSD1306_CHARGEPUMP 								0x8D

#define SSD1306_EXTERNALVCC 							0x1
#define SSD1306_SWITCHCAPVCC 							0x2

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 											0x2F
#define SSD1306_DEACTIVATE_SCROLL 										0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 							0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 							0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 								0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 	0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 	0x2A




//
//	Enum voor de kleuren van het scherm Black en White
//
typedef enum {
	Black = 0x00, /*!< Black color, no pixel */
	White = 0x01  /*!< Pixel is set. Color depends on LCD */
} SSD1306_COLOR;

//
//	Struct om wijzigingen bij te houden
//
typedef struct {
	uint16_t CurrentX;
	uint16_t CurrentY;
	uint8_t Inverted;
	uint8_t Initialized;
} SSD1306_t;


uint8_t ssd1306_Init(void);
void ssd1306_SetDisplay(void);
void ssd1306_ClearDisplay(void);
void ssd1306_RefreshScreen(void);
void ssd1306_SetPixel(int uiPosX, int uiPosY, int eColor);
int ssd1306_GetPixel(int uiPosX, int uiPosY);

#endif		/* _SSD1306_H */
