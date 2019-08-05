/**
 * @file
 * @brief    Unified place for entity field c-string lengths definitions.
 */

#ifndef CGTFS_XSTRLENGTHS_H
#define CGTFS_XSTRLENGTHS_H

// #define CGTFS_SL_MODE_PREPARATION  // comment this line out once you've established string lengths your feed needs.


#ifdef CGTFS_SL_MODE_PREPARATION

    #define CGTFS_SL_BASE_COLOR 129
    #define CGTFS_SL_BASE_CURRENCY 129
    #define CGTFS_SL_BASE_DATE 129
    #define CGTFS_SL_BASE_TIME 129

    #define CGTFS_SL_BASE_SHORTTEXT 1025
    #define CGTFS_SL_BASE_TEXT 1025
    #define CGTFS_SL_BASE_LONGTEXT 1025

#else

    #define CGTFS_SL_BASE_COLOR 7
    #define CGTFS_SL_BASE_CURRENCY 4
    #define CGTFS_SL_BASE_DATE 9
    #define CGTFS_SL_BASE_TIME 9

    #define CGTFS_SL_BASE_SHORTTEXT 64
    #define CGTFS_SL_BASE_TEXT 128
    #define CGTFS_SL_BASE_LONGTEXT 256

#endif


/**
 * @def        CGTFS_SL_IDS
 * @brief      Length of strings for IDs.
 *
 * Default value CGTFS_SL_BASE_SHORTTEXT.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_IDS CGTFS_SL_BASE_SHORTTEXT

/**
 * @def        CGTFS_SL_COL
 * @brief      Length of strings for hexadecimal RGB colors.
 *
 * Default value CGTFS_SL_BASE_COLOR.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_COL CGTFS_SL_BASE_COLOR

/**
 * @def        CGTFS_SL_CUR
 * @brief      Length of strings for currency codes.
 *
 * Default value CGTFS_SL_BASE_CURRENCY.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_CUR CGTFS_SL_BASE_CURRENCY

/**
 * @def        CGTFS_SL_DAT
 * @brief      Length of strings for YYYYMMDD dates.
 *
 * Default value CGTFS_SL_BASE_DATE.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_DAT CGTFS_SL_BASE_DATE

/**
 * @def        CGTFS_SL_TIM
 * @brief      Length of strings for HH:MM:DD times.
 *
 * Default value CGTFS_SL_BASE_TIME.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_TIM CGTFS_SL_BASE_TIME

/**
 * @def        CGTFS_SL_NAM
 * @brief      Length of strings for names or displayed codes.
 *
 * Default value CGTFS_SL_BASE_SHORTTEXT.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_NAM CGTFS_SL_BASE_SHORTTEXT

/**
 * @def        CGTFS_SL_TXT
 * @brief      Length of strings for texts.
 *
 * Default value CGTFS_SL_BASE_TEXT.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_TXT CGTFS_SL_BASE_TEXT

/**
 * @def        CGTFS_SL_DSC
 * @brief      Length of strings for long descriptions.
 *
 * Default value CGTFS_SL_BASE_LONGTEXT.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_DSC CGTFS_SL_BASE_LONGTEXT

/**
 * @def        CGTFS_SL_LNG
 * @brief      Length of strings for languages.
 *
 * Default value CGTFS_SL_BASE_SHORTTEXT.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_LNG CGTFS_SL_BASE_SHORTTEXT

/**
 * @def        CGTFS_SL_TMZ
 * @brief      Length of strings for timezones.
 *
 * Default value CGTFS_SL_BASE_SHORTTEXT.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_TMZ CGTFS_SL_BASE_SHORTTEXT

/**
 * @def        CGTFS_SL_EML
 * @brief      Length of strings for emails.
 *
 * Default value CGTFS_SL_BASE_SHORTTEXT.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_EML CGTFS_SL_BASE_SHORTTEXT

/**
 * @def        CGTFS_SL_PHN
 * @brief      Length of strings for phones.
 *
 * Default value CGTFS_SL_BASE_SHORTTEXT.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_PHN CGTFS_SL_BASE_SHORTTEXT

/**
 * @def        CGTFS_SL_URL
 * @brief      Length of strings for URLs.
 *
 * Default value CGTFS_SL_BASE_TEXT.
 *
 * @ingroup    Core__EntityCstrlengthdefs
 */
#define CGTFS_SL_URL CGTFS_SL_BASE_TEXT


#endif