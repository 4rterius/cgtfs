#include "database/records/shape.h"

feed_db_status_t store_shape_db(shape_t *record, feed_db_t *db) {
    sqlite3_stmt *stmt;
    char qr[] = "INSERT INTO shapes ("
                    "shape_id,"
                    "shape_pt_lat, shape_pt_lon,"
                    "shape_pt_sequence, shape_dist_traveled"
                ") values ("
                    "?1,"
                    "?2, ?3,"
                    "?4, ?5"
                ");";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, record->id, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 2, record->pt_lat);
    sqlite3_bind_double(stmt, 3, record->pt_lon);
    sqlite3_bind_int(stmt, 4, record->pt_sequence);
    sqlite3_bind_double(stmt, 5, record->dist_traveled);

    db->rc = sqlite3_step(stmt);
    if (db->rc != SQLITE_DONE) {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
        sqlite3_finalize(stmt);
        return FEED_DB_ERROR;
    }

    sqlite3_finalize(stmt);
    return FEED_DB_SUCCESS;
}