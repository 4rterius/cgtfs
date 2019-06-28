#include "database/database_utils.h"

int count_rows(feed_db_t *db, const char *table_name) {   
    int count = -1; 
    sqlite3_stmt *stmt;
    
    int query_buf_len = 25 + strlen(table_name);
    char *query_buf = malloc(sizeof(char) * query_buf_len);
    snprintf(query_buf, query_buf_len, "SELECT count(*) FROM `%s`;", table_name);

    sqlite3_prepare_v2(db->conn, query_buf, -1, &stmt, NULL);
    db->rc = sqlite3_step(stmt);

    if (db->rc == SQLITE_ROW) {
        count = sqlite3_column_int(stmt, 0);
    } else {
        db->error_msg = strdup(sqlite3_errmsg(db->conn));
    }

    sqlite3_finalize(stmt);
    free(query_buf);
    return count;
}


feed_db_status_t begin_transaction(feed_db_t *db) {
    char *err_msg = 0;
    db->rc = sqlite3_exec(db->conn, "BEGIN TRANSACTION;", NULL, NULL, &err_msg);
    
    if (db->rc != SQLITE_OK) {
        db->error_msg = strdup(err_msg);
        sqlite3_free(err_msg);
        return FEED_DB_ERROR;
    }

    return FEED_DB_SUCCESS;
}

feed_db_status_t end_transaction(feed_db_t *db) {
    char *err_msg = 0;
    db->rc = sqlite3_exec(db->conn, "END TRANSACTION;", NULL, NULL, &err_msg);
    
    if (db->rc != SQLITE_OK) {
        db->error_msg = strdup(err_msg);
        sqlite3_free(err_msg);
        return FEED_DB_ERROR;
    }

    return FEED_DB_SUCCESS;
}
