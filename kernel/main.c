#include "main.h"
#include "devices/video/vge.h"
#include "io/io.h"
#include "System/GDT.h"
#include <stddef.h>
#include "System/Interupts/IDT.h"
#include "../lobster/logger.h"

void kernel_main(struct stivale2_struct* stivale2_struct)
{
	
	Boot_LocateTag(stivale2_struct);
 	uint32_t width,height;
 	VGE_SetBackgroundColor(rgb2hex(45,49,61));
 	VGE_ClearBG();
	width = (uint32_t)(fb_hdr_tag->framebuffer_width);
	height = (uint32_t)(fb_hdr_tag->framebuffer_height);
 	VGE_PrintString("\nWindow Size: (x:" , 7, rgb2hex(100,100,100));
	VGE_PrintString( int2str(width ) , 7, rgb2hex(100,100,100));
	VGE_PrintString( ", y:" , 7, rgb2hex(100,100,100));
	VGE_PrintString( int2str(height ) , 7, rgb2hex(100,100,100));
	VGE_PrintString(")\n" , 7, rgb2hex(100,100,100));
 	VGE_PrintString( "\nWelcome to,", 7, rgb2hex(199, 199, 199));
	VGE_PrintString( " Replica OS\n", 7, rgb2hex(255,255,255));
	VGE_PrintString("Created by [replica0xF]\n", 7, rgb2hex(199,199,199));
	VGE_PrintString( "This operating system is still is beta. Report any bugs to the github.\n", 7, rgb2hex(199,199,199));

 	VGE_Rectangle( 0 , height - 70, width, 70 , rgb2hex(200,154,154));
	VGE_Rectangle( 0 , height - 70, width / 2, 70 , rgb2hex(255,154,154));
	for (int i=0;i<120;i++){
		VGE_PrintString( "loop\n", 20, rgb2hex(199,199,199));
	}

  	VGE_DrawCircle( 400,400,50, rgb2hex(255,255,255));
  	InitGDT(); 
 	Initialize_IDT();
  
  
   

 
 
  	Boot_Loop();
}





