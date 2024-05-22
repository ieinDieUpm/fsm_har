/**
 * @file port_har_sensor.h
 * @author Josué Pagán (j.pagan@upm.es)
 * @brief Header file for the accelerometer sensor port layer.
 * @version 0.1
 * @date 2024-05-01
 *
 */

#ifndef PORT_HAR_SENSOR_H
#define PORT_HAR_SENSOR_H

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdbool.h>

/* HW dependent includes */
#include "port_system.h"

/* Defines and macros --------------------------------------------------------*/
// HW Nucleo-STM32F446RE:
#define HAR_SENSOR_X_GPIO GPIOA    /*!< GPIO port of the analog X axis of the accelerometer in the Nucleo board */
#define HAR_SENSOR_X_PIN 0         /*!< GPIO pin of the analog X axis of the accelerometer in the Nucleo board */
#define HAR_SENSOR_X_ADC ADC1      /*!< ADC of the analog X axis of the accelerometer in the Nucleo board */
#define HAR_SENSOR_X_ADC_CHANNEL 0 /*!< ADC channel of the analog X axis of the accelerometer in the Nucleo board */

#define HAR_SENSOR_Y_GPIO GPIOA    /*!< GPIO port of the analog Y axis of the accelerometer in the Nucleo board */
#define HAR_SENSOR_Y_PIN 1         /*!< GPIO pin of the analog Y axis of the accelerometer in the Nucleo board */
#define HAR_SENSOR_Y_ADC ADC1      /*!< ADC of the analog Y axis of the accelerometer in the Nucleo board */
#define HAR_SENSOR_Y_ADC_CHANNEL 1 /*!< ADC channel of the analog Y axis of the accelerometer in the Nucleo board */

#define HAR_SENSOR_Z_GPIO GPIOA    /*!< GPIO port of the analog Z axis of the accelerometer in the Nucleo board */
#define HAR_SENSOR_Z_PIN 4         /*!< GPIO pin of the analog Z axis of the accelerometer in the Nucleo board */
#define HAR_SENSOR_Z_ADC ADC1      /*!< ADC of the analog Z axis of the accelerometer in the Nucleo board */
#define HAR_SENSOR_Z_ADC_CHANNEL 4 /*!< ADC channel of the analog Z axis of the accelerometer in the Nucleo board */

/* Typedefs --------------------------------------------------------------------*/

/**
 * @brief Structure to store the information of an analog axis of the accelerometer. 
 * 
 */
typedef struct
{
    GPIO_TypeDef *p_port; /*!< GPIO where the analog axis of the accelerometer is connected */
    uint8_t pin;          /*!< Pin where the analog axis of the accelerometer is connected */
    ADC_TypeDef *p_adc;   /*!< ADC where the axis of the accelerometer is connected */
    uint32_t adc_channel; /*!< ADC channel where the axis of the accelerometer is connected */
    double axis_value;    /*!< Value of the axis of the accelerometer */
} analog_acc_axis_t;

/**
 * @brief Structure to store the information of the accelerometer sensor. 
 * 
 */
typedef struct
{
    analog_acc_axis_t x;    /*!< X axis of the accelerometer */
    analog_acc_axis_t y;    /*!< Y axis of the accelerometer */
    analog_acc_axis_t z;    /*!< Z axis of the accelerometer */
    bool samples_available; /*!< Flag to indicate if a sample is available */    
} port_har_sensor_t;

/* Global variables -----------------------------------------------------------*/
extern port_har_sensor_t har_sensor; /*!< Accelerometer sensor of the HAR system system. Public for access to interrupt handlers. */

/* Function prototypes -------------------------------------------------------*/

/**
 * @brief Checks if the time has passed to get a new sample from the accelerometer sensor.
 *
 * @param p_har_sensor Pointer to the accelerometer sensor.
 * @return true Sample available.
 * @return false Sample not available.
 */
bool port_har_sensor_check_samples_available(port_har_sensor_t *p_har_sensor);

/**
 * @brief Saves the ADC value of the accelerometer sensor and converts it to millivolts.
 *
 * @param p_axis Pointer to the axis of the accelerometer sensor.
 * @param adc_value ADC value of the accelerometer sensor.
 */
void port_har_sensor_save_adc_value(analog_acc_axis_t *p_axis, double adc_value);

/**
 * @brief Initializes the HAR sensor.
 *
 * @param p_har_sensor Pointer to the accelerometer sensor.
 */
void port_har_sensor_init(port_har_sensor_t *p_har_sensor);

#endif /* PORT_HAR_SENSOR_H */