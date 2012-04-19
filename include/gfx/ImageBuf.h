// ImageBuf.h by Paul Jones on 4.14.2012
/* The ImageBuf struct is used to contain graphical information for drawing to
 * the screen. ImageBuf is inherited by ImageBufBA and ImageBufRGBA */

#pragma once
#ifndef PJ_FWP_GFX_IMAGEBUF_H
#define PJ_FWP_GFX_IMAGEBUF_H

#include <cstdint>

#define IB_ALPHA_LAYER 0

enum ImageBufFormat {BA = 0, RGBA};

struct ImageBuf {
  ImageBufFormat format;
  size_t width;
  size_t height;
  uint8_t **alpha;

  ImageBuf(size_t height, size_t width, ImageBufFormat format);
  ~ImageBuf();
};

#endif // PJ_FWP_GFX_IMAGEBUF_H