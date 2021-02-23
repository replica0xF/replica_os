#include "main.h"
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


// 

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
	
	
	
	for (;;)
	{
		asm("hlt");
	}
}





