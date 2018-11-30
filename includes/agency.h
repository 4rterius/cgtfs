#ifndef CGTFS_AGENCY_H
#define CGTFS_AGENCY_H

#include <stdio.h>
#include <string.h>


typedef struct {
    char id[64];
    char name[64];
    char url[128];
    char timezone[64];
    char lang[64];
    char phone[64];
    char fare_url[128];
    char email[64];
    int is_null;
} agency_t;


agency_t make_agency(int field_count, char **field_names, char **field_values);

#endif
