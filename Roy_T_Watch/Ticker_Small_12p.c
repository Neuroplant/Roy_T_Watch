#include "lvgl/lvgl.h"

/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifndef TICKER_SMALL_12P
#define TICKER_SMALL_12P 1
#endif

#if TICKER_SMALL_12P

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+20 " " */

    /* U+21 "!" */
    0x38, 0x0, 0x6, 0x7, 0x1, 0x81, 0xc0, 0x0,
    0x0, 0x38, 0x0,

    /* U+22 "\"" */
    0x38, 0x70, 0x70, 0xe0, 0x0, 0x0,

    /* U+23 "#" */
    0x7, 0xe, 0x0, 0x0, 0x0, 0x1, 0xc3, 0x80,
    0xff, 0xff, 0xc0, 0x70, 0xe0, 0x3f, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0xe1, 0xc0, 0x7, 0xe, 0x0,

    /* U+24 "$" */
    0x0, 0xe0, 0x0, 0x0, 0x0, 0x1, 0xff, 0x80,
    0xe0, 0x0, 0x0, 0x7f, 0xe0, 0x0, 0x0, 0x60,
    0x0, 0x0, 0x0, 0xff, 0xc0, 0x0, 0xe0, 0x0,

    /* U+25 "%" */
    0x7f, 0x0, 0xe0, 0x0, 0x0, 0x1f, 0xc0, 0x30,
    0x0, 0x1f, 0xc0, 0x6, 0x0, 0x3, 0x80, 0x0,
    0x0, 0x0, 0xe, 0x1, 0xf8, 0x70, 0xf, 0xe0,

    /* U+26 "&" */
    0x0, 0xe0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xf0,
    0xe0, 0x0, 0x0, 0x7f, 0xfc, 0x38, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xf8, 0x0, 0xe0, 0x0,

    /* U+27 "'" */
    0x38, 0xc, 0x0, 0x0,

    /* U+28 "(" */
    0x0, 0x70, 0x0, 0x0, 0xc, 0x1, 0xc0, 0x3,
    0x80, 0x7, 0x0, 0x0, 0x0, 0x1, 0x80, 0x0,
    0x70,

    /* U+29 ")" */
    0x38, 0x0, 0x0, 0x0, 0xc, 0x0, 0x3, 0x80,
    0x7, 0x0, 0xe, 0x0, 0x0, 0x1, 0x80, 0x38,
    0x0,

    /* U+2A "*" */
    0x7, 0x0, 0x0, 0x0, 0xff, 0xc0, 0x38, 0x0,
    0x0, 0x0,

    /* U+2B "+" */
    0x0, 0xe0, 0x0, 0x3, 0x0, 0x1f, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x70, 0x0,

    /* U+2C "," */
    0x3, 0x0, 0x0, 0x3, 0x3, 0x80,

    /* U+2D "-" */
    0x3f, 0xf0, 0x0, 0x0,

    /* U+2E "." */
    0x3f, 0x3, 0xf0,

    /* U+2F "/" */
    0x0, 0x0, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x30,
    0x0, 0x1c, 0x0, 0x6, 0x0, 0x3, 0x80, 0x0,
    0x0, 0x0, 0xe, 0x0, 0x0, 0x70, 0x0, 0x0,

    /* U+30 "0" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0x0, 0xc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xfe, 0x0,

    /* U+31 "1" */
    0x7, 0x0, 0x0, 0x0, 0xfc, 0x0, 0x38, 0x0,
    0x30, 0x0, 0xe0, 0x0, 0x0, 0x1, 0x80, 0x3f,
    0xf0,

    /* U+32 "2" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0x0, 0x1, 0xc0, 0x0, 0xe0, 0x0, 0x30, 0x0,
    0x0, 0x0, 0x0, 0xe0, 0x0, 0x7f, 0xff, 0xe0,

    /* U+33 "3" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0x0, 0x1, 0xc0, 0x7f, 0xe0, 0x0, 0x0, 0x60,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xfe, 0x0,

    /* U+34 "4" */
    0x0, 0xe, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x80,
    0xe, 0x1c, 0x7, 0x0, 0xe0, 0x3f, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x1, 0xc0, 0x0, 0xe, 0x0,

    /* U+35 "5" */
    0x7f, 0xff, 0xe0, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0xff, 0xfc, 0x0, 0x0, 0xc, 0x0, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xfe, 0x0,

    /* U+36 "6" */
    0x0, 0xfe, 0x0, 0x0, 0x0, 0x1, 0xc0, 0x0,
    0xe0, 0x0, 0x7, 0xff, 0xe0, 0x38, 0x0, 0x60,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xfe, 0x0,

    /* U+37 "7" */
    0x7f, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x30,
    0x0, 0x1c, 0x0, 0x6, 0x0, 0x3, 0x80, 0x0,
    0x0, 0x0, 0xe, 0x0, 0x0, 0x70, 0x0, 0x0,

    /* U+38 "8" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc0, 0x7f, 0xe0, 0x38, 0x0, 0x60,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xfe, 0x0,

    /* U+39 "9" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc0, 0x7f, 0xfc, 0x0, 0x0, 0x70,
    0x0, 0x0, 0x0, 0x1, 0xc0, 0x7, 0xe0, 0x0,

    /* U+3A ":" */
    0x3f, 0x3, 0xf0, 0x0, 0x0, 0x0, 0x3f, 0x3,
    0xf0,

    /* U+3B ";" */
    0x3, 0x0, 0x70, 0x0, 0x0, 0x30, 0x0, 0x0,
    0x30, 0x38, 0x0,

    /* U+3C "<" */
    0x0, 0xe, 0x0, 0x0, 0x0, 0x6, 0x0, 0x1c,
    0x0, 0x70, 0x0, 0x1, 0xc0, 0x0, 0x0, 0x0,
    0x1, 0x80, 0x0, 0xe, 0x0,

    /* U+3D "=" */
    0x7f, 0xff, 0xc0, 0x0, 0x0, 0x1f, 0xff, 0xf0,
    0x0, 0x0, 0x0,

    /* U+3E ">" */
    0x38, 0x0, 0x0, 0x0, 0x0, 0x30, 0x0, 0x1,
    0xc0, 0x0, 0x6, 0x0, 0x1c, 0x0, 0x0, 0x0,
    0xc, 0x0, 0x38, 0x0, 0x0,

    /* U+3F "?" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0x0, 0x1, 0xc0, 0x0, 0xe0, 0x0, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x0,

    /* U+40 "@" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe1, 0xff, 0xc7, 0x6, 0xc, 0x38, 0x7f, 0xf0,
    0x0, 0x0, 0xe, 0x0, 0x0, 0x7, 0xff, 0xe0,

    /* U+41 "A" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0xff, 0xfc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x70, 0x0, 0xe0,

    /* U+42 "B" */
    0x7f, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0xff, 0xe0, 0x38, 0x0, 0x60,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7f, 0xfe, 0x0,

    /* U+43 "C" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x0, 0x7, 0x0, 0x0, 0x38, 0x0, 0x0,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xfe, 0x0,

    /* U+44 "D" */
    0x7f, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0x0, 0xc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7f, 0xfe, 0x0,

    /* U+45 "E" */
    0x7f, 0xff, 0xe0, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0xe0, 0x0, 0x7, 0xff, 0xfc, 0x38, 0x0, 0x0,
    0x0, 0x0, 0xe, 0x0, 0x0, 0x7f, 0xff, 0xe0,

    /* U+46 "F" */
    0x7f, 0xff, 0xe0, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0xe0, 0x0, 0x7, 0xff, 0xfc, 0x38, 0x0, 0x0,
    0x0, 0x0, 0xe, 0x0, 0x0, 0x70, 0x0, 0x0,

    /* U+47 "G" */
    0x7, 0xff, 0xe0, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0xe0, 0x0, 0x7, 0x0, 0xfc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xff, 0xe0,

    /* U+48 "H" */
    0x70, 0x0, 0xe0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0xff, 0xfc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x70, 0x0, 0xe0,

    /* U+49 "I" */
    0x3f, 0xf0, 0x0, 0x0, 0xc, 0x0, 0x38, 0x0,
    0x30, 0x0, 0xe0, 0x0, 0x0, 0x1, 0x80, 0x3f,
    0xf0,

    /* U+4A "J" */
    0x0, 0x0, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x30,
    0x0, 0x1, 0xc0, 0x0, 0xc, 0x0, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xfe, 0x0,

    /* U+4B "K" */
    0x70, 0x0, 0xe0, 0x0, 0x0, 0x1c, 0x3, 0x80,
    0xe1, 0xc0, 0x7, 0xf0, 0x0, 0x38, 0x30, 0x0,
    0x0, 0x0, 0xe, 0x1, 0xc0, 0x70, 0x0, 0xe0,

    /* U+4C "L" */
    0x70, 0x0, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0xe0, 0x0, 0x7, 0x0, 0x0, 0x38, 0x0, 0x0,
    0x0, 0x0, 0xe, 0x0, 0x0, 0x7f, 0xff, 0xe0,

    /* U+4D "M" */
    0x70, 0x0, 0xe0, 0x0, 0x0, 0x1f, 0xc3, 0xf0,
    0xe1, 0xc1, 0xc7, 0x6, 0xc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x70, 0x0, 0xe0,

    /* U+4E "N" */
    0x70, 0x0, 0xe0, 0x0, 0x0, 0x1f, 0xc0, 0x30,
    0xe1, 0xc1, 0xc7, 0x0, 0xfc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x70, 0x0, 0xe0,

    /* U+4F "O" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0x0, 0xc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xfe, 0x0,

    /* U+50 "P" */
    0x7f, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0xff, 0xe0, 0x38, 0x0, 0x0,
    0x0, 0x0, 0xe, 0x0, 0x0, 0x70, 0x0, 0x0,

    /* U+51 "Q" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0x0, 0xc, 0x38, 0x30, 0x70,
    0x0, 0x0, 0xe, 0x1, 0xc0, 0x7, 0xe0, 0xe0,

    /* U+52 "R" */
    0x7f, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0xff, 0xe0, 0x38, 0x0, 0x60,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x70, 0x0, 0xe0,

    /* U+53 "S" */
    0x7, 0xfe, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x0, 0x0, 0x7f, 0xe0, 0x0, 0x0, 0x60,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xfe, 0x0,

    /* U+54 "T" */
    0x7f, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x18, 0x0,
    0x1, 0xc0, 0x0, 0x6, 0x0, 0x0, 0x70, 0x0,
    0x0, 0x0, 0x0, 0xc, 0x0, 0x0, 0xe0, 0x0,

    /* U+55 "U" */
    0x70, 0x0, 0xe0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0x0, 0xc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xfe, 0x0,

    /* U+56 "V" */
    0x70, 0x0, 0xe0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0x0, 0xc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0x0, 0xe1, 0xc0, 0x0, 0xe0, 0x0,

    /* U+57 "W" */
    0x70, 0x0, 0xe0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc7, 0x6, 0xc, 0x38, 0x70, 0x70,
    0x0, 0x0, 0xf, 0xe1, 0xf8, 0x70, 0x0, 0xe0,

    /* U+58 "X" */
    0x70, 0x0, 0xe0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe, 0x1c, 0x0, 0x6, 0x0, 0x3, 0x87, 0x0,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x70, 0x0, 0xe0,

    /* U+59 "Y" */
    0x70, 0x0, 0xe0, 0x0, 0x0, 0x1c, 0x0, 0x30,
    0xe0, 0x1, 0xc0, 0x70, 0xe0, 0x0, 0x30, 0x0,
    0x0, 0x0, 0x0, 0xc, 0x0, 0x0, 0xe0, 0x0,

    /* U+5A "Z" */
    0x7f, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x30,
    0x0, 0x1c, 0x0, 0x6, 0x0, 0x3, 0x80, 0x0,
    0x0, 0x0, 0xe, 0x0, 0x0, 0x7f, 0xff, 0xe0,

    /* U+5B "[" */
    0x3f, 0xf0, 0x0, 0x0, 0xe0, 0x1, 0xc0, 0x3,
    0x80, 0x7, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x3f,
    0xf0,

    /* U+5C "\\" */
    0x70, 0x0, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0xe, 0x0, 0x0, 0x6, 0x0, 0x0, 0x7, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x18, 0x0, 0x0, 0xe0,

    /* U+5D "]" */
    0x3f, 0xf0, 0x0, 0x0, 0x1, 0xc0, 0x3, 0x80,
    0x7, 0x0, 0xe, 0x0, 0x0, 0x0, 0x38, 0x3f,
    0xf0,

    /* U+5E "^" */
    0x0, 0x60, 0x0, 0x0, 0x0, 0x1, 0xc3, 0x80,
    0xe0, 0x1, 0x80, 0x0, 0x0, 0x0,

    /* U+5F "_" */
    0x7f, 0xff, 0xc0, 0x0, 0x0, 0x0,

    /* U+60 "`" */
    0x38, 0x0, 0x30, 0x0, 0x0,

    /* U+61 "a" */
    0x7, 0xfe, 0x0, 0x0, 0x6, 0x1, 0xff, 0xf8,
    0x0, 0x0, 0x7, 0x0, 0xc, 0x3, 0xff, 0xf0,

    /* U+62 "b" */
    0x70, 0x0, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0xff, 0xfc, 0x7, 0x0, 0xc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7f, 0xfe, 0x0,

    /* U+63 "c" */
    0x7, 0xfe, 0x3, 0x80, 0x6, 0x1c, 0x0, 0x0,
    0x0, 0x0, 0x7, 0x0, 0xc, 0x3, 0xff, 0x0,

    /* U+64 "d" */
    0x0, 0x0, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x30,
    0xf, 0xff, 0xc7, 0x0, 0xc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x7, 0xff, 0xe0,

    /* U+65 "e" */
    0x7, 0xfe, 0x3, 0x80, 0x6, 0x1f, 0xff, 0xf8,
    0x0, 0x0, 0x7, 0x0, 0x0, 0x3, 0xff, 0x0,

    /* U+66 "f" */
    0x0, 0xfe, 0x0, 0x0, 0x0, 0x1, 0xc0, 0x30,
    0xe, 0x0, 0x7, 0xff, 0xe0, 0x3, 0x80, 0x0,
    0x0, 0x0, 0x0, 0xe0, 0x0, 0x7, 0x0, 0x0,

    /* U+67 "g" */
    0x7, 0xfe, 0x3, 0x80, 0x6, 0x1, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0xc, 0x3f, 0xff, 0x0,

    /* U+68 "h" */
    0x70, 0x0, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0xff, 0xfc, 0x7, 0x0, 0xc, 0x38, 0x0, 0x70,
    0x0, 0x0, 0xe, 0x0, 0x18, 0x70, 0x0, 0xe0,

    /* U+69 "i" */
    0x38, 0x0, 0x0, 0x7, 0x1, 0x81, 0xc0, 0x0,
    0x30, 0x38, 0x0,

    /* U+6A "j" */
    0x0, 0xe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x38, 0x0, 0xe, 0x0, 0x3, 0x80, 0x0, 0x1,
    0xc0, 0x38, 0x7, 0xe0, 0x0,

    /* U+6B "k" */
    0x70, 0x0, 0x0, 0x0, 0x7, 0x0, 0x1, 0xc0,
    0x38, 0x70, 0x60, 0x1f, 0xc0, 0x0, 0x0, 0x1,
    0xc1, 0x80, 0x70, 0xe, 0x0,

    /* U+6C "l" */
    0x38, 0x0, 0x6, 0x7, 0x1, 0x81, 0xc0, 0x0,
    0x30, 0x38, 0x0,

    /* U+6D "m" */
    0x7f, 0xfe, 0x3, 0x83, 0x6, 0x1c, 0x38, 0x38,
    0x0, 0x0, 0x7, 0x6, 0xc, 0x38, 0x70, 0x70,

    /* U+6E "n" */
    0x7f, 0xfe, 0x3, 0x80, 0x6, 0x1c, 0x0, 0x38,
    0x0, 0x0, 0x7, 0x0, 0xc, 0x38, 0x0, 0x70,

    /* U+6F "o" */
    0x7, 0xfe, 0x3, 0x80, 0x6, 0x1c, 0x0, 0x38,
    0x0, 0x0, 0x7, 0x0, 0xc, 0x3, 0xff, 0x0,

    /* U+70 "p" */
    0x7f, 0xfe, 0x3, 0x80, 0x6, 0x1f, 0xff, 0x80,
    0x0, 0x0, 0x7, 0x0, 0x0, 0x38, 0x0, 0x0,

    /* U+71 "q" */
    0x7, 0xff, 0xe3, 0x80, 0x6, 0x1, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0xc, 0x0, 0x0, 0x70,

    /* U+72 "r" */
    0x7f, 0xfe, 0x3, 0x80, 0x6, 0x1c, 0x0, 0x0,
    0x0, 0x0, 0x7, 0x0, 0x0, 0x38, 0x0, 0x0,

    /* U+73 "s" */
    0x7, 0xff, 0xe3, 0x80, 0x0, 0x1, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0xc, 0x3f, 0xff, 0x0,

    /* U+74 "t" */
    0x7, 0x0, 0x3, 0xff, 0xf0, 0x1, 0xc0, 0x0,
    0xe, 0x0, 0x0, 0x0, 0x0, 0x3, 0x80, 0x60,
    0x3, 0xf8, 0x0,

    /* U+75 "u" */
    0x70, 0x0, 0xe3, 0x80, 0x6, 0x1c, 0x0, 0x38,
    0x0, 0x0, 0x7, 0x0, 0xc, 0x3, 0xff, 0xf0,

    /* U+76 "v" */
    0x70, 0x0, 0xe3, 0x80, 0x6, 0x1c, 0x0, 0x38,
    0x0, 0x0, 0x0, 0x70, 0xe0, 0x0, 0x70, 0x0,

    /* U+77 "w" */
    0x70, 0xe0, 0xe3, 0x83, 0x6, 0x1c, 0x38, 0x38,
    0x0, 0x0, 0x7, 0x6, 0xc, 0x3f, 0xff, 0x0,

    /* U+78 "x" */
    0x70, 0x0, 0xe0, 0x38, 0x70, 0x0, 0x18, 0x0,
    0x0, 0x0, 0x0, 0x70, 0xe0, 0x38, 0x0, 0x70,

    /* U+79 "y" */
    0x70, 0x0, 0xe3, 0x80, 0x6, 0x1, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0xc, 0x3f, 0xff, 0x0,

    /* U+7A "z" */
    0x7f, 0xff, 0xe0, 0x0, 0x70, 0x0, 0x18, 0x0,
    0x0, 0x0, 0x0, 0x70, 0x0, 0x3f, 0xff, 0xf0,

    /* U+7B "{" */
    0x0, 0xfe, 0x0, 0x0, 0x0, 0x70, 0x0, 0x1c,
    0x0, 0x70, 0x0, 0x1, 0xc0, 0x0, 0x0, 0x0,
    0x1c, 0x0, 0x0, 0xfe, 0x0,

    /* U+7C "|" */
    0x38, 0x0, 0x6, 0x7, 0x1, 0x81, 0xc0, 0x0,
    0x30, 0x38, 0x0,

    /* U+7D "}" */
    0x3f, 0x0, 0x0, 0x0, 0x0, 0x7, 0x0, 0x1,
    0xc0, 0x0, 0x6, 0x0, 0x1c, 0x0, 0x0, 0x0,
    0x1, 0xc0, 0x3f, 0x0, 0x0,

    /* U+7E "~" */
    0x7, 0xe0, 0xc3, 0x87, 0xf0, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 106, .box_w = 6, .box_h = 0, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 106, .box_w = 9, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 106, .box_w = 15, .box_h = 3, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 17, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 106, .box_w = 9, .box_h = 3, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 117, .adv_w = 106, .box_w = 15, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 106, .box_w = 15, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 106, .box_w = 15, .box_h = 5, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 161, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 106, .box_w = 12, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 106, .box_w = 15, .box_h = 2, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 187, .adv_w = 106, .box_w = 12, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 214, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 106, .box_w = 15, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 255, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 327, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 399, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 447, .adv_w = 106, .box_w = 12, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 456, .adv_w = 106, .box_w = 12, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 106, .box_w = 18, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 488, .adv_w = 106, .box_w = 21, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 106, .box_w = 18, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 520, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 544, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 568, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 592, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 616, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 688, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 712, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 736, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 760, .adv_w = 106, .box_w = 15, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 777, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 801, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 825, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 849, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 873, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 897, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 921, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 945, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 969, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 993, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1017, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1041, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1065, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1089, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1113, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1137, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1161, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1185, .adv_w = 106, .box_w = 15, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1202, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1226, .adv_w = 106, .box_w = 15, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1243, .adv_w = 106, .box_w = 21, .box_h = 5, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1257, .adv_w = 106, .box_w = 21, .box_h = 2, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1263, .adv_w = 106, .box_w = 12, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1268, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1284, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1308, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1324, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1348, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1364, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1388, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1404, .adv_w = 106, .box_w = 21, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1428, .adv_w = 106, .box_w = 9, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1439, .adv_w = 106, .box_w = 18, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1460, .adv_w = 106, .box_w = 18, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1481, .adv_w = 106, .box_w = 9, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1492, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1508, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1524, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1540, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1556, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1572, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1588, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1604, .adv_w = 106, .box_w = 21, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1623, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1639, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1655, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1671, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1687, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1703, .adv_w = 106, .box_w = 21, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1719, .adv_w = 106, .box_w = 18, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1740, .adv_w = 106, .box_w = 9, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1751, .adv_w = 106, .box_w = 18, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1772, .adv_w = 106, .box_w = 21, .box_h = 3, .ofs_x = 0, .ofs_y = 5}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t Ticker_Small_12p = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 10,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_HOR,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -2,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if TICKER_SMALL_12P*/

