#ifndef CGTFS_AGENCY_H
#define CGTFS_AGENCY_H

typedef struct {
    char id[64];
    char name[64];
    char url[128];
    char timezone[64];
    char lang[64];
    char phone[64];
    char fare_url[128];
    char email[64];
} agency_t;

#endif
