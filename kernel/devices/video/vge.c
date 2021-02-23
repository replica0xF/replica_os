#include "vge.h"
#include "font.h"

static uint32_t cursor_x = 0;
static uint32_t cursor_y = 0;

uint32_t rgb2hex(int r, int g, int b)
{
	return (uint32_t)((r << 16) | (g << 8) | (b << 0));
}

void VGE_Pixel(struct stivale2_struct_tag_framebuffer* information, int x, int y, uint32_t color)
{
	uint32_t offset = x + (information->framebuffer_pitch / sizeof(uint32_t)) * y;
	uint32_t* framebuffer_addr = (uint32_t*)information->framebuffer_addr;
	framebuffer_addr[offset] = color;

}

void VGE_Rectangle(struct stivale2_struct_tag_framebuffer* information, int x, int y, int w , int h , uint32_t color)
{
	for (int width =0; width < w;width++)
	{
		for (int height = 0; height < h;height++)
		{
			VGE_Pixel(information , width + x, height + y, color);
		}
	}
}

void VGE_SetBackgroundColor(struct stivale2_struct_tag_framebuffer* information, uint32_t color )
{
	VGE_Rectangle(information,0,0,(uint32_t)(information->framebuffer_width) , (uint32_t)(information->framebuffer_height), color);
}

void VGE_PrintChar(struct stivale2_struct_tag_framebuffer* information, char c , uint32_t color)
{
	uint32_t ix , iy;
	for (ix = 0; ix < 8;ix++)
	{
		for (iy = 0;iy < 8;iy++)
		{
			if (font[(uint32_t)(c)][iy] >> ix & 1){
			VGE_Pixel(information,ix  + cursor_x ,iy  + cursor_y ,color);
			}
		}
	}
}

void VGE_PrintString(struct stivale2_struct_tag_framebuffer* information ,char* str , int letter_spacing , uint32_t color)
{
	int i = 0;
	while (str[i])

	{

		if (str[i] != '\n'){
			cursor_x += letter_spacing;
		VGE_PrintChar(information , str[i], color);
		} else
		{
			cursor_y += letter_spacing  + 7; 
			cursor_x = 0;
		}
		i++;
	}

}