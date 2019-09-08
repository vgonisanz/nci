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
#include <ncurses.h>

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
    /* Ncurses input keys are
     * Pseudo-character tokens outside ASCII range */
    I_KEY_DOWN		     = 258, /* down-arrow key */
    I_KEY_UP		     = 259, /* up-arrow key */
    I_KEY_LEFT		     = 260, /* left-arrow key */
    I_KEY_RIGHT		     = 261, /* right-arrow key */
    I_KEY_HOME		     = 262, /* home key */
    I_KEY_BACKSPACE		 = 263, /* backspace key */
    I_KEY_F0		     = 264, /* Function keys.  Space for 64 */
    I_KEY_DL		     = 328, /* delete-line key */
    I_KEY_IL		     = 329, /* insert-line key */
    I_KEY_DC		     = 330, /* delete-character key */
    I_KEY_IC		     = 331, /* insert-character key */
    I_KEY_EIC		     = 332, /* sent by rmir or smir in insert mode */
    I_KEY_CLEAR		     = 333, /* clear-screen or erase key */
    I_KEY_EOS		     = 334, /* clear-to-end-of-screen key */
    I_KEY_EOL		     = 335, /* clear-to-end-of-line key */
    I_KEY_SF		     = 336, /* scroll-forward key */
    I_KEY_SR		     = 337, /* scroll-backward key */
    I_KEY_NPAGE		     = 338, /* next-page key */
    I_KEY_PPAGE		     = 339, /* previous-page key */
    I_KEY_STAB		     = 340, /* set-tab key */
    I_KEY_CTAB		     = 341, /* clear-tab key */
    I_KEY_CATAB		     = 342, /* clear-all-tabs key */
    I_KEY_ENTER		     = 343, /* enter/send key */
    I_KEY_PRINT		     = 346, /* print key */
    I_KEY_LL		     = 347, /* lower-left key (home down) */
    I_KEY_A1		     = 348, /* upper left of keypad */
    I_KEY_A3		     = 349, /* upper right of keypad */
    I_KEY_B2		     = 350, /* center of keypad */
    I_KEY_C1		     = 351, /* lower left of keypad */
    I_KEY_C3		     = 352, /* lower right of keypad */
    I_KEY_BTAB		     = 353, /* back-tab key */
    I_KEY_BEG		     = 354, /* begin key */
    I_KEY_CANCEL		 = 355, /* cancel key */
    I_KEY_CLOSE		     = 356, /* close key */
    I_KEY_COMMAND		 = 357, /* command key */
    I_KEY_COPY		     = 358, /* copy key */
    I_KEY_CREATE		 = 359, /* create key */
    I_KEY_END		     = 360, /* end key */
    I_KEY_EXIT		     = 361, /* exit key */
    I_KEY_FIND		     = 362, /* find key */
    I_KEY_HELP		     = 363, /* help key */
    I_KEY_MARK		     = 364, /* mark key */
    I_KEY_MESSAGE		 = 365, /* message key */
    I_KEY_MOVE		     = 366, /* move key */
    I_KEY_NEXT		     = 367, /* next key */
    I_KEY_OPEN		     = 368, /* open key */
    I_KEY_OPTIONS		 = 369, /* options key */
    I_KEY_PREVIOUS		 = 370, /* previous key */
    I_KEY_REDO		     = 371, /* redo key */
    I_KEY_REFERENCE		 = 372, /* reference key */
    I_KEY_REFRESH		 = 373, /* refresh key */
    I_KEY_REPLACE		 = 374, /* replace key */
    I_KEY_RESTART		 = 375, /* restart key */
    I_KEY_RESUME		 = 376, /* resume key */
    I_KEY_SAVE		     = 377, /* save key */
    I_KEY_SBEG		     = 378, /* shifted begin key */
    I_KEY_SCANCEL		 = 379, /* shifted cancel key */
    I_KEY_SCOMMAND		 = 380, /* shifted command key */
    I_KEY_SCOPY		     = 381, /* shifted copy key */
    I_KEY_SCREATE		 = 382, /* shifted create key */
    I_KEY_SDC		     = 383, /* shifted delete-character key */
    I_KEY_SDL		     = 384, /* shifted delete-line key */
    I_KEY_SELECT		 = 385, /* select key */
    I_KEY_SEND		     = 386, /* shifted end key */
    I_KEY_SEOL		     = 387, /* shifted clear-to-end-of-line key */
    I_KEY_SEXIT		     = 388, /* shifted exit key */
    I_KEY_SFIND		     = 389, /* shifted find key */
    I_KEY_SHELP		     = 390, /* shifted help key */
    I_KEY_SHOME		     = 391, /* shifted home key */
    I_KEY_SIC		     = 392, /* shifted insert-character key */
    I_KEY_SLEFT		     = 393, /* shifted left-arrow key */
    I_KEY_SMESSAGE		 = 394, /* shifted message key */
    I_KEY_SMOVE		     = 395, /* shifted move key */
    I_KEY_SNEXT		     = 396, /* shifted next key */
    I_KEY_SOPTIONS		 = 397, /* shifted options key */
    I_KEY_SPREVIOUS		 = 398, /* shifted previous key */
    I_KEY_SPRINT		 = 399, /* shifted print key */
    I_KEY_SREDO		     = 400, /* shifted redo key */
    I_KEY_SREPLACE		 = 401, /* shifted replace key */
    I_KEY_SRIGHT		 = 402, /* shifted right-arrow key */
    I_KEY_SRSUME		 = 403, /* shifted resume key */
    I_KEY_SSAVE		     = 404, /* shifted save key */
    I_KEY_SSUSPEND		 = 405, /* shifted suspend key */
    I_KEY_SUNDO		     = 406, /* shifted undo key */
    I_KEY_SUSPEND		 = 407, /* suspend key */
    I_KEY_UNDO		     = 408, /* undo key */
    I_KEY_MOUSE		     = 409, /* Mouse event has occurred */
    I_KEY_RESIZE		 = 410, /* Terminal resize event */
    I_KEY_EVENT		     = 411, /* We were interrupted by an event */
    I_KEY_MAX		     = 511, /* Maximum key value is 0633 */
};

}   // namespace nci

#endif  /* __NCI_TYPES_HEADER_FILE_H */
