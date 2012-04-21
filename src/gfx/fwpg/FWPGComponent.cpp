#include "gfx/fwpg/FWPGComponent.h"
#include "gfx/fwpg/Signal.h"

void FWPGComponent::addSignalListener(SignalListener *list,
    const std::string signal) {
  listeners_[signal].push_back(list);
}

void FWPGComponent::reshape(uint16_t xpos, uint16_t ypos, uint16_t width,
    uint16_t height) {
  xpos_ = xpos;
  ypos_ = ypos;
  width_ = width;
  height_ = height;
  fireSignal("reshape");
}

void FWPGComponent::fireSignal(const std::string signal) {
  if(listeners_.count(signal)) {
    Signal sig(this, signal);
    for(unsigned int i = 0; i < listeners_[signal].size(); i++)
      listeners_[signal][i].onSignal(sig);
  }
}

void FWPGComponent::setVisible(bool visible, bool cascade) {
  visible_ = visible;
  fireSignal("visibilityChanged");
}

bool FWPGComponent::isVisible() {
  return visible_;
}