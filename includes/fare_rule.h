#ifndef CGTFS_FARE_RULE_H
#define CGTFS_FARE_RULE_H

typedef struct FareRule {
    char fare_id[64];
    char route_id[64];
    char origin_id[64];
    char destination_id[64];
    char contains_id[64];
} fare_rule_t;

#endif
