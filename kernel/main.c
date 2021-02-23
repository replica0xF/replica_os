#include "main.h"
#include "devices/video/vge.h"
#include "io/io.h"
#include "System/GDT.h"
#include <stddef.h>


static uint8_t stack[4098];

struct stivale2_header_tag_framebuffer framebuffer_hdr_tag =
{
	.tag = 
	{
		.identifier = STIVALE2_HEADER_TAG_FRAMEBUFFER_ID,
		.next = 0
	},
	
	.framebuffer_width = 0,
	.framebuffer_height = 0,
	.framebuffer_bpp = 0
	
};


__attribute__ ((section(".stivale2hdr"), used))
struct stivale2_header stivale_hdr = {
	.entry_point = (uint64_t)kernel_main,
	.stack = (uintptr_t)stack + sizeof(stack),
	.flags = 0,
	.tags = (uintptr_t)&framebuffer_hdr_tag
};

void* stivale2_get_tag(struct stivale2_struct * stivale2_struct , uint64_t id) 
{
    struct stivale2_tag* current_tag;
    current_tag = (void*)stivale2_struct->tags;
    for (;;)
    {
        if (current_tag == NULL)
            return NULL;

        if (current_tag->identifier == id)
        {
            return current_tag;
        }

        current_tag = (void*)current_tag->next;
    }
} 
 

void kernel_main(struct stivale2_struct* stivale2_struct)
{

	struct stivale2_struct_tag_framebuffer* fb_hdr_tag = stivale2_get_tag(stivale2_struct,  STIVALE2_STRUCT_TAG_FRAMEBUFFER_ID);
	if (fb_hdr_tag == NULL)
	{
 		for (;;)
		{
			asm("hlt");
		}	
	} 
	//struct stivale2_struct_tag_framebuffer* fb, char* message , int err_code
 	//kernel_panic(fb_hdr_tag, "Invoked." , 4);

	VGE_SetBackgroundColor(fb_hdr_tag, rgb2hex(45,49,61));	
	uint32_t width,height;
	width = (uint32_t)(fb_hdr_tag->framebuffer_width);
	height = (uint32_t)(fb_hdr_tag->framebuffer_height);
	VGE_PrintString(fb_hdr_tag , "\nWindow Size: (x:" , 7, rgb2hex(100,100,100));
	VGE_PrintString(fb_hdr_tag , int2str(width ) , 7, rgb2hex(100,100,100));
	VGE_PrintString(fb_hdr_tag , ", y:" , 7, rgb2hex(100,100,100));
	VGE_PrintString(fb_hdr_tag , int2str(height ) , 7, rgb2hex(100,100,100));
	VGE_PrintString(fb_hdr_tag , ")\n" , 7, rgb2hex(100,100,100));

	VGE_PrintString(fb_hdr_tag , "\nWelcome to,", 7, rgb2hex(199, 199, 199));
	VGE_PrintString(fb_hdr_tag , " Replica OS\n", 7, rgb2hex(255,255,255));
	VGE_PrintString(fb_hdr_tag , "Created by [replica0xF]\n", 7, rgb2hex(199,199,199));
	VGE_PrintString(fb_hdr_tag , "This operating system is still is beta. Report any bugs to the github.\n", 7, rgb2hex(199,199,199));
 
 	VGE_Rectangle(fb_hdr_tag , 0 , height - 70, width, 70 , rgb2hex(200,154,154));
	VGE_Rectangle(fb_hdr_tag , 0 , height - 70, width / 2, 70 , rgb2hex(255,154,154));
	VGE_Line(fb_hdr_tag , 450,450,500,500, rgb2hex(255,0,0));
	VGE_DrawCircle(fb_hdr_tag , 600,600,50, rgb2hex(255,255,255));
	VGE_DrawCircle(fb_hdr_tag , 400,400,50, rgb2hex(255,255,255));
	//kernel_panic(fb_hdr_tag , "Fatal Invoked Error." , 30284);
	for (;;)
	{
		asm("hlt");
	}
}





