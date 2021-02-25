#include "main.h"
#include "devices/video/vge.h"
#include "io/io.h"
#include "System/GDT.h"
#include <stddef.h>
#include "System/Interupts/IDT.h"
#include "../lobster/logger.h"

void kernel_main(struct stivale2_struct* stivale2_struct)
{
	
	//struct stivale2_struct_tag_framebuffer* fb, char* message , int err_code
	Boot_LocateTag(stivale2_struct);

 	VGE_SetBackgroundColor(rgb2hex(45,49,61));	
	uint32_t width,height;
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

 	VGE_DrawCircle( 600,600,50, rgb2hex(255,255,255));
  
  	VGE_DrawCircle( 400,400,50, rgb2hex(255,255,255));

 	Lobster_Log( LOBSTER_INFO, "Initializing GDT..\n ");
   	InitGDT();
 	Lobster_Log( LOBSTER_SUCCESS, "Loaded GDT\n");

  	//  	815 + 2x + x = 1080  
 	// IDT
 	Lobster_Log(  LOBSTER_INFO, "Initializing IDT..\n ");

 	Initialize_IDT();
 	Lobster_Log(LOBSTER_SUCCESS, "Loaded IDT\n ");

 
	//kernel_panic(fb_hdr_tag , "Fatal Invoked Error." , 30284);
 	Boot_Loop();
}





