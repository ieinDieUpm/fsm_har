/**
 * @file port_har_system.h
 * @author Josué Pagán (j.pagan@upm.es)
 * @brief Header file for the HAR system system port layer.
 * @version 0.1
 * @date 2024-05-01
 *
 */

#ifndef PORT_HAR_SYSTEM_H
#define PORT_HAR_SYSTEM_H

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */

/* HW dependent includes */
#include "port_system.h"

/* Defines and macros --------------------------------------------------------*/
// HW Nucleo-STM32F446RE:
#define HAR_SYSTEM_TIMER TIM2 /*!< Timer to measure the acceleration in the Nucleo board */

/* Typedefs --------------------------------------------------------------------*/

/**
 * @brief Structure to store the information of the HAR system hardware. 
 * 
 */
typedef struct
{
    TIM_TypeDef *p_timer; /*!< Period of the timer in seconds */
} port_har_system_t;

/* Function prototypes -------------------------------------------------------*/

/**
 * @brief Initializes the timer of the HAR system.
 *
 * @param p_timer Pointer to the timer of the HAR system hardware.
 * @param period_sec Period of the timer in seconds.
 */
void port_har_system_timer_setup(TIM_TypeDef *p_timer, double period_sec);

/**
 * @brief Disables the timer of the HAR system.
 *
 * @param p_har_system_hw Pointer to the HAR system hardware.
 */
void port_har_system_timer_disable(port_har_system_t *p_har_system_hw);

/**
 * @brief Enables the timer of the HAR system.
 *
 * @param p_har_system_hw Pointer to the HAR system hardware.
 */
void port_har_system_timer_enable(port_har_system_t *p_har_system_hw);

#endif
