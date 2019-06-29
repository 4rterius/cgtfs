/**
 * @file
 * @brief    Feed info entity handling functionality.
 */

#ifndef CGTFS_FEED_INFO_H
#define CGTFS_FEED_INFO_H

#include <stdio.h>
#include <string.h>


/**
 * feed_info.txt record
 * 
 * @see        init_feed_info()
 * @see        read_feed_info()
 * @see        https://developers.google.com/transit/gtfs/reference/#feed_infotxt
 * 
 * @ingroup    Core__EntityTypes
 */
typedef struct {
    char feed_publisher_name[65];  ///< [Required] Full name of the organization publishing the feed.
    char feed_publisher_url[129];  ///< [Required] URL of the publishing organization's website.
    char feed_lang[65];            ///< [Required] Language of the feed (IETF BCP 47).
    char feed_start_date[9];       ///< [Optional] The first date (YYYYMMDD) when the feed's info becomes valid/active.
    char feed_end_date[9];         ///< [Optional] The last date (YYYYMMDD) when the feed's info is valid/active.
    char feed_version[65];         ///< [Optional] String identifying the feed version.
    char feed_contact_email[65];   ///< [Optional] Email address to contact regarding the GTFS dataset.
    char feed_contact_url[129];    ///< [Optional] URL address to visit regatding the GTFS dataset.
    int is_null;
} feed_info_t;


/**
 * Initializes the given feed info record with empty/default values.
 * 
 * @param[out]    record    Feed info record pointer to initialize.
 * 
 * @ingroup       Core__EntityFunctions
 */
void init_feed_info(feed_info_t *record);

/**
 * Reads given datafields and field names into the given feed info struct.
 * 
 * @param[out]    record          The pointer to write into.
 * @param[in]     field_count     Number of rows (columns) the record has.
 * @param[in]     field_names     Names of the fields.
 * @param[in]     field_values    Contents of the record.
 * 
 * @ingroup       Core__EntityFunctions
 */
void read_feed_info(feed_info_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 * 
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 * 
 * @returns      0 if structures are equal, non-zero otherwise.
 * 
 * @ingroup      Core__EntityFunctions
 */
int equal_feed_info(const feed_info_t *a, const feed_info_t *b);

#endif