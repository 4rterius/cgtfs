#include "records/feed_info.h"

void init_feed_info(feed_info_t *record) {
    strcpy(record->feed_publisher_name, "");
    strcpy(record->feed_publisher_url, "");
    strcpy(record->feed_lang, "");
    strcpy(record->feed_start_date, "");
    strcpy(record->feed_end_date, "");
    strcpy(record->feed_version, "");
    strcpy(record->feed_contact_email, "");
    strcpy(record->feed_contact_url, "");
}

void read_feed_info(feed_info_t *record, int field_count, const char **field_names, const char **field_values) {
    init_feed_info(record);

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "feed_publisher_name") == 0) {
            strcpy(record->feed_publisher_name, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "feed_publisher_url") == 0) {
            strcpy(record->feed_publisher_url, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "feed_lang") == 0) {
            strcpy(record->feed_lang, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "feed_start_date") == 0) {
            strcpy(record->feed_start_date, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "feed_end_date") == 0) {
            strcpy(record->feed_end_date, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "feed_version") == 0) {
            strcpy(record->feed_version, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "feed_contact_email") == 0) {
            strcpy(record->feed_contact_email, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "feed_contact_url") == 0) {
            strcpy(record->feed_contact_url, field_values[i]);
            continue;
        }
    }
}

int equal_feed_info(const feed_info_t *a, const feed_info_t *b) {
    return (!strcmp(a->feed_publisher_name, b->feed_publisher_name) &&
             !strcmp(a->feed_publisher_url, b->feed_publisher_url) &&
             !strcmp(a->feed_lang, b->feed_lang) &&
             !strcmp(a->feed_start_date, b->feed_start_date) &&
             !strcmp(a->feed_end_date, b->feed_end_date) &&
             !strcmp(a->feed_version, b->feed_version) &&
             !strcmp(a->feed_contact_email, b->feed_contact_email) &&
             !strcmp(a->feed_contact_url, b->feed_contact_url));
}