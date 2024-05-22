
#ifndef KNN_HAR_MODEL_H
#define KNN_HAR_MODEL_H

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdint.h>

/* Other includes */
#include "fsm_har_system.h"

/* Defines and enums ----------------------------------------------------------*/
/* Defines */


/* Constants -----------------------------------------------------------------*/

/* KNN model constants */

/**
 * @brief Centroids of the clusters for the KNN model. 
 * 
 */
extern const double har_clusters_knn_centroids[NUM_CLUSTERS][NUM_FEATURES];

/**
 * @brief Labels of the activities for the KNN model (strings)
 * 
 */
extern const char *har_knn_activity_labels[NUM_ACTIVITY_LABELS];

/**
 * @brief Activities for the KNN model (numbers) 
 * 
 */
extern const uint32_t har_activities[NUM_ACTIVITY_LABELS];

#endif /* KNN_HAR_MODEL_H */