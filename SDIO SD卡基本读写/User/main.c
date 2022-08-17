#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "bps_usart.h"
#include "sdio_test.h"
#include "bsp_sdio_sdcard.h"
#include "bps_key.h"
#include <stdio.h>



int main()
{
	/* 初始化LED灯 */
  LED_GPIO_Config();
	LED_BLUE;	
	/* 初始化独立按键 */
	KEY1_GPIO_Config();
  
  /*初始化USART1*/
  USART_Config();
	
	printf("在开始进行SD卡基本测试前，请给开发板插入32G以内的SD卡\r\n");			
	printf("本程序会对SD卡进行 非文件系统 方式读写，会删除SD卡的文件系统\r\n");		
	printf("实验后可通过电脑格式化或使用SD卡文件系统的例程恢复SD卡文件系统\r\n");		
	printf("\r\n 但sd卡内的原文件不可恢复，实验前务必备份SD卡内的原文件！！！\r\n");		
	
	printf("\r\n 若已确认，请按开发板的KEY1按键，开始SD卡测试实验....\r\n");	
	
	while (1)
  {	
		/*按下按键开始进行SD卡读写实验，会损坏SD卡原文件*/
		if(	key_scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == key_on)
		{
			printf("\r\n开始进行SD卡读写实验\r\n");	
		  SD_Test();			
		}
	} 
	
}


/*
 * 函数名：SDIO_IRQHandler
 * 描述  ：在SDIO_ITConfig(）这个函数开启了sdio中断	，
 			数据传输结束时产生中断
 * 输入  ：无		 
 * 输出  ：无
 */
void SDIO_IRQHandler(void) 
{
  /* Process All SDIO Interrupt Sources */
  SD_ProcessIRQSrc();
}




