/**
 * @file interr.c
 * @brief Interrupt service routines for the STM32F4 platform.
 * @author Josué Pagán (j.pagan@upm.es)
 * @date 2024-04-01
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>

// Include headers of different port elements:
#include "stm32f4xx.h"
#include "port_system.h"
#include "port_har_sensor.h"
#include "port_har_system.h"
#include "adc_data_stored.h"

//------------------------------------------------------
// INTERRUPT SERVICE ROUTINES
//------------------------------------------------------
/**
 * @brief Interrupt service routine for the System tick timer (SysTick).
 *
 * @note This ISR is called when the SysTick timer generates an interrupt.
 * The program flow jumps to this ISR and increments the tick counter by one millisecond.
 *
 * @warning **The variable `msTicks` must be declared volatile!** Just because it is modified by a call of an ISR, in order to avoid [*race conditions*](https://en.wikipedia.org/wiki/Race_condition)
. **Added to the definition** after *static*.
 *
 */
void SysTick_Handler(void)
{
  port_system_set_millis(port_system_get_millis() + 1);
}

/**
 * @brief Interrupt service routine for the TIM2 timer.
 *
 * @note This ISR is called when the TIM2 timer generates an interrupt.
 *
 */
void TIM2_IRQHandler(void)
{
  port_system_systick_resume(); // Resume the SysTick timer

  // Check if the ADC data is stored in a buffer or must be accessed directly from sensor structure
#ifndef USE_ADC_STORED // This macro is defined in the adc_data_stored.h file
  // Start the ADC conversion
  port_system_adc_start_conversion(har_sensor.x.p_adc, har_sensor.x.adc_channel);
  port_system_adc_start_conversion(har_sensor.y.p_adc, har_sensor.y.adc_channel);
  port_system_adc_start_conversion(har_sensor.z.p_adc, har_sensor.z.adc_channel);

#else
  // Do not start the ADC conversion, just read the stored values
  static uint32_t sample_idx = 0;
  port_har_sensor_save_adc_value(&har_sensor.x, ADC_STORED_ACC_X[sample_idx]);
  port_har_sensor_save_adc_value(&har_sensor.y, ADC_STORED_ACC_Y[sample_idx]);
  port_har_sensor_save_adc_value(&har_sensor.z, ADC_STORED_ACC_Z[sample_idx]);

  // There are few problems to print double values using printf with SWO. The value is multiplied by 10 and printed as an integer the decimal point is added manually.
  printf("d: %ld. ADC store data read [X, Y, Z]: [%ld, %ld, %ld] mV\n", sample_idx, (uint32_t)har_sensor.x.axis_value, (uint32_t)har_sensor.y.axis_value, (uint32_t)har_sensor.z.axis_value);

  sample_idx = (sample_idx + 1) % ADC_STORED_SAMPLES;
  
  // Notify that the samples are available
  har_sensor.samples_available = true;
#endif

  TIM2->SR &= ~TIM_SR_UIF; // Clear the update interrupt flag
}

/**
 * @brief Interrupt service routine for all the ADCs.
 *
 * @note This ISR is called when any ADC generates an interrupt.
 *
 */
void ADC_IRQHandler(void)
{
  // Local variables to identify when all 3 ADCs have finished the conversion
  static bool adc_x_conversion = false;
  static bool adc_y_conversion = false;
  static bool adc_z_conversion = false;

  // Identify if the ADC that generated the interrupt
  if (har_sensor.x.p_adc->SR & ADC_SR_EOC)
  {
    port_har_sensor_save_adc_value(&har_sensor.x, har_sensor.x.p_adc->DR);

    // Clear the ADC interrupt flag
    har_sensor.x.p_adc->SR &= ~ADC_SR_EOC;
    adc_x_conversion = true;
  }

  if (har_sensor.y.p_adc->SR & ADC_SR_EOC)
  {
    // Read the accelerometer sensor value
    port_har_sensor_save_adc_value(&har_sensor.y, har_sensor.y.p_adc->DR);

    // Clear the ADC interrupt flag
    har_sensor.y.p_adc->SR &= ~ADC_SR_EOC;
    adc_y_conversion = true;
  }

  if (har_sensor.z.p_adc->SR & ADC_SR_EOC)
  {
    // Read the accelerometer sensor value
    port_har_sensor_save_adc_value(&har_sensor.z, har_sensor.z.p_adc->DR);

    // Clear the ADC interrupt flag
    har_sensor.z.p_adc->SR &= ~ADC_SR_EOC;
    adc_z_conversion = true;
  }

  // Check if all the ADCs have finished the conversion
  if (adc_x_conversion && adc_y_conversion && adc_z_conversion)
  {
    // Set the flag to indicate that the samples are available
    har_sensor.samples_available = true;

    // Reset the flags
    adc_x_conversion = false;
    adc_y_conversion = false;
    adc_z_conversion = false;
  }
}