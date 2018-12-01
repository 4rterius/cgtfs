#ifndef CGTFS_FARE_ATTRIBUTES_H
#define CGTFS_FARE_ATTRIBUTES_H

typedef enum {
    PM_ON_BOARD,
    PM_BEFOREHAND
} payment_method_t;

typedef enum {
    T_NOT_ALLOWED,
    T_ONCE,
    T_TWICE,
    T_UNLIMITED
} transfers_t;

typedef struct {
    char fare_id[65];
    int price;
    char currency_type[4];
    payment_method_t payment_method;
    transfers_t transfers;
    char agency_id[65];
    int transfer_duration;
} fare_attribute_t;

#endif
