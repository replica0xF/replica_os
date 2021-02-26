#ifndef PANIC_H
#define PANIC_H
#include "../drivers/video/vge.h"
void kernel_panic( char* message , int err_code);

#endif