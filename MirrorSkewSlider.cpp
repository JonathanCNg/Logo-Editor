//
// Created by jonng on 6/5/2021.
//

#include "MirrorSkewSlider.h"

MirrorSkewSlider::MirrorSkewSlider() {
    setActualRange(0, 3);
    setDisplayedRange(0, 100);
    setDisplayedValue(10);
    setLabelString("Mirror Skew");
    setPosition({50.f, 670.f});
    setStartingBarPosition(150.f);
    setSliderLength(450.f);
}

void MirrorSkewSlider::reset() {
    setDisplayedValue(10);
}
