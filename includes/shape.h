#ifndef CGTFS_SHAPE_H
#define CGTFS_SHAPE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct {
    char id[65];
    long double pt_lat;
    long double pt_lon;
    unsigned int pt_sequence;
    double dist_traveled;
    int is_null;
} shape_t;

void init_shape(shape_t *record);
void read_shape(shape_t *record, int field_count, const char **field_names, const char **field_values);

#endif
