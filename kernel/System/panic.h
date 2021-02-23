#ifndef PANIC_H
#define PANIC_H
#include "../devices/video/vge.h"
void kernel_panic(struct stivale2_struct_tag_framebuffer* fb, char* message , int err_code);

#endif