

#include "GDT.h"
struct gdt_descriptor gdt[8]; 
struct gdt_ptr ptr = {.limit = sizeof(gdt) - 1 , .base = (uint64_t)(gdt)};

void LoadGDT()
{
	// loading the GDT onto the lgdt
	__asm__ volatile (
		"lgdt %0"
		:
		: "m" (ptr)
		: "memory"
	);	
	
	__asm__ volatile (
 
		// pushes 0x10 on segment registers.
		 "mov $0x10, %%ax\n"
		 "mov %%ax, %%ds\n"
		 "mov %%ax, %%es\n"
		 "mov %%ax, %%ss\n"
		 "mov %%ax, %%fs\n"
		 "mov %%ax, %%gs\n"
		
		 :
		:
		: "rax", "memory"
	);	
	

}

void InitGDT()
{

	gdt[1] = (struct gdt_descriptor){ .access = 0b10011010, .flags = 0b11001111, .limit_low16 = 0xFFFF , .base_low16 = 0x0000 , .base_mid16 = 0x00, .base_high = 0x00}; // code segment (cs)
	gdt[2] =  (struct gdt_descriptor){ .access = 0b10010010, .flags = 0b11001111, .limit_low16 = 0xFFFF , .base_low16 = 0x0000 , .base_mid16 = 0x00, .base_high = 0x00}; // data segment (ds)
	LoadGDT(); 
}