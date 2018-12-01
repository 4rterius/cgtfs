#ifndef CGTFS_FARE_RULE_H
#define CGTFS_FARE_RULE_H

typedef struct {
    char fare_id[65];
    char route_id[65];
    char origin_id[65];
    char destination_id[65];
    char contains_id[65];
} fare_rule_t;

#endif
