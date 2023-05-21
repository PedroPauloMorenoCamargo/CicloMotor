/*******************************************************************************
 * Size: 45 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/
#define LV_LVGL_H_INCLUDE_SIMPLE
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef ROBOTO_40
#define ROBOTO_40 1
#endif

#if ROBOTO_40

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+002E "." */
    0xff, 0xef, 0xbe, 0xf8,

    /* U+003A ":" */
    0x1f, 0xf, 0x87, 0xc3, 0xe1, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x8f, 0x87,
    0xc3, 0xe1, 0xf0,

    /* U+0041 "A" */
    0x0, 0x0, 0xf8, 0x0, 0x0, 0x3f, 0x0, 0x0,
    0x7, 0xe0, 0x0, 0x1, 0xfe, 0x0, 0x0, 0x3f,
    0xc0, 0x0, 0xf, 0xf8, 0x0, 0x1, 0xff, 0x0,
    0x0, 0x7f, 0xe0, 0x0, 0xf, 0xbe, 0x0, 0x3,
    0xe7, 0xc0, 0x0, 0x7c, 0xf8, 0x0, 0x1f, 0x1f,
    0x0, 0x3, 0xe3, 0xe0, 0x0, 0xf8, 0x7e, 0x0,
    0x1f, 0x7, 0xc0, 0x7, 0xc0, 0xf8, 0x0, 0xf8,
    0x1f, 0x0, 0x3e, 0x3, 0xe0, 0x7, 0xc0, 0x7e,
    0x1, 0xf0, 0xf, 0xc0, 0x3f, 0xff, 0xf8, 0xf,
    0xff, 0xff, 0x1, 0xff, 0xff, 0xe0, 0x7f, 0xff,
    0xfe, 0xf, 0x80, 0xf, 0xc3, 0xe0, 0x0, 0xf8,
    0x7c, 0x0, 0x1f, 0x1f, 0x0, 0x3, 0xe3, 0xe0,
    0x0, 0x7e, 0xfc, 0x0, 0xf, 0xdf, 0x0, 0x1,
    0xff, 0xe0, 0x0, 0x1f,

    /* U+0042 "B" */
    0xf, 0xff, 0xe0, 0x7, 0xff, 0xfe, 0x3, 0xff,
    0xff, 0x81, 0xff, 0xff, 0xe0, 0xf8, 0x7, 0xf0,
    0x7c, 0x0, 0xfc, 0x7e, 0x0, 0x7e, 0x3f, 0x0,
    0x3f, 0x1f, 0x0, 0xf, 0x8f, 0x80, 0xf, 0xc7,
    0xc0, 0x7, 0xc3, 0xe0, 0x3, 0xe1, 0xf0, 0x3,
    0xe1, 0xf8, 0x7, 0xf0, 0xff, 0xff, 0xf0, 0x7f,
    0xff, 0xe0, 0x3f, 0xff, 0xfc, 0x1f, 0xff, 0xff,
    0xf, 0x80, 0x1f, 0xcf, 0xc0, 0x7, 0xe7, 0xe0,
    0x1, 0xfb, 0xf0, 0x0, 0xfd, 0xf0, 0x0, 0x7e,
    0xf8, 0x0, 0x3f, 0x7c, 0x0, 0x1f, 0x3e, 0x0,
    0x1f, 0xbf, 0x0, 0x1f, 0xdf, 0x80, 0x1f, 0xcf,
    0xff, 0xff, 0xc7, 0xff, 0xff, 0xc3, 0xff, 0xff,
    0x81, 0xff, 0xff, 0x0,

    /* U+0043 "C" */
    0x0, 0xf, 0xf0, 0x0, 0xf, 0xff, 0x80, 0x3,
    0xff, 0xfc, 0x1, 0xff, 0xff, 0xc0, 0x7f, 0x83,
    0xfc, 0xf, 0xc0, 0x1f, 0x83, 0xf0, 0x1, 0xf0,
    0xfc, 0x0, 0x3e, 0x1f, 0x0, 0x7, 0xe7, 0xe0,
    0x0, 0xf8, 0xf8, 0x0, 0x0, 0x1f, 0x0, 0x0,
    0x3, 0xe0, 0x0, 0x0, 0xfc, 0x0, 0x0, 0x1f,
    0x80, 0x0, 0x3, 0xe0, 0x0, 0x0, 0x7c, 0x0,
    0x0, 0xf, 0x80, 0x0, 0x1, 0xf0, 0x0, 0x0,
    0x7e, 0x0, 0x0, 0xf, 0xc0, 0x0, 0x1, 0xf8,
    0x0, 0x3f, 0x3f, 0x0, 0x7, 0xc3, 0xe0, 0x0,
    0xf8, 0x7c, 0x0, 0x3f, 0xf, 0xc0, 0x7, 0xc1,
    0xfc, 0x1, 0xf8, 0x1f, 0xc0, 0xfe, 0x1, 0xff,
    0xff, 0x80, 0x1f, 0xff, 0xe0, 0x1, 0xff, 0xf0,
    0x0, 0xf, 0xf8, 0x0,

    /* U+0044 "D" */
    0xf, 0xff, 0xe0, 0x1, 0xff, 0xff, 0x0, 0x3f,
    0xff, 0xf8, 0x7, 0xff, 0xff, 0x80, 0xf8, 0x7,
    0xf8, 0x1f, 0x0, 0x3f, 0x7, 0xe0, 0x3, 0xf0,
    0xfc, 0x0, 0x3e, 0x1f, 0x0, 0x7, 0xe3, 0xe0,
    0x0, 0xfc, 0x7c, 0x0, 0x1f, 0x8f, 0x80, 0x3,
    0xf1, 0xf0, 0x0, 0x7e, 0x7e, 0x0, 0xf, 0xcf,
    0xc0, 0x1, 0xf9, 0xf0, 0x0, 0x3e, 0x3e, 0x0,
    0x7, 0xc7, 0xc0, 0x0, 0xf8, 0xf8, 0x0, 0x1f,
    0x3f, 0x0, 0x7, 0xe7, 0xe0, 0x0, 0xf8, 0xfc,
    0x0, 0x1f, 0x1f, 0x0, 0x7, 0xe3, 0xe0, 0x0,
    0xf8, 0x7c, 0x0, 0x3f, 0xf, 0x80, 0xf, 0xc3,
    0xf0, 0x3, 0xf0, 0x7e, 0x1, 0xfe, 0xf, 0xff,
    0xff, 0x1, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xe0,
    0x7, 0xff, 0xe0, 0x0,

    /* U+0045 "E" */
    0xf, 0xff, 0xff, 0xf, 0xff, 0xff, 0xf, 0xff,
    0xff, 0xf, 0xff, 0xff, 0xf, 0x80, 0x0, 0xf,
    0x80, 0x0, 0x1f, 0x80, 0x0, 0x1f, 0x80, 0x0,
    0x1f, 0x0, 0x0, 0x1f, 0x0, 0x0, 0x1f, 0x0,
    0x0, 0x1f, 0x0, 0x0, 0x1f, 0x0, 0x0, 0x3f,
    0x0, 0x0, 0x3f, 0xff, 0xf0, 0x3f, 0xff, 0xf0,
    0x3f, 0xff, 0xf0, 0x3f, 0xff, 0xf0, 0x3e, 0x0,
    0x0, 0x7e, 0x0, 0x0, 0x7e, 0x0, 0x0, 0x7e,
    0x0, 0x0, 0x7c, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x7c, 0x0, 0x0, 0x7c, 0x0, 0x0, 0xfc, 0x0,
    0x0, 0xfc, 0x0, 0x0, 0xff, 0xff, 0xf0, 0xff,
    0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0,

    /* U+0046 "F" */
    0xf, 0xff, 0xff, 0x87, 0xff, 0xff, 0xc3, 0xff,
    0xff, 0xc1, 0xff, 0xff, 0xe0, 0xf8, 0x0, 0x0,
    0x7c, 0x0, 0x0, 0x7e, 0x0, 0x0, 0x3f, 0x0,
    0x0, 0x1f, 0x0, 0x0, 0xf, 0x80, 0x0, 0x7,
    0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0,
    0x1, 0xf8, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x7f,
    0xff, 0xe0, 0x3f, 0xff, 0xf0, 0x1f, 0xff, 0xf8,
    0xf, 0x80, 0x0, 0xf, 0xc0, 0x0, 0x7, 0xe0,
    0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0, 0x0,
    0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x3e, 0x0,
    0x0, 0x3f, 0x0, 0x0, 0x1f, 0x80, 0x0, 0xf,
    0x80, 0x0, 0x7, 0xc0, 0x0, 0x3, 0xe0, 0x0,
    0x1, 0xf0, 0x0, 0x0,

    /* U+0047 "G" */
    0x0, 0xf, 0xf0, 0x0, 0xf, 0xff, 0xc0, 0x3,
    0xff, 0xfc, 0x1, 0xff, 0xff, 0xc0, 0x7f, 0x81,
    0xfc, 0xf, 0xc0, 0x1f, 0x83, 0xf0, 0x1, 0xf0,
    0xfc, 0x0, 0x3f, 0x1f, 0x0, 0x7, 0xc7, 0xe0,
    0x0, 0xf8, 0xf8, 0x0, 0x0, 0x1f, 0x0, 0x0,
    0x3, 0xe0, 0x0, 0x0, 0xfc, 0x0, 0x0, 0x1f,
    0x80, 0x0, 0x3, 0xe0, 0x1f, 0xfe, 0x7c, 0x3,
    0xff, 0xcf, 0x80, 0xff, 0xf1, 0xf0, 0x1f, 0xfe,
    0x7e, 0x0, 0x7, 0xcf, 0xc0, 0x0, 0xf9, 0xf8,
    0x0, 0x3f, 0x3f, 0x0, 0x7, 0xe7, 0xe0, 0x0,
    0xfc, 0x7c, 0x0, 0x1f, 0xf, 0xc0, 0x3, 0xe1,
    0xfc, 0x0, 0xfc, 0x1f, 0xe0, 0x7f, 0x81, 0xff,
    0xff, 0xe0, 0x1f, 0xff, 0xf0, 0x1, 0xff, 0xf8,
    0x0, 0x7, 0xf8, 0x0,

    /* U+0048 "H" */
    0xf, 0xc0, 0x0, 0xf8, 0x7e, 0x0, 0x7, 0xc3,
    0xe0, 0x0, 0x3e, 0x1f, 0x0, 0x3, 0xf0, 0xf8,
    0x0, 0x1f, 0x87, 0xc0, 0x0, 0xfc, 0x7e, 0x0,
    0x7, 0xc3, 0xf0, 0x0, 0x3e, 0x1f, 0x0, 0x1,
    0xf0, 0xf8, 0x0, 0xf, 0x87, 0xc0, 0x0, 0xfc,
    0x3e, 0x0, 0x7, 0xe1, 0xf0, 0x0, 0x3f, 0x1f,
    0x80, 0x1, 0xf0, 0xff, 0xff, 0xff, 0x87, 0xff,
    0xff, 0xfc, 0x3f, 0xff, 0xff, 0xe1, 0xff, 0xff,
    0xff, 0xf, 0x80, 0x1, 0xf8, 0xfc, 0x0, 0xf,
    0x87, 0xe0, 0x0, 0x7c, 0x3e, 0x0, 0x3, 0xe1,
    0xf0, 0x0, 0x1f, 0xf, 0x80, 0x1, 0xf8, 0x7c,
    0x0, 0xf, 0xc3, 0xe0, 0x0, 0x7e, 0x3f, 0x0,
    0x3, 0xe1, 0xf8, 0x0, 0x1f, 0xf, 0x80, 0x0,
    0xf8, 0x7c, 0x0, 0x7, 0xc3, 0xe0, 0x0, 0x7e,
    0x1f, 0x0, 0x3, 0xf0,

    /* U+0049 "I" */
    0x7, 0xc1, 0xf0, 0xfc, 0x3f, 0xf, 0xc3, 0xe0,
    0xf8, 0x3e, 0xf, 0x87, 0xe1, 0xf8, 0x7c, 0x1f,
    0x7, 0xc1, 0xf0, 0x7c, 0x3f, 0xf, 0xc3, 0xe0,
    0xf8, 0x3e, 0xf, 0x87, 0xe1, 0xf8, 0x7e, 0x1f,
    0x7, 0xc1, 0xf0, 0x7c, 0x3f, 0xf, 0xc3, 0xe0,

    /* U+004A "J" */
    0x0, 0x0, 0x3e, 0x0, 0x0, 0x3e, 0x0, 0x0,
    0x3e, 0x0, 0x0, 0x3e, 0x0, 0x0, 0x3e, 0x0,
    0x0, 0x7e, 0x0, 0x0, 0x7e, 0x0, 0x0, 0x7c,
    0x0, 0x0, 0x7c, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x7c, 0x0, 0x0, 0xfc, 0x0, 0x0, 0xfc, 0x0,
    0x0, 0xfc, 0x0, 0x0, 0xf8, 0x0, 0x0, 0xf8,
    0x0, 0x0, 0xf8, 0x0, 0x0, 0xf8, 0x0, 0x1,
    0xf8, 0x0, 0x1, 0xf8, 0x0, 0x1, 0xf0, 0x0,
    0x1, 0xf0, 0x0, 0x1, 0xf0, 0xf8, 0x1, 0xf0,
    0xf8, 0x3, 0xf0, 0xf8, 0x3, 0xe0, 0xfc, 0x7,
    0xe0, 0xfe, 0x1f, 0xc0, 0x7f, 0xff, 0x80, 0x7f,
    0xff, 0x0, 0x1f, 0xfe, 0x0, 0x7, 0xf0, 0x0,

    /* U+004B "K" */
    0x7, 0xc0, 0x7, 0xf0, 0x7c, 0x0, 0xfe, 0x7,
    0xc0, 0xf, 0xc0, 0x7c, 0x1, 0xf8, 0xf, 0xc0,
    0x3f, 0x80, 0xfc, 0x7, 0xf0, 0xf, 0xc0, 0x7e,
    0x0, 0xf8, 0xf, 0xc0, 0xf, 0x81, 0xf8, 0x0,
    0xf8, 0x3f, 0x0, 0xf, 0x83, 0xf0, 0x1, 0xf8,
    0x7e, 0x0, 0x1f, 0x8f, 0xc0, 0x1, 0xf9, 0xf8,
    0x0, 0x1f, 0xff, 0x0, 0x1, 0xff, 0xe0, 0x0,
    0x1f, 0xfe, 0x0, 0x1, 0xff, 0xf0, 0x0, 0x3f,
    0x3f, 0x0, 0x3, 0xf1, 0xf8, 0x0, 0x3e, 0xf,
    0x80, 0x3, 0xe0, 0xfc, 0x0, 0x3e, 0x7, 0xe0,
    0x3, 0xe0, 0x7e, 0x0, 0x7e, 0x3, 0xf0, 0x7,
    0xe0, 0x3f, 0x0, 0x7e, 0x1, 0xf8, 0x7, 0xc0,
    0x1f, 0x80, 0x7c, 0x0, 0xfc, 0x7, 0xc0, 0x7,
    0xe0, 0x7c, 0x0, 0x7e, 0xf, 0xc0, 0x3, 0xf0,

    /* U+004C "L" */
    0xf, 0xc0, 0x0, 0x7e, 0x0, 0x3, 0xe0, 0x0,
    0x1f, 0x0, 0x0, 0xf8, 0x0, 0x7, 0xc0, 0x0,
    0x7e, 0x0, 0x3, 0xf0, 0x0, 0x1f, 0x0, 0x0,
    0xf8, 0x0, 0x7, 0xc0, 0x0, 0x3e, 0x0, 0x1,
    0xf0, 0x0, 0x1f, 0x80, 0x0, 0xfc, 0x0, 0x7,
    0xc0, 0x0, 0x3e, 0x0, 0x1, 0xf0, 0x0, 0xf,
    0x80, 0x0, 0xfc, 0x0, 0x7, 0xe0, 0x0, 0x3f,
    0x0, 0x1, 0xf0, 0x0, 0xf, 0x80, 0x0, 0x7c,
    0x0, 0x3, 0xe0, 0x0, 0x3f, 0x0, 0x1, 0xf8,
    0x0, 0xf, 0xff, 0xff, 0x7f, 0xff, 0xfb, 0xff,
    0xff, 0xdf, 0xff, 0xfe,

    /* U+004D "M" */
    0xf, 0xf0, 0x0, 0x3, 0xf8, 0x7f, 0x80, 0x0,
    0x3f, 0xc3, 0xfc, 0x0, 0x1, 0xfc, 0x1f, 0xe0,
    0x0, 0x1f, 0xe0, 0xff, 0x0, 0x0, 0xff, 0x7,
    0xfc, 0x0, 0xf, 0xf8, 0x7f, 0xe0, 0x0, 0x7f,
    0xc3, 0xff, 0x0, 0x7, 0xfe, 0x1f, 0xf8, 0x0,
    0x7f, 0xf0, 0xfb, 0xe0, 0x3, 0xff, 0x7, 0xdf,
    0x0, 0x3e, 0xf8, 0x3e, 0xf8, 0x1, 0xf7, 0xc1,
    0xf3, 0xc0, 0x1f, 0x3e, 0x1f, 0x9e, 0x0, 0xfb,
    0xf0, 0xfc, 0xf8, 0xf, 0x9f, 0x87, 0xc7, 0xc0,
    0x7c, 0xf8, 0x3e, 0x3e, 0x7, 0xc7, 0xc1, 0xf0,
    0xf0, 0x3c, 0x3e, 0xf, 0x87, 0xc3, 0xe1, 0xf0,
    0xfc, 0x3e, 0x1e, 0xf, 0x87, 0xe1, 0xf1, 0xf0,
    0xfc, 0x3f, 0x7, 0x8f, 0x7, 0xe1, 0xf0, 0x3c,
    0xf8, 0x3e, 0xf, 0x81, 0xf7, 0x81, 0xf0, 0x7c,
    0xf, 0xfc, 0xf, 0x83, 0xe0, 0x3f, 0xc0, 0x7c,
    0x3f, 0x1, 0xfe, 0x7, 0xe1, 0xf8, 0xf, 0xe0,
    0x3f, 0xf, 0x80, 0x7f, 0x1, 0xf8, 0x7c, 0x3,
    0xf0, 0xf, 0x83, 0xe0, 0xf, 0x80, 0x7c, 0x1f,
    0x0, 0x78, 0x3, 0xe0,

    /* U+004E "N" */
    0xf, 0xc0, 0x0, 0xf8, 0x7e, 0x0, 0x7, 0xc3,
    0xf8, 0x0, 0x3e, 0x1f, 0xc0, 0x3, 0xf0, 0xff,
    0x0, 0x1f, 0x87, 0xf8, 0x0, 0xfc, 0x7f, 0xe0,
    0x7, 0xc3, 0xff, 0x0, 0x3e, 0x1f, 0xfc, 0x1,
    0xf0, 0xfb, 0xe0, 0xf, 0x87, 0xdf, 0x80, 0xfc,
    0x3e, 0x7c, 0x7, 0xe1, 0xf3, 0xf0, 0x3f, 0x1f,
    0x8f, 0x81, 0xf0, 0xfc, 0x7c, 0xf, 0x87, 0xc1,
    0xf0, 0x7c, 0x3e, 0xf, 0x83, 0xe1, 0xf0, 0x7e,
    0x3f, 0xf, 0x81, 0xf1, 0xf8, 0xfc, 0xf, 0xcf,
    0x87, 0xe0, 0x3e, 0x7c, 0x3f, 0x1, 0xfb, 0xe1,
    0xf0, 0x7, 0xdf, 0xf, 0x80, 0x3f, 0xf8, 0x7c,
    0x0, 0xff, 0xc3, 0xe0, 0x7, 0xfe, 0x3f, 0x0,
    0x1f, 0xe1, 0xf8, 0x0, 0xff, 0xf, 0x80, 0x3,
    0xf8, 0x7c, 0x0, 0x1f, 0xc3, 0xe0, 0x0, 0x7e,
    0x1f, 0x0, 0x3, 0xf0,

    /* U+004F "O" */
    0x0, 0xf, 0xf0, 0x0, 0x3, 0xff, 0xc0, 0x0,
    0xff, 0xff, 0x0, 0x1f, 0xff, 0xf8, 0x3, 0xf8,
    0x1f, 0xc0, 0x7e, 0x0, 0xfc, 0xf, 0xc0, 0x7,
    0xe1, 0xf8, 0x0, 0x3e, 0x1f, 0x0, 0x3, 0xe3,
    0xf0, 0x0, 0x3f, 0x3e, 0x0, 0x3, 0xf3, 0xe0,
    0x0, 0x3f, 0x7e, 0x0, 0x3, 0xf7, 0xe0, 0x0,
    0x3f, 0x7e, 0x0, 0x3, 0xe7, 0xc0, 0x0, 0x3e,
    0x7c, 0x0, 0x3, 0xe7, 0xc0, 0x0, 0x3e, 0x7c,
    0x0, 0x7, 0xef, 0xc0, 0x0, 0x7e, 0xfc, 0x0,
    0x7, 0xcf, 0xc0, 0x0, 0x7c, 0xfc, 0x0, 0xf,
    0xc7, 0xc0, 0x0, 0xf8, 0x7c, 0x0, 0x1f, 0x87,
    0xe0, 0x3, 0xf0, 0x3f, 0x0, 0x7e, 0x3, 0xf8,
    0x1f, 0xc0, 0x1f, 0xff, 0xf8, 0x0, 0xff, 0xff,
    0x0, 0x7, 0xff, 0xc0, 0x0, 0xf, 0xf0, 0x0,

    /* U+0050 "P" */
    0xf, 0xff, 0xf8, 0x1, 0xff, 0xff, 0xc0, 0x3f,
    0xff, 0xfc, 0x7, 0xff, 0xff, 0xc0, 0xf8, 0x1,
    0xfc, 0x1f, 0x0, 0x1f, 0x87, 0xe0, 0x1, 0xf0,
    0xfc, 0x0, 0x3f, 0x1f, 0x0, 0x7, 0xe3, 0xe0,
    0x0, 0xfc, 0x7c, 0x0, 0x1f, 0xf, 0x80, 0x3,
    0xe1, 0xf0, 0x0, 0xfc, 0x7e, 0x0, 0x1f, 0xf,
    0xc0, 0x7, 0xe1, 0xf0, 0x3, 0xf8, 0x3f, 0xff,
    0xfe, 0x7, 0xff, 0xff, 0x80, 0xff, 0xff, 0xe0,
    0x3f, 0xff, 0xe0, 0x7, 0xe0, 0x0, 0x0, 0xfc,
    0x0, 0x0, 0x1f, 0x0, 0x0, 0x3, 0xe0, 0x0,
    0x0, 0x7c, 0x0, 0x0, 0xf, 0x80, 0x0, 0x3,
    0xf0, 0x0, 0x0, 0x7e, 0x0, 0x0, 0xf, 0x80,
    0x0, 0x1, 0xf0, 0x0, 0x0, 0x3e, 0x0, 0x0,
    0x7, 0xc0, 0x0, 0x0,

    /* U+0051 "Q" */
    0x0, 0xf, 0xf0, 0x0, 0x3, 0xff, 0xc0, 0x0,
    0xff, 0xff, 0x0, 0x1f, 0xff, 0xf8, 0x3, 0xf8,
    0x1f, 0xc0, 0x7e, 0x0, 0xfc, 0xf, 0xc0, 0x7,
    0xe1, 0xf8, 0x0, 0x3e, 0x1f, 0x0, 0x3, 0xe3,
    0xf0, 0x0, 0x3f, 0x3e, 0x0, 0x3, 0xf3, 0xe0,
    0x0, 0x3f, 0x7e, 0x0, 0x3, 0xf7, 0xe0, 0x0,
    0x3f, 0x7e, 0x0, 0x3, 0xe7, 0xc0, 0x0, 0x3e,
    0x7c, 0x0, 0x3, 0xe7, 0xc0, 0x0, 0x3e, 0x7c,
    0x0, 0x7, 0xef, 0xc0, 0x0, 0x7e, 0xfc, 0x0,
    0x7, 0xcf, 0xc0, 0x0, 0x7c, 0xfc, 0x0, 0xf,
    0xc7, 0xc0, 0x0, 0xf8, 0x7c, 0x0, 0x1f, 0x87,
    0xe0, 0x3, 0xf0, 0x3f, 0x0, 0x7f, 0x3, 0xf8,
    0x1f, 0xe0, 0x1f, 0xff, 0xff, 0x0, 0xff, 0xff,
    0xf8, 0x7, 0xff, 0xff, 0xc0, 0xf, 0xf0, 0xfe,
    0x0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0x30, 0x0,
    0x0, 0x2, 0x0,

    /* U+0052 "R" */
    0xf, 0xff, 0xe0, 0x7, 0xff, 0xfe, 0x3, 0xff,
    0xff, 0x81, 0xff, 0xff, 0xe0, 0xf8, 0x3, 0xf8,
    0x7c, 0x0, 0xfc, 0x7e, 0x0, 0x3e, 0x3f, 0x0,
    0x1f, 0x1f, 0x0, 0xf, 0x8f, 0x80, 0x7, 0xc7,
    0xc0, 0x3, 0xe3, 0xe0, 0x3, 0xf1, 0xf0, 0x1,
    0xf1, 0xf8, 0x1, 0xf8, 0xfc, 0x3, 0xf8, 0x7f,
    0xff, 0xf8, 0x3f, 0xff, 0xf0, 0x1f, 0xff, 0xf8,
    0xf, 0xff, 0xff, 0xf, 0xc0, 0x1f, 0x87, 0xe0,
    0x7, 0xe3, 0xf0, 0x1, 0xf1, 0xf0, 0x0, 0xf8,
    0xf8, 0x0, 0x7c, 0x7c, 0x0, 0x3e, 0x3e, 0x0,
    0x3f, 0x3f, 0x0, 0x1f, 0x9f, 0x80, 0xf, 0xcf,
    0x80, 0x7, 0xe7, 0xc0, 0x3, 0xf3, 0xe0, 0x1,
    0xf9, 0xf0, 0x0, 0xfc,

    /* U+0053 "S" */
    0x0, 0x3f, 0xc0, 0x0, 0xff, 0xfc, 0x0, 0xff,
    0xff, 0x1, 0xff, 0xff, 0xc0, 0xfe, 0xf, 0xf0,
    0xfc, 0x1, 0xf8, 0x7c, 0x0, 0x7c, 0x7e, 0x0,
    0x3f, 0x3f, 0x0, 0x1f, 0x9f, 0x80, 0xf, 0x8f,
    0xc0, 0x0, 0x3, 0xf0, 0x0, 0x1, 0xfe, 0x0,
    0x0, 0xff, 0xe0, 0x0, 0x3f, 0xfe, 0x0, 0x7,
    0xff, 0xc0, 0x1, 0xff, 0xf0, 0x0, 0x1f, 0xfe,
    0x0, 0x1, 0xff, 0x80, 0x0, 0x3f, 0xc0, 0x0,
    0x7, 0xe0, 0x0, 0x1, 0xfb, 0xe0, 0x0, 0xfd,
    0xf0, 0x0, 0x7e, 0xf8, 0x0, 0x3e, 0x7e, 0x0,
    0x1f, 0x3f, 0x80, 0x1f, 0x8f, 0xf0, 0x3f, 0x83,
    0xff, 0xff, 0x80, 0xff, 0xff, 0x80, 0x3f, 0xff,
    0x80, 0x3, 0xfe, 0x0,

    /* U+0054 "T" */
    0x7f, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfb, 0xff, 0xff, 0xfe, 0x0, 0x3e, 0x0,
    0x0, 0xf, 0x80, 0x0, 0x7, 0xe0, 0x0, 0x1,
    0xf8, 0x0, 0x0, 0x7e, 0x0, 0x0, 0x1f, 0x0,
    0x0, 0x7, 0xc0, 0x0, 0x1, 0xf0, 0x0, 0x0,
    0x7c, 0x0, 0x0, 0x3f, 0x0, 0x0, 0xf, 0xc0,
    0x0, 0x3, 0xf0, 0x0, 0x0, 0xf8, 0x0, 0x0,
    0x3e, 0x0, 0x0, 0xf, 0x80, 0x0, 0x3, 0xe0,
    0x0, 0x1, 0xf8, 0x0, 0x0, 0x7e, 0x0, 0x0,
    0x1f, 0x0, 0x0, 0x7, 0xc0, 0x0, 0x1, 0xf0,
    0x0, 0x0, 0x7c, 0x0, 0x0, 0x1f, 0x0, 0x0,
    0xf, 0xc0, 0x0, 0x3, 0xf0, 0x0, 0x0, 0xf8,
    0x0, 0x0, 0x3e, 0x0, 0x0, 0xf, 0x80, 0x0,

    /* U+0055 "U" */
    0x1f, 0x0, 0x3, 0xf1, 0xf0, 0x0, 0x3f, 0x1f,
    0x0, 0x3, 0xe3, 0xf0, 0x0, 0x3e, 0x3f, 0x0,
    0x3, 0xe3, 0xe0, 0x0, 0x3e, 0x3e, 0x0, 0x7,
    0xe3, 0xe0, 0x0, 0x7e, 0x3e, 0x0, 0x7, 0xe3,
    0xe0, 0x0, 0x7c, 0x7e, 0x0, 0x7, 0xc7, 0xe0,
    0x0, 0x7c, 0x7c, 0x0, 0x7, 0xc7, 0xc0, 0x0,
    0xfc, 0x7c, 0x0, 0xf, 0xc7, 0xc0, 0x0, 0xf8,
    0xfc, 0x0, 0xf, 0x8f, 0xc0, 0x0, 0xf8, 0xfc,
    0x0, 0xf, 0x8f, 0x80, 0x0, 0xf8, 0xf8, 0x0,
    0x1f, 0x8f, 0x80, 0x1, 0xf8, 0xf8, 0x0, 0x1f,
    0xf, 0x80, 0x1, 0xf0, 0xf8, 0x0, 0x3f, 0xf,
    0xc0, 0x7, 0xe0, 0xfe, 0x0, 0xfe, 0x7, 0xf0,
    0x3f, 0xc0, 0x3f, 0xff, 0xf8, 0x1, 0xff, 0xfe,
    0x0, 0xf, 0xff, 0xc0, 0x0, 0x3f, 0xe0, 0x0,

    /* U+0056 "V" */
    0xfc, 0x0, 0x3, 0xf7, 0xc0, 0x0, 0x3f, 0x7c,
    0x0, 0x7, 0xe7, 0xe0, 0x0, 0x7e, 0x7e, 0x0,
    0xf, 0xc7, 0xe0, 0x0, 0xf8, 0x3e, 0x0, 0x1f,
    0x83, 0xe0, 0x1, 0xf0, 0x3f, 0x0, 0x1f, 0x3,
    0xf0, 0x3, 0xe0, 0x1f, 0x0, 0x3e, 0x1, 0xf0,
    0x7, 0xc0, 0x1f, 0x0, 0x7c, 0x1, 0xf0, 0xf,
    0x80, 0x1f, 0x80, 0xf8, 0x0, 0xf8, 0x1f, 0x0,
    0xf, 0x81, 0xf0, 0x0, 0xf8, 0x3e, 0x0, 0xf,
    0x83, 0xe0, 0x0, 0xfc, 0x7c, 0x0, 0x7, 0xc7,
    0xc0, 0x0, 0x7c, 0xf8, 0x0, 0x7, 0xcf, 0x80,
    0x0, 0x7d, 0xf0, 0x0, 0x7, 0xdf, 0x0, 0x0,
    0x3d, 0xe0, 0x0, 0x3, 0xfe, 0x0, 0x0, 0x3f,
    0xc0, 0x0, 0x3, 0xfc, 0x0, 0x0, 0x3f, 0x80,
    0x0, 0x1, 0xf8, 0x0, 0x0, 0x1f, 0x0, 0x0,

    /* U+0057 "W" */
    0xf8, 0x0, 0xf8, 0x0, 0xfb, 0xe0, 0x3, 0xe0,
    0x7, 0xef, 0x80, 0x1f, 0x80, 0x1f, 0xbe, 0x0,
    0x7e, 0x0, 0x7c, 0xfc, 0x3, 0xf8, 0x3, 0xf3,
    0xf0, 0xf, 0xf0, 0xf, 0x8f, 0xc0, 0x3f, 0xc0,
    0x3e, 0x3f, 0x1, 0xff, 0x1, 0xf8, 0xfc, 0x7,
    0xfc, 0x7, 0xc3, 0xf0, 0x3f, 0xf0, 0x1f, 0x7,
    0xc0, 0xff, 0xc0, 0xf8, 0x1f, 0x7, 0xcf, 0x3,
    0xe0, 0x7c, 0x1f, 0x3c, 0x1f, 0x81, 0xf0, 0x78,
    0xf0, 0x7c, 0x7, 0xc3, 0xe3, 0xe1, 0xf0, 0x1f,
    0xf, 0xf, 0x8f, 0xc0, 0x7c, 0x7c, 0x3e, 0x3e,
    0x1, 0xf1, 0xf0, 0xf8, 0xf8, 0x7, 0xc7, 0x81,
    0xe7, 0xc0, 0x1f, 0x3e, 0x7, 0x9f, 0x0, 0x7c,
    0xf0, 0x1e, 0x7c, 0x0, 0xf7, 0xc0, 0x7b, 0xe0,
    0x3, 0xfe, 0x1, 0xff, 0x80, 0xf, 0xf8, 0x7,
    0xfc, 0x0, 0x3f, 0xe0, 0x1f, 0xf0, 0x0, 0xff,
    0x0, 0x7f, 0xc0, 0x3, 0xfc, 0x0, 0xfe, 0x0,
    0xf, 0xe0, 0x3, 0xf8, 0x0, 0x3f, 0x80, 0xf,
    0xe0, 0x0, 0xfc, 0x0, 0x3f, 0x0, 0x3, 0xf0,
    0x0, 0xfc, 0x0, 0xf, 0xc0, 0x3, 0xe0, 0x0,

    /* U+0058 "X" */
    0x3, 0xf0, 0x0, 0x7e, 0x7, 0xe0, 0x1, 0xf8,
    0x7, 0xe0, 0x7, 0xe0, 0xf, 0xc0, 0xf, 0xc0,
    0x1f, 0xc0, 0x3f, 0x0, 0x1f, 0x80, 0xfc, 0x0,
    0x3f, 0x3, 0xf0, 0x0, 0x3f, 0x7, 0xe0, 0x0,
    0x7e, 0x1f, 0x80, 0x0, 0x7e, 0x7e, 0x0, 0x0,
    0xfd, 0xf8, 0x0, 0x0, 0xfb, 0xf0, 0x0, 0x1,
    0xff, 0xc0, 0x0, 0x1, 0xff, 0x0, 0x0, 0x3,
    0xfc, 0x0, 0x0, 0x3, 0xf0, 0x0, 0x0, 0xf,
    0xe0, 0x0, 0x0, 0x1f, 0xe0, 0x0, 0x0, 0x7f,
    0xc0, 0x0, 0x1, 0xff, 0xc0, 0x0, 0x7, 0xef,
    0x80, 0x0, 0x1f, 0x9f, 0x80, 0x0, 0x3f, 0x3f,
    0x0, 0x0, 0xfc, 0x3f, 0x0, 0x3, 0xf0, 0x7e,
    0x0, 0xf, 0xc0, 0x7e, 0x0, 0x1f, 0x80, 0xfc,
    0x0, 0x7e, 0x0, 0xfc, 0x1, 0xf8, 0x1, 0xf8,
    0x7, 0xf0, 0x3, 0xf8, 0x1f, 0xc0, 0x3, 0xf0,
    0x3f, 0x0, 0x7, 0xf0,

    /* U+0059 "Y" */
    0xfc, 0x0, 0x7, 0xff, 0x80, 0x1, 0xf9, 0xf0,
    0x0, 0x7e, 0x3f, 0x0, 0xf, 0xc7, 0xe0, 0x3,
    0xf0, 0x7c, 0x0, 0xfc, 0xf, 0xc0, 0x1f, 0x81,
    0xf8, 0x7, 0xe0, 0x1f, 0x80, 0xf8, 0x3, 0xf0,
    0x3e, 0x0, 0x3e, 0xf, 0xc0, 0x7, 0xe1, 0xf0,
    0x0, 0xfc, 0x7c, 0x0, 0xf, 0x9f, 0x80, 0x1,
    0xfb, 0xe0, 0x0, 0x1f, 0xf8, 0x0, 0x3, 0xff,
    0x0, 0x0, 0x7f, 0xc0, 0x0, 0x7, 0xf0, 0x0,
    0x0, 0xfe, 0x0, 0x0, 0x1f, 0x80, 0x0, 0x3,
    0xf0, 0x0, 0x0, 0x7c, 0x0, 0x0, 0xf, 0x80,
    0x0, 0x1, 0xf0, 0x0, 0x0, 0x3e, 0x0, 0x0,
    0x7, 0xc0, 0x0, 0x1, 0xf8, 0x0, 0x0, 0x3f,
    0x0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0xf8, 0x0,
    0x0, 0x1f, 0x0, 0x0,

    /* U+005A "Z" */
    0xf, 0xff, 0xff, 0x1f, 0xff, 0xff, 0x1f, 0xff,
    0xff, 0x1f, 0xff, 0xfe, 0x0, 0x0, 0xfe, 0x0,
    0x0, 0xfc, 0x0, 0x1, 0xf8, 0x0, 0x3, 0xf0,
    0x0, 0x3, 0xf0, 0x0, 0x7, 0xe0, 0x0, 0xf,
    0xc0, 0x0, 0xf, 0xc0, 0x0, 0x1f, 0x80, 0x0,
    0x3f, 0x0, 0x0, 0x7f, 0x0, 0x0, 0x7e, 0x0,
    0x0, 0xfc, 0x0, 0x1, 0xfc, 0x0, 0x1, 0xf8,
    0x0, 0x3, 0xf0, 0x0, 0x7, 0xe0, 0x0, 0x7,
    0xe0, 0x0, 0xf, 0xc0, 0x0, 0x1f, 0x80, 0x0,
    0x1f, 0x80, 0x0, 0x3f, 0x0, 0x0, 0x7e, 0x0,
    0x0, 0x7e, 0x0, 0x0, 0xff, 0xff, 0xfc, 0xff,
    0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8,

    /* U+0061 "a" */
    0x0, 0x7f, 0x80, 0x7, 0xff, 0x80, 0x7f, 0xff,
    0x3, 0xff, 0xfe, 0x1f, 0xc1, 0xf8, 0x7c, 0x3,
    0xe1, 0xf0, 0xf, 0x80, 0x0, 0x3e, 0x0, 0x0,
    0xf8, 0x7, 0xff, 0xe0, 0xff, 0xff, 0x87, 0xff,
    0xfe, 0x3f, 0xff, 0xf9, 0xfc, 0x7, 0xe7, 0xe0,
    0x1f, 0x3f, 0x0, 0x7c, 0xfc, 0x1, 0xf3, 0xe0,
    0xf, 0xcf, 0xc0, 0x7f, 0x3f, 0x7, 0xfc, 0xff,
    0xff, 0xf1, 0xff, 0xef, 0xc3, 0xff, 0x3f, 0x3,
    0xf0, 0xfc,

    /* U+0062 "b" */
    0x7, 0xc0, 0x0, 0xf, 0x80, 0x0, 0x1f, 0x0,
    0x0, 0x3e, 0x0, 0x0, 0x7c, 0x0, 0x1, 0xf8,
    0x0, 0x3, 0xf0, 0x0, 0x7, 0xc0, 0x0, 0xf,
    0x80, 0x0, 0x1f, 0x0, 0x0, 0x3e, 0x3f, 0x0,
    0xfd, 0xff, 0x81, 0xff, 0xff, 0x83, 0xff, 0xff,
    0x87, 0xf8, 0x7f, 0xf, 0xc0, 0x3e, 0x1f, 0x0,
    0x7e, 0x3e, 0x0, 0xfc, 0xfc, 0x1, 0xf9, 0xf8,
    0x1, 0xf3, 0xe0, 0x7, 0xe7, 0xc0, 0xf, 0xcf,
    0x80, 0x1f, 0x9f, 0x0, 0x3e, 0x7e, 0x0, 0x7c,
    0xfc, 0x0, 0xf9, 0xf8, 0x3, 0xf3, 0xf0, 0x7,
    0xc7, 0xe0, 0x1f, 0x8f, 0xe0, 0xfe, 0x1f, 0xff,
    0xf8, 0x7d, 0xff, 0xe0, 0xf9, 0xff, 0x81, 0xf0,
    0xfc, 0x0,

    /* U+0063 "c" */
    0x0, 0x7f, 0x0, 0x3f, 0xfc, 0x7, 0xff, 0xe0,
    0xff, 0xfe, 0x1f, 0x83, 0xf3, 0xf0, 0x1f, 0x7e,
    0x1, 0xf7, 0xe0, 0x1f, 0x7c, 0x1, 0xff, 0xc0,
    0x0, 0xf8, 0x0, 0xf, 0x80, 0x0, 0xf8, 0x0,
    0xf, 0x80, 0x0, 0xf8, 0x0, 0xf, 0x80, 0x0,
    0xf8, 0x3, 0xef, 0x80, 0x3e, 0xfc, 0x7, 0xc7,
    0xe1, 0xfc, 0x7f, 0xff, 0x83, 0xff, 0xf0, 0x1f,
    0xfe, 0x0, 0x7f, 0x0,

    /* U+0064 "d" */
    0x0, 0x0, 0x1f, 0x0, 0x0, 0x3f, 0x0, 0x0,
    0x3f, 0x0, 0x0, 0x3e, 0x0, 0x0, 0x3e, 0x0,
    0x0, 0x3e, 0x0, 0x0, 0x3e, 0x0, 0x0, 0x7e,
    0x0, 0x0, 0x7e, 0x0, 0x0, 0x7e, 0x0, 0xfc,
    0x7c, 0x3, 0xfe, 0x7c, 0xf, 0xff, 0x7c, 0x1f,
    0xff, 0xfc, 0x1f, 0xc3, 0xfc, 0x3f, 0x1, 0xfc,
    0x7e, 0x0, 0xf8, 0x7e, 0x0, 0xf8, 0x7c, 0x0,
    0xf8, 0xfc, 0x0, 0xf8, 0xf8, 0x1, 0xf8, 0xf8,
    0x1, 0xf8, 0xf8, 0x1, 0xf8, 0xf8, 0x1, 0xf0,
    0xf8, 0x1, 0xf0, 0xf8, 0x1, 0xf0, 0xf8, 0x1,
    0xf0, 0xf8, 0x3, 0xf0, 0xfc, 0x7, 0xf0, 0xfe,
    0xf, 0xf0, 0x7f, 0xff, 0xe0, 0x7f, 0xff, 0xe0,
    0x3f, 0xf3, 0xe0, 0xf, 0xc3, 0xe0,

    /* U+0065 "e" */
    0x0, 0x7f, 0x0, 0x3f, 0xfc, 0x7, 0xff, 0xe0,
    0xff, 0xfe, 0x1f, 0x83, 0xf3, 0xf0, 0x1f, 0x3e,
    0x1, 0xf7, 0xc0, 0x1f, 0x7c, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x80, 0x0, 0xf8, 0x0, 0xf, 0x80, 0x0,
    0xf8, 0x0, 0xf, 0xc0, 0x0, 0xfc, 0x0, 0x87,
    0xe0, 0x3c, 0x7f, 0xff, 0xc3, 0xff, 0xfc, 0x1f,
    0xff, 0x0, 0x7f, 0xc0,

    /* U+0066 "f" */
    0x0, 0x3f, 0x80, 0x7f, 0xc0, 0x7f, 0xe0, 0x7f,
    0xe0, 0x3f, 0x0, 0x3f, 0x0, 0x1f, 0x0, 0xf,
    0x80, 0x7, 0xc0, 0x7, 0xe0, 0x1f, 0xff, 0x1f,
    0xff, 0x8f, 0xff, 0xc7, 0xff, 0xe0, 0x3e, 0x0,
    0x1f, 0x0, 0x1f, 0x80, 0xf, 0xc0, 0x7, 0xc0,
    0x3, 0xe0, 0x1, 0xf0, 0x0, 0xf8, 0x0, 0xfc,
    0x0, 0x7e, 0x0, 0x3f, 0x0, 0x1f, 0x0, 0xf,
    0x80, 0x7, 0xc0, 0x3, 0xe0, 0x3, 0xf0, 0x1,
    0xf8, 0x0, 0xfc, 0x0, 0x7c, 0x0, 0x3e, 0x0,
    0x0,

    /* U+0067 "g" */
    0x0, 0xfc, 0x3c, 0x7, 0xfe, 0x78, 0x1f, 0xff,
    0xf0, 0x7f, 0xff, 0xe1, 0xfc, 0x3f, 0xc7, 0xe0,
    0x3f, 0x8f, 0x80, 0x3f, 0x3f, 0x0, 0x7c, 0x7c,
    0x0, 0xf8, 0xf8, 0x1, 0xf3, 0xf0, 0x3, 0xe7,
    0xc0, 0xf, 0xcf, 0x80, 0x1f, 0x9f, 0x0, 0x3e,
    0x3e, 0x0, 0x7c, 0x7c, 0x0, 0xf8, 0xf8, 0x1,
    0xf1, 0xf0, 0x7, 0xe3, 0xf0, 0x1f, 0xc7, 0xf0,
    0x7f, 0x87, 0xff, 0xfe, 0x7, 0xff, 0xfc, 0x7,
    0xfe, 0xf8, 0x7, 0xf1, 0xf0, 0x0, 0x7, 0xe0,
    0x0, 0xf, 0xc0, 0x0, 0x1f, 0x0, 0x0, 0x7e,
    0x7, 0x3, 0xf8, 0x1f, 0xff, 0xe0, 0x3f, 0xff,
    0x80, 0x7f, 0xfe, 0x0, 0x1f, 0xe0, 0x0,

    /* U+0068 "h" */
    0x7, 0xc0, 0x0, 0x1f, 0x0, 0x0, 0x7c, 0x0,
    0x1, 0xf0, 0x0, 0xf, 0xc0, 0x0, 0x3f, 0x0,
    0x0, 0xf8, 0x0, 0x3, 0xe0, 0x0, 0xf, 0x80,
    0x0, 0x3e, 0x0, 0x0, 0xf8, 0x7e, 0x7, 0xef,
    0xfc, 0x1f, 0xff, 0xf8, 0x7f, 0xff, 0xf1, 0xfe,
    0xf, 0xc7, 0xe0, 0x1f, 0x1f, 0x0, 0x7c, 0xfc,
    0x1, 0xf3, 0xf0, 0x7, 0xcf, 0x80, 0x1f, 0x3e,
    0x0, 0x7c, 0xf8, 0x1, 0xf3, 0xe0, 0xf, 0xcf,
    0x80, 0x3f, 0x7e, 0x0, 0xf9, 0xf8, 0x3, 0xe7,
    0xc0, 0xf, 0x9f, 0x0, 0x3e, 0x7c, 0x1, 0xf9,
    0xf0, 0x7, 0xe7, 0xc0, 0x1f, 0xbf, 0x0, 0x7c,
    0xfc, 0x1, 0xf3, 0xe0, 0x7, 0xc0,

    /* U+0069 "i" */
    0x7, 0xe0, 0xfc, 0x1f, 0x3, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3e, 0x7,
    0xc0, 0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x3,
    0xe0, 0x7c, 0xf, 0x83, 0xf0, 0x7e, 0xf, 0x81,
    0xf0, 0x3e, 0x7, 0xc0, 0xf8, 0x3f, 0x7, 0xe0,
    0xf8, 0x1f, 0x3, 0xe0, 0x7c, 0x1f, 0x80,

    /* U+006A "j" */
    0x0, 0xf, 0x80, 0xf, 0xc0, 0x7, 0xe0, 0x3,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0x80,
    0x7, 0xc0, 0x3, 0xe0, 0x1, 0xf0, 0x0, 0xf8,
    0x0, 0xfc, 0x0, 0x7e, 0x0, 0x3e, 0x0, 0x1f,
    0x0, 0xf, 0x80, 0x7, 0xc0, 0x7, 0xe0, 0x3,
    0xf0, 0x1, 0xf8, 0x0, 0xf8, 0x0, 0x7c, 0x0,
    0x3e, 0x0, 0x1f, 0x0, 0x1f, 0x80, 0xf, 0xc0,
    0x7, 0xc0, 0x3, 0xe0, 0x1, 0xf0, 0x0, 0xf8,
    0x0, 0x7c, 0x0, 0x7e, 0x0, 0x3e, 0x0, 0x1f,
    0x0, 0x1f, 0x80, 0xff, 0x80, 0x7f, 0x80, 0x7f,
    0x80, 0x3f, 0x0, 0x0,

    /* U+006B "k" */
    0x7, 0xc0, 0x0, 0xf, 0x80, 0x0, 0x1f, 0x0,
    0x0, 0x3e, 0x0, 0x0, 0x7c, 0x0, 0x1, 0xf8,
    0x0, 0x3, 0xf0, 0x0, 0x7, 0xc0, 0x0, 0xf,
    0x80, 0x0, 0x1f, 0x0, 0x0, 0x3e, 0x1, 0xf8,
    0xfc, 0x7, 0xe1, 0xf8, 0x1f, 0x83, 0xf0, 0x7f,
    0x7, 0xc0, 0xfc, 0xf, 0x83, 0xf0, 0x1f, 0xf,
    0xc0, 0x3e, 0x3f, 0x0, 0xfc, 0x7c, 0x1, 0xf9,
    0xf8, 0x3, 0xff, 0xe0, 0x7, 0xff, 0x80, 0xf,
    0xff, 0x0, 0x1f, 0xff, 0x0, 0x3e, 0x7e, 0x0,
    0xfc, 0x7e, 0x1, 0xf8, 0xfc, 0x3, 0xe0, 0xfc,
    0x7, 0xc1, 0xfc, 0xf, 0x81, 0xf8, 0x1f, 0x1,
    0xf8, 0x7e, 0x3, 0xf0, 0xfc, 0x3, 0xf1, 0xf0,
    0x7, 0xf0,

    /* U+006C "l" */
    0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xe0, 0x7c, 0xf,
    0x81, 0xf0, 0x7e, 0xf, 0xc1, 0xf0, 0x3e, 0x7,
    0xc0, 0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x3,
    0xe0, 0x7c, 0xf, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf0, 0x3e, 0x7, 0xc0, 0xf8, 0x3f, 0x7, 0xe0,
    0xf8, 0x1f, 0x3, 0xe0, 0x7c, 0x1f, 0x80,

    /* U+006D "m" */
    0xf, 0xf, 0xe0, 0x3f, 0x1, 0xf3, 0xff, 0xf,
    0xfc, 0x1f, 0x7f, 0xf9, 0xff, 0xe1, 0xff, 0xff,
    0xff, 0xfe, 0x1f, 0xc1, 0xff, 0x87, 0xf1, 0xf8,
    0xf, 0xe0, 0x3f, 0x1f, 0x0, 0xfc, 0x3, 0xf3,
    0xf0, 0xf, 0xc0, 0x1f, 0x3f, 0x0, 0xfc, 0x3,
    0xf3, 0xf0, 0xf, 0xc0, 0x3f, 0x3e, 0x0, 0xfc,
    0x3, 0xf3, 0xe0, 0xf, 0x80, 0x3e, 0x3e, 0x0,
    0xf8, 0x3, 0xe3, 0xe0, 0xf, 0x80, 0x3e, 0x7e,
    0x0, 0xf8, 0x3, 0xe7, 0xe0, 0x1f, 0x80, 0x7e,
    0x7e, 0x1, 0xf8, 0x7, 0xe7, 0xc0, 0x1f, 0x0,
    0x7e, 0x7c, 0x1, 0xf0, 0x7, 0xc7, 0xc0, 0x1f,
    0x0, 0x7c, 0x7c, 0x1, 0xf0, 0x7, 0xcf, 0xc0,
    0x1f, 0x0, 0x7c, 0xfc, 0x3, 0xf0, 0xf, 0xcf,
    0x80, 0x3f, 0x0, 0xfc,

    /* U+006E "n" */
    0x1f, 0x7, 0xe0, 0x7c, 0xff, 0xc1, 0xf7, 0xff,
    0x87, 0xff, 0xff, 0x1f, 0xe0, 0xfc, 0x7e, 0x1,
    0xf1, 0xf0, 0x7, 0xcf, 0xc0, 0x1f, 0x3f, 0x0,
    0x7c, 0xfc, 0x1, 0xf3, 0xe0, 0x7, 0xcf, 0x80,
    0x3f, 0x3e, 0x0, 0xfc, 0xf8, 0x3, 0xf7, 0xe0,
    0xf, 0x9f, 0x80, 0x3e, 0x7c, 0x0, 0xf9, 0xf0,
    0x3, 0xe7, 0xc0, 0x1f, 0x9f, 0x0, 0x7e, 0x7c,
    0x1, 0xfb, 0xf0, 0x7, 0xcf, 0xc0, 0x1f, 0x3e,
    0x0, 0x7c,

    /* U+006F "o" */
    0x0, 0x7f, 0x0, 0xf, 0xff, 0x0, 0x7f, 0xfe,
    0x3, 0xff, 0xfc, 0x1f, 0xc3, 0xf8, 0xfc, 0x7,
    0xe3, 0xe0, 0xf, 0x9f, 0x80, 0x3f, 0x7c, 0x0,
    0xff, 0xf0, 0x1, 0xff, 0x80, 0x7, 0xfe, 0x0,
    0x3f, 0xf8, 0x0, 0xff, 0xe0, 0x3, 0xef, 0x80,
    0xf, 0xbe, 0x0, 0x7e, 0xf8, 0x1, 0xf3, 0xe0,
    0xf, 0xcf, 0xc0, 0x7e, 0x1f, 0x83, 0xf8, 0x7f,
    0xff, 0xc0, 0xff, 0xfe, 0x1, 0xff, 0xe0, 0x1,
    0xfe, 0x0,

    /* U+0070 "p" */
    0x7, 0x87, 0xe0, 0xf, 0x9f, 0xf8, 0xf, 0xbf,
    0xfc, 0xf, 0xff, 0xfc, 0xf, 0xf0, 0xfe, 0xf,
    0xc0, 0x7e, 0xf, 0x80, 0x3f, 0x1f, 0x80, 0x3f,
    0x1f, 0x80, 0x3f, 0x1f, 0x80, 0x3f, 0x1f, 0x0,
    0x3f, 0x1f, 0x0, 0x3f, 0x1f, 0x0, 0x3f, 0x1f,
    0x0, 0x3e, 0x3f, 0x0, 0x3e, 0x3f, 0x0, 0x7e,
    0x3e, 0x0, 0x7e, 0x3e, 0x0, 0xfc, 0x3f, 0x0,
    0xfc, 0x3f, 0x83, 0xf8, 0x3f, 0xff, 0xf0, 0x7f,
    0xff, 0xe0, 0x7e, 0xff, 0xc0, 0x7c, 0x3f, 0x0,
    0x7c, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x7c, 0x0,
    0x0, 0xfc, 0x0, 0x0, 0xfc, 0x0, 0x0, 0xfc,
    0x0, 0x0, 0xf8, 0x0, 0x0, 0xf8, 0x0, 0x0,
    0xf8, 0x0, 0x0,

    /* U+0071 "q" */
    0x0, 0xfc, 0x3c, 0xf, 0xf9, 0xf0, 0xff, 0xf7,
    0xc7, 0xff, 0xff, 0x1f, 0xc3, 0xfc, 0xfc, 0x7,
    0xe7, 0xe0, 0xf, 0x9f, 0x80, 0x3e, 0x7c, 0x0,
    0xfb, 0xf0, 0x7, 0xef, 0xc0, 0x1f, 0xbe, 0x0,
    0x7e, 0xf8, 0x1, 0xf3, 0xe0, 0x7, 0xcf, 0x80,
    0x1f, 0x3e, 0x0, 0x7c, 0xf8, 0x3, 0xf3, 0xe0,
    0xf, 0xcf, 0xc0, 0x7e, 0x3f, 0x83, 0xf8, 0x7f,
    0xff, 0xe1, 0xff, 0xff, 0x83, 0xff, 0x7e, 0x3,
    0xf1, 0xf8, 0x0, 0x7, 0xe0, 0x0, 0x1f, 0x0,
    0x0, 0x7c, 0x0, 0x1, 0xf0, 0x0, 0x7, 0xc0,
    0x0, 0x3f, 0x0, 0x0, 0xfc, 0x0, 0x3, 0xf0,
    0x0, 0xf, 0x80,

    /* U+0072 "r" */
    0xf, 0xf, 0x1f, 0x3f, 0x1f, 0x7e, 0x1f, 0xfe,
    0x1f, 0xfe, 0x1f, 0xc0, 0x1f, 0x80, 0x3f, 0x0,
    0x3f, 0x0, 0x3f, 0x0, 0x3e, 0x0, 0x3e, 0x0,
    0x3e, 0x0, 0x3e, 0x0, 0x7e, 0x0, 0x7e, 0x0,
    0x7e, 0x0, 0x7c, 0x0, 0x7c, 0x0, 0x7c, 0x0,
    0x7c, 0x0, 0xfc, 0x0, 0xfc, 0x0, 0xf8, 0x0,

    /* U+0073 "s" */
    0x0, 0x7f, 0x0, 0x1f, 0xfe, 0x1, 0xff, 0xf8,
    0x1f, 0xff, 0xe1, 0xf8, 0x3f, 0x8f, 0x80, 0xfc,
    0xfc, 0x3, 0xe7, 0xe0, 0x0, 0x3f, 0x0, 0x1,
    0xfe, 0x0, 0x7, 0xff, 0x0, 0x1f, 0xff, 0x0,
    0x3f, 0xfc, 0x0, 0x3f, 0xf0, 0x0, 0x3f, 0xc0,
    0x0, 0x7e, 0xf8, 0x3, 0xf7, 0xc0, 0x1f, 0xbf,
    0x0, 0xf8, 0xfc, 0x1f, 0xc7, 0xff, 0xfc, 0x1f,
    0xff, 0xc0, 0x7f, 0xfc, 0x0, 0x7f, 0x0,

    /* U+0074 "t" */
    0x7, 0xc0, 0x1f, 0x0, 0x7c, 0x3, 0xf0, 0xf,
    0xc0, 0x3f, 0xf, 0xff, 0xff, 0xfe, 0xff, 0xfb,
    0xff, 0xe1, 0xf8, 0x7, 0xe0, 0x1f, 0x0, 0x7c,
    0x1, 0xf0, 0x7, 0xc0, 0x1f, 0x0, 0xfc, 0x3,
    0xf0, 0xf, 0x80, 0x3e, 0x0, 0xf8, 0x3, 0xe0,
    0x1f, 0x80, 0x7e, 0x1, 0xfc, 0x83, 0xfe, 0xf,
    0xf8, 0x1f, 0xe0, 0x3f, 0x0,

    /* U+0075 "u" */
    0x3f, 0x0, 0x7c, 0x7e, 0x0, 0xf8, 0xf8, 0x1,
    0xf1, 0xf0, 0x3, 0xe3, 0xe0, 0xf, 0xc7, 0xc0,
    0x1f, 0x9f, 0x80, 0x3f, 0x3f, 0x0, 0x7c, 0x7e,
    0x0, 0xf8, 0xf8, 0x1, 0xf1, 0xf0, 0x3, 0xe3,
    0xe0, 0xf, 0xc7, 0xc0, 0x1f, 0x9f, 0x80, 0x3f,
    0x3f, 0x0, 0x7c, 0x7e, 0x0, 0xf8, 0xfc, 0x1,
    0xf1, 0xf8, 0x7, 0xe3, 0xf0, 0x1f, 0xc3, 0xf0,
    0x7f, 0x87, 0xff, 0xfe, 0xf, 0xff, 0xfc, 0xf,
    0xfc, 0xf8, 0x7, 0xe1, 0xf0,

    /* U+0076 "v" */
    0x7c, 0x0, 0xfd, 0xf0, 0x3, 0xe7, 0xc0, 0x1f,
    0x9f, 0x80, 0x7c, 0x7e, 0x1, 0xf0, 0xf8, 0xf,
    0x83, 0xe0, 0x3e, 0xf, 0x81, 0xf0, 0x3e, 0x7,
    0xc0, 0xfc, 0x3e, 0x1, 0xf0, 0xf8, 0x7, 0xc7,
    0xc0, 0x1f, 0x1f, 0x0, 0x7c, 0x78, 0x1, 0xf3,
    0xe0, 0x3, 0xcf, 0x0, 0xf, 0xfc, 0x0, 0x3f,
    0xe0, 0x0, 0xff, 0x80, 0x3, 0xfc, 0x0, 0x7,
    0xf0, 0x0, 0x1f, 0x80, 0x0, 0x7e, 0x0, 0x1,
    0xf0, 0x0,

    /* U+0077 "w" */
    0xf8, 0x7, 0xc0, 0x3e, 0xf8, 0x7, 0xc0, 0x3e,
    0xf8, 0xf, 0xc0, 0x7c, 0xf8, 0xf, 0xc0, 0x7c,
    0xf8, 0xf, 0xc0, 0x7c, 0xf8, 0x1f, 0xc0, 0xf8,
    0xf8, 0x1f, 0xc0, 0xf8, 0x78, 0x3f, 0xe1, 0xf0,
    0x7c, 0x3f, 0xe1, 0xf0, 0x7c, 0x7d, 0xe1, 0xf0,
    0x7c, 0x79, 0xe3, 0xe0, 0x7c, 0xf9, 0xe3, 0xe0,
    0x7c, 0xf1, 0xe3, 0xc0, 0x7c, 0xf1, 0xf7, 0xc0,
    0x7d, 0xe1, 0xf7, 0x80, 0x3d, 0xe0, 0xf7, 0x80,
    0x3f, 0xc0, 0xff, 0x80, 0x3f, 0xc0, 0xff, 0x0,
    0x3f, 0x80, 0xff, 0x0, 0x3f, 0x80, 0xfe, 0x0,
    0x3f, 0x80, 0xfe, 0x0, 0x3f, 0x0, 0x7e, 0x0,
    0x3f, 0x0, 0x7c, 0x0, 0x3e, 0x0, 0x7c, 0x0,

    /* U+0078 "x" */
    0xf, 0xc0, 0x3f, 0x7, 0xe0, 0x3f, 0x81, 0xf8,
    0x1f, 0x80, 0xfc, 0x1f, 0x80, 0x3f, 0x1f, 0x80,
    0x1f, 0x8f, 0x80, 0x7, 0xcf, 0xc0, 0x3, 0xff,
    0xc0, 0x0, 0xff, 0xc0, 0x0, 0x7f, 0xc0, 0x0,
    0x1f, 0xe0, 0x0, 0xf, 0xe0, 0x0, 0x7, 0xf0,
    0x0, 0x7, 0xf8, 0x0, 0x7, 0xfe, 0x0, 0x3,
    0xff, 0x0, 0x3, 0xef, 0xc0, 0x3, 0xf3, 0xe0,
    0x3, 0xf1, 0xf8, 0x3, 0xf0, 0xfc, 0x1, 0xf8,
    0x3f, 0x1, 0xf8, 0x1f, 0x81, 0xf8, 0x7, 0xe1,
    0xf8, 0x3, 0xf0,

    /* U+0079 "y" */
    0x1f, 0x80, 0x1f, 0x8f, 0xc0, 0xf, 0x83, 0xe0,
    0xf, 0xc1, 0xf8, 0x7, 0xc0, 0xfc, 0x7, 0xe0,
    0x7e, 0x3, 0xe0, 0x1f, 0x3, 0xf0, 0xf, 0x81,
    0xf0, 0x7, 0xc1, 0xf8, 0x3, 0xf0, 0xf8, 0x1,
    0xf8, 0xfc, 0x0, 0x7c, 0x7c, 0x0, 0x3e, 0x3e,
    0x0, 0x1f, 0x3e, 0x0, 0xf, 0x9f, 0x0, 0x3,
    0xdf, 0x0, 0x1, 0xff, 0x80, 0x0, 0xff, 0x80,
    0x0, 0x7f, 0xc0, 0x0, 0x3f, 0xc0, 0x0, 0xf,
    0xe0, 0x0, 0x7, 0xe0, 0x0, 0x3, 0xf0, 0x0,
    0x1, 0xf0, 0x0, 0x0, 0xf8, 0x0, 0x0, 0xf8,
    0x0, 0x0, 0x7c, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x7c, 0x0, 0x3, 0xfe, 0x0, 0x1, 0xfe, 0x0,
    0x1, 0xfe, 0x0, 0x0, 0xfc, 0x0, 0x0, 0x0,

    /* U+007A "z" */
    0xf, 0xff, 0xfc, 0x3f, 0xff, 0xf0, 0xff, 0xff,
    0xc7, 0xff, 0xff, 0x0, 0x3, 0xf8, 0x0, 0xf,
    0xc0, 0x0, 0x7e, 0x0, 0x3, 0xf0, 0x0, 0x1f,
    0xc0, 0x0, 0xfe, 0x0, 0x7, 0xf0, 0x0, 0x3f,
    0x80, 0x1, 0xfc, 0x0, 0x7, 0xe0, 0x0, 0x3f,
    0x0, 0x1, 0xf8, 0x0, 0xf, 0xe0, 0x0, 0x7f,
    0x0, 0x3, 0xf8, 0x0, 0x1f, 0xc0, 0x0, 0x7f,
    0xff, 0xf3, 0xff, 0xff, 0xcf, 0xff, 0xff, 0x3f,
    0xff, 0xfc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 179, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 201, .box_w = 6, .box_h = 5, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 193, .box_w = 9, .box_h = 24, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 32, .adv_w = 457, .box_w = 27, .box_h = 32, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 458, .box_w = 25, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 457, .box_w = 27, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 482, .box_w = 27, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 456, .adv_w = 399, .box_w = 24, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 552, .adv_w = 399, .box_w = 25, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 652, .adv_w = 484, .box_w = 27, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 760, .adv_w = 507, .box_w = 29, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 876, .adv_w = 207, .box_w = 10, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 916, .adv_w = 397, .box_w = 24, .box_h = 32, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1012, .adv_w = 436, .box_w = 28, .box_h = 32, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1124, .adv_w = 398, .box_w = 21, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1208, .adv_w = 626, .box_w = 37, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1356, .adv_w = 507, .box_w = 29, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1472, .adv_w = 493, .box_w = 28, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1584, .adv_w = 458, .box_w = 27, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1692, .adv_w = 504, .box_w = 28, .box_h = 35, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1815, .adv_w = 458, .box_w = 25, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1915, .adv_w = 440, .box_w = 25, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2015, .adv_w = 423, .box_w = 26, .box_h = 32, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 2119, .adv_w = 491, .box_w = 28, .box_h = 32, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 2231, .adv_w = 457, .box_w = 28, .box_h = 32, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 2343, .adv_w = 626, .box_w = 38, .box_h = 32, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2495, .adv_w = 457, .box_w = 31, .box_h = 32, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 2619, .adv_w = 457, .box_w = 27, .box_h = 32, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2727, .adv_w = 404, .box_w = 24, .box_h = 32, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2823, .adv_w = 392, .box_w = 22, .box_h = 24, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2889, .adv_w = 408, .box_w = 23, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2987, .adv_w = 374, .box_w = 20, .box_h = 24, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3047, .adv_w = 408, .box_w = 24, .box_h = 34, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3149, .adv_w = 377, .box_w = 20, .box_h = 24, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3209, .adv_w = 244, .box_w = 17, .box_h = 34, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3282, .adv_w = 408, .box_w = 23, .box_h = 33, .ofs_x = 2, .ofs_y = -9},
    {.bitmap_index = 3377, .adv_w = 408, .box_w = 22, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3471, .adv_w = 187, .box_w = 11, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3518, .adv_w = 189, .box_w = 17, .box_h = 43, .ofs_x = -5, .ofs_y = -9},
    {.bitmap_index = 3610, .adv_w = 377, .box_w = 23, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3708, .adv_w = 187, .box_w = 11, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3755, .adv_w = 626, .box_w = 36, .box_h = 24, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3863, .adv_w = 408, .box_w = 22, .box_h = 24, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3929, .adv_w = 408, .box_w = 22, .box_h = 24, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3995, .adv_w = 408, .box_w = 24, .box_h = 33, .ofs_x = 0, .ofs_y = -9},
    {.bitmap_index = 4094, .adv_w = 408, .box_w = 22, .box_h = 33, .ofs_x = 2, .ofs_y = -9},
    {.bitmap_index = 4185, .adv_w = 253, .box_w = 16, .box_h = 24, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4233, .adv_w = 374, .box_w = 21, .box_h = 24, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4296, .adv_w = 246, .box_w = 14, .box_h = 30, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 4349, .adv_w = 408, .box_w = 23, .box_h = 24, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 4418, .adv_w = 365, .box_w = 22, .box_h = 24, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 4484, .adv_w = 538, .box_w = 32, .box_h = 24, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 4580, .adv_w = 365, .box_w = 25, .box_h = 24, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 4655, .adv_w = 365, .box_w = 25, .box_h = 33, .ofs_x = -1, .ofs_y = -9},
    {.bitmap_index = 4759, .adv_w = 365, .box_w = 22, .box_h = 24, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xe, 0x1a
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 27, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 3, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 4,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 30,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t Roboto_40 = {
#else
lv_font_t Roboto_40 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 43,          /*The maximum line height required by the font*/
    .base_line = 9,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if ROBOTO_40*/

