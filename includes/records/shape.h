/**
 * @file
 * @brief    Shape entity handling functionality.
 */

#ifndef CGTFS_SHAPE_H
#define CGTFS_SHAPE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * shapes.txt record
 * 
 * @see        init_shape()
 * @see        read_shape()
 * @see        https://developers.google.com/transit/gtfs/reference/#shapestxt
 * 
 * @ingroup    Core__EntityTypes
 */
typedef struct {
    char id[65];               ///< [Required] Unique ID that identifies the shape.
    long double pt_lat;        ///< [Required] The shape point's latitude.
    long double pt_lon;        ///< [Required] The shape point's longitude.
    unsigned int pt_sequence;  ///< [Required] The shape point's sequence order withing the shape.
    double dist_traveled;      ///< [Optional] Real distance travelled along the route up to the shape point.
    int is_null;
} shape_t;

/**
 * Initializes the given shape record with empty/default values.
 * 
 * @param[out]    record    Shape record pointer to initialize.
 * 
 * @ingroup       Core__EntityFunctions
 */
void init_shape(shape_t *record);

/**
 * Reads given datafields and field names into the given shape struct.
 * 
 * @param[out]    record          The pointer to write into.
 * @param[in]     field_count     Number of rows (columns) the record has.
 * @param[in]     field_names     Names of the fields.
 * @param[in]     field_values    Contents of the record.
 * 
 * @ingroup       Core__EntityFunctions
 */
void read_shape(shape_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 * 
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 * 
 * @returns      0 if structures are equal, non-zero otherwise.
 * 
 * @ingroup      Core__EntityFunctions
 */
int equal_shape(const shape_t *a, const shape_t *b);

#endif
