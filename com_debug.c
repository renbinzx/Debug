#include "com_debug.h"
#include "str_int.h"


#if (DEBUG)
uint8_t   DebugBuffer[MAX_DEBUG_BUFFER_SIZE];
#endif




void DEBUG_Print(uint8_t *data)
{
	uint8_t size;
	
	size = strlen((char *)data);
	//RS485_Write(data, size);
	vPort_Com_Write(data, size);
}
