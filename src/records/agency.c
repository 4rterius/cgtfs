#include "records/agency.h"

void init_agency(agency_t *record) {
    strcpy(record->id, "");
    strcpy(record->name, "");
    strcpy(record->url, "");
    strcpy(record->timezone, "");
    strcpy(record->lang, "");
    strcpy(record->phone, "");
    strcpy(record->fare_url, "");
    strcpy(record->email, "");
}

void read_agency(agency_t *record, int field_count, const char **field_names, const char **field_values) {
    init_agency(record);

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "agency_id") == 0) {
            strcpy(record->id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "agency_name") == 0) {
            strcpy(record->name, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "agency_url") == 0) {
            strcpy(record->url, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "agency_timezone") == 0) {
            strcpy(record->timezone, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "agency_lang") == 0) {
            strcpy(record->lang, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "agency_phone") == 0) {
            strcpy(record->phone, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "agency_fare_url") == 0) {
            strcpy(record->fare_url, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "agency_email") == 0) {
            strcpy(record->email, field_values[i]);
            continue;
        }
    }
}

int equal_agency(const agency_t *a, const agency_t *b) {
    return (!strcmp(a->id, b->id) &&
             !strcmp(a->name, b->name) &&
             !strcmp(a->url, b->url) &&
             !strcmp(a->timezone, b->timezone) &&
             !strcmp(a->lang, b->lang) &&
             !strcmp(a->phone, b->phone) &&
             !strcmp(a->fare_url, b->fare_url) &&
             !strcmp(a->email, b->email));
}