//
// Created by jonng on 6/5/2021.
//

#include "MirrorYSlider.h"

MirrorYSlider::MirrorYSlider() {
    setActualRange(0, 300);
    setDisplayedRange(-50, 50);
    setDisplayedValue(-5);
    setLabelString("Mirror Y");
    setPosition({50.f, 590.f});
    setStartingBarPosition(150.f);
    setSliderLength(450.f);
}

void MirrorYSlider::reset() {
    setDisplayedValue(-5);
}
