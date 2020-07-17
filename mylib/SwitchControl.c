#include "SwitchControl.h"

GPIO_InitTypeDef g_sw; //GPIO struct
EXTI_InitTypeDef e_SW; // EXTI struct
NVIC_InitTypeDef n_SW; // NVIC struct
void EXTI_Config_0(void)
{
    //cap clock cho ngat ngoai va ngoai vi
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
    g_sw.GPIO_Pin = GPIO_Pin_0;
    g_sw.GPIO_Speed = GPIO_Speed_50MHz;
    g_sw.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &g_sw);
    /* mapping */
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
    /* Clear the the EXTI line interrupt pending bit */
    EXTI_ClearITPendingBit(EXTI_Line0);
    /*EXTI line Configuration */
    e_SW.EXTI_Mode = EXTI_Mode_Interrupt;
    e_SW.EXTI_Line = EXTI_Line0;
    e_SW.EXTI_Trigger = EXTI_Trigger_Falling;
    e_SW.EXTI_LineCmd = ENABLE;
    EXTI_Init(&e_SW);
    /*NVIC Configuration*/
    n_SW.NVIC_IRQChannel = EXTI0_IRQn;
    n_SW.NVIC_IRQChannelPreemptionPriority = 0;
    n_SW.NVIC_IRQChannelSubPriority = 0;
    n_SW.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&n_SW);
		NVIC_EnableIRQ(EXTI0_IRQn);
}