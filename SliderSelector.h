//
// Created by jonng on 5/30/2021.
//

#ifndef FINALPROJECTCS8_SLIDERSELECTOR_H
#define FINALPROJECTCS8_SLIDERSELECTOR_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Fonts.h"
#include "Label.h"
#include "TextInput.h"
#include "HelperFunctions.h"
#include <assert.h>
#include "DynamicCursor.h"

class SliderSelector : public sf::Drawable, public sf::Transformable {
public:
    SliderSelector();
    void setPosition(sf::Vector2f aCoordinatePair);
    void setLabelString(std::string labelString);
    void addEventHandler(sf::RenderWindow& window, sf::Event anEvent);
    void setActualRange(float minActualValue, float maxActualValue);
    float getActualValue();
    virtual void draw(sf::RenderTarget& targetWindow, sf::RenderStates states) const;
    void setSliderLength(float length);
    void setDisplayedValue(float displayedValue);
    void update();
    void setDisplayedRange(float minDisplayedValue, float maxDisplayedValue);
    float getDisplayedValue();
    void setActualValue(const float& actualValue);
    bool valueBoxContains(sf::Vector2f position);
    void setStartingBarPosition(float spaceForLabel);
private:
    bool circleSelectorClicked, manualBarPositioningEnabled;
    float min_actual_value, max_actual_value, the_actual_value, min_displayed_value, max_displayed_value, space_for_label;
    Label the_label;
    sf::CircleShape the_circle_selector;
    sf::RectangleShape the_slider_bar;
    TextInput the_value_box;
    float convertToActualValue(const float& displayedValue) const;
    float convertToDisplayedValue(const float& actualValue) const;
    bool enableCircle(sf::Vector2f position);
};


#endif //FINALPROJECTCS8_SLIDERSELECTOR_H
