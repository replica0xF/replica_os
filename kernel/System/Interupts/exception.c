#include "exception.h"
static char* expections[] = 
{
[0] = "Divide by zero",
[1] = "Debug",
[2] = "Non-maskable Interrupt",
[3] = "Breakpoint",
[4] = "Overflow",
[5] = "Bound Range Exceeded",
[6] = "Invalid Opcode",
[7] = "Device Not Available",
[8] = "Double Fault",
[10] = "Invalid TSS",
[11] = "Segment Not Present",
[12] = "Stack-Segment Fault",
[13] = "General Protection Fault",
[14] = "Page Fault",
[16] = "x87 Floating-Point Exception",
[17] = "Alignment Check",
[18] = "Machine Check",
[19] = "SIMD Floating-Point Exception",
[20] = "Virtualization Exception",
[30] = "Security Exception" 
};

void fatal_expection_catch(uint8_t x)
{
	if (expections[x] != NULL)
	{
	kernel_panic("Unknown expection.", x);

	}
	kernel_panic(expections[x], x);
}

void ex_0() {fatal_expection_catch	(0);		};	
void ex_1() { fatal_expection_catch	(1); 	};	
void ex_2() { fatal_expection_catch	(2); 	};	
void ex_3() { fatal_expection_catch	(3); 	};	
void ex_4() { fatal_expection_catch	(4); 	};	
void ex_5() { fatal_expection_catch	(5); 	};	
void ex_6() { fatal_expection_catch	(6); 	};	
void ex_7() { fatal_expection_catch	(7); 	};	
void ex_8() { fatal_expection_catch	(8); 	};	
void ex_10() { fatal_expection_catch(10); 	};	
void ex_11() { fatal_expection_catch(11); 	};	
void ex_12() { fatal_expection_catch(12); 	};	
void ex_13() { fatal_expection_catch(13); 	};	
void ex_14() { fatal_expection_catch(14); 	};	
void ex_16() { fatal_expection_catch(16); 	};
void ex_17() { fatal_expection_catch(17); 	};	
void ex_18() { fatal_expection_catch(18); 	};	
void ex_19() { fatal_expection_catch(19); 	};	
void ex_20() { fatal_expection_catch(20); 	};	
void ex_30() { fatal_expection_catch(30); 	};	