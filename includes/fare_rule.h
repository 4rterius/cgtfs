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

void init_fare_rule(fare_rule_t *record);
void read_fare_rule(fare_rule_t *record, int field_count, const char **field_names, const char **field_values);

#endif
