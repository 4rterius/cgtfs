#ifndef CGTFS_FEED_INFO_H
#define CGTFS_FEED_INFO_H

typedef struct {
    char publisher_name[65];
    char publisher_url[129];
    char publisher_lang[65];
    char feed_start_date[9];
    char feed_end_date[9];
    char feed_version[65];
    char feed_contact_email[65];
    char feed_contact_url[129];
} feed_info_t;

#endif
