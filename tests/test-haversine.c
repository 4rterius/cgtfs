#include <assert.h>
#include <stdio.h>

#include "_utils.c"

#include "haversine.h"

int test_haversine_correct() {
    geo_location_t point_a = {.latitude = 41.8903, .longitude = 12.4924};
    geo_location_t point_b = {.latitude = 41.88526, .longitude = 12.48712};

    long double dist_ab = haversine_distance(point_a, point_b);
    
    if (in_ld(dist_ab, 705, 715) != 0) {
        printf("Dist. btw. Colloseo & Circo Massimo calculated incorrectly: %lf, should be around %li", dist_ab, 710);
    }

    geo_location_t point_c = {.latitude = 60.98390, .longitude = 25.65733};
    geo_location_t point_d = {.latitude = 60.98395, .longitude = 25.65694};

    long double dist_cd = haversine_distance(point_c, point_d);

    if (in_ld(dist_cd, 21, 22) != 0) {
        printf("Dist. btw. Lahden Kauppatori D2 & E calculated incorrectly: %lf, should be around %lf", dist_cd, 21.7f);
    }

    return 0;
}