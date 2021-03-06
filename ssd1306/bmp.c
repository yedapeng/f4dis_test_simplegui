
#include "bmp.h"

const unsigned char battery_0[] = 
{
	0x00,0x00,0xFE,0xFE,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,
	0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0xFE,0xFE,0xF0,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x7F,0x7F,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,
	0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x7F,0x7F,0x0F,0x07,0x00,0x00,0x00
};

const unsigned char battery_1[] = 
{
	0x00,0x00,0xFE,0xFE,0x06,0xF6,0xF6,0xF6,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,
	0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0xFE,0xFE,0xF0,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x7F,0x7F,0x60,0x6F,0x6F,0x6F,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,
	0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x7F,0x7F,0x0F,0x07,0x00,0x00,0x00
};

const unsigned char battery_2[] = 
{
	0x00,0x00,0xFE,0xFE,0x06,0xF6,0xF6,0xF6,0x06,0xF6,0xF6,0xF6,0x06,0x06,0x06,0x06,
	0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0xFE,0xFE,0xF0,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x7F,0x7F,0x60,0x6F,0x6F,0x6F,0x60,0x6F,0x6F,0x6F,0x60,0x60,0x60,0x60,
	0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x7F,0x7F,0x0F,0x07,0x00,0x00,0x00
};

const unsigned char battery_3[] = 
{
	0x00,0x00,0xFE,0xFE,0x06,0xF6,0xF6,0xF6,0x06,0xF6,0xF6,0xF6,0x06,0xF6,0xF6,0xF6,
	0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0xFE,0xFE,0xF0,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x7F,0x7F,0x60,0x6F,0x6F,0x6F,0x60,0x6F,0x6F,0x6F,0x60,0x6F,0x6F,0x6F,
	0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x7F,0x7F,0x0F,0x07,0x00,0x00,0x00
};

const unsigned char battery_4[] = 
{
	0x00,0x00,0xFE,0xFE,0x06,0xF6,0xF6,0xF6,0x06,0xF6,0xF6,0xF6,0x06,0xF6,0xF6,0xF6,
	0x06,0xF6,0xF6,0xF6,0x06,0x06,0x06,0x06,0x06,0xFE,0xFE,0xF0,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x7F,0x7F,0x60,0x6F,0x6F,0x6F,0x60,0x6F,0x6F,0x6F,0x60,0x6F,0x6F,0x6F,
	0x60,0x6F,0x6F,0x6F,0x60,0x60,0x60,0x60,0x60,0x7F,0x7F,0x0F,0x07,0x00,0x00,0x00
};

const unsigned char battery_5[] = 
{
	0x00,0x00,0xFE,0xFE,0x06,0xF6,0xF6,0xF6,0x06,0xF6,0xF6,0xF6,0x06,0xF6,0xF6,0xF6,
	0x06,0xF6,0xF6,0xF6,0x06,0xF6,0xF6,0xF6,0x06,0xFE,0xFE,0xF0,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x7F,0x7F,0x60,0x6F,0x6F,0x6F,0x60,0x6F,0x6F,0x6F,0x60,0x6F,0x6F,0x6F,
	0x60,0x6F,0x6F,0x6F,0x60,0x6F,0x6F,0x6F,0x60,0x7F,0x7F,0x0F,0x07,0x00,0x00,0x00
};

const unsigned char battery_chg[] = 
{
	0x00,0x00,0xFE,0xFE,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0xC6,0xE0,0xF0,0xFC,
	0x80,0x80,0x86,0x86,0x06,0x06,0x06,0x06,0x06,0xFE,0xFE,0xF0,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x7F,0x7F,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x61,0x61,0x01,0x21,0x1F,
	0x0F,0x03,0x61,0x60,0x60,0x60,0x60,0x60,0x60,0x7F,0x7F,0x0F,0x07,0x00,0x00,0x00
};
//const unsigned char point_0[] = 
//{
//	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFC,0xFF,
//	0xFF,0xFF,0xF8,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFC,0xFF,0xFF,0xFF,0xFF,
//	0xFF,0xFF,0xFF,0xFF,0xFE,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
//	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//	0x00,0x00,0x00,0x00,0x00,0x80,0xFC,0x7F,0x3F,0x3F,0x1F,0x0F,0x07,0x07,0x03,0x01,
//	0x01,0x01,0x03,0x07,0x07,0x1F,0x3F,0x3F,0x7F,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00
//};


const unsigned char point_0[] = 
	{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF0,0xF8,0xFC,
0xF8,0xF0,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x18,0x1E,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x1F,0x1E,0x18,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x3F,0x3F,
0x3F,0x3F,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00


	};