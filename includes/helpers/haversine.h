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

#define MATH_PI 3.14159265358979323846

/**
 * Converts degrees into radians.
 * 
 * @param[in]    d    Degrees value.
 * 
 * @returns      Radians value.
 */
double dg_to_rad(const long double d);

/**
 * Calculates the distance in meters between two given locations.
 * @see https://en.wikipedia.org/wiki/Haversine_formula
 * 
 * @param[in]    a    Point A.
 * @param[in]    b    Point B.
 * 
 * @returns      Meters between points A & B.
 */
double haversine_distance(const geo_location_t a, const geo_location_t b);

#endif
