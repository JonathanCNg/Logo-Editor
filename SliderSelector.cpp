//
// Created by jonng on 5/30/2021.
//

#include "SliderSelector.h"

SliderSelector::SliderSelector() {
    //LABEL
    the_label.setCharacterSize(17);
    //CIRCLE SELECTOR
    circleSelectorClicked = false;
    the_circle_selector.setRadius(5.f);
    the_circle_selector.setOrigin(the_circle_selector.getGlobalBounds().left + the_circle_selector.getGlobalBounds().width/2, the_circle_selector.getGlobalBounds().top + the_circle_selector.getGlobalBounds().height/2);
    //SLIDER BAR
    manualBarPositioningEnabled = false;
    the_slider_bar.setSize({200.f,2.f});
    //VALUE
    setActualRange(0,100);
    setDisplayedRange(0,200);
    setDisplayedValue(100);

    the_value_box.setSize({53.f, 20.f});
    the_value_box.setOutlineThickness(1.f);

    setPosition({0,0});
}

void SliderSelector::setPosition(sf::Vector2f aCoordinatePair) {
    the_label.setPosition({aCoordinatePair.x,aCoordinatePair.y});
    if(manualBarPositioningEnabled) {
        the_slider_bar.setPosition({aCoordinatePair.x+space_for_label,aCoordinatePair.y+the_label.getGlobalBounds().height/2+3.f});
    }
    else {
        the_slider_bar.setPosition({aCoordinatePair.x+the_label.getGlobalBounds().width+20.f,aCoordinatePair.y+the_label.getGlobalBounds().height/2+3.f});
    }
    the_circle_selector.setPosition({the_slider_bar.getPosition().x,the_slider_bar.getPosition().y+the_slider_bar.getGlobalBounds().height/2});
    the_value_box.setPosition({the_slider_bar.getGlobalBounds().left + the_slider_bar.getGlobalBounds().width + 13.f, aCoordinatePair.y + 2.f});
}

void SliderSelector::setLabelString(std::string labelString) {
    the_label.setString(labelString);
}

void SliderSelector::addEventHandler(sf::RenderWindow &window, sf::Event anEvent) {
    the_value_box.addEventHandler(window, anEvent);

    if(MouseEvents<sf::RenderWindow>::mouseClicked(window, anEvent) && enableCircle((sf::Vector2f)sf::Mouse::getPosition(window))) {
        the_value_box.disable();
        circleSelectorClicked = true;
    }
    if(circleSelectorClicked) {
        DynamicCursor::enableCursorRequest(sf::Cursor::Hand);
        if (static_cast<float>(sf::Mouse::getPosition(window).x) > the_slider_bar.getGlobalBounds().left+the_slider_bar.getGlobalBounds().width) {
            the_circle_selector.setPosition({static_cast<float>(the_slider_bar.getGlobalBounds().left+the_slider_bar.getGlobalBounds().width), the_circle_selector.getPosition().y});
        }
        else if (static_cast<float>(sf::Mouse::getPosition(window).x) < the_slider_bar.getGlobalBounds().left) {
            the_circle_selector.setPosition({static_cast<float>(the_slider_bar.getGlobalBounds().left), the_circle_selector.getPosition().y});
        }
        else
            the_circle_selector.setPosition({static_cast<float>(sf::Mouse::getPosition(window).x), the_circle_selector.getPosition().y});

        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            circleSelectorClicked = false;
        }
        setActualValue((the_circle_selector.getPosition().x - the_slider_bar.getGlobalBounds().left) / the_slider_bar.getGlobalBounds().width * (max_actual_value - min_actual_value) + min_actual_value);
        the_value_box.setString(to_string(convertToDisplayedValue(the_actual_value)));
    }
    if(the_circle_selector.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window))) {
        DynamicCursor::enableCursorRequest(sf::Cursor::Hand);
    }
}

void SliderSelector::setActualRange(float minValue, float maxValue) {
    assert(minValue < maxValue);
    min_actual_value = minValue;
    max_actual_value = maxValue;
}

float SliderSelector::getActualValue() {
    return the_actual_value;
}

void SliderSelector::draw(sf::RenderTarget &targetWindow, sf::RenderStates states) const {
    targetWindow.draw(the_label);
    targetWindow.draw(the_circle_selector);
    targetWindow.draw(the_slider_bar);
    targetWindow.draw(the_value_box);
}

void SliderSelector::setSliderLength(float length) {
    the_slider_bar.setSize({length, the_slider_bar.getSize().y});
    setPosition(the_label.getPosition());
}

void SliderSelector::setDisplayedValue(float displayedValue) {
    float convertedValue = convertToActualValue(displayedValue);
    setActualValue(convertedValue);
}

void SliderSelector::update() {
    the_circle_selector.setPosition({(the_actual_value - min_actual_value) / (max_actual_value - min_actual_value) * the_slider_bar.getGlobalBounds().width + the_slider_bar.getGlobalBounds().left, the_circle_selector.getPosition().y});
    if(!the_value_box.isEnabled()) {
        if(HelperFunctions::isNumber(the_value_box.getString())) {
            float input = stof(the_value_box.getString());
            setDisplayedValue(input);
        }
        else {
            setActualValue(the_actual_value);
        }
    }
    the_value_box.update();
}

void SliderSelector::setDisplayedRange(float minDisplayedValue, float maxDisplayedValue) {
    assert(minDisplayedValue < maxDisplayedValue);
    min_displayed_value = minDisplayedValue;
    max_displayed_value = maxDisplayedValue;
}

float SliderSelector::convertToActualValue(const float &displayedValue) const {
    return (displayedValue-min_displayed_value)/(max_displayed_value-min_displayed_value)*(max_actual_value-min_actual_value)+min_actual_value;
}

float SliderSelector::convertToDisplayedValue(const float &actualValue) const {
    return (actualValue-min_actual_value)/(max_actual_value-min_actual_value)*(max_displayed_value-min_displayed_value)+min_displayed_value;
}

float SliderSelector::getDisplayedValue() {
    return convertToDisplayedValue(the_actual_value);
}

void SliderSelector::setActualValue(const float& actualValue) {
    if (actualValue >= max_actual_value)
        the_actual_value = max_actual_value;
    else if (actualValue <= min_actual_value)
        the_actual_value = min_actual_value;
    else
        the_actual_value = actualValue;

    float convertedValue = convertToDisplayedValue(the_actual_value);
    std::string aString = to_string(convertedValue);
    the_value_box.setString(aString);
}

bool SliderSelector::valueBoxContains(sf::Vector2f position) {
    return (the_value_box.getGlobalBounds().contains(position));
}

bool SliderSelector::enableCircle(sf::Vector2f position) {
    FloatRect acceptableArea = the_slider_bar.getGlobalBounds();
    acceptableArea.top -= the_circle_selector.getRadius();
    acceptableArea.height += 2*the_circle_selector.getRadius();
    acceptableArea.left -= the_circle_selector.getRadius();
    acceptableArea.width += 2*the_circle_selector.getRadius();
    return acceptableArea.contains(position);
}

void SliderSelector::setStartingBarPosition(float spaceForLabel) {
    manualBarPositioningEnabled = true;
    space_for_label = spaceForLabel;
    setPosition(the_label.getPosition());
}