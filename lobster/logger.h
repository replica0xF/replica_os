#ifndef LOGGER_H
#define LOGGER_H
#include "kernel/devices/video/vge.h"

typedef enum lob_sym_t
{
	LOBSTER_ERROR = 1 << 1,
	LOBSTER_WARNING = 1 << 2,
	LOBSTER_INFO = 1 << 3
} lob_sym;
 
void Lobster_Log(struct stivale2_struct_tag_framebuffer* fb,  enum lob_sym_t log_sym, char* message);

#endif