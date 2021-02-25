#include "IDT.h"
#include "../../io/io.h"

idt_entry_t entry[256];
idtr_t idtr = {.size = 256 * sizeof(idt_entry_t), .offset = (uint64_t)entry };
idt_entry_t new_entry(uint64_t offset)
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

 void Load_ISR()
 {
 	entry[0] = new_entry((uint64_t)&ex_0);
	entry[1] = new_entry((uint64_t)&ex_1);
	entry[2] = new_entry((uint64_t)&ex_2);
	entry[3] = new_entry((uint64_t)&ex_3);
	entry[4] = new_entry((uint64_t)&ex_4);
	entry[5] = new_entry((uint64_t)&ex_5);
	entry[6] = new_entry((uint64_t)&ex_6);
	entry[7] = new_entry((uint64_t)&ex_7);
	entry[8] = new_entry((uint64_t)&ex_8);
	entry[10] = new_entry((uint64_t)&ex_10);
	entry[11] = new_entry((uint64_t)&ex_11);
	entry[12] = new_entry((uint64_t)&ex_12);
	entry[13] = new_entry((uint64_t)&ex_13);
	entry[14] = new_entry((uint64_t)&ex_14);
	entry[16] = new_entry((uint64_t)&ex_16);
	entry[17] = new_entry((uint64_t)&ex_17);
	entry[18] = new_entry((uint64_t)&ex_18);
	entry[19] = new_entry((uint64_t)&ex_19);
	entry[20] = new_entry((uint64_t)&ex_20);
	entry[30] = new_entry((uint64_t)&ex_30);
 }
void Initialize_IDT(void)
{
 	// Our expections, so we don't get into a crash
 	Lobster_Log(LOBSTER_INFO, "Loading ISR.\n");
	Load_ISR();
	Lobster_Log(LOBSTER_SUCCESS, "Loaded ISR.\n");

	Lobster_Log(LOBSTER_INFO, "Loading IDT.\n");
	Load_IDT();
	Lobster_Log(LOBSTER_SUCCESS, "Loaded IDT.\n");

}
