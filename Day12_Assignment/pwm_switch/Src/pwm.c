/*
 * pwm.c
 *
 *  Created on: Oct 2, 2024
 *      Author: sunbeam
 */

#include "pwm.h"

void PWM_Init(void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= BV(6*2+1);
	GPIOC->MODER &= ~BV(6*2);
	GPIOC->AFR[0] |= BV(24) | BV(25);

	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;

	TIM8->ARR = ARR_Val;

	TIM8->CCR1 = 0;

	TIM8->CCMR1 &= ~(TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC1S_1);

	TIM8->CCER &= ~TIM_CCER_CC1P;

	TIM8->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;

	TIM8->CCMR1 |= TIM_CCMR1_OC1PE;
	TIM8->CR1 |= TIM_CR1_ARPE;

	TIM8->CR1 &= ~(TIM_CR1_CMS_0 | TIM_CR1_CMS_1);

	TIM8->CCER |= TIM_CCER_CC1E;

	TIM8->BDTR |= TIM_BDTR_MOE;
	TIM8->CR1 |= TIM_CR1_CEN;
}



























