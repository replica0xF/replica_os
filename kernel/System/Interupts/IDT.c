#include "IDT.h"
#include "../../io/io.h"
idt_entry_t entry[256];
idtr_t idtr = {.size = 256 * sizeof(idt_entry_t), .offset = (uint64_t)entry };
static idt_entry_t new_entry(uint64_t offset)
{
	return (idt_entry_t)
	{
		.cs = 0x08,
		.offset_low16 = offset & 0xFFFF,
		.offset_mid16 = (offset >> 16) & 0xFFFF,
		.offset_high32 = (offset >> 32) & 0xFFFFFFFF,
		.zero =0,
		.ist = 0,
		.attributes = 0x8e
	};
}
static void Load_IDT()
{
	__asm__ volatile (
		"lidt %0"
		:
		
		: "m" (idtr) 
		 
		);
}

  
void Initialize_IDT(void)
{

	Load_IDT();
}
