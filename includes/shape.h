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

shape_t empty_shape(void);
shape_t read_shape(int field_count, char **field_names, char **field_values);

#endif
