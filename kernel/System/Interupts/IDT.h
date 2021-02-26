
#ifndef IDT_h
#define IDT_H
#include <stdint.h>
#include "exception.h"
#include "../../../lobster/logger.h"

typedef struct
{
   uint16_t size;
    uint64_t addr;
} __attribute__((packed)) idtr_t;

typedef struct
{
   uint16_t offset_lo;
    uint16_t selector;
    uint8_t ist;
    uint8_t type_attr;
    uint16_t offset_mid;
    uint32_t offset_hi;
    uint32_t zero;

}

 __attribute__((packed)) idt_entry_t;
void Initialize_IDT(void);


#endif