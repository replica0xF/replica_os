#include "logger.h"
uint32_t logger_pos_y = 0;

int inline_strlen(char* msg) { int a=0;while(msg[a]!= '\0'){a++;} return a; }
void Lobster_InitLogger(int offset)
{
	logger_pos_y = offset;
}
void Lobster_Log(struct stivale2_struct_tag_framebuffer* fb, enum lob_sym_t log_sym, char* message)
{
 
	 logger_pos_y += 8;
	switch (log_sym){
		case LOBSTER_ERROR: // red
		{
		VGE_PrintString(fb , message , 7, rgb2hex(255,0,0));

		} break;

		case LOBSTER_WARNING: // yellow
		{
		VGE_PrintString(fb , message, 7, rgb2hex(250,218,94) );

		} break;
		
		case LOBSTER_INFO: // 
		{
		VGE_PrintString(fb , message, 7, rgb2hex(219,237,255)  );

		} break;
		
		default : // regular
		{
		VGE_PrintString(fb , message, 7, rgb2hex(100,100,100));

		} break;
	}
}
