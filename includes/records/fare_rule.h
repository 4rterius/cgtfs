/**
 * @file
 * @brief    Fare rule entity handling functionality.
 */

#ifndef CGTFS_FARE_RULE_H
#define CGTFS_FARE_RULE_H

#include <stdio.h>
#include <string.h>


/**
 * fare_rules.txt record
 * 
 * @see        init_fare_rule()
 * @see        read_fare_rule()
 * @see        https://developers.google.com/transit/gtfs/reference/#fare_rulestxt
 * 
 * @ingroup    Core__EntityTypes Core__EntityList__FareRule
 */
typedef struct {
    char fare_id[65];         ///< [Required] Unique ID that identifies the fare class.
    char route_id[65];        ///< [Optional] The route ID associated with the fare class.
    char origin_id[65];       ///< [Optional] The origin zone ID associated with the fare class.
    char destination_id[65];  ///< [Optional] The destination zone ID associated with the fare class.
    char contains_id[65];     ///< [Optional] The passing-through zone ID associated with the fare class.
    int is_null;
} fare_rule_t;

/**
 * Initializes the given fare rules record with empty/default values.
 * 
 * @param[out]    record    Fare rules record pointer to initialize.
 * 
 * @ingroup       Core__EntityFunctions Core__EntityList__FareRule
 */
void init_fare_rule(fare_rule_t *record);

/**
 * Reads given datafields and field names into the given fare rules struct.
 * 
 * @param[out]    record          The pointer to write into.
 * @param[in]     field_count     Number of rows (columns) the record has.
 * @param[in]     field_names     Names of the fields.
 * @param[in]     field_values    Contents of the record.
 * 
 * @ingroup       Core__EntityFunctions Core__EntityList__FareRule
 */
void read_fare_rule(fare_rule_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 * 
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 * 
 * @returns      0 if structures are equal, non-zero otherwise.
 * 
 * @ingroup      Core__EntityFunctions Core__EntityList__FareRule
 */
int equal_fare_rule(const fare_rule_t *a, const fare_rule_t *b);

#endif
