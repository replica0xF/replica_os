#pragma once 
#include "../../boot/stivale2.h"

typedef struct vec
{
	uint32_t x;
	uint32_t y;
} vec2;

uint32_t rgb2hex(int r, int g, int b);

void VGE_Pixel(struct stivale2_struct_tag_framebuffer* information, int x, int y, uint32_t color);
 
void VGE_Rectangle(struct stivale2_struct_tag_framebuffer* information, int x, int y, int w , int h , uint32_t color);

void VGE_SetBackgroundColor(struct stivale2_struct_tag_framebuffer* information, uint32_t color );

void VGE_PrintChar(struct stivale2_struct_tag_framebuffer* information ,char c , uint32_t color);
// for letter_spacing 7 is good, 
void VGE_PrintString(struct stivale2_struct_tag_framebuffer* information ,char* str , int letter_spacing,  uint32_t color);


void VGE_PrintCharPos(struct stivale2_struct_tag_framebuffer* information ,char c , uint32_t color , vec2 pos );

void VGE_PrintStringPos(struct stivale2_struct_tag_framebuffer* information ,char* str , int letter_spacing,  uint32_t color , vec2 pos);

char* int2str(int val);

vec2 CreateVec2(uint32_t x , uint32_t y);

void VGE_ClearCursorPos();