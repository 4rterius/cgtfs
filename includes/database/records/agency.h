/**
 * @file
 * @brief    Agency database record handling functionality.
 */

#ifndef CGTFS_DATABASE_AGENCY_H
#define CGTFS_DATABASE_AGENCY_H

#include <stdio.h>

#include "../../records/agency.h"
#include "database/database.h"

/**
 * Stores an agency_t record in the given database.
 * 
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 * 
 * @ingroup      Database__RecordStoring
 */
feed_db_status_t store_agency_db(agency_t *record, feed_db_t *db);

#endif