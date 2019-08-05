#include "database/records/pathway.h"

feed_db_status_t store_pathway_db(pathway_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO pathways ("
                    "pathway_id, from_stop_id, to_stop_id, pathway_mode, is_bidirectional, "
                    "length, traversal_time, stair_count, max_slope, min_width, "
                    "signposted_as, reversed_signposted_as"
                ") values ("
                    "?1, ?2, ?3, ?4, ?5, "
                    "?6, ?7, ?8, ?9, ?10, "
                    "?11, ?12"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record->from_stop_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, record->to_stop_id, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, (int)record->mode);
    sqlite3_bind_int(stmt, 5, (int)record->is_bidirectional);
    sqlite3_bind_double(stmt, 6, record->length);
    sqlite3_bind_int(stmt, 7, record->traversal_time);
    sqlite3_bind_int(stmt, 8, record->stair_count);
    sqlite3_bind_double(stmt, 9, record->max_slope);
    sqlite3_bind_double(stmt, 10, record->min_width);
    sqlite3_bind_text(stmt, 11, record->signposted_as, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 12, record->reversed_signposted_as, -1, SQLITE_STATIC);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}