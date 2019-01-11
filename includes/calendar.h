#ifndef CGTFS_CALENDAR_H
#define CGTFS_CALENDAR_H

#include <stdio.h>
#include <string.h>


typedef enum {
    SA_UNAVAILABLE = 0,
    SA_AVAILABLE = 1,
    SA_NOT_SET
} service_availability_t;

typedef struct {
    char service_id[65];
    service_availability_t monday;
    service_availability_t tuesday;
    service_availability_t wednesday;
    service_availability_t thursday;
    service_availability_t friday;
    service_availability_t saturday;
    service_availability_t sunday;
    char start_date[9];
    char end_date[9];
    int is_null;
} calendar_record_t;


service_availability_t parse_service_availability(const char *value);

calendar_record_t empty_calendar_record(void);
calendar_record_t read_calendar_record(int field_count, const char **field_names, const char **field_values);

#endif
