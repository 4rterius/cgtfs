#ifndef CGTFS_TESTS_ENUM_PARSING_C
#define CGTFS_TESTS_ENUM_PARSING_C

#include "greatest/greatest.h"

#include "records/calendar_dates.h"
#include "records/calendar.h"
#include "records/fare_attributes.h"
#include "records/frequency.h"
#include "records/route.h"
#include "records/stop_time.h"
#include "records/stop.h"
#include "records/transfers.h"
#include "records/trip.h"

TEST pf_exception_type(void) {
    ASSERT_EQ(ET_ADDED, parse_exception_type("1"));
    ASSERT_EQ(ET_REMOVED, parse_exception_type("2"));
    ASSERT_EQ(ET_NOT_SET, parse_exception_type(""));
    PASS();
}

TEST pf_service_availability(void) {
    ASSERT_EQ(SA_UNAVAILABLE, parse_service_availability("0"));
    ASSERT_EQ(SA_AVAILABLE, parse_service_availability("1"));
    ASSERT_EQ(SA_NOT_SET, parse_service_availability(""));
    PASS();
}

TEST pf_payment_method(void) {
    ASSERT_EQ(PM_ON_BOARD, parse_payment_method("0"));
    ASSERT_EQ(PM_BEFOREHAND, parse_payment_method("1"));
    ASSERT_EQ(PM_NOT_SET, parse_payment_method(""));
    PASS();
}

TEST pf_transfer_state(void) {
    ASSERT_EQ(TS_NOT_ALLOWED, parse_transfer_state("0"));
    ASSERT_EQ(TS_ONCE, parse_transfer_state("1"));
    ASSERT_EQ(TS_TWICE, parse_transfer_state("2"));
    ASSERT_EQ(TS_UNLIMITED, parse_transfer_state(""));
    PASS();
}

TEST pf_time_exactness(void) {
    ASSERT_EQ(TE_NOT_EXACT, parse_time_exactness("0"));
    ASSERT_EQ(TE_EXACT, parse_time_exactness("1"));
    ASSERT_EQ(TE_NOT_EXACT, parse_time_exactness(""));
    PASS();
}

TEST pf_route_type(void) {
    ASSERT_EQ(RT_STREET_LEVEL, parse_route_type("0"));
    ASSERT_EQ(RT_UNDERGROUND, parse_route_type("1"));
    ASSERT_EQ(RT_LONG_RAIL, parse_route_type("2"));
    ASSERT_EQ(RT_BUS, parse_route_type("3"));
    ASSERT_EQ(RT_FERRY, parse_route_type("4"));
    ASSERT_EQ(RT_CABLE_CAR, parse_route_type("5"));
    ASSERT_EQ(RT_SUSPENDED, parse_route_type("6"));
    ASSERT_EQ(RT_FUNICULAR, parse_route_type("7"));
    ASSERT_EQ(RT_NOT_SET, parse_route_type(""));
    PASS();
}

TEST pf_stop_type(void) {
    ASSERT_EQ(ST_REGULAR, parse_stop_type("0"));
    ASSERT_EQ(ST_NOT_AVAILABLE, parse_stop_type("1"));
    ASSERT_EQ(ST_CONTACT_AGENCY, parse_stop_type("2"));
    ASSERT_EQ(ST_CONTACT_DRIVER, parse_stop_type("3"));
    ASSERT_EQ(ST_REGULAR, parse_stop_type(""));
    PASS();
}

TEST pf_timepoint_precision(void) {
    ASSERT_EQ(TP_APPROXIMATE, parse_timepoint_precision("0"));
    ASSERT_EQ(TP_EXACT, parse_timepoint_precision("1"));
    ASSERT_EQ(TP_EXACT, parse_timepoint_precision(""));
    PASS();
}

TEST pf_location_type(void) {
    ASSERT_EQ(LT_STOP, parse_location_type("0"));
    ASSERT_EQ(LT_STATION, parse_location_type("1"));
    ASSERT_EQ(LT_STATION_ENTRANCE_EXIT, parse_location_type("2"));
    ASSERT_EQ(LT_STOP, parse_location_type(""));
    PASS();
}

TEST pf_wheelchair_boarding(void) {
    ASSERT_EQ(WB_UNKNOWN_OR_INHERITED, parse_wheelchair_boarding("0"));
    ASSERT_EQ(WB_SOME, parse_wheelchair_boarding("1"));
    ASSERT_EQ(WB_NOT_POSSIBLE, parse_wheelchair_boarding("2"));
    ASSERT_EQ(WB_UNKNOWN_OR_INHERITED, parse_wheelchair_boarding(""));
    PASS();
}

TEST pf_transfer_type(void) {
    ASSERT_EQ(TT_RECOMMENDED, parse_transfer_type("0"));
    ASSERT_EQ(TT_TIMED, parse_transfer_type("1"));
    ASSERT_EQ(TT_TIME_REQUIRED, parse_transfer_type("2"));
    ASSERT_EQ(TT_NOT_POSSIBLE, parse_transfer_type("3"));
    ASSERT_EQ(TT_RECOMMENDED, parse_transfer_type(""));
    PASS();
}

TEST pf_wheelchair_accessibility(void) {
    ASSERT_EQ(WA_UNKNOWN, parse_wheelchair_accessibility("0"));
    ASSERT_EQ(WA_POSSIBLE, parse_wheelchair_accessibility("1"));
    ASSERT_EQ(WA_NOT_POSSIBLE, parse_wheelchair_accessibility("2"));
    ASSERT_EQ(WA_UNKNOWN, parse_wheelchair_accessibility(""));
    PASS();
}

TEST pf_bike_allowance(void) {
    ASSERT_EQ(BA_UNKNOWN, parse_bike_allowance("0"));
    ASSERT_EQ(BA_POSSIBLE, parse_bike_allowance("1"));
    ASSERT_EQ(BA_NOT_POSSIBLE, parse_bike_allowance("2"));
    ASSERT_EQ(BA_UNKNOWN, parse_bike_allowance(""));
    PASS();
}


SUITE(CGTFS_EnumParsing) {
    RUN_TEST(pf_exception_type);
    RUN_TEST(pf_service_availability);
    RUN_TEST(pf_payment_method);
    RUN_TEST(pf_transfer_state);
    RUN_TEST(pf_time_exactness);
    RUN_TEST(pf_route_type);
    RUN_TEST(pf_stop_type);
    RUN_TEST(pf_timepoint_precision);
    RUN_TEST(pf_location_type);
    RUN_TEST(pf_wheelchair_boarding);
    RUN_TEST(pf_transfer_type);
    RUN_TEST(pf_wheelchair_accessibility);
}

#endif