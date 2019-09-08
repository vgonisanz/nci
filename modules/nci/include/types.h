/**
 * @file            types.h
 * @version         1.0
 * @date            May 2019
 * @brief           General Types for nci library.
 * @author          vgonisanz
 *
 */
#ifndef __NCI_TYPES_HEADER_FILE_H
#define __NCI_TYPES_HEADER_FILE_H

#include <stdint.h>
#include <iostream>

namespace nci
{

enum CURSOR : uint8_t {
    INVISIBLE = 0,
    VISIBLE = 1,
    VERY_VISIBLE = 2,
};

typedef struct Point2D
{
    uint32_t x;
    uint32_t y;

    Point2D(uint32_t x = 0, uint32_t y = 0):
    x(x),
    y(y) {}

    inline Point2D operator+(const Point2D& other) const
    {
        Point2D res {x + other.x, y + other.y};
        return res;
    }
    inline Point2D &operator+=( const uint32_t &rhs)
    {
        this->x += rhs;
        this->y += rhs;
        return *this;
    }
    inline Point2D operator-(const Point2D& other) const
    {
        Point2D res {x - other.x, y - other.y};
        return res;
    }
    inline Point2D &operator-=( const uint32_t &rhs)
    {
        this->x -= rhs;
        this->y -= rhs;
        return *this;
    }
} Point2D;

typedef struct Size2D
{
    uint32_t width;
    uint32_t height;

    Size2D(uint32_t width = 2, uint32_t height = 2):
    width(width),
    height(height) {}

    inline Size2D operator+(const Size2D& other) const
    {
        Size2D res {width + other.width, height + other.height};
        return res;
    }
    inline Size2D &operator+=( const uint32_t &rhs)
    {
        this->width += rhs;
        this->height += rhs;
        return *this;
    }
    inline Size2D operator-(const Size2D& other) const
    {
        Size2D res {width - other.width, height - other.height};
        return res;
    }
    inline Size2D &operator-=( const uint32_t &rhs)
    {
        this->width -= rhs;
        this->height -= rhs;
        return *this;
    }
} Size2D;

/**
 * Keyboard relationship in decimal
 * ASCII / not included: ISO 8859-1 (Latin-1)
 */
enum KEYS : uint16_t {
    /* Control characters */
    NUL                  =  0,   /* NUL */
    START_OF_HEADING     =  1,   /* SOH */
    START_OF_TEXT        =  2,   /* STX */
    END_OF_TEXT          =  3,   /* EOT */
    END_OF_TX            =  4,   /* EOT */
    ENQUIRY              =  5,   /* ENQ */
    ACKNOWLEDGE          =  6,   /* ACK */
    BELL                 =  7,   /* BEL */
    BACKSPACE            =  8,   /* BS */
    HORIZONTAL_TAB       =  9,   /* HT */
    ENTER                = 10,   /* LF, NL */
    VERTICAL_TAB         = 11,   /* VT */
    NEW_PAGE             = 12,   /* FF, NP */
    CARRIAGE_RETURN      = 13,   /* CR */
    SHIFT_IN             = 14,   /* SO */
    SHIFT_OUT            = 15,   /* SI */
    DATA_LINK_ESCAPE     = 16,   /* DLE */
    DEVICE_CTRL_1        = 17,   /* DC1 */
    DEVICE_CTRL_2        = 18,   /* DC2 */
    DEVICE_CTRL_3        = 19,   /* DC3 */
    DEVICE_CTRL_4        = 20,   /* DC4 */
    NEGATIVE_ACKNOWLEDGE = 21,   /* NAK */
    SYNC_IDLE            = 22,   /* SYN */
    END_OF_TX_BLOCK      = 23,   /* ETB */
    CANCEL               = 24,   /* CAN */
    END_OF_MEDIUM        = 25,   /* EM */
    SUBSTITUTE           = 26,   /* SUB */
    ESCAPE               = 27,   /* ESC */
    FILE_SEPARATOR       = 28,   /* FS */
    GROUP_SEPARATOR      = 29,   /* GS */
    RECORD_SEPARATOR     = 30,   /* RS */
    UNIT_SEPARATOR       = 31,   /* US */
    /* Special characters and numbers */
    SPACE                = 32,	/*   */
    EXCLAMATION		     = 33,	/* ! */
    DOUBLE_QUOTE		 = 34,	/* " */
    NUMBER_SIGN		     = 35,	/* # */
    DOLLAR_SIGN		     = 36,	/* $ */
    PERCENT_SIGN		 = 37,	/* % */
    AMPERSAND		     = 38,	/* & */
    SINGLE_QUOTE		 = 39,	/* ' */
    OPENING_PARENTHESIS  = 40,	/* ( */
    CLOSING_PARENTHESIS	 = 41,	/* ) */
    ASTERISK		     = 42,	/* * */
    PLUS_SIGN		     = 43,	/* + */
    COMMA		         = 44,	/* , */
    MINUS_SIGN		     = 45,	/* - */
    PERIOD		         = 46,	/* . */
    SLASH		         = 47,	/* / */
    DIGIT_0		         = 48,	/* 0 */
    DIGIT_1		         = 49,	/* 1 */
    DIGIT_2		         = 50,	/* 2 */
    DIGIT_3		         = 51,	/* 3 */
    DIGIT_4		         = 52,	/* 4 */
    DIGIT_5		         = 53,	/* 5 */
    DIGIT_6		         = 54,	/* 6 */
    DIGIT_7		         = 55,	/* 7 */
    DIGIT_8		         = 56,	/* 8 */
    DIGIT_9		         = 57,	/* 9 */
    COLON		         = 58,	/* : */
    SEMICOLON		     = 59,	/* ; */
    LESS_THAN_SIGN	 	 = 60,	/* < */
    EQUAL_SIGN		     = 61,	/* = */
    GREATER_THAN_SIGN	 = 62,	/* > */
    QUESTION		     = 63,	/* ? */
    /* Upper Case Letters */
    AT_SYMBOL		     = 64,	/* @ */
    CAPITAL_A		     = 65,	/* A */
    CAPITAL_B		     = 66,	/* B */
    CAPITAL_C		     = 67,	/* C */
    CAPITAL_D		     = 68,	/* D */
    CAPITAL_E		     = 69,	/* E */
    CAPITAL_F		     = 70,	/* F */
    CAPITAL_G		     = 71,	/* G */
    CAPITAL_H		     = 72,	/* H */
    CAPITAL_I		     = 73,	/* I */
    CAPITAL_J		     = 74,	/* J */
    CAPITAL_K		     = 75,	/* K */
    CAPITAL_L		     = 76,	/* L */
    CAPITAL_M		     = 77,	/* M */
    CAPITAL_N		     = 78,	/* N */
    CAPITAL_O		     = 79,	/* O */
    CAPITAL_P		     = 80,	/* P */
    CAPITAL_Q		     = 81,	/* Q */
    CAPITAL_R		     = 82,	/* R */
    CAPITAL_S		     = 83,	/* S */
    CAPITAL_T		     = 84,	/* T */
    CAPITAL_U		     = 85,	/* U */
    CAPITAL_V		     = 86,	/* V */
    CAPITAL_W		     = 87,	/* W */
    CAPITAL_X		     = 88,	/* X */
    CAPITAL_Y		     = 89,	/* Y */
    CAPITAL_Z		     = 90,	/* Z */
    OPENING_BRACKET		 = 91,	/* [ */
    BACKSLASH		     = 92,	/* \ */
    CLOSING_BRACKET		 = 93,	/* ] */
    CARET		         = 94,	/* ^ */
    UNDERSCORE		     = 95,	/* _ */
    /* Lower Case Letters */
    GRAVE_ACCENT		 = 96,	/* ` */
    SMALL_A		         = 97,	/* a */
    SMALL_B		         = 98,	/* b */
    SMALL_C		         = 99,	/* c */
    SMALL_D		         = 100,	/* d */
    SMALL_E		         = 101,	/* e */
    SMALL_F		         = 102,	/* f */
    SMALL_G		         = 103,	/* g */
    SMALL_H		         = 104,	/* h */
    SMALL_I		         = 105,	/* i */
    SMALL_J		         = 106,	/* j */
    SMALL_K		         = 107,	/* k */
    SMALL_L		         = 108,	/* l */
    SMALL_M		         = 109,	/* m */
    SMALL_N		         = 110,	/* n */
    SMALL_O		         = 111,	/* o */
    SMALL_P		         = 112,	/* p */
    SMALL_Q		         = 113,	/* q */
    SMALL_R		         = 114,	/* r */
    SMALL_S		         = 115,	/* s */
    SMALL_T		         = 116,	/* t */
    SMALL_U		         = 117,	/* u */
    SMALL_V		         = 118,	/* v */
    SMALL_W		         = 119,	/* w */
    SMALL_X		         = 120,	/* x */
    SMALL_Y	             = 121,	/* y */
    SMALL_Z		         = 122,	/* z */
    OPENING_BRACE		 = 123,	/* { */
    VERTICAL_BAR		 = 124,	/* | */
    CLOSING_BRACE		 = 125,	/* } */
    TILDE		         = 126,	/* ~ */
    DEL                  = 127, /* DEL */
};

}   // namespace nci

#endif  /* __NCI_TYPES_HEADER_FILE_H */
