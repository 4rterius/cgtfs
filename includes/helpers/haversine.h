/**
 * @file
 * @brief    Haversine formula utility.
 *
 * Does not directly relate to GTFS,
 * but is likely necessary for location comparison handling.
 */

#ifndef CGTFS_HAVERSINE_H
#define CGTFS_HAVERSINE_H

#include "helpers/geo_location.h"

/**
 * @def        MATH_PI
 * @brief      Pi constant.
 *
 * Defined to avoid linking against default math library
 * only for a single value.
 *
 * @ingroup    Helpers
 */
#define MATH_PI 3.14159265358979323846

/**
 * Converts degrees into radians.
 *
 * @param[in]    d    Degrees value.
 *
 * @returns      Radians value.
 *
 * @ingroup      Helpers
 */
double dg_to_rad(const long double d);

/**
 * Calculates the distance in meters between two given locations.
 *
 * @see https://en.wikipedia.org/wiki/Haversine_formula
 *
 * @param[in]    a    Point A.
 * @param[in]    b    Point B.
 *
 * @returns      Meters between points A & B.
 *
 * @ingroup      Helpers
 */
double haversine_distance(const geo_location_t a, const geo_location_t b);

#endif
