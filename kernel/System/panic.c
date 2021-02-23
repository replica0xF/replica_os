#include "panic.h"

void kernel_panic(struct stivale2_struct_tag_framebuffer* fb, char* message , int err_code)
{
	asm("cli");
	VGE_ClearCursorPos();
	VGE_PrintString(fb , "\n\n\n" , 7, rgb2hex(255,0,0));
	VGE_SetBackgroundColor(fb, rgb2hex(99,44,44));	
	VGE_PrintString(fb , "Fatal error occured.\n" , 7, rgb2hex(255,0,0));
	VGE_PrintString(fb , "Message:" , 7, rgb2hex(255,255 /2,255/2));
	VGE_PrintString(fb , message , 7, rgb2hex(255,255,255));
	VGE_PrintString(fb , "\nERROR:CODE: ", 7, rgb2hex(255,255,255));
	VGE_PrintString(fb , int2str(err_code), 7, rgb2hex(255,255,255));
	while (1);
}