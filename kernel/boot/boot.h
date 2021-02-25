#ifndef BOOT_H
#define BOOT_H
#include "stivale2.h"
#include "../main.h"
#include <stddef.h>

 struct stivale2_struct_tag_framebuffer* fb_hdr_tag;
void* stivale2_get_tag(struct stivale2_struct * stivale2_struct , uint64_t id);

void Boot_LocateTag(struct stivale2_struct * stivale2_struct );
void Boot_Loop();

#endif