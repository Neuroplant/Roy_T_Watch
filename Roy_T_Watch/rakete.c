#include "lvgl/lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_RAKETE
#define LV_ATTRIBUTE_IMG_RAKETE
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG_RAKETE uint8_t rakete_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit, Alpha 8 bit */
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xe9, 0xcf, 0xe9, 0xcf, 0xe9, 0xcf, 0xe9, 0xf0, 0xff, 0x08, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xe5, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xe5, 0xf0, 0xe9, 0xd4, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xe5, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xe9, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xe5, 0xff, 0xe5, 0xff, 0xf1, 0xff, 0xf8, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xe5, 0xff, 0xe5, 0xff, 0xf5, 0xff, 0xf1, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xb6, 0xcf, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0xe5, 0xff, 0xe9, 0xff, 0x92, 0xff, 0x92, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 
  0xb6, 0xc7, 0xe9, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0xe5, 0xfc, 0xe5, 0xff, 0xe5, 0xff, 
  0xff, 0x08, 0xb2, 0xeb, 0xe5, 0xfb, 0xe5, 0xff, 0xe5, 0xff, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xe5, 0xff, 
  0xff, 0x00, 0xff, 0x10, 0xce, 0xf3, 0xe5, 0xfb, 0xe5, 0xff, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xfb, 0x5c, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x20, 0xc9, 0xfb, 0xe5, 0xff, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0xe5, 0xff, 0xae, 0xf7, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x2f, 0xcd, 0xff, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0xc9, 0xff, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x92, 0xff, 0x92, 0xff, 0xb6, 0xff, 0xb6, 0xff, 0xff, 0xff, 0x92, 0xff, 0x92, 0xf0, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0xb6, 0xff, 0x92, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0xff, 0xfc, 0x92, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x92, 0xf8, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0x92, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xb7, 0xab, 0xe5, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xe5, 0xff, 0xe9, 0xfc, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x18, 0xcd, 0xfb, 0xe5, 0xf8, 0xe5, 0xff, 0xe5, 0xff, 0xce, 0xd4, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xd7, 0xa0, 0xe5, 0xfc, 0xe5, 0xff, 0xe5, 0xff, 0xff, 0x18, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
  0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x18, 0xb2, 0xf7, 0xe5, 0xff, 0xd6, 0xb7, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit, Alpha 8 bit*/
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x4a, 0xf2, 0xcf, 0x4a, 0xf2, 0xcf, 0x4a, 0xf2, 0xcf, 0xc7, 0xf1, 0xf0, 0xdf, 0xff, 0x08, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0x67, 0xf1, 0xf0, 0x2a, 0xf2, 0xd4, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0x25, 0xf1, 0xff, 0x65, 0xfa, 0xff, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0x45, 0xfc, 0xff, 0x02, 0xfe, 0xff, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x05, 0xf1, 0xff, 0x25, 0xf1, 0xff, 0xc4, 0xfc, 0xff, 0x25, 0xfc, 0xff, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xf3, 0x9c, 0xcf, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x05, 0xf1, 0xff, 0x87, 0xd9, 0xff, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x26, 0xe9, 0xff, 0x25, 0xe9, 0xff, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 
  0x14, 0xa5, 0xc7, 0xa8, 0xd9, 0xff, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0x26, 0xe9, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x31, 0x8c, 0xff, 0x66, 0xe9, 0xfc, 0x05, 0xf1, 0xff, 0x46, 0xe9, 0xff, 
  0xff, 0xff, 0x08, 0xaf, 0xab, 0xeb, 0x46, 0xe9, 0xfb, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0x31, 0x8c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x31, 0x8c, 0xff, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0x26, 0xe9, 0xff, 
  0xff, 0xff, 0x00, 0xdf, 0xff, 0x10, 0x0c, 0xbb, 0xf3, 0x46, 0xe9, 0xfb, 0x05, 0xf1, 0xff, 0x31, 0x8c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x31, 0x8c, 0xff, 0x05, 0xf1, 0xff, 0x46, 0xe9, 0xff, 0x18, 0xee, 0x5c, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x9e, 0xf7, 0x20, 0x4a, 0xca, 0xfb, 0x05, 0xf1, 0xff, 0x31, 0x8c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x31, 0x8c, 0xff, 0x05, 0xf1, 0xff, 0x8e, 0xa3, 0xf7, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x5d, 0xef, 0x2f, 0x8b, 0xba, 0xff, 0x31, 0x8c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x31, 0x8c, 0xff, 0x8b, 0xc2, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0xd3, 0x9c, 0xff, 0xd3, 0x9c, 0xff, 0xdf, 0xff, 0xff, 0x31, 0x8c, 0xff, 0x71, 0x8c, 0xf0, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x72, 0x8c, 0xff, 0xb3, 0x9c, 0xff, 0x31, 0x8c, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x51, 0x8c, 0xff, 0x71, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x71, 0x8c, 0xff, 0x71, 0x8c, 0xff, 0x3d, 0xef, 0xfc, 0x31, 0x8c, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x51, 0x8c, 0xf8, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0x31, 0x8c, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x76, 0xb5, 0xab, 0x87, 0xe1, 0xff, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0x05, 0xf1, 0xff, 0x87, 0xe1, 0xfc, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xbe, 0xf7, 0x18, 0xab, 0xba, 0xfb, 0x46, 0xf1, 0xf8, 0x05, 0xf1, 0xff, 0x26, 0xe9, 0xff, 0x4d, 0xd3, 0xd4, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x96, 0xbd, 0xa0, 0x67, 0xe1, 0xfc, 0x05, 0xf1, 0xff, 0x87, 0xe1, 0xff, 0xbe, 0xf7, 0x18, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xbe, 0xf7, 0x18, 0xef, 0x9b, 0xf7, 0x25, 0xe9, 0xff, 0xd3, 0xbc, 0xb7, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format:  Blue: 5 bit Green: 6 bit, Red: 5 bit, Alpha 8 bit  BUT the 2  color bytes are swapped*/
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf2, 0x4a, 0xcf, 0xf2, 0x4a, 0xcf, 0xf2, 0x4a, 0xcf, 0xf1, 0xc7, 0xf0, 0xff, 0xdf, 0x08, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x67, 0xf0, 0xf2, 0x2a, 0xd4, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x25, 0xff, 0xfa, 0x65, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xfc, 0x45, 0xff, 0xfe, 0x02, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf1, 0x05, 0xff, 0xf1, 0x25, 0xff, 0xfc, 0xc4, 0xff, 0xfc, 0x25, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x9c, 0xf3, 0xcf, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0xf1, 0x05, 0xff, 0xd9, 0x87, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0xe9, 0x26, 0xff, 0xe9, 0x25, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 
  0xa5, 0x14, 0xc7, 0xd9, 0xa8, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xe9, 0x26, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x31, 0xff, 0xe9, 0x66, 0xfc, 0xf1, 0x05, 0xff, 0xe9, 0x46, 0xff, 
  0xff, 0xff, 0x08, 0xab, 0xaf, 0xeb, 0xe9, 0x46, 0xfb, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0x8c, 0x31, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x31, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xe9, 0x26, 0xff, 
  0xff, 0xff, 0x00, 0xff, 0xdf, 0x10, 0xbb, 0x0c, 0xf3, 0xe9, 0x46, 0xfb, 0xf1, 0x05, 0xff, 0x8c, 0x31, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x31, 0xff, 0xf1, 0x05, 0xff, 0xe9, 0x46, 0xff, 0xee, 0x18, 0x5c, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf7, 0x9e, 0x20, 0xca, 0x4a, 0xfb, 0xf1, 0x05, 0xff, 0x8c, 0x31, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x31, 0xff, 0xf1, 0x05, 0xff, 0xa3, 0x8e, 0xf7, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xef, 0x5d, 0x2f, 0xba, 0x8b, 0xff, 0x8c, 0x31, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x31, 0xff, 0xc2, 0x8b, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0x9c, 0xd3, 0xff, 0x9c, 0xd3, 0xff, 0xff, 0xdf, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x71, 0xf0, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x72, 0xff, 0x9c, 0xb3, 0xff, 0x8c, 0x31, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x51, 0xff, 0x8c, 0x71, 0xff, 0x8c, 0x31, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x71, 0xff, 0x8c, 0x71, 0xff, 0xef, 0x3d, 0xfc, 0x8c, 0x31, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x8c, 0x51, 0xf8, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0x8c, 0x31, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xb5, 0x76, 0xab, 0xe1, 0x87, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xf1, 0x05, 0xff, 0xe1, 0x87, 0xfc, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf7, 0xbe, 0x18, 0xba, 0xab, 0xfb, 0xf1, 0x46, 0xf8, 0xf1, 0x05, 0xff, 0xe9, 0x26, 0xff, 0xd3, 0x4d, 0xd4, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xbd, 0x96, 0xa0, 0xe1, 0x67, 0xfc, 0xf1, 0x05, 0xff, 0xe1, 0x87, 0xff, 0xf7, 0xbe, 0x18, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf7, 0xbe, 0x18, 0x9b, 0xef, 0xf7, 0xe9, 0x25, 0xff, 0xbc, 0xd3, 0xb7, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format:  Blue: 8 bit, Green: 8 bit, Red: 8 bit, Alpha: 8 bit*/
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x51, 0x4a, 0xf1, 0xcf, 0x51, 0x4a, 0xf1, 0xcf, 0x51, 0x4a, 0xf1, 0xcf, 0x36, 0x37, 0xf0, 0xf0, 0xf8, 0xf8, 0xfe, 0x08, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0x35, 0x2d, 0xef, 0xf0, 0x4d, 0x46, 0xf1, 0xd4, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0x29, 0x23, 0xee, 0xff, 0x2a, 0x4b, 0xf6, 0xff, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0x2a, 0x8a, 0xff, 0xff, 0x11, 0xc0, 0xfd, 0xff, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x29, 0x20, 0xee, 0xff, 0x29, 0x26, 0xef, 0xff, 0x24, 0x9a, 0xff, 0xff, 0x2c, 0x85, 0xff, 0xff, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0x9c, 0x9c, 0x9c, 0xcf, 0x85, 0x85, 0x85, 0xff, 0x85, 0x85, 0x85, 0xff, 0x85, 0x85, 0x85, 0xff, 0x29, 0x20, 0xee, 0xff, 0x39, 0x32, 0xdb, 0xff, 0x85, 0x85, 0x85, 0xff, 0x85, 0x85, 0x85, 0xff, 0x2e, 0x26, 0xe8, 0xff, 0x2c, 0x24, 0xea, 0xff, 0x85, 0x85, 0x85, 0xff, 0x85, 0x85, 0x85, 0xff, 0x85, 0x85, 0x85, 0xff, 
  0xa0, 0xa0, 0xa0, 0xc7, 0x3d, 0x35, 0xda, 0xff, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0x2e, 0x26, 0xe8, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x85, 0x85, 0x85, 0xff, 0x33, 0x2b, 0xe5, 0xfc, 0x29, 0x20, 0xee, 0xff, 0x2f, 0x27, 0xe7, 0xff, 
  0xfb, 0xfb, 0xfb, 0x08, 0x75, 0x73, 0xac, 0xeb, 0x31, 0x29, 0xe9, 0xfb, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0x85, 0x85, 0x85, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x85, 0x85, 0x85, 0xff, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0x2d, 0x25, 0xe9, 0xff, 
  0xff, 0xff, 0xff, 0x00, 0xf7, 0xf7, 0xf7, 0x10, 0x63, 0x5f, 0xba, 0xf3, 0x31, 0x29, 0xea, 0xfb, 0x29, 0x20, 0xee, 0xff, 0x85, 0x85, 0x85, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x85, 0x85, 0x85, 0xff, 0x29, 0x20, 0xee, 0xff, 0x32, 0x29, 0xe6, 0xff, 0xc2, 0xc0, 0xe7, 0x5c, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xf0, 0xf0, 0xf0, 0x20, 0x4f, 0x49, 0xc9, 0xfb, 0x29, 0x20, 0xee, 0xff, 0x85, 0x85, 0x85, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x85, 0x85, 0x85, 0xff, 0x29, 0x20, 0xee, 0xff, 0x73, 0x70, 0xa2, 0xf7, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xe9, 0xe9, 0xe9, 0x2f, 0x56, 0x51, 0xbb, 0xff, 0x85, 0x85, 0x85, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x85, 0x85, 0x85, 0xff, 0x55, 0x4f, 0xbd, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x85, 0x85, 0x85, 0xff, 0x85, 0x85, 0x85, 0xff, 0x9a, 0x9a, 0x9a, 0xff, 0x98, 0x98, 0x98, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0x85, 0x85, 0x85, 0xff, 0x8c, 0x8c, 0x8c, 0xf0, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x85, 0x85, 0x85, 0xff, 0x85, 0x85, 0x85, 0xff, 0x86, 0x85, 0x85, 0xff, 0x8d, 0x8c, 0x88, 0xff, 0x95, 0x95, 0x95, 0xff, 0x85, 0x85, 0x85, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x85, 0x85, 0x85, 0xff, 0x85, 0x85, 0x85, 0xff, 0x86, 0x86, 0x85, 0xff, 0x89, 0x88, 0x86, 0xff, 0x8b, 0x8b, 0x8b, 0xff, 0x85, 0x85, 0x85, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x85, 0x85, 0x85, 0xff, 0x85, 0x85, 0x85, 0xff, 0x8c, 0x8c, 0x8c, 0xff, 0x8b, 0x8b, 0x8b, 0xff, 0xe5, 0xe5, 0xe5, 0xfc, 0x85, 0x85, 0x85, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x89, 0x89, 0x89, 0xf8, 0x86, 0x86, 0x86, 0xff, 0x85, 0x85, 0x85, 0xff, 0x85, 0x85, 0x85, 0xff, 0x85, 0x85, 0x85, 0xff, 0x86, 0x86, 0x86, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xae, 0xae, 0xae, 0xab, 0x38, 0x30, 0xde, 0xff, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0x29, 0x20, 0xee, 0xff, 0x39, 0x31, 0xdf, 0xfc, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xf3, 0xf3, 0xf3, 0x18, 0x5b, 0x56, 0xb8, 0xfb, 0x30, 0x27, 0xed, 0xf8, 0x29, 0x20, 0xee, 0xff, 0x2e, 0x25, 0xea, 0xff, 0x6c, 0x68, 0xcd, 0xd4, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xaf, 0xaf, 0xb5, 0xa0, 0x36, 0x2e, 0xe2, 0xfc, 0x29, 0x20, 0xee, 0xff, 0x36, 0x2f, 0xdf, 0xff, 0xf3, 0xf3, 0xf3, 0x18, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xf3, 0xf3, 0xf3, 0x18, 0x7c, 0x7b, 0x9a, 0xf7, 0x2c, 0x24, 0xea, 0xff, 0x99, 0x98, 0xb8, 0xb7, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
#endif
};

const lv_img_dsc_t rakete = {
  .header.always_zero = 0,
  .header.w = 13,
  .header.h = 20,
  .data_size = 260 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .data = rakete_map,
};

