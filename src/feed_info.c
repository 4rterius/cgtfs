#include "feed_info.h"

void init_feed_info(feed_info_t *record) {
    strcpy(record->feed_publisher_name, "");
    strcpy(record->feed_publisher_url, "");
    strcpy(record->feed_lang, "");
    strcpy(record->feed_start_date, "");
    strcpy(record->feed_end_date, "");
    strcpy(record->feed_version, "");
    strcpy(record->feed_contact_email, "");
    strcpy(record->feed_contact_url, "");
    record->is_null = 1;
}

void read_feed_info(feed_info_t *record, int field_count, const char **field_names, const char **field_values) {
    init_feed_info(record);
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "feed_publisher_name") == 0) {
            strcpy(record->feed_publisher_name, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_publisher_url") == 0) {
            strcpy(record->feed_publisher_url, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_lang") == 0) {
            strcpy(record->feed_lang, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_start_date") == 0) {
            strcpy(record->feed_start_date, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_end_date") == 0) {
            strcpy(record->feed_end_date, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_version") == 0) {
            strcpy(record->feed_version, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_contact_email") == 0) {
            strcpy(record->feed_contact_email, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_contact_url") == 0) {
            strcpy(record->feed_contact_url, field_values[i]);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        record->is_null = 1;
    else
        record->is_null = 0;
}