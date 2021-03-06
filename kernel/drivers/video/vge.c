#include "vge.h"
#include "font.h"

static uint32_t cursor_x = 0;
static uint32_t cursor_y = 0;

static uint32_t bg_color;

static uint32_t cursor_xp = 0;
static uint32_t cursor_yp = 0;


static uint32_t vge_text_buffer_width = 8;
static uint32_t vge_text_buffer_height = 8;

uint32_t rgb2hex(int r, int g, int b)
{
	return (uint32_t)((r << 16) | (g << 8) | (b << 0));
}
vec2 CreateVec2(uint32_t x , uint32_t y)
{
	vec2 pos;
	pos.x = x;
	pos.y = y;
	return pos;
};
void VGE_Pixel( int x, int y, uint32_t color)
{
	size_t offset = x + (fb_hdr_tag->framebuffer_pitch / sizeof(uint32_t)) * y;
	uint32_t* framebuffer_addr = (uint32_t*)fb_hdr_tag->framebuffer_addr;
	framebuffer_addr[offset] = color;

}

void VGE_Rectangle(  int x, int y, int w , int h , uint32_t color)
{
	for (int width =0; width < w;width++)
	{
		for (int height = 0; height < h;height++)
		{
			VGE_Pixel(  width + x, height + y, color);
		}
	}
}

void VGE_SetBackgroundColor( uint32_t color )
{
	bg_color = color;


}
uint64_t page_meta = 0;
uint64_t page_index = 0;

void VGE_ClearBG()
{
 	uint32_t* framebuffer_addr = (uint32_t*)fb_hdr_tag->framebuffer_addr;
 
	for (int i=0;i < fb_hdr_tag->framebuffer_width;i++)
	{
		for (int j=0;j < fb_hdr_tag->framebuffer_height;j++)
		{
 			framebuffer_addr[j + i] = bg_color;
 			framebuffer_addr[i] = bg_color;
 			framebuffer_addr[j] = bg_color;
 

		}
 	        framebuffer_addr+=fb_hdr_tag->framebuffer_height;
 	}
	if (page_meta == 1)
	{
	VGE_PrintStringPos(int2str(page_index++) , 7,  rgb2hex(255,255,255) , CreateVec2(500,500));
	page_meta = 0;
	}

}
void VGE_PrintChar( char c , uint32_t color)
{
	uint32_t ix , iy;
	for (ix = 0; ix < (uint32_t)vge_text_buffer_width;ix++)
	{
		for (iy = 0;iy < (uint32_t)vge_text_buffer_height;iy++)
		{
			if (font[(uint32_t)(c)][iy] >> ix & 1){
			VGE_Pixel(ix  + cursor_x ,iy  + cursor_y ,color);
			}
		}
	}
}

 //https://stackoverflow.com/questions/31331019/how-do-you-properly-implement-turning-an-int-into-a-string
char* int2str(int res) {
    int size = 0;
    int t = res;

    while(t / 10 != 0) {
        t = t/10;
        size++;
    }
    static char ret[64];
    size++;
    ret[size] = '\0';
    t = res;
    int i = size - 1;
    while(i >= 0) {
        ret[i] = (t % 10) + '0';
        t = t/10;
        i--;
    }

    return ret;
}

void VGE_PrintString(char* str , int letter_spacing , uint32_t color)
{
	int i = 0;
	if (cursor_y >= fb_hdr_tag->framebuffer_height - vge_text_buffer_height) 
	{
		page_meta = 1;
			VGE_ClearBG();
			VGE_ClearCursorPos();
	}
	while (str[i])

	{


		if (str[i] != '\n'){
			cursor_x += letter_spacing;
		VGE_PrintChar( str[i], color);
		} else
		{

			cursor_y += letter_spacing  + vge_text_buffer_height + 1; 
			cursor_x = 0;
		}

		
		i++;
	}

}
//
void VGE_SetX(int x){
	cursor_x = x;
}
void VGE_SetY(int y){
	cursor_y = y;
}
//
int VGE_GetX(){
	return cursor_x;
}
int VGE_GetY()
{
	return cursor_y;
}


//
void VGE_SetXp(int x){
	cursor_xp = x;
}
void VGE_SetYp(int y){
	cursor_yp = y;
}
//
int VGE_GetXp(){
	return cursor_xp;
}
int VGE_GetYp()
{
	return cursor_yp;
}

void VGE_PrintCharPos(char c , uint32_t color , vec2 pos )
{
	uint32_t ix , iy;
 	for (ix = 0; ix < vge_text_buffer_width;ix++)
	{
		for (iy = 0;iy < vge_text_buffer_height;iy++)
		{
			if (font[(uint32_t)(c)][iy] >> ix & 1){

			VGE_Pixel( (ix  + cursor_xp) + pos.x , (iy  + cursor_yp) + pos.y , color);
			}
		}
	}
}
	
void VGE_ClearCursorPos()
{
	cursor_xp = 0;
	cursor_yp = 0;
	cursor_x = 0;
	cursor_y = 0;
}


void VGE_PrintStringPos(char* str , int letter_spacing,  uint32_t color , vec2 pos)
{
	int i = 0;
	if (cursor_yp >= fb_hdr_tag->framebuffer_height - vge_text_buffer_height) 
	{
				page_meta = 1;

			VGE_ClearBG();
			VGE_ClearCursorPos();
	}
	while (str[i])

	{
		 
		 
		cursor_xp += letter_spacing;
		VGE_PrintCharPos( str[i], color , pos);
		
		i++;
	}

}

void VGE_Line( int x0 , int y0 , int x1, int y1, uint32_t color)
{
	uint32_t dx = x1 - x0;
	uint32_t dy = y1 - y0;
	uint32_t D = 2 * dy - dx;
	uint32_t y = y0;

	for (int x = x0; x < x1; x++)
	{
		VGE_Pixel(x,y,color);
		if (D > 0)
		{
			y = y+ 1;
			D = D - 2 * dx;
		}
		D = D + 2* dy;
	}
}

void VGE_circle__( int xc, int yc,int x, int y,  uint32_t color)
{
 

	VGE_Pixel(xc+x, yc+y, color);
    VGE_Pixel(xc-x, yc+y, color);
    VGE_Pixel(xc+x, yc-y, color);
    VGE_Pixel(xc-x, yc-y, color);
    VGE_Pixel(xc+y, yc+x, color);
    VGE_Pixel(xc-y, yc+x, color);
    VGE_Pixel(xc+y, yc-x, color);
    VGE_Pixel(xc-y, yc-x, color);
}

void VGE_DrawCircle( int xc, int yc,int radius,uint32_t color)
{
	int x = 0, y = radius;
	int d = 3 - 2 * radius;
	VGE_circle__( xc,yc,x,y,color);
	while (y >= x)
	{
		x++;

		if (d > 0)
		{
			y--;
			d = d + 4 * (x-y) + 10;
		}
		else
		{
			d = d + 4 * x + 6;
		}
		VGE_circle__(xc,yc,x,y,color);

	}
}