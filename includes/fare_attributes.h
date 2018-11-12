#ifndef CGTFS_FARE_ATTRIBUTES_H
#define CGTFS_FARE_ATTRIBUTES_H

typedef enum PaymentMethod {
    ON_BOARD,
    BEFOREHAND
} payment_method_t;

typedef enum Transfers {
    NOT_ALLOWED,
    ONCE,
    TWICE,
    UNLIMITED
} transfers_t;

typedef struct FareAttribute {
    char fare_id[64];
    int price;
    char currency_type[3];
    payment_method_t payment_method;
    transfers_t transfers;
    char agency_id[64];
    int transfer_duration;
} fare_attribute_t;

#endif
