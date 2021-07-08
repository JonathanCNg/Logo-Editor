//
// Created by jonng on 12/7/2020.
//

#ifndef FINAL_PROJECT_BUTTON_H
#define FINAL_PROJECT_BUTTON_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "MouseEvents.h"
using namespace sf;
using namespace std;
class Button : public Drawable, public Transformable{
public:
    Button();
    Button(string input, float x, float y, float width, float height);
    void setPosition(sf::Vector2f position);
    void draw (RenderTarget &window, RenderStates states) const override;
    FloatRect getGlobalBounds();
    void setString(std::string aString);
    void setSize(sf::Vector2f size);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
private:
    RectangleShape buttonBackground;
    Text theText;
};


#endif //FINAL_PROJECT_BUTTON_H
