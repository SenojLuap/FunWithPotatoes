// ImageBuf.cpp by Paul Jones on 4.14.2012

#include "gfx\ImageBuf.h"

ImageBuf::ImageBuf(size_t w, size_t h, ImageBufFormat f) : width(w), height(h),
    format(f) {
  alpha = new uint8_t*[width];
  for(unsigned int i = 0; i < width; i++)
    alpha[i] = new uint8_t[height];
}

ImageBuf::~ImageBuf() {
  for(unsigned int i = 0; i < width; i++)
    delete[] alpha[i];
  delete[] alpha;
}