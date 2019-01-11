#include <math.h>

#include "geo_location.h"
#include "haversine.h"

double dg_to_rad(const long double d) {
    return d * MATH_PI / 180;
}

double haversine_distance(const geo_location_t pa, const geo_location_t pb) {
    int earth_radius = 6371000;

    double lat_a = dg_to_rad(pa.latitude);
    double lon_a = dg_to_rad(pa.longitude);
    double lat_b = dg_to_rad(pb.latitude);
    double lon_b = dg_to_rad(pb.longitude);

    double lat_diff = dg_to_rad(pb.latitude - pa.latitude);
    double lon_diff = dg_to_rad(pb.longitude - pa.longitude);

    double a = pow(sin(lat_diff / 2), 2) + cos(lat_a) * cos(lat_b) * pow(sin(lon_diff / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return c * earth_radius;
}
