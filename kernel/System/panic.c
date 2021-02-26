#include "panic.h"

void kernel_panic(char* message , int err_code)
{
	asm("cli");
	VGE_SetBackgroundColor(  rgb2hex(100,44,44));	
	VGE_ClearBG();
 
 
  	VGE_SetY(50);
 
 	VGE_PrintStringPos("ReplicaOS : Kernel Module" , 8,  rgb2hex(255,150,150) , CreateVec2(0,25));
 	VGE_PrintString("FATAL PANIC.\n" , 8 , rgb2hex(255,150,150));
	VGE_Rectangle(0,VGE_GetY(),fb_hdr_tag->framebuffer_width,2,rgb2hex(255,100,100));
  	VGE_PrintString("\nOops! FATAL CRASH. Your computer has suffered a kernel panic.\nThis may be easily fix by rebooting your system.\n" , 8 , rgb2hex(255,255,255));
	VGE_Rectangle(0,VGE_GetY(),fb_hdr_tag->framebuffer_width,2,rgb2hex(255,100,100));
 
 	VGE_PrintString("\nAdditonal Information:\n" , 8 , rgb2hex(255,255,255));
 	VGE_PrintString(message , 8 , rgb2hex(255,255,255));
 	VGE_PrintString("\n" , 8 , rgb2hex(255,255,255));
 	VGE_PrintString("Error Code:  " , 8 , rgb2hex(255,255,255));
 	VGE_PrintString(int2str(err_code), 8 , rgb2hex(255,255,255));
 	VGE_PrintString("\n", 8 , rgb2hex(255,255,255));
	 	
 	
 
 
 

	while (1);
}