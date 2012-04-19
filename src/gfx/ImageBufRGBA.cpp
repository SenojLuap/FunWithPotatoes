// ImageBufRGBA.cpp by Paul Jones on 4.14.2012

#include <stdexcept>
#include "gfx\ImageBufRGBA.h"

ImageBufRGBA::ImageBufRGBA(size_t h, size_t w) : ImageBuf(h, w, RGBA) {
  rgb = new uint8_t**[width];
  for(unsigned int i = 0; i < width; i++) {
    rgb[i] = new uint8_t*[height];
    for(unsigned int ii = 0; ii < height; ii++)
      rgb[i][ii] = new uint8_t[3];
  }
}

ImageBufRGBA::~ImageBufRGBA() {
  for(unsigned int i = 0; i < width; i++) {
    for(unsigned int ii = 0; ii < height; ii++)
      delete[] rgb[i][ii];
    delete[] rgb[i];
  }
  delete rgb;
}

uint8_t& ImageBufRGBA::operator()(size_t layer, size_t x, size_t y) {
  switch(layer){
    case IB_ALPHA_LAYER:
      return alpha[x][y];
    case IB_RED_LAYER:
    case IB_BLUE_LAYER:
    case IB_GREEN_LAYER:
      return rgb[x][y][layer-1];
    default:
      throw new std::domain_error("Specified an invalid layer");
  }
}
