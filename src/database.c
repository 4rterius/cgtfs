#include "database.h"

feed_db_status_t init_feed_db(feed_db_t *db, const char *db_path) {
    db->path = strdup(db_path);
    db->rc = -1;
    db->error_msg = NULL;
    
    db->rc = sqlite3_open(db_path, &(db->conn));

    if (db->rc) {
        free(db->error_msg);
        db->error_msg = sqlite3_errmsg(db->conn);
        return FEED_DB_ERROR;
    }

    return FEED_DB_SUCCESS;
}

feed_db_status_t free_feed_db(feed_db_t *db) {
    db->rc = sqlite3_close(db->conn);
    
    if (db->rc != SQLITE_OK) {
        free(db->error_msg);
        db->error_msg = sqlite3_errmsg(db->conn);
        return FEED_DB_ERROR;
    }

    free(db->path);
    free(db->error_msg);
    return FEED_DB_SUCCESS;
}