#ifndef CGTFS_SHAPE_H
#define CGTFS_SHAPE_H

typedef struct {
    char id[65];
    long double pt_lat;
    long double pt_lon;
    unsigned int pt_sequence;
    double dist_travelled;
} shape_t;

#endif
