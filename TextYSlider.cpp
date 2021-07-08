//
// Created by jonng on 6/5/2021.
//

#include "TextYSlider.h"

TextYSlider::TextYSlider() {
    setActualRange(0, 300);
    setDisplayedRange( -50,50);
    setDisplayedValue(12);
    setLabelString("Text Y");
    setPosition({50.f,470.f});
    setStartingBarPosition(150.f);
    setSliderLength(450.f);
}

void TextYSlider::reset() {
    setDisplayedValue(12);
}
