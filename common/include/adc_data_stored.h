
/**
 * @file adc_data_stored.h
 * @author Josué Pagán (j.pagan@upm.es)
 * @brief Header file for the declaration of the stored ADC data.
 * @date 2024-05-01
 *
 */

#ifndef ADC_DATA_STORED_H
#define ADC_DATA_STORED_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

#include "port_system.h"

/* Defines and macros --------------------------------------------------------*/
#define USE_ADC_STORED /*!< Macro to indicate that the ADC data is stored in a buffer and not accessed directly */

#define ADC_STORED_SAMPLES 1024 /*!< Number of samples stored per axis */

/**
 * @brief Stored values of the X axis of the accelerometer in ADC counts with a sampling frequency of 25 Hz and a Vref+ of 5000 mV.
 *
 */
extern const uint32_t ADC_STORED_ACC_X[];

/**
 * @brief Stored values of the Y axis of the accelerometer in ADC counts with a sampling frequency of 25 Hz and a Vref+ of 5000 mV.
 *
 */
extern const uint32_t ADC_STORED_ACC_Y[];

/**
 * @brief Stored values of the Z axis of the accelerometer in ADC counts with a sampling frequency of 25 Hz and a Vref+ of 5000 mV.
 *
 */
extern const uint32_t ADC_STORED_ACC_Z[];

#endif