/**
 * @file
 * @brief    Agency entity handling functionality.
 */

#ifndef CGTFS_AGENCY_H
#define CGTFS_AGENCY_H

#include <stdio.h>
#include <string.h>

#include "xstrlengths.h"


/**
 * agency.txt record
 *
 * @see        init_agency()
 * @see        read_agency()
 * @see        https://developers.google.com/transit/gtfs/reference/#agencytxt
 *
 * @ingroup    Core__EntityTypes Core__EntityList__Agency
 */
typedef struct {
    char id[CGTFS_SL_IDS];         ///< [Optional] Unique agency ID
    char name[CGTFS_SL_NAM];       ///< [Required] Agency name
    char url[CGTFS_SL_URL];        ///< [Required] Agency URL
    char timezone[CGTFS_SL_TMZ];   ///< [Required] Timezone in which the agency operates (http://en.wikipedia.org/wiki/List_of_tz_zones)
    char lang[CGTFS_SL_LNG];       ///< [Optional] Primary agency's language (IETF BCP 47)
    char phone[CGTFS_SL_PHN];      ///< [Optional] Telephone number for contacting the agency
    char fare_url[CGTFS_SL_URL];   ///< [Optional] URL that allows visitor to buy tickets for the agency's trips
    char email[CGTFS_SL_EML];      ///< [Optional] Agency's customer support email.
} agency_t;


/**
 * Initializes the given agency record with empty/default values.
 *
 * @param[out]    record    Agency pointer to initialize.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__Agency
 */
void init_agency(agency_t *record);

/**
 * Reads given datafields and field names into the given agency record struct
 *
 * @param[out]    record          The pointer to write into
 * @param[in]     field_count     Number of rows (columns) the record has
 * @param[in]     field_names     Names of the fields
 * @param[in]     field_values    Contents of the record
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__Agency
 */
void read_agency(agency_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 *
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 *
 * @returns      0 if structures are equal, non-zero otherwise.
 *
 * @ingroup      Core__EntityFunctions Core__EntityList__Agency
 */
int equal_agency(const agency_t *a, const agency_t *b);

#endif
