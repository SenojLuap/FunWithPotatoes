// FWPGDoubleContainer.cpp by Paul Jones 4.21.2012

#include "gfx\fwpg\FWPGDoubleContainer.h"

void FWPGDoubleContainer::add(FWPGComponent *com) {
  if(!child1_)
    child1_ = com;
  else
    child2_ = com;
  fireSignal("contentsChanged");
}

void FWPGDoubleContainer::add1(FWPGComponent *com) {
  child1_ = com;
  fireSignal("contentsChanged");
}

void FWPGDoubleContainer::add2(FWPGComponent *com) {
  child2_ = com;
  fireSignal("contentsChanged");
}

uint16_t FWPGDoubleContainer::getMinWidth() {
  if(horizontal_) {
    if(child1_ && child2_)
      return child1_->getMinWidth() + child2_->getMinWidth() +
          individualPadding_ + (externalPadding_ * 2);
    return (child1_ ? child1_->getMinWidth() : 0) + (child2_ ?
        child2_->getMinWidth() : 0) + (externalPadding_ * 2);
  }
  uint16_t left = (child1_ ? child1_->getMinWidth() : 0);
  uint16_t right = (child2_ ? child2_->getMinWidth() : 0);
  return (left > right ? left : right) + (externalPadding_ * 2);
}

uint16_t FWPGDoubleContainer::getMinHeight() {
  if(!horizontal_) {
    if(child1_ && child2_)
      return child1_->getMinHeight() + child2_->getMinHeight() +
          individualPadding_ + (externalPadding_ * 2);
    return (child1_ ? child1_->getMinHeight() : 0) + (child2_ ?
        child2_->getMinHeight() : 0) + (externalPadding_ * 2);
  }
  uint16_t top = (child1_ ? child1_->getMinHeight() : 0);
  uint16_t bot = (child2_ ? child2_->getMinHeight() : 0);
  return (top > bot ? top : bot) + (externalPadding_ * 2);
}

FWPGComponent *FWPGDoubleContainer::get1() {
  return child1_;
}

FWPGComponent *FWPGDoubleContainer::get2() {
  return child2_;
}
