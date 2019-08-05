/**
 * @file
 * @brief    Pathway database record handling functionality.
 */

#ifndef CGTFS_DATABASE_PATHWAY_H
#define CGTFS_DATABASE_PATHWAY_H

#include <stdio.h>

#include "../../records/pathway.h"
#include "database/database.h"

/**
 * Stores a pathway_t record in the given database.
 *
 * @param[in]    record    Record to store.
 * @param[in]    db        Target feed database instance.
 *
 * @ingroup      Database__EntityStoring
 */
feed_db_status_t store_pathway_db(pathway_t *record, feed_db_t *db);

#endif