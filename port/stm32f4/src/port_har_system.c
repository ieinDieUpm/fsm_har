/**
 * @file port_har_system.c
 * @file port_har_system.h
 * @author Josué Pagán (j.pagan@upm.es)
 * @brief Source file for the HAR system system port layer.
 * @version 0.1
 * @date 2024-05-01
 *
 */

/* Standard C includes */
#include <stdlib.h>
#include <math.h>

/* Project includes */
#include "port_system.h"
#include "port_har_system.h"

/* Private functions ---------------------------------------------------------*/
void port_har_system_timer_setup(TIM_TypeDef *p_timer, double period)
{
    if (p_timer == TIM2)
    {
        // Enable the timer clock
        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    }

    // Disable the timer
    p_timer->CR1 &= ~TIM_CR1_CEN;

    // Autoreload preload enabled
    p_timer->CR1 |= TIM_CR1_ARPE;

    // Reset the values of the timer
    p_timer->CNT = 0;

    // Set the timeout value
    // Compute ARR and PSC to match the duration. Check if the duration is too long and adapt prescaler and ARR
    double sec = period;
    double scc = (double)SystemCoreClock;
    double psc = round(((scc * sec) / (65535.0 + 1.0)) - 1.0);
    double arr = round(((scc * sec) / (psc + 1.0)) - 1.0);

    // Adjust psc and arr if necessary
    if (arr > 0xFFFF)
    {
        psc += 1.0;
        arr = round((scc * sec) / (psc + 1.0) - 1.0);
    }

    // Load the values
    p_timer->ARR = (uint32_t)(round(arr));
    p_timer->PSC = (uint32_t)(round(psc));

    // Clean interrupt flags
    p_timer->SR &= ~TIM_SR_UIF;

    // Enable the update interrupt
    p_timer->DIER |= TIM_DIER_UIE;

    if (p_timer == TIM2)
    {
        // Enable the interrupt in the NVIC
        NVIC_SetPriority(TIM2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 2, 0));
        NVIC_EnableIRQ(TIM2_IRQn);
    }

    p_timer->EGR |= TIM_EGR_UG; // 6) Update generation: Re-inicializa el contador y actualiza los registros. IMPORTANTE que esté lo último

    // Enable the timer
    p_timer->CR1 |= TIM_CR1_CEN;
}

void port_har_system_timer_disable(port_har_system_t *p_har_system_hw)
{
    // Disable the timer
    p_har_system_hw->p_timer->CR1 &= ~TIM_CR1_CEN;
}

void port_har_system_timer_enable(port_har_system_t *p_har_system_hw)
{
    // Enable the timer
    p_har_system_hw->p_timer->CR1 |= TIM_CR1_CEN;
}