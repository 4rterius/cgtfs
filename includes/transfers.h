typedef enum TransferType {
    RECOMMENDED,
    TIMED,
    TIME_REQUIRED,
    NOT_POSSIBLE
} transfer_type_t;

typedef struct Transfer {
    char from_stop_id[64];
    char to_stop_id[64];
    transfer_type_t transfer_type;
    unsigned int min_transfer_time;
} transfer_t;
