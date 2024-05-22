/**
 * @file fsm_har_system.c
 * @author Josué Pagán (j.pagan@upm.es)
 * @brief Finite State Machine for a HAR system.
 * @date 2024-05-01
 *
 */

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Project includes */
#include "fsm_har_system.h"
#include "knn_har_model.h"
#include "port_har_sensor.h"

/* Private functions ---------------------------------------------------------*/

/**
 * @brief Compute the maximum value of an axis
 *
 * > TO-DO: \n
 * > 1. Recorrer el bloque de aceleración para el eje indicado y encontrar el valor máximo \n
 * 
 * @param p_fsm Pointer to the HAR system FSM structure
 * @param axis Axis index to compute the maximum value
 * @return double Maximum value of the axis
 */
double _compute_max(fsm_har_system_t *p_fsm, uint8_t axis)
{
    
}

/**
 * @brief Compute the minimum value of an axis
 *
 * > TO-DO: \n
 * > 1. Recorrer el bloque de aceleración para el eje indicado y encontrar el valor mínimo \n
 *
 * @param p_fsm Pointer to the HAR system FSM structure
 * @param axis Axis index to compute the minimum value
 * @return double Minimum value of the axis
 */
double _compute_min(fsm_har_system_t *p_fsm, uint8_t axis)
{
    
    
}

/**
 * @brief Compute the mean value of an axis
 *
 * > TO-DO: \n
 * > 1. Recorrer el bloque de aceleración para el eje indicado y encontrar el valor medio \n
 *
 * @param p_fsm Pointer to the HAR system FSM structure
 * @param axis Axis index to compute the mean value
 * @return double Mean value of the axis
 */
double _compute_mean(fsm_har_system_t *p_fsm, uint8_t axis)
{
    
    
}

/**
 * @brief Compare function for qsort to sort an array of doubles
 *
 * @param a Pointer to the first element to compare
 * @param b Pointer to the second element to compare
 * @return int 0 if the elements are equal, 1 if the first element is greater than the second, -1 if the first element is less than the second
 */
