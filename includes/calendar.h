typedef struct Service {
    char id[64];
    unsigned int monday;
    unsigned int tuesday;
    unsigned int wednesday;
    unsigned int thursday;
    unsigned int friday;
    unsigned int saturday;
    unsigned int sunday;
    char start_date[8];
    char end_date[8];
} service_t;
