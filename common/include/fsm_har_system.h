/**
 * @file fsm_har_system.h
 * @author Josué Pagán (j.pagan@upm.es)
 * @brief Header file for the HAR system FSM.
 * @date 2024-05-01
 *
 */

#ifndef FSM_HAR_SYSTEM_H
#define FSM_HAR_SYSTEM_H

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>

/* Other includes */
#include <fsm.h>
#include "port_har_sensor.h"
#include "port_har_system.h"

/* Defines and enums ----------------------------------------------------------*/
/* Defines */
#define SAMPLING_FREQ_ACCEL 25                                          /*!< Sampling frequency of the accelerometer in Hz */
#define SAMPLING_PERIOD_ACCEL (1.0 / SAMPLING_FREQ_ACCEL)               /*!< Sampling period of the accelerometer in seconds */
#define WINDOW_SIZE_SECONDS 5                                           /*!< Window size in seconds */
#define WINDOW_SIZE_SAMPLES (WINDOW_SIZE_SECONDS * SAMPLING_FREQ_ACCEL) /*!< Window size in samples */
#define NUM_CHANNELS_ACCEL 3                                            /*!< Number of channels of the accelerometer */
#define NUM_METRICS 7                                                   /*!< Number of different metrics to compute */
#define NUM_FEATURES (NUM_METRICS * NUM_CHANNELS_ACCEL)                 /*!< Number of features to compute */
#define NUM_ACTIVITY_LABELS 5                                           /*!< Number of activity labels */
#define NUM_CLUSTERS NUM_ACTIVITY_LABELS                                /*!< Number of clusters */
#define MAX_NUM_RECORDS 300                                             /*!< Maximum number of records to store */

#define AXIS_X 0 /*!< X axis index */
#define AXIS_Y 1 /*!< Y axis index */
#define AXIS_Z 2 /*!< Z axis index */

/* Enums */
/**
 * @brief Enumerates the states of the HAR system FSM.
 *
 */
enum FSM_HAR_SYSTEM_STATES
{
    GET_DATA = 0,                 /*!< Get data from the accelerometer */
    COMPUTE_FEATURES,             /*!< Compute the features from the data */
    COMPUTE_ACTIVITY_RECOGNITION, /*!< Compute the activity recognition */
};

/**
 * @brief Enumerates the indexes of the features array.
 *
 */
enum FEATURES_INDEXES
{
    AMP_X = 0, /*!< Amplitude of the X axis */
    AMP_Y,     /*!< Amplitude of the Y axis */
    AMP_Z,     /*!< Amplitude of the Z axis */
    MED_X,     /*!< Median of the X axis */
    MED_Y,     /*!< Median of the Y axis */
    MED_Z,     /*!< Median of the Z axis */
    MEAN_X,    /*!< Mean of the X axis */
    MEAN_Y,    /*!< Mean of the Y axis */
    MEAN_Z,    /*!< Mean of the Z axis */
    MAX_X,     /*!< Maximum of the X axis */
    MAX_Y,     /*!< Maximum of the Y axis */
    MAX_Z,     /*!< Maximum of the Z axis */
    MIN_X,     /*!< Minimum of the X axis */
    MIN_Y,     /*!< Minimum of the Y axis */
    MIN_Z,     /*!< Minimum of the Z axis */
    VAR_X,     /*!< Variance of the X axis */
    VAR_Y,     /*!< Variance of the Y axis */
    VAR_Z,     /*!< Variance of the Z axis */
    STD_X,     /*!< Standard deviation of the X axis */
    STD_Y,     /*!< Standard deviation of the Y axis */
    STD_Z,     /*!< Standard deviation of the Z axis */
};

/* Typedefs ------------------------------------------------------------------*/
/**
 * @brief Structure to define the HAR knn_classifier. It contains an array of cluster centroids and an array of activity- labels (activity names).
 */
typedef struct
{
    double cluster_centroids[NUM_CLUSTERS][NUM_FEATURES]; /*!< Array of cluster centroids */
    const char *activity_labels[NUM_ACTIVITY_LABELS];     /*!< Array of activity labels */
} knn_har_classifier;

/**
 * @brief Structure to define the HAR system FSM.
 */
typedef struct
{
    fsm_t f;                           /*!< Base FSM structure */
    port_har_sensor_t *p_har_sensor;   /*!< Pointer to the HAR sensor structure */
    port_har_system_t har_system_hw;   /*!< Pointer to the HAR system hardware structure */
    knn_har_classifier knn_classifier; /*!< Pointer to the HAR knn_classifier structure */

    double acc_block[WINDOW_SIZE_SAMPLES][NUM_CHANNELS_ACCEL]; /*!< Block of accelerometer samples to compute features */
    uint32_t acc_sample_index;                                 /*!< Index of the accelerometer sample */
    bool acc_block_available;                                  /*!< Flag to indicate if the accelerometer block is available */

    double features[NUM_FEATURES]; /*!< Array of features */
    bool features_computed;        /*!< Flag to indicate if the features are computed */

    uint32_t activities_detected[MAX_NUM_RECORDS]; /*!< Array of detected activities */
    uint32_t activities_detected_index;            /*!< Index of the detected activities */
    char *last_activity_name;                      /*!< Pointer to the last activity name */
} fsm_har_system_t;

/* Function prototypes and explanations ---------------------------------------*/

/**
 * @brief Gets the activity of the HAR system FSM.
 *
 * @param p_this Pointer to the HAR system FSM.
 * @return const char* Pointer to the activity name.
 */
char *fsm_har_system_get_activity(fsm_t *p_this);

/**
 * @brief Creates a new HAR system FSM.
 *
 * @param p_har_sensor Pointer to the HAR sensor structure.
 * @return fsm_har_system_t* Pointer to the new HAR system FSM.
 */
fsm_t *fsm_har_system_new(port_har_sensor_t *p_har_sensor);

#endif /* FSM_HAR_SYSTEM_H */