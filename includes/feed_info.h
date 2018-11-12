#ifndef CGTFS_FEED_INFO_H
#define CGTFS_FEED_INFO_H

typedef struct FeedInfo {
    char publisher_name[64];
    char publisher_url[128];
    char publisher_lang[64];
    char feed_start_date[8];
    char feed_end_date[8];
    char feed_version[64];
    char feed_contact_email[64];
    char feed_contact_url[128];
} feed_info_t;

#endif
