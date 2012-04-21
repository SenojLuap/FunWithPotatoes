// FWPGSingleContainer.cpp by Paul Jones on 4.21.2012

#include "gfx\fwpg\FWPGSingleContainer.h"

void FWPGSingleContainer::add(FWPGComponent *com) {
  child_ = com;
  fireSignal("contentsChanged");
}
FWPGComponent *FWPGSingleContainer::getContents() {
  return child_;
}

uint16_t FWPGSingleContainer::getMinWidth() {
  return child_->getMinWidth() + (padding_ * 2);
}

uint16_t FWPGSingleContainer::getMinHeight() {
  return child_->getMinHeight() + (padding_ * 2);
}
