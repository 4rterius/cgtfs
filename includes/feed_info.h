#ifndef CGTFS_FEED_INFO_H
#define CGTFS_FEED_INFO_H

#include <stdio.h>
#include <string.h>


typedef struct {
    char feed_publisher_name[65];
    char feed_publisher_url[129];
    char feed_lang[65];
    char feed_start_date[9];
    char feed_end_date[9];
    char feed_version[65];
    char feed_contact_email[65];
    char feed_contact_url[129];
    int is_null;
} feed_info_t;

void init_feed_info(feed_info_t *record);
void read_feed_info(feed_info_t *record, int field_count, const char **field_names, const char **field_values);

#endif
