#include "database/records/fare_rule.h"

feed_db_status_t store_fare_rule_db(fare_rule_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO fare_rules ("
                    "fare_id, route_id, origin_id, destination_id, contains_id"
                ") values ("
                    "?1, ?2, ?3, ?4, ?5"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->fare_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record->route_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, record->origin_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, record->destination_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, record->contains_id, -1, SQLITE_STATIC);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}