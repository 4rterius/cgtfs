#ifndef CGTFS_FARE_RULE_H
#define CGTFS_FARE_RULE_H

#include <stdio.h>
#include <string.h>


typedef struct {
    char fare_id[65];
    char route_id[65];
    char origin_id[65];
    char destination_id[65];
    char contains_id[65];
    int is_null;
} fare_rule_t;

fare_rule_t empty_fare_rule(void);
fare_rule_t read_fare_rule(int field_count, char **field_names, char **field_values);

#endif
