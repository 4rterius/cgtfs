#ifndef CGTFS_TESTS_PARSING_FUNCTIONS_C
#define CGTFS_TESTS_PARSING_FUNCTIONS_C

#include "records/calendar_dates.h"
#include "records/calendar.h"
#include "records/fare_attributes.h"
#include "records/frequency.h"
#include "records/route.h"
#include "records/stop_time.h"
#include "records/stop.h"
#include "records/transfers.h"
#include "records/trip.h"

int test_pf_exception_type(void) {
    {
        if (parse_exception_type("1") != ET_ADDED) {
            printf("exception_type_t value (1) parsed incorrectly");
        }
        if (parse_exception_type("2") != ET_REMOVED) {
            printf("exception_type_t value (2) parsed incorrectly");
        }
        if (parse_exception_type("") != ET_NOT_SET) {
            printf("exception_type_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_service_availability(void) {
    {
        if (parse_service_availability("0") != SA_UNAVAILABLE) {
            printf("service_availability_t value (0) parsed incorrectly");
        }
        if (parse_service_availability("1") != SA_AVAILABLE) {
            printf("service_availability_t value (1) parsed incorrectly");
        }
        if (parse_service_availability("") != SA_NOT_SET) {
            printf("service_availability_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_payment_method(void) {
    {
        if (parse_payment_method("0") != PM_ON_BOARD) {
            printf("payment_method_t value (0) parsed incorrectly");
        }
        if (parse_payment_method("1") != PM_BEFOREHAND) {
            printf("payment_method_t value (1) parsed incorrectly");
        }
        if (parse_payment_method("") != PM_NOT_SET) {
            printf("payment_method_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_transfer_state(void) {
    {
        if (parse_transfer_state("0") != TS_NOT_ALLOWED) {
            printf("transfers_state_t value (0) parsed incorrectly");
        }
        if (parse_transfer_state("1") != TS_ONCE) {
            printf("transfers_state_t value (1) parsed incorrectly");
        }
        if (parse_transfer_state("2") != TS_TWICE) {
            printf("transfers_state_t value (1) parsed incorrectly");
        }
        if (parse_transfer_state("") != TS_UNLIMITED) {
            printf("transfers_state_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_time_exactness(void) {
    {
        if (parse_time_exactness("0") != TE_NOT_EXACT) {
            printf("time_exactness_t value (0) parsed incorrectly");
        }
        if (parse_time_exactness("1") != TE_EXACT) {
            printf("time_exactness_t value (1) parsed incorrectly");
        }
        if (parse_time_exactness("") != TE_NOT_EXACT) {
            printf("time_exactness_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_route_type(void) {
    {
        if (parse_route_type("0") != RT_STREET_LEVEL) {
            printf("route_type_t value (0) parsed incorrectly");
        }
        if (parse_route_type("1") != RT_UNDERGROUND) {
            printf("route_type_t value (1) parsed incorrectly");
        }
        if (parse_route_type("2") != RT_LONG_RAIL) {
            printf("route_type_t value (2) parsed incorrectly");
        }
        if (parse_route_type("3") != RT_BUS) {
            printf("route_type_t value (3) parsed incorrectly");
        }
        if (parse_route_type("4") != RT_FERRY) {
            printf("route_type_t value (4) parsed incorrectly");
        }
        if (parse_route_type("5") != RT_CABLE_CAR) {
            printf("route_type_t value (5) parsed incorrectly");
        }
        if (parse_route_type("6") != RT_SUSPENDED) {
            printf("route_type_t value (6) parsed incorrectly");
        }
        if (parse_route_type("7") != RT_FUNICULAR) {
            printf("route_type_t value (7) parsed incorrectly");
        }
        if (parse_route_type("") != RT_NOT_SET) {
            printf("route_type_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_stop_type(void) {
    {
        if (parse_stop_type("0") != ST_REGULAR) {
            printf("stop_type_t value (0) parsed incorrectly");
        }
        if (parse_stop_type("1") != ST_NOT_AVAILABLE) {
            printf("stop_type_t value (1) parsed incorrectly");
        }
        if (parse_stop_type("2") != ST_CONTACT_AGENCY) {
            printf("stop_type_t value (2) parsed incorrectly");
        }
        if (parse_stop_type("3") != ST_CONTACT_DRIVER) {
            printf("stop_type_t value (3) parsed incorrectly");
        }
        if (parse_stop_type("") != ST_REGULAR) {
            printf("stop_type_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_timepoint_precision(void) {
    {
        if (parse_timepoint_precision("0") != TP_APPROXIMATE) {
            printf("timepoint_precision_t value (0) parsed incorrectly");
        }
        if (parse_timepoint_precision("1") != TP_EXACT) {
            printf("timepoint_precision_t value (1) parsed incorrectly");
        }
        if (parse_timepoint_precision("") != TP_EXACT) {
            printf("timepoint_precision_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_location_type(void) {
    {
        if (parse_location_type("0") != LT_STOP) {
            printf("location_type_t value (0) parsed incorrectly");
        }
        if (parse_location_type("1") != LT_STATION) {
            printf("location_type_t value (1) parsed incorrectly");
        }
        if (parse_location_type("2") != LT_STATION_ENTRANCE_EXIT) {
            printf("location_type_t value (2) parsed incorrectly");
        }
        if (parse_location_type("") != LT_STOP) {
            printf("location_type_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_wheelchair_boarding(void) {
    {
        if (parse_wheelchair_boarding("0") != WB_UNKNOWN_OR_INHERITED) {
            printf("wheelchair_boarding_t value (0) parsed incorrectly");
        }
        if (parse_wheelchair_boarding("1") != WB_SOME) {
            printf("wheelchair_boarding_t value (1) parsed incorrectly");
        }
        if (parse_wheelchair_boarding("2") != WB_NOT_POSSIBLE) {
            printf("wheelchair_boarding_t value (2) parsed incorrectly");
        }
        if (parse_wheelchair_boarding("") != WB_UNKNOWN_OR_INHERITED) {
            printf("wheelchair_boarding_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_transfer_type(void) {
    {
        if (parse_transfer_type("0") != TT_RECOMMENDED) {
            printf("transfer_type_t value (0) parsed incorrectly");
        }
        if (parse_transfer_type("1") != TT_TIMED) {
            printf("transfer_type_t value (1) parsed incorrectly");
        }
        if (parse_transfer_type("2") != TT_TIME_REQUIRED) {
            printf("transfer_type_t value (2) parsed incorrectly");
        }
        if (parse_transfer_type("3") != TT_NOT_POSSIBLE) {
            printf("transfer_type_t value (3) parsed incorrectly");
        }
        if (parse_transfer_type("") != TT_RECOMMENDED) {
            printf("transfer_type_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_wheelchair_accessibility(void) {
    {
        if (parse_wheelchair_accessibility("0") != WA_UNKNOWN) {
            printf("wheelchair_accessible_t value (0) parsed incorrectly");
        }
        if (parse_wheelchair_accessibility("1") != WA_POSSIBLE) {
            printf("wheelchair_accessible_t value (1) parsed incorrectly");
        }
        if (parse_wheelchair_accessibility("2") != WA_NOT_POSSIBLE) {
            printf("wheelchair_accessible_t value (2) parsed incorrectly");
        }
        if (parse_wheelchair_accessibility("") != WA_UNKNOWN) {
            printf("wheelchair_accessible_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

int test_pf_bike_allowance(void) {
    {
        if (parse_bike_allowance("0") != BA_UNKNOWN) {
            printf("bikes_allowed_t value (0) parsed incorrectly");
        }
        if (parse_bike_allowance("1") != BA_POSSIBLE) {
            printf("bikes_allowed_t value (1) parsed incorrectly");
        }
        if (parse_bike_allowance("2") != BA_NOT_POSSIBLE) {
            printf("bikes_allowed_t value (2) parsed incorrectly");
        }
        if (parse_bike_allowance("") != BA_UNKNOWN) {
            printf("bikes_allowed_t value (empty) parsed incorrectly");
        }
    }
    return 0;
}

#endif