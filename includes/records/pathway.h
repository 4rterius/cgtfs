/**
 * @file
 * @brief    Pathway entity handling functionality.
 */

#ifndef CGTFS_PATHWAY_H
#define CGTFS_PATHWAY_H

#include <stdio.h>
#include <string.h>


/**
 * The kind of pathway.
 *
 * @ingroup    Core__EntityEnums Core__EntityList__Pathway
 */
typedef enum {
    PTMD_WALKWAY = 1,      ///< Walkway.
    PTMD_STAIRS = 2,       ///< Stairs.
    PTMD_MOVING = 3,       ///< A moving sidewalk/travelator.
    PTMD_ESCALATOR = 4,    ///< An escalator.
    PTMD_ELEVATOR = 5,     ///< An elevator.
    PTMD_PAYGATE = 6,      ///< Pathway leading into a proof-of-payment area of the station.
    PTMD_EXITGATE = 7,     ///< Where passangers exit a restricted area
    PTMD_NOT_SET
} pathway_mode_t;

/**
 * Whether the pathway allows movement in one or both directions.
 *
 * @note       Basically, a glorified boolean, but defined as a enumeration by the spec.
 *
 * @ingroup    Core__EntityEnums Core__EntityList__Pathway
 */
typedef enum {
    PD_UNIDIRECTIONAL = 0,    ///< The pathway can only be used in one direction
    PD_BIDIRECTIONAL = 1,     ///< The pathway can be used in both directions
    PD_NOT_SET
} pathway_directions_t;

/**
 * pathway.txt record
 *
 * @see        init_pathway()
 * @see        read_pathway()
 * @see        https://developers.google.com/transit/gtfs/reference/#pathwaystxt
 *
 * @ingroup    Core__EntityTypes Core__EntityList__Pathway
 */
typedef struct {
    char id[65];              ///< [Required] Unique pathway ID
    char from_stop_id[65];
    char top_stop_id[65];
    pathway_mode_t mode;
    pathway_directions_t is_bidirectional;
    double length;
    int traversal_time;
    int stair_count;
    double max_slope;
    double min_width;
    char signposted_as[129];
    char reversed_signposted_as[129];
    int is_null;
} pathway_t;

/**
 * Parses the pathway mode from the given string
 * with regard for the default value as per GTFS reference.
 *
 * @param[in]    value    Char array (string) to parse the enumerator from.
 *
 * @returns      An according pathway_mode_t value.
 *
 * @ingroup      Core__EntityEnums Core__EntityList__Pathway
 */
pathway_mode_t parse_pathway_mode(const char *value);

/**
 * Parses the pathway directions from the given string
 * with regard for the default value as per GTFS reference.
 *
 * @param[in]    value    Char array (string) to parse the enumerator from.
 *
 * @returns      An according pathway_directions_t value.
 *
 * @ingroup      Core__EntityEnums Core__EntityList__Pathway
 */
pathway_directions_t parse_pathway_directions(const char *value);

/**
 * Initializes the given pathway record with empty/default values.
 *
 * @param[out]    record    Pathway pointer to initialize.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__Pathway
 */
void init_pathway(pathway_t *record);

/**
 * Reads given datafields and field names into the given pathway record struct
 *
 * @param[out]    record          The pointer to write into
 * @param[in]     field_count     Number of rows (columns) the record has
 * @param[in]     field_names     Names of the fields
 * @param[in]     field_values    Contents of the record
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__Pathway
 */
void read_pathway(pathway_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 *
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 *
 * @returns      0 if structures are equal, non-zero otherwise.
 *
 * @ingroup      Core__EntityFunctions Core__EntityList__Pathway
 */
int equal_pathway(const pathway_t *a, const pathway_t *b);

#endif
