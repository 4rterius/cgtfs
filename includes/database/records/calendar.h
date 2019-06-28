/**
 * @file
 * @brief    Calendar record database record handling functionality.
 */

#ifndef CGTFS_DATABASE_CALENDAR_H
#define CGTFS_DATABASE_CALENDAR_H

#include <stdio.h>

#include "../../records/calendar.h"
#include "database/database.h"

/**
 * Stores a calendar_record_t record in the given database.
 * 
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 */
feed_db_status_t store_calendar_record_db(calendar_record_t *record, feed_db_t *db);

#endif