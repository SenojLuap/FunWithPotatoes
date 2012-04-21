// FWPGComponent.h by Paul Jones on 4.19.2012

#pragma once
#ifndef PJ_FWP_GFX_FWPG_FWPGCOMPONENT_H
#define PJ_FWP_GFX_FWPG_FWPGCOMPONENT_H

#include <cstdint>
#include <string>
#include <boost\unordered_map.hpp>
#include <boost\ptr_container\ptr_vector.hpp>

#include "gfx/fwpg/SignalListener.h"

class FWPGComponent {
  uint16_t xpos_, ypos_, width_, height_;
  boost::unordered_map<std::string, boost::ptr_vector<SignalListener>>
      listeners_;

public:
  // Retrieves the minimum size (in pixels) required for this component to draw
  // itself
  virtual uint16_t getMinWidth()=0;
  virtual uint16_t getMinHeight()=0;

  // Indicates the position and available area that the component should draw
  // itself to
  virtual void reshape(uint16_t xpos, uint16_t ypos, uint16_t width,
      uint16_t height);

  // Installs a listener for the specified signal.
  // Note: It is possible to install a listener for a signal that cannot or will
  // not ever be emitted.
  void addSignalListener(SignalListener *el, const std::string signal);

  FWPGComponent() : xpos_(0), ypos_(0), width_(0), height_(0) {}
protected:
  // Calls the signal listener's listen function, for all the listeners that
  // were installed for the specified signal
  void fireSignal(const std::string signal);
};

#endif // PJ_FWP_GFX_FWPG_FWPGCOMPONENT_H