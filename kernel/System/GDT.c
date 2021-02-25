

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
		 
		"mov %%rsp, %%rax\n"
		"push $0x10\n"
		"push %%rax\n"
		
		"pushf\n" // push flags to stack
		"push $0x8\n" // segment = 0x8:1
		"push $1f\n" // a/k/a = SEGMENT : OUTSET
		"iretq\n" // IRETQ 
		"1:\n"
		"ret\n"		
	
		:
		:
	        :	"rax", "memory"
	);	
	

}

void InitGDT()
{

	gdt[1] = (struct gdt_descriptor){ .access = 0b10011010, .flags = 0b00100000}; // code segment (cs)
	gdt[2] =  (struct gdt_descriptor){ .access = 0b10010010, .flags = 0b00000000}; // data segment (ds)


	Lobster_Log(LOBSTER_INFO, "Loading GDT.\n");
	LoadGDT(); 
	Lobster_Log(LOBSTER_SUCCESS, "Loading GDT.\n");

	

}