int _compare_doubles(const void *a, const void *b)
{
    double arg1 = *(const double *)a;
    double arg2 = *(const double *)b;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

/**
 * @brief Compute the median value of an axis
 *
 * @param p_fsm Pointer to the HAR system FSM structure
 * @param axis Axis index to compute the median value
 * @return double Median value of the axis
 */
double _compute_median(fsm_har_system_t *p_fsm, uint8_t axis)
{
    double axis_cpy[WINDOW_SIZE_SAMPLES];

    // Copy the row to a local array to sort it
    for (uint32_t r = 0; r < WINDOW_SIZE_SAMPLES; r++)
    {
        axis_cpy[r] = p_fsm->acc_block[r][axis];
    }
    qsort(axis_cpy, WINDOW_SIZE_SAMPLES, sizeof(axis_cpy[0]), _compare_doubles); // Short axis_cpy
    return axis_cpy[(uint32_t)round(WINDOW_SIZE_SAMPLES / 2)];                   // Value in the middle
}

/**
 * @brief Compute the variance value of an axis
 *
 * > TO-DO: \n
 * > 1. Recorrer el bloque de aceleración para el eje indicado y encontrar la varianza. Utilizar la media previamente calculada según el eje dado. \n
 * > La fórmula de la varianza es: \n
 * > @image html variance.png
 *
 * @param p_fsm Pointer to the HAR system FSM structure
 * @param axis Axis index to compute the variance value
 * @return double Variance value of the axis
 */
double _compute_variance(fsm_har_system_t *p_fsm, uint8_t axis)
{
    
}

/* State machine input or transition functions */

/**
 * @brief Check if there are new samples available
 *
 * @param p_this Pointer to the HAR system FSM structure
 * @return true If there is a new sample available to be converted
 * @return false If there is no new sample available
 */
static bool check_sample(fsm_t *p_this)
{
    fsm_har_system_t *p_fsm = (fsm_har_system_t *)p_this;
    return port_har_sensor_check_samples_available(p_fsm->p_har_sensor);
}

/**
 * @brief Check if the block size is complete to compute the features
 *
 * @param p_this Pointer to the HAR system FSM structure
 * @return true If the block size is complete
 * @return false If the block size is not complete
 */
static bool check_block_size(fsm_t *p_this)
{
    fsm_har_system_t *p_fsm = (fsm_har_system_t *)p_this;
    return p_fsm->acc_block_available;
}

/**
 * @brief Check if the features are computed
 *
 * @param p_this Pointer to the HAR system FSM structure
 * @return true If the features are computed
 * @return false If the features are not computed
 */
static bool check_features(fsm_t *p_this)
{
    fsm_har_system_t *p_fsm = (fsm_har_system_t *)p_this;
    return p_fsm->features_computed;
}

/**
 * @brief Check if the activity is computed
 *
 * @param p_this Pointer to the HAR system FSM structure
 * @return true If the activity is computed
 * @return false If the activity is not computed
 */
static bool check_activity(fsm_t *p_this)
{
    static uint32_t last_activity_index = 0;
    fsm_har_system_t *p_fsm = (fsm_har_system_t *)p_this;

    // Check if the last activity is different from the current activity
    if (last_activity_index != p_fsm->activities_detected_index)
    {
        last_activity_index = p_fsm->activities_detected_index;
        return true;
    }
    return false;
}

/* State machine output or action functions */

/**
 * @brief Store the data from the accelerometer sensor
 *
 * @param p_this Pointer to the HAR system FSM structure
 */
static void do_store_data(fsm_t *p_this)
{
    fsm_har_system_t *p_fsm = (fsm_har_system_t *)p_this;
    port_har_sensor_t *p_har_sensor = p_fsm->p_har_sensor;

    uint32_t current_idx = p_fsm->acc_sample_index;

    // Save the sample in the acceleration block
    p_fsm->acc_block[current_idx][AXIS_X] = p_har_sensor->x.axis_value;
    p_fsm->acc_block[current_idx][AXIS_Y] = p_har_sensor->y.axis_value;
    p_fsm->acc_block[current_idx][AXIS_Z] = p_har_sensor->z.axis_value;

    // Increase the sample index
    p_fsm->acc_sample_index++;

    // Disable the flag to indicate that the sample is not available
    p_har_sensor->samples_available = false;

    if (p_fsm->acc_sample_index >= WINDOW_SIZE_SAMPLES)
    {
        p_fsm->acc_sample_index = 0;                          // Restart the index
        port_har_system_timer_disable(&p_fsm->har_system_hw); // Disable the timer to compute the features
        p_fsm->acc_block_available = true;                    // Enable the flag to indicate that the block is available
    }
    else
    {
        port_system_sleep(); // Go to sleep
    }
}

/**
 * @brief Compute the features from the acceleration block
 *
 * > TO-DO: \n
 * > 1. Guardar en el array `features` los valores de las características de las tres componentes de la aceleración (X, Y, Z) en el siguiente orden. Utilizar las etiquetas definidas en el fichero `fsm_har_system.h` para acceder a los índices del array. \n
 * > 2. Calcular el máximo, mínimo, media, mediana, varianza, llamando a las funciones correspondientes para cada componente de la aceleración. \n
 * > 3. Calcular la desviación estándar para cada componente de la aceleración. Utilizar la función `sqrt` de la librería `math.h` para calcular la raíz cuadrada. \n
 * > 4. Calcular la amplitud para cada componente de la aceleración como la diferencia entre el máximo y la media. \n
 * 
 * @param p_this Pointer to the HAR system FSM structure
 */
static void do_compute_features(fsm_t *p_this)
{
    fsm_har_system_t *p_fsm = (fsm_har_system_t *)p_this;

    // Calcular el máximo, mínimo, media, mediana, y varianza para cada componente de la aceleración
    





    // Calcular la varianza y la desviación estándar. Para calcular la varianza es importante calcular primero la media, luego la varianza, y finalmente la desviación estándar
    
    




    // Calcular la amplitud. Es importante calcular la amplitud después del máximo y la media
    
    




    // Enable the flag to indicate that the features are computed
    p_fsm->features_computed = true;

    // Disable the flag to indicate that the block is not available
    p_fsm->acc_block_available = false;

    // Print each feature for X, Y, and Z axis. Float does not work with printf, so we need to print the integer part and the decimal part separately
    printf("\nf: %ld. Features computed:\n", p_fsm->acc_sample_index);
    printf("Max X: %ld.%ld, Max Y: %ld.%ld, Max Z: %ld.%ld\n", (uint32_t)p_fsm->features[MAX_X], (uint32_t)(p_fsm->features[MAX_X] * 10) % 10, (uint32_t)p_fsm->features[MAX_Y], (uint32_t)(p_fsm->features[MAX_Y] * 10) % 10, (uint32_t)p_fsm->features[MAX_Z], (uint32_t)(p_fsm->features[MAX_Z] * 10) % 10);
    printf("Min X: %ld.%ld, Min Y: %ld.%ld, Min Z: %ld.%ld\n", (uint32_t)p_fsm->features[MIN_X], (uint32_t)(p_fsm->features[MIN_X] * 10) % 10, (uint32_t)p_fsm->features[MIN_Y], (uint32_t)(p_fsm->features[MIN_Y] * 10) % 10, (uint32_t)p_fsm->features[MIN_Z], (uint32_t)(p_fsm->features[MIN_Z] * 10) % 10);
    printf("Mean X: %ld.%ld, Mean Y: %ld.%ld, Mean Z: %ld.%ld\n", (uint32_t)p_fsm->features[MEAN_X], (uint32_t)(p_fsm->features[MEAN_X] * 10) % 10, (uint32_t)p_fsm->features[MEAN_Y], (uint32_t)(p_fsm->features[MEAN_Y] * 10) % 10, (uint32_t)p_fsm->features[MEAN_Z], (uint32_t)(p_fsm->features[MEAN_Z] * 10) % 10);
    printf("Median X: %ld.%ld, Median Y: %ld.%ld, Median Z: %ld.%ld\n", (uint32_t)p_fsm->features[MED_X], (uint32_t)(p_fsm->features[MED_X] * 10) % 10, (uint32_t)p_fsm->features[MED_Y], (uint32_t)(p_fsm->features[MED_Y] * 10) % 10, (uint32_t)p_fsm->features[MED_Z], (uint32_t)(p_fsm->features[MED_Z] * 10) % 10);
    printf("Variance X: %ld.%ld, Variance Y: %ld.%ld, Variance Z: %ld.%ld\n", (uint32_t)p_fsm->features[VAR_X], (uint32_t)(p_fsm->features[VAR_X] * 10) % 10, (uint32_t)p_fsm->features[VAR_Y], (uint32_t)(p_fsm->features[VAR_Y] * 10) % 10, (uint32_t)p_fsm->features[VAR_Z], (uint32_t)(p_fsm->features[VAR_Z] * 10) % 10);
    printf("Standard deviation X: %ld.%ld, Standard deviation Y: %ld.%ld, Standard deviation Z: %ld.%ld\n", (uint32_t)p_fsm->features[STD_X], (uint32_t)(p_fsm->features[STD_X] * 10) % 10, (uint32_t)p_fsm->features[STD_Y], (uint32_t)(p_fsm->features[STD_Y] * 10) % 10, (uint32_t)p_fsm->features[STD_Z], (uint32_t)(p_fsm->features[STD_Z] * 10) % 10);
    printf("Amplitude X: %ld.%ld, Amplitude Y: %ld.%ld, Amplitude Z: %ld.%ld\n", (uint32_t)p_fsm->features[AMP_X], (uint32_t)(p_fsm->features[AMP_X] * 10) % 10, (uint32_t)p_fsm->features[AMP_Y], (uint32_t)(p_fsm->features[AMP_Y] * 10) % 10, (uint32_t)p_fsm->features[AMP_Z], (uint32_t)(p_fsm->features[AMP_Z] * 10) % 10);
}

/**
 * @brief Compute the activity recognition
 *
 * @param p_this Pointer to the HAR system FSM structure
 */
static void do_compute_activity(fsm_t *p_this)
{
    fsm_har_system_t *p_fsm = (fsm_har_system_t *)p_this;
    double distances[NUM_CLUSTERS];
    uint32_t min_distance_cluster_index = 0;

    // Compute Euclidean distance to clusters and find the closest one
    for (uint32_t c = 0; c < NUM_CLUSTERS; c++)
    {
        distances[c] = 0;
        for (uint32_t f = 0; f < NUM_FEATURES; f++)
        {
            distances[c] += pow(p_fsm->features[f] - p_fsm->knn_classifier.cluster_centroids[c][f], 2);
        }
        distances[c] = sqrt(distances[c]);

        // Find the closest cluster
        if (distances[c] < distances[min_distance_cluster_index])
        {
            min_distance_cluster_index = c;
        }
    }

    // Store the activity detected
    p_fsm->activities_detected[p_fsm->activities_detected_index] = har_activities[min_distance_cluster_index];

    // Store the last activity detected
    p_fsm->last_activity_name = malloc(strlen(p_fsm->knn_classifier.activity_labels[min_distance_cluster_index]) + 1); // Allocate memory for the string
    strcpy(p_fsm->last_activity_name, p_fsm->knn_classifier.activity_labels[min_distance_cluster_index]);              // Copy the string

    // Print the activity detected
    printf("\na: %ld. Activity detected: %s\n\n", p_fsm->activities_detected_index, p_fsm->last_activity_name);

    // Increase the activities detected index. If it is greater than the maximum number of records, reset it
    p_fsm->activities_detected_index = (p_fsm->activities_detected_index + 1) % MAX_NUM_RECORDS;

    // Disable the flag to indicate that the features are computed
    p_fsm->features_computed = false;
}

/**
 * @brief Put the system to sleep
 *
 * @param p_this Pointer to the HAR system FSM structure
 */
static void do_sleep(fsm_t *p_this)
{
    fsm_har_system_t *p_fsm = (fsm_har_system_t *)p_this;

    // Enable the timer to measure the acceleration
    port_har_system_timer_enable(&p_fsm->har_system_hw);

    // Go to sleep
    port_system_sleep();
}

/* Transitions table ---------------------------------------------------------*/
/**
 * @brief Transitions table for the HAR system
 *
 */
fsm_trans_t fsm_trans_har_system[] = {
    {GET_DATA, check_sample, GET_DATA, do_store_data},
    {GET_DATA, check_block_size, COMPUTE_FEATURES, do_compute_features},
    {COMPUTE_FEATURES, check_features, COMPUTE_ACTIVITY_RECOGNITION, do_compute_activity},
    {COMPUTE_ACTIVITY_RECOGNITION, check_activity, GET_DATA, do_sleep},
    {-1, NULL, -1, NULL},
};

char *fsm_har_system_get_activity(fsm_t *p_this)
{
    fsm_har_system_t *p_fsm = (fsm_har_system_t *)p_this;
    return p_fsm->last_activity_name;
}

/* Initialize the FSM */

/**
 * @brief Initialize the HAR system FSM 
 * 
 * @param p_this Pointer to the HAR system FSM structure 
 * @param p_har_sensor Pointer to the HAR sensor structure 
 */
void fsm_har_system_init(fsm_t *p_this, port_har_sensor_t *p_har_sensor)
{
    fsm_har_system_t *p_fsm = (fsm_har_system_t *)(p_this);
    fsm_init(p_this, fsm_trans_har_system);

    // Assign the sensor to the FSM
    p_fsm->p_har_sensor = p_har_sensor;

    // Initialize the acceleration block, features, and activities detected
    memset(p_fsm->acc_block, 0, sizeof(p_fsm->acc_block));
    memset(p_fsm->features, 0, sizeof(p_fsm->features));
    memset(p_fsm->activities_detected, 0, sizeof(p_fsm->activities_detected));

    // Initialize the cluster centroids and activity labels
    memcpy(p_fsm->knn_classifier.cluster_centroids, har_clusters_knn_centroids, sizeof(har_clusters_knn_centroids));

    // Assign the activity labels
    memcpy(p_fsm->knn_classifier.activity_labels, har_knn_activity_labels, sizeof(har_knn_activity_labels));

    p_fsm->acc_sample_index = 0;
    p_fsm->features_computed = false;
    p_fsm->activities_detected_index = 0;
    p_fsm->last_activity_name = NULL;

    // Initialize the peripherals
    port_har_sensor_init(p_fsm->p_har_sensor);

    // Initialize the HAR sensor hardware structure with the timer
    p_fsm->har_system_hw.p_timer = HAR_SYSTEM_TIMER;
    port_har_system_timer_setup(p_fsm->har_system_hw.p_timer, SAMPLING_PERIOD_ACCEL);
}

/* Create FSM */
fsm_t *fsm_har_system_new(port_har_sensor_t *p_har_sensor)
{
    // Do malloc for the whole FSM structure to reserve memory for the rest of the FSM, although I interpret it as fsm_t which is the first field of the structure so that the FSM library can work with it
    fsm_t *p_fsm = malloc(sizeof(fsm_har_system_t));

    // Initialize the FSM
    fsm_har_system_init(p_fsm, p_har_sensor);

    return p_fsm;
}
