//
// Created by jonng on 6/5/2021.
//

#include "MirrorXSlider.h"

MirrorXSlider::MirrorXSlider() {
    setActualRange(0, 665);
    setDisplayedRange(-100, 100);
    setDisplayedValue(0);
    setLabelString("Mirror X");
    setPosition({50.f, 550.f});
    setStartingBarPosition(150.f);
    setSliderLength(450.f);
}

void MirrorXSlider::reset() {
    setDisplayedValue(0);
}
