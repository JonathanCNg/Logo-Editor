//
// Created by jonng on 12/7/2020.
//

#include "Button.h"

Button::Button() : Button("Text",0.f,0.f,100.f,50.f){ }

Button::Button(string input, float x, float y, float width, float height) {
    buttonBackground.setFillColor(sf::Color::White);
    setSize({width,height});
    setPosition({x,y});
    theText.setFont(Fonts::getFont(Fonts::MILKY_NICE));
    setString(input);
    theText.setFillColor(Color::Black);
//    theText.setCharacterSize(25);
//    theText.setOrigin(theText.getGlobalBounds().width/2, theText.getGlobalBounds().height/2);
//    theText.setPosition(buttonBackground.getGlobalBounds().left + buttonBackground.getGlobalBounds().width/2, buttonBackground.getGlobalBounds().top + buttonBackground.getGlobalBounds().height/2-5);
}

void Button::setPosition(sf::Vector2f position) {
    buttonBackground.setPosition(position);
    theText.setPosition({buttonBackground.getGlobalBounds().left+(buttonBackground.getGlobalBounds().width-theText.getGlobalBounds().width)/2, buttonBackground.getGlobalBounds().top+(buttonBackground.getGlobalBounds().height-theText.getGlobalBounds().height)/4});
}
void Button::draw (RenderTarget &window, RenderStates states) const {
    window.draw(buttonBackground);
    window.draw(theText);
}
FloatRect Button::getGlobalBounds() {
    return buttonBackground.getGlobalBounds();
}

void Button::setString(std::string aString) {
    theText.setString(aString);
    setPosition(buttonBackground.getPosition());
//    theText.setPosition({buttonBackground.getGlobalBounds().left+(buttonBackground.getGlobalBounds().width-theText.getGlobalBounds().width)/2, buttonBackground.getGlobalBounds().top+(buttonBackground.getGlobalBounds().height-theText.getGlobalBounds().height)/4});
}

void Button::setSize(sf::Vector2f size) {
    buttonBackground.setSize(size);
    theText.setCharacterSize((int)(buttonBackground.getSize().y*0.7));
    setPosition(buttonBackground.getPosition());

//    theText.setPosition({buttonBackground.getGlobalBounds().left+(buttonBackground.getGlobalBounds().width-theText.getGlobalBounds().width)/2, buttonBackground.getGlobalBounds().top+(buttonBackground.getGlobalBounds().height-theText.getGlobalBounds().height)/4});
}

void Button::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::mouseClicked(buttonBackground,window)) {
        buttonBackground.setFillColor({100,100,255});
        theText.setFillColor({200,200,255});
    }
    else if (MouseEvents<sf::RectangleShape>::hovered(buttonBackground,window)) {
        buttonBackground.setFillColor({200,200,255});
        theText.setFillColor({33,33,33});
    }
    else {
        buttonBackground.setFillColor(sf::Color::White);
        theText.setFillColor({33,33,33});
    }
}


