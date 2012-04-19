// ImageBufBA.cpp by Paul Jones on 4.14.2012

#include <stdexcept>
#include "gfx\ImageBufBA.h"

ImageBufBA::ImageBufBA(size_t h, size_t w) : ImageBuf(h, w, BA) {
  bright = new uint8_t*[width];
  for(unsigned int i = 0; i < width; i++)
    bright[i] = new uint8_t[height];
}

ImageBufBA::~ImageBufBA() {
  for(unsigned int i = 0; i < width; i++)
    delete[] bright[i];
  delete[] bright;
}

uint8_t& ImageBufBA::operator()(size_t layer, size_t x, size_t y) {
  switch(layer) {
    case IB_ALPHA_LAYER:
      return alpha[x][y];
    case IB_BRIGHTNESS_LAYER:
      return bright[x][y];
    default:
      throw new std::domain_error("Specified an invalid layer");
  }
}

ImageBufRGBA ImageBufBA::colorize(uint8_t red, uint8_t green, uint8_t blue) 
    const {
  ImageBufRGBA result(height, width);
  for(unsigned int x = 0; x < width; x++)
    for(unsigned int y = 0; y < height; y++) {
      result(IB_RED_LAYER, x, y) = (uint8_t)(((uint16_t)bright[x][y] * 
          (uint16_t)red) / 0xFE01);
      result(IB_GREEN_LAYER, x, y) = (uint8_t)(((uint16_t)bright[x][y] * 
          (uint16_t)green) / 0xFE01);
      result(IB_BLUE_LAYER, x, y) = (uint8_t)(((uint16_t)bright[x][y] * 
          (uint16_t)blue) / 0xFE01);
      result(IB_ALPHA_LAYER, x, y) = alpha[x][y];
    }
  return result;
}