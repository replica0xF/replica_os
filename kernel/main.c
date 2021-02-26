#include "main.h"
#include "devices/video/vge.h"
#include "io/io.h"
#include "System/GDT.h"
#include <stddef.h>
#include "System/Interupts/IDT.h"
#include "../lobster/logger.h"

static uint8_t ui_ver = 2;
void kernel_main(struct stivale2_struct* stivale2_struct)
{
	
  
	Boot_LocateTag(stivale2_struct);
   	InitGDT(); 
 	Initialize_IDT();

 	VGE_SetBackgroundColor(rgb2hex(20,20,20));
 	VGE_ClearBG(); 

  	VGE_SetXp(5);
  	VGE_SetYp(5);
  	VGE_SetY(50);
  	VGE_Rectangle(  fb_hdr_tag->framebuffer_width- 25 ,  fb_hdr_tag->framebuffer_height - 25 , 25 , 25 , rgb2hex(255,0,0));
	VGE_Rectangle(  fb_hdr_tag->framebuffer_width- 50,  fb_hdr_tag->framebuffer_height - 25, 25 , 25 , rgb2hex(0,255,0));
	VGE_Rectangle(  fb_hdr_tag->framebuffer_width- 75,  fb_hdr_tag->framebuffer_height - 25, 25 , 50 , rgb2hex(0,0,255));
 	VGE_PrintStringPos("ReplicaOS" , 8, rgb2hex(160,170,255) , CreateVec2(0,25));
 	VGE_PrintString("IDT, GDT Loaded.\n" , 8 , rgb2hex(255,255,255));
	VGE_Rectangle(0,VGE_GetY(),fb_hdr_tag->framebuffer_width,2,rgb2hex(100,100,100));
 	VGE_PrintString("\n(c) 2021: ReplicaOS Foundation\n" , 8 , rgb2hex(255,255,255));

 	
 
 
  	Boot_Loop();
}





