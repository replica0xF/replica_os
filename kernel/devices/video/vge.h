#pragma once 
#include "../../boot/stivale2.h"



uint32_t rgb2hex(int r, int g, int b);

void VGE_Pixel(struct stivale2_struct_tag_framebuffer* information, int x, int y, uint32_t color);
 
void VGE_Rectangle(struct stivale2_struct_tag_framebuffer* information, int x, int y, int w , int h , uint32_t color);

void VGE_SetBackgroundColor(struct stivale2_struct_tag_framebuffer* information, uint32_t color );

void VGE_PrintChar(struct stivale2_struct_tag_framebuffer* information ,char c , uint32_t color);
// for letter_spacing 7 is good, 
void VGE_PrintString(struct stivale2_struct_tag_framebuffer* information ,char* str , int letter_spacing,  uint32_t color);


