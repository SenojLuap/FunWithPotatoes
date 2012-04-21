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
  if(!visible_)
    return 0;
  return child_ ? child_->getMinWidth() + (padding_ * 2) : 0;
}

uint16_t FWPGSingleContainer::getMinHeight() {
  if(!visible_)
    return 0;
  return child_ ? child_->getMinHeight() + (padding_ * 2) : 0;
}

void FWPGSingleContainer::setVisible(bool visible, bool cascade) {
  FWPGComponent::setVisible(visible, cascade);
  if(cascade)
    child_->setVisible(visible, cascade);
}