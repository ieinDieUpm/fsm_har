/**
 * @file port_har_sensor.c
 * @author Josué Pagán (j.pagan@upm.es)
 * @brief Port layer for a accelerometer sensor.
 * @version 0.1
 * @date 2024-05-01
 *
 */

/* Standard C includes */
#include <stdint.h>
#include <stdio.h>

/* HW dependent includes */
#include "port_har_sensor.h"
#include "stm32f4xx.h"
#include "port_system.h"

/* Other includes */
#include "adc_data_stored.h"

/* Global variables -----------------------------------------------------------*/
port_har_sensor_t har_sensor = {
    .x = {
        .p_port = HAR_SENSOR_X_GPIO,
        .pin = HAR_SENSOR_X_PIN,
        .p_adc = HAR_SENSOR_X_ADC,
        .adc_channel = HAR_SENSOR_X_ADC_CHANNEL,
        .axis_value = 0.0,
    },
    .y = {
        .p_port = HAR_SENSOR_Y_GPIO,
        .pin = HAR_SENSOR_Y_PIN,
        .p_adc = HAR_SENSOR_Y_ADC,
        .adc_channel = HAR_SENSOR_Y_ADC_CHANNEL,
        .axis_value = 0.0,
    },
    .z = {
        .p_port = HAR_SENSOR_Z_GPIO,
        .pin = HAR_SENSOR_Z_PIN,
        .p_adc = HAR_SENSOR_Z_ADC,
        .adc_channel = HAR_SENSOR_Z_ADC_CHANNEL,
        .axis_value = 0.0,
    },
    .samples_available = false,
};

/* Private functions */

/**
 * @brief Converts an ADC value to millivolts.
 *
 * @param adcValue Counts of the ADC
 * @param adc_res_bits Resolution of the ADC in bits
 * @return uint32_t Millivolts
 */
uint32_t _adc_to_mvolts(uint32_t adcValue, uint8_t adc_res_bits)
{
#ifdef USE_ADC_STORED // This macro is defined in the adc_data_stored.h file
    uint32_t mvolts = (ADC_VREF_5000_MV * adcValue) / ((1 << adc_res_bits) - 1);
#else
    uint32_t mvolts = (ADC_VREF_3300_MV * adcValue) / ((1 << adc_res_bits) - 1);
#endif
    return mvolts;
}
/* Function definitions ------------------------------------------------------*/
bool port_har_sensor_check_samples_available(port_har_sensor_t *p_har_sensor)
{
    return p_har_sensor->samples_available;
}

void port_har_sensor_save_adc_value(analog_acc_axis_t *p_axis, double adc_value)
{
    // Convert the ADC value to millivolts
    p_axis->axis_value = _adc_to_mvolts(adc_value, 12);
}

void port_har_sensor_init(port_har_sensor_t *p_har_sensor)
{
    // Initialize the GPIOs
    port_system_gpio_config(p_har_sensor->x.p_port, p_har_sensor->x.pin, GPIO_MODE_ANALOG, GPIO_PUPDR_NOPULL);
    port_system_gpio_config(p_har_sensor->y.p_port, p_har_sensor->y.pin, GPIO_MODE_ANALOG, GPIO_PUPDR_NOPULL);
    port_system_gpio_config(p_har_sensor->z.p_port, p_har_sensor->z.pin, GPIO_MODE_ANALOG, GPIO_PUPDR_NOPULL);

    // Initialize the ADC with 12-bit resolution and EOC interrupt enable
    port_system_adc_single_ch_init(p_har_sensor->x.p_adc, p_har_sensor->x.adc_channel, ADC_RESOLUTION_12B | ADC_EOC_INTERRUPT_ENABLE);
    port_system_adc_single_ch_init(p_har_sensor->y.p_adc, p_har_sensor->y.adc_channel, ADC_RESOLUTION_12B | ADC_EOC_INTERRUPT_ENABLE);
    port_system_adc_single_ch_init(p_har_sensor->z.p_adc, p_har_sensor->z.adc_channel, ADC_RESOLUTION_12B | ADC_EOC_INTERRUPT_ENABLE);

    // Enable the ADC global interrupt
    port_system_adc_interrupt_enable(1, 0);

    // Enable the ADCs
    port_system_adc_enable(p_har_sensor->x.p_adc);
    port_system_adc_enable(p_har_sensor->y.p_adc);
    port_system_adc_enable(p_har_sensor->z.p_adc);
}