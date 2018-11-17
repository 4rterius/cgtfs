#ifndef CGTFS_CALENDAR_H
#define CGTFS_CALENDAR_H

typedef struct {
    char id[64];
    unsigned int monday;
    unsigned int tuesday;
    unsigned int wednesday;
    unsigned int thursday;
    unsigned int friday;
    unsigned int saturday;
    unsigned int sunday;
    char start_date[8];
    char end_date[8];
} calendar_record_t;

#endif
