// FWPGVectorContainer.cpp by Paul Jones on 4.22.2012

#include "gfx/fwpg/FWPGVectorContainer.h"

void FWPGVectorContainer::add(FWPGComponent *com) {
  children_.push_back(com);
  fireSignal("contentsChanged");
}

FWPGComponent *FWPGVectorContainer::get(size_t index) {
  return &children_.at(index);
}

uint16_t FWPGVectorContainer::getMinWidth() {
  if(!visible_)
    return 0;
  if(children_.size() == 0)
    return 0;
  if(children_.size() == 1)
    return (externalPadding_ * 2) + children_.at(0).getMinWidth();
  if(horizontal_) {
    uint16_t w = 0;
    for(unsigned int i = 0; i < children_.size(); i++)
      w += children_.at(i).getMinWidth();
    return (externalPadding_ * 2) + (individualPadding_ *
        (children_.size() - 1)) + w;
  }
  uint16_t w = 0;
  for(unsigned int i = 0; i < children_.size(); i++)
    w = children_.at(i).getMinWidth() > w ? children_.at(i).getMinWidth() : w;
  return w + (externalPadding_ * 2);
}

uint16_t FWPGVectorContainer::getMinHeight() {
  if(!visible_)
    return 0;
  if(children_.size() == 0)
    return 0;
  if(children_.size() == 1)
    return (externalPadding_ * 2) + children_.at(0).getMinHeight();
  if(!horizontal_) {
    uint16_t h = 0;
    for(unsigned int i = 0; i < children_.size(); i++)
      h += children_.at(i).getMinHeight();
    return (externalPadding_ * 2) + (individualPadding_ *
        (children_.size() - 1)) + h;
  }
  uint16_t h = 0;
  for(unsigned int i = 0; i < children_.size(); i++)
    h = children_.at(i).getMinHeight() > h ? children_.at(i).getMinHeight() : h;
  return h + (externalPadding_ * 2);
}

void FWPGVectorContainer::setVisible(bool visible, bool cascade) {
  FWPGComponent::setVisible(visible, cascade);
  if(cascade)
    for(unsigned int i = 0; i < children_.size(); i++)
      children_.at(i).setVisible(visible, cascade);
}
