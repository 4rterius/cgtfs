#ifndef CGTFS_HAVERSINE_H
#define CGTFS_HAVERSINE_H

#include "geo_location.h"

#define MATH_PI 3.14159265358979323846

double dg_to_rad(long double d);
double haversine_distance(geo_location_t a, geo_location_t b);

#endif
