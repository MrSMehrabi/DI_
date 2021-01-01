
#include "stm32f746xx.h"
#include "stm32f7xx_hal_gpio.h"

#define __HAL_RCC_GPIOI_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOIEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOIEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
int main()
	
{
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOIEN;

	
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };


	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);

	/*Configure GPIO pin : PI1 */
	GPIO_InitStruct.Pin = GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);
	
  
	
	while (true)
	{
		//comment 2
		//commit azure 4
		//3 commit
		
		//5commit
		HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);
		for (size_t i = 0; i < 10000; i++)
		{
			for (size_t i = 0; i < 1000; i++) ;
		}
	}
}