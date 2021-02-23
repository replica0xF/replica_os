#ifndef IO_H
#define IO_H
#include <stddef.h>

void outb(int port, unsigned char val);

unsigned char inb(int port);


#endif