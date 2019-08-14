#include "database/database_utils.h"

int count_rows_db(feed_db_t *db, const char *table_name) {
    int count = -1;
    sqlite3_stmt *stmt;

    int query_buf_len = 25 + strlen(table_name);
    char *query_buf = malloc(sizeof(char) * query_buf_len);
    if (query_buf == NULL) {
        return -1;
    }

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

void bake_create_uni_query_db(const char *table_name, int field_count, char **field_names, char **query) {
    char *query_beginning = "CREATE TABLE IF NOT EXISTS ";
    char *query_middle = " ( ";
    char *query_ending = ");";

    int query_length = strlen(query_beginning) + strlen(table_name) + strlen(query_middle) + strlen(query_ending) + 1;
    for (int i = 0; i < field_count; i++)
        query_length += strlen(field_names[i]) + 7;

    *query = malloc(query_length * sizeof(char));
    if (*query == NULL) {
        return;
    }
    int insert_pos = 0;

    insert_pos += snprintf(*query, query_length, "%s%s%s", query_beginning, table_name, query_middle);
    for (int i = 0; i < field_count - 1; i++)
        insert_pos += snprintf(*query + insert_pos, query_length, "%s TEXT, ", field_names[i]);
    insert_pos += snprintf(*query + insert_pos, query_length, "%s TEXT ", field_names[field_count - 1]);
    insert_pos += snprintf(*query + insert_pos, query_length, "%s", query_ending);
}

void bake_insert_uni_query_db(const char *table_name, int field_count, char **query) {
    char *query_beginning = "INSERT INTO ";
    char *query_middle = " VALUES (";
    char *query_ending = ");";

    int sql_insert_query_length = strlen(query_beginning) + strlen(table_name) + strlen(query_middle) + strlen(query_ending) + 1;
    for (int i = 0; i < field_count; i++)
        sql_insert_query_length += 4 + ((i > 9) ? 1 : 0);


    *query = malloc(sql_insert_query_length * sizeof(char));
    if (*query == NULL) {
        return;
    }
    int insert_pos = 0;

    insert_pos += snprintf(*query, sql_insert_query_length, "%s%s%s", query_beginning, table_name, query_middle);
    for (int i = 0; i < field_count - 1; i++)
        insert_pos += snprintf(*query + insert_pos, sql_insert_query_length, "?%i, ", i + 1);
    insert_pos += snprintf(*query + insert_pos, sql_insert_query_length, "?%i ", field_count - 1 + 1);
    insert_pos += snprintf(*query + insert_pos, sql_insert_query_length, "%s", query_ending);
}

feed_db_status_t begin_transaction_db(feed_db_t *db) {

    if (db->in_transaction != 0) {
        db->error_msg = strdup("cgtfs has already opened an unfinished transaction");
        return FEED_DB_ERROR;
    }

    char *err_msg = 0;
    db->rc = sqlite3_exec(db->conn, "BEGIN TRANSACTION;", NULL, NULL, &err_msg);

    if (db->rc != SQLITE_OK) {
        db->error_msg = strdup(err_msg);
        sqlite3_free(err_msg);
        return FEED_DB_ERROR;
    }

    db->in_transaction = 1;

    return FEED_DB_SUCCESS;
}

feed_db_status_t end_transaction_db(feed_db_t *db) {

    if (db->in_transaction == 0) {
        db->error_msg = strdup("cgtfs has not opened an unfinished transaction");
        return FEED_DB_ERROR;
    }

    char *err_msg = 0;
    db->rc = sqlite3_exec(db->conn, "END TRANSACTION;", NULL, NULL, &err_msg);

    if (db->rc != SQLITE_OK) {
        db->error_msg = strdup(err_msg);
        sqlite3_free(err_msg);
        return FEED_DB_ERROR;
    }

    db->in_transaction = 0;

    return FEED_DB_SUCCESS;
}
