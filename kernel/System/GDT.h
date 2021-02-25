#ifndef GDT_H
#define GDT_H
#include <stdint.h>
#include "../../lobster/logger.h"

struct gdt_ptr 
{
  uint16_t limit;
  uint64_t base;
} __attribute__((packed));
  
struct gdt_descriptor
{
  uint16_t limit_low16;
  uint16_t base_low16;
  uint8_t base_mid16;
  uint8_t access;
  uint8_t flags;
  uint8_t base_high;
} __attribute__((packed));

void InitGDT();

#endif