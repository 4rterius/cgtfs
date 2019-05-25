#include "database/fetching.h"

int fetch_all_agencies_db(feed_db_t *db, agency_t **records) {
    
    agency_t record;
    feed_db_status_t res;

    int record_count = count_rows(db, "agency");
    int i = 0;

    if (record_count < 1) {
        return record_count;
    }

    sqlite3_stmt *stmt;
    char qr[] = "SELECT * FROM `agency`;";

    sqlite3_prepare_v2(db->conn, qr, -1, &stmt, NULL);

    *records = malloc(record_count * sizeof(**records));

    while ((db->rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        init_agency(&record);

        strcpy(record.id, sqlite3_column_text(stmt, 0));
        strcpy(record.name, sqlite3_column_text(stmt, 1));
        strcpy(record.url, sqlite3_column_text(stmt, 2));
        strcpy(record.timezone, sqlite3_column_text(stmt, 3));
        strcpy(record.lang, sqlite3_column_text(stmt, 4));
        strcpy(record.phone, sqlite3_column_text(stmt, 5));
        strcpy(record.fare_url, sqlite3_column_text(stmt, 6));
        strcpy(record.email, sqlite3_column_text(stmt, 7));

        (*records)[i] = record;
        i++;

        if (i >= record_count)
            break;
    }

    return record_count;
}