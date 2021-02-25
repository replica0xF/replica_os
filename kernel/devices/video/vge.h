 
#pragma once 
#include "../../boot/boot.h"

typedef struct vec
{
	uint32_t x;
	uint32_t y;
} vec2;

uint32_t rgb2hex(int r, int g, int b);

void VGE_Pixel( int x, int y, uint32_t color);
 
void VGE_Rectangle( int x, int y, int w , int h , uint32_t color);

void VGE_SetBackgroundColor( uint32_t color );

void VGE_PrintChar(char c , uint32_t color);
// for letter_spacing 7 is good, 
void VGE_PrintString(char* str , int letter_spacing,  uint32_t color);

void VGE_PrintCharPos(char c , uint32_t color , vec2 pos );

void VGE_PrintStringPos(char* str , int letter_spacing,  uint32_t color , vec2 pos);

char* int2str(int val);

vec2 CreateVec2(uint32_t x , uint32_t y);

void VGE_ClearCursorPos();

void VGE_Line(  int x0 , int y0 , int x1, int y1, uint32_t color);

void VGE_circle__(int xc, int yc,int x, int y,  uint32_t color);
void VGE_DrawCircle(int xc, int yc,int radius,uint32_t color);
 
//
void VGE_SetX(int x);
void VGE_SetY(int y);
//
int VGE_GetX();
int VGE_GetY();
//
void VGE_SetXp(int x);
void VGE_SetYp(int y);
//
int VGE_GetXp();
int VGE_GetYp();
void VGE_ClearBG();