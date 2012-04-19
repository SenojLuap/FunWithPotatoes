// ImageBufBA.h by Paul Jones on 4.14.2012
/* The ImageBufBA struct is an extension of the ImageBuf class. An ImageBufBA
 * holds brightness and alpha data. */

#pragma once
#ifndef PJ_FWP_GFX_IMAGEBUFBA_H
#define PJ_FWP_GFX_IMAGEBUFBA_H

#include "gfx\ImageBuf.h"
#include "gfx\ImageBufRGBA.h"

#define IB_BRIGHTNESS_LAYER 1

struct ImageBufBA : public ImageBuf {
  uint8_t **bright;

  ImageBufBA(size_t height, size_t width);
  ~ImageBufBA();
  uint8_t& operator()(size_t layer, size_t x, size_t y);
  ImageBufRGBA colorize(uint8_t red, uint8_t green, uint8_t blue) const;
};

#endif // PJ_FWP_GFX_IMAGEBUFBA_H