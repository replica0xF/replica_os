#include "panic.h"

void kernel_panic(char* message , int err_code)
{
	asm("cli");
	VGE_ClearCursorPos();
	VGE_PrintString("\n\n\n" , 7, rgb2hex(255,0,0));
	VGE_SetBackgroundColor(  rgb2hex(99,44,44));	
	VGE_PrintString("Fatal error occured.\n" , 7, rgb2hex(255,0,0));
	VGE_PrintString( "Message:" , 7, rgb2hex(255,255 /2,255/2));
	VGE_PrintString(message , 7, rgb2hex(255,255,255));
	VGE_PrintString("\nERROR:CODE: ", 7, rgb2hex(255,255,255));
	VGE_PrintString(int2str(err_code), 7, rgb2hex(255,255,255));

 	VGE_Rectangle( 0 , (uint32_t)fb_hdr_tag->framebuffer_height - 70, (uint32_t)fb_hdr_tag->framebuffer_width, 70 , rgb2hex(200, 10,10));
	VGE_Rectangle(  0 , (uint32_t)fb_hdr_tag->framebuffer_height - 70, (uint32_t)fb_hdr_tag->framebuffer_width / 2, 70 , rgb2hex(255,10,10));
	VGE_PrintStringPos( "Reboot your system to re-continue.", 7, rgb2hex(255,255,255), CreateVec2( (uint32_t)fb_hdr_tag->framebuffer_height / 2, (uint32_t)fb_hdr_tag->framebuffer_width / 2));

	while (1);
}