#include "database/records/level.h"

feed_db_status_t store_level_db(level_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO levels ("
                    "level_id, level_index, level_name"
                ") values ("
                    "?1, ?2, ?3"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->id, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 2, record->index);
    sqlite3_bind_text(stmt, 3, record->name, -1, SQLITE_STATIC);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}