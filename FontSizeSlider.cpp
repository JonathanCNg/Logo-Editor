//
// Created by jonng on 6/5/2021.
//

#include "FontSizeSlider.h"

FontSizeSlider::FontSizeSlider() {
    setActualRange(10,130);
    setDisplayedRange( 0,100);
    setDisplayedValue(50);
    setLabelString("Font Size");
    setPosition({50.f,390.f});
    setStartingBarPosition(150.f);
    setSliderLength(450.f);
}

void FontSizeSlider::reset() {
    setDisplayedValue(50);
}
