#ifndef CGTFS_AGENCY_H
#define CGTFS_AGENCY_H

#include <stdio.h>
#include <string.h>


typedef struct {
    char id[65];
    char name[65];
    char url[129];
    char timezone[65];
    char lang[65];
    char phone[65];
    char fare_url[129];
    char email[65];
    int is_null;
} agency_t;


agency_t empty_agency(void);
agency_t read_agency(int field_count, const char **field_names, const char **field_values);

#endif
