#include "feed_info.h"

feed_info_t empty_feed_info(void) {
    feed_info_t feed_info;
    strcpy(feed_info.feed_publisher_name, "");
    strcpy(feed_info.feed_publisher_url, "");
    strcpy(feed_info.feed_lang, "");
    strcpy(feed_info.feed_start_date, "");
    strcpy(feed_info.feed_end_date, "");
    strcpy(feed_info.feed_version, "");
    strcpy(feed_info.feed_contact_email, "");
    strcpy(feed_info.feed_contact_url, "");
    feed_info.is_null = 1;
    return feed_info;
}

feed_info_t read_feed_info(int field_count, char **field_names, char **field_values) {
    feed_info_t feed_info = empty_feed_info();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "feed_publisher_name") == 0) {
            strcpy(feed_info.feed_publisher_name, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_publisher_url") == 0) {
            strcpy(feed_info.feed_publisher_url, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_lang") == 0) {
            strcpy(feed_info.feed_lang, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_start_date") == 0) {
            strcpy(feed_info.feed_start_date, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_end_date") == 0) {
            strcpy(feed_info.feed_end_date, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_version") == 0) {
            strcpy(feed_info.feed_version, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_contact_email") == 0) {
            strcpy(feed_info.feed_contact_email, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "feed_contact_url") == 0) {
            strcpy(feed_info.feed_contact_url, field_values[i]);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        feed_info.is_null = 1;
    else
        feed_info.is_null = 0;

    return feed_info;
}