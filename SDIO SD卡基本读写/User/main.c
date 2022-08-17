#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "bps_usart.h"
#include "sdio_test.h"
#include "bsp_sdio_sdcard.h"
#include "bps_key.h"
#include <stdio.h>



int main()
{
	/* ��ʼ��LED�� */
  LED_GPIO_Config();
	LED_BLUE;	
	/* ��ʼ���������� */
	KEY1_GPIO_Config();
  
  /*��ʼ��USART1*/
  USART_Config();
	
	printf("�ڿ�ʼ����SD����������ǰ��������������32G���ڵ�SD��\r\n");			
	printf("��������SD������ ���ļ�ϵͳ ��ʽ��д����ɾ��SD�����ļ�ϵͳ\r\n");		
	printf("ʵ����ͨ�����Ը�ʽ����ʹ��SD���ļ�ϵͳ�����ָ̻�SD���ļ�ϵͳ\r\n");		
	printf("\r\n ��sd���ڵ�ԭ�ļ����ɻָ���ʵ��ǰ��ر���SD���ڵ�ԭ�ļ�������\r\n");		
	
	printf("\r\n ����ȷ�ϣ��밴�������KEY1��������ʼSD������ʵ��....\r\n");	
	
	while (1)
  {	
		/*���°�����ʼ����SD����дʵ�飬����SD��ԭ�ļ�*/
		if(	key_scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == key_on)
		{
			printf("\r\n��ʼ����SD����дʵ��\r\n");	
		  SD_Test();			
		}
	} 
	
}


/*
 * ��������SDIO_IRQHandler
 * ����  ����SDIO_ITConfig(���������������sdio�ж�	��
 			���ݴ������ʱ�����ж�
 * ����  ����		 
 * ���  ����
 */
void SDIO_IRQHandler(void) 
{
  /* Process All SDIO Interrupt Sources */
  SD_ProcessIRQSrc();
}




