//
// Created by jonng on 6/5/2021.
//

#include "TextXSlider.h"

TextXSlider::TextXSlider() {
    setActualRange(0, 665);
    setDisplayedRange(-100,100);
    setDisplayedValue(0);
    setLabelString("Text X");
    setPosition({50.f,430.f});
    setStartingBarPosition(150.f);
    setSliderLength(450.f);
}

void TextXSlider::reset() {
    setDisplayedValue(0);
}
