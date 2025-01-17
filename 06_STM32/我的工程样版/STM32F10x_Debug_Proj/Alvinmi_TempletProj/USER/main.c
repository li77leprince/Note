/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <string.h>
#include <stdio.h>
#include "stm32f10x_rcc.h"
#include "delay.h"
#include "usart.h" 
#include "sys.h"
//#include "epson_m150ii.h"
#include "timer.h"
//#include "oled.h"
//#include "lcd.h"

ErrorStatus HSEStartUpStatus;

void RCC_Configuration(void)
{   
	/* RCC system reset(for debug purpose) */
	RCC_DeInit();

	/* Enable HSE */
	RCC_HSEConfig(RCC_HSE_ON);

	/* Wait till HSE is ready */
	HSEStartUpStatus = RCC_WaitForHSEStartUp();

	if(HSEStartUpStatus == SUCCESS)
	{
		/* HCLK = SYSCLK */
		RCC_HCLKConfig(RCC_SYSCLK_Div1); 
  
		/* PCLK2 = HCLK */
		RCC_PCLK2Config(RCC_HCLK_Div1); 

		/* PCLK1 = HCLK/2 */
		RCC_PCLK1Config(RCC_HCLK_Div2);

		/* Flash 2 wait state */
		FLASH_SetLatency(FLASH_Latency_2);
		/* Enable Prefetch Buffer */
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

		/* PLLCLK = 8MHz * 9 = 72 MHz */
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);

		/* Enable PLL */ 
		RCC_PLLCmd(ENABLE);

		/* Wait till PLL is ready */
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
		{
		}

		/* Select PLL as system clock source */
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

		/* Wait till PLL is used as system clock source */
		while(RCC_GetSYSCLKSource() != 0x08)
		{
		}
	}

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 | 
		RCC_APB2Periph_GPIOA |
		RCC_APB2Periph_GPIOB |
		RCC_APB2Periph_ADC1 |
		RCC_APB2Periph_USART1 |
		RCC_APB2Periph_AFIO,		
		ENABLE);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 |
		RCC_APB1Periph_TIM4, 
		ENABLE);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, 
		ENABLE);

	/* Enable DMA clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	//	SEGGER_RTT_printf(0, "sysclock is %d", SystemCoreClock );
}


/*******************************************************************
+-----------------------------------------------------------+
|					NVIC 优先级配置表						|
+-----------------------------------------------------------+
|		名称		|			用途			|	优先级	|
+-----------------------------------------------------------+
|	Reset:PB10 		|      打印机中断驱动		|Pre:4,Sub:1|
+-----------------------------------------------------------+
|					|							|			|
+-----------------------------------------------------------+
|					|							|			|
------------------------------------------------------------+

===================================================================

+-----------------------------------------------------------+
|					Timer 分配表							|
+-----------------------------------------------------------+
|	TimerX	|					用	途						|		
+-----------------------------------------------------------+
|	Timer1	|				     							|	
+-----------------------------------------------------------+
|	Timer2	|												|	
+-----------------------------------------------------------+
|	Timer3	|												|	
+-----------------------------------------------------------+
|	Timer4	|												|	
+-----------------------------------------------------------+

*******************************************************************/


int main(void)
{	
//	RCC_Configuration();	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		// 位于同一组别, 

	Uart1_Init(115200);	// 串口初始化： 波特率 115200, 8 数据位, 1 位停止位, 禁用奇偶校验
	printf("\r\n usart init finish \r\n");

	delay_init();		// 延时初始化

	/*** OLED_Test ***/
//	OLED_Init();			//初始化OLED  
//	OLED_Clear(); 

	/*** LCD_Test ***/
//	LCD_Init();
//	POINT_COLOR=GRAY;
//	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);    // 将LCD ID 打印到 lcd_id 数组。	
	
	printf("\r\n <<===== BSP Init finish =====>> \r\n");

  	while (1)
  	{

  	}
}

