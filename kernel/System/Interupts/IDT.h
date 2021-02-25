
#ifndef IDT_h
#define IDT_H
#include <stdint.h>
typedef struct
{
	uint16_t size;
	uint64_t offset;

} __attribute__((packed)) idtr_t;
 
typedef struct
{
    uint16_t offset_low16;
    uint16_t cs;
    uint8_t ist;
    uint8_t attributes;
    uint16_t offset_mid16;
    uint32_t offset_high32;
    uint32_t zero;

} __attribute__((packed)) idt_entry_t;
void Initialize_IDT(void);


#endif