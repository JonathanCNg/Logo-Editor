//
// Created by jonng on 6/5/2021.
//

#include "TextOpacitySlider.h"

TextOpacitySlider::TextOpacitySlider() {
    setActualRange(0,255);
    setDisplayedRange(0,100);
    setDisplayedValue(100);
    setLabelString("Text Opacity");
    setPosition({50.f,510.f});
    setStartingBarPosition(150.f);
    setSliderLength(450.f);
}

void TextOpacitySlider::reset() {
    setDisplayedValue(100);
}
