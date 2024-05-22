/**
 * @file main.c
 * @author Josué Pagán (j.pagan@upm.es)
 * @brief   Activity recognition from acceleration data (analog).
 *   Node located in the right arm (RA)
 *   Trained for 5 different activities, as:
 *   (label:activity) --> 18: jumping, 2: standing, 12: running, 10: walkingSlow, 1: sitting
 * The accelerometer used is the ADXL335. The dataset used for training and testing belongs to the UCI repository: http://archive.ics.uci.edu/ml/datasets/Daily+and+Sports+Activities
 * @version 0.1
 * @date 2024-05-01
 *
 */

/* INCLUDES */
#include <stdio.h>
#include <string.h>
#include "port_system.h"
#include "fsm_har_system.h"
#include "port_har_sensor.h"

/* Defines and macros --------------------------------------------------------*/

/* MAIN FUNCTION */

/**
 * @brief Main function
 *
 * @return int
 */
int main()
{
    /* Init board */
    port_system_init();

    // Create an HAR system FSM and get a pointer to it
    fsm_t *p_fsm_har_system = fsm_har_system_new(&har_sensor);

    while (1)
    {
        // Launch the FSM
        fsm_fire(p_fsm_har_system);
    }
    return 0;
}