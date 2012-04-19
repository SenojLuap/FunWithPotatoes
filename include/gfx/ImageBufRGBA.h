// ImageBufRGBA.h by Paul Jones on 4.14.2012
/* An ImageBufRGBA is an ImageBuf that stores 8-bit color information as well as
 * alpha. */

#pragma once
#ifndef PJ_FWP_GFX_IMAGEBUFRGBA_H
#define PJ_FWP_GFX_IMAGEBUFRGBA_H

#include "gfx\ImageBuf.h"

#define IB_RED_LAYER 1
#define IB_BLUE_LAYER 2
#define IB_GREEN_LAYER 3

struct ImageBufRGBA : public ImageBuf {
  uint8_t ***rgb;

  ImageBufRGBA(size_t height, size_t width);
  ~ImageBufRGBA();
  uint8_t& operator()(size_t layer, size_t x, size_t y);
};

#endif // PJ_FWP_GFX_IMAGEBUFRGBA_H