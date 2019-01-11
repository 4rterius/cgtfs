#include "calendar.h"

service_availability_t parse_service_availability(const char *value) {
    if (strcmp(value, "0") == 0)
        return SA_UNAVAILABLE;
    else if (strcmp(value, "1") == 0)
        return SA_AVAILABLE;
    else
        return SA_NOT_SET;
}

calendar_record_t empty_calendar_record(void) {
    calendar_record_t calendar_record;
    strcpy(calendar_record.service_id, "");
    strcpy(calendar_record.start_date, "");
    strcpy(calendar_record.end_date, "");
    calendar_record.monday = SA_NOT_SET;
    calendar_record.tuesday = SA_NOT_SET;
    calendar_record.wednesday = SA_NOT_SET;
    calendar_record.thursday = SA_NOT_SET;
    calendar_record.friday = SA_NOT_SET;
    calendar_record.saturday = SA_NOT_SET;
    calendar_record.sunday = SA_NOT_SET;

    calendar_record.is_null = 1;
    return calendar_record;
}

calendar_record_t read_calendar_record(int field_count, const char **field_names, const char **field_values) {
    calendar_record_t calendar_record = empty_calendar_record();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "service_id") == 0) {
            strcpy(calendar_record.service_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "start_date") == 0) {
            strcpy(calendar_record.start_date, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "end_date") == 0) {
            strcpy(calendar_record.end_date, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "monday") == 0) {
            calendar_record.monday = parse_service_availability(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "tuesday") == 0) {
            calendar_record.tuesday = parse_service_availability(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "wednesday") == 0) {
            calendar_record.wednesday = parse_service_availability(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "thursday") == 0) {
            calendar_record.thursday = parse_service_availability(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "friday") == 0) {
            calendar_record.friday = parse_service_availability(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "saturday") == 0) {
            calendar_record.saturday = parse_service_availability(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "sunday") == 0) {
            calendar_record.sunday = parse_service_availability(field_values[i]);
            assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        calendar_record.is_null = 1;
    else
        calendar_record.is_null = 0;

    return calendar_record;
}
