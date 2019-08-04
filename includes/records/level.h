/**
 * @file
 * @brief    Level entity handling functionality.
 */

#ifndef CGTFS_LEVEL_H
#define CGTFS_LEVEL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * level.txt record
 *
 * @see        init_level()
 * @see        read_level()
 * @see        https://developers.google.com/transit/gtfs/reference/#levelstxt
 *
 * @ingroup    Core__EntityTypes Core__EntityList__Level
 */
typedef struct {
    char id[65];        ///< [Required] Unique level ID
    double index;       ///< [Required] Relative position of the level (higher above lower)
    char name[65];      ///< [Optional] Level name
} level_t;


/**
 * Initializes the given level record with empty/default values.
 *
 * @param[out]    record    Level pointer to initialize.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__Level
 */
void init_level(level_t *record);

/**
 * Reads given datafields and field names into the given level record struct
 *
 * @param[out]    record          The pointer to write into
 * @param[in]     field_count     Number of rows (columns) the record has
 * @param[in]     field_names     Names of the fields
 * @param[in]     field_values    Contents of the record
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__Level
 */
void read_level(level_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 *
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 *
 * @returns      0 if structures are equal, non-zero otherwise.
 *
 * @ingroup      Core__EntityFunctions Core__EntityList__Level
 */
int equal_level(const level_t *a, const level_t *b);

#endif
