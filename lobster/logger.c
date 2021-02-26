#include "logger.h"
uint32_t logger_pos_y = 0;

int inline_strlen(char* msg) { int a=0;while(msg[a]!= '\0'){a++;} return a; }
void Lobster_InitLogger(int offset)
{
	logger_pos_y = offset;
}
void Lobster_Log(  enum lob_sym_t log_sym, char* message)
{
 
	 logger_pos_y += 8;
		VGE_PrintString(  "[Logger]: " , 7, rgb2hex(90,90,90));

	switch (log_sym){
		case LOBSTER_ERROR: // red
		{
		VGE_PrintString(  message , 7, rgb2hex(255,0,0));

		} break;

		case LOBSTER_WARNING: // yellow
		{
		VGE_PrintString( message, 7, rgb2hex(250,218,94) );

		} break;
		
		case LOBSTER_INFO: // 
		{
		VGE_PrintString( message, 7, rgb2hex(219,237,255)  );

		} break;
		case LOBSTER_SUCCESS: // 
		{
		VGE_PrintString( message, 7, rgb2hex(0,255,0)  );

		} break;
		
		default : // regular
		{
		VGE_PrintString( message, 7, rgb2hex(100,100,100));

		} break;
	}
}
