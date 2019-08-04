#include "records/calendar.h"

service_availability_t parse_service_availability(const char *value) {
    if (strcmp(value, "0") == 0)
        return SA_UNAVAILABLE;
    else if (strcmp(value, "1") == 0)
        return SA_AVAILABLE;
    else
        return SA_NOT_SET;
}

void init_calendar_record(calendar_record_t *record) {
    strcpy(record->service_id, "");
    strcpy(record->start_date, "");
    strcpy(record->end_date, "");
    record->monday = SA_NOT_SET;
    record->tuesday = SA_NOT_SET;
    record->wednesday = SA_NOT_SET;
    record->thursday = SA_NOT_SET;
    record->friday = SA_NOT_SET;
    record->saturday = SA_NOT_SET;
    record->sunday = SA_NOT_SET;
}

void read_calendar_record(calendar_record_t *record, int field_count, const char **field_names, const char **field_values) {
    init_calendar_record(record);

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "service_id") == 0) {
            strcpy(record->service_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "start_date") == 0) {
            strcpy(record->start_date, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "end_date") == 0) {
            strcpy(record->end_date, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "monday") == 0) {
            record->monday = parse_service_availability(field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "tuesday") == 0) {
            record->tuesday = parse_service_availability(field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "wednesday") == 0) {
            record->wednesday = parse_service_availability(field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "thursday") == 0) {
            record->thursday = parse_service_availability(field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "friday") == 0) {
            record->friday = parse_service_availability(field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "saturday") == 0) {
            record->saturday = parse_service_availability(field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "sunday") == 0) {
            record->sunday = parse_service_availability(field_values[i]);
            continue;
        }
    }
}

int equal_calendar_record(const calendar_record_t *a, const calendar_record_t *b) {
    return !(!strcmp(a->service_id, b->service_id) &&
             !strcmp(a->start_date, b->start_date) &&
             !strcmp(a->end_date, b->end_date) &&
             a->monday == b->monday &&
             a->tuesday == b->tuesday &&
             a->wednesday == b->wednesday &&
             a->thursday == b->thursday &&
             a->friday == b->friday &&
             a->saturday == b->saturday &&
             a->sunday == b->sunday);
}