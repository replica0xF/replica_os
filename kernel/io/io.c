#include "io.h"

void outb(int port, unsigned char val)s
{
	__asm__ volatile ( "outb %0, %1" : : "a"(val) , "Nd"(port) );
}
unsigned char inb(int port){
	unsigned char return_t = 0;
	__asm__ volatile ( "inb %1, %0" 
					:  "=a"(return_t) 
					: "Nd"(port)
				  );
	return return_t;
}