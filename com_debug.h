#ifndef __COM_DEBUG_H__
#define	__COM_DEBUG_H__

#include "stdio.h"
#include "string.h"

#define DEBUG			0

#if (DEBUG)

#include "USART.h"

#define DEBUG_Init()		USART2_Init()

#define		MAX_DEBUG_BUFFER_SIZE			128

extern uint8_t   DebugBuffer[MAX_DEBUG_BUFFER_SIZE];

void DEBUG_Print(uint8_t *data);

/*
调试输出调用接口Debug()
*/
#define		Debug(x,...)		{sprintf((char *)DebugBuffer, "FILE:%s, LINE:%d " "FUNCTION: " x "\n" ,__FILE__,__LINE__,##__VA_ARGS__);\
														DEBUG_Print(DebugBuffer);}

#define		vPort_Com_Write(data, size)			USART2_Write(data, size)  //移植重定义此宏
														
#else

#define DEBUG_Init()														
#define		Debug(x,...)
#define		vPort_Com_Write(data, size)																		
														
#endif



#endif
