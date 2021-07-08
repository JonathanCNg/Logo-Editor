//
// Created by jonng on 6/5/2021.
//

#include "MirrorOpacitySlider.h"

MirrorOpacitySlider::MirrorOpacitySlider() {
    setActualRange(0, 255);
    setDisplayedRange(0, 100);
    setDisplayedValue(50);
    setLabelString("Mirror Opacity");
    setPosition({50.f, 630.f});
    setStartingBarPosition(150.f);
    setSliderLength(450.f);
}

void MirrorOpacitySlider::reset() {
    setDisplayedValue(50);
}
