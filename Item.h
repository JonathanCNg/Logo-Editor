//
// Created by jonng on 5/2/2021.
//

#ifndef TYPINGINSFML_ITEM_H
#define TYPINGINSFML_ITEM_H
#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "Fonts.h"
#include "MouseEvents.h"
using namespace sf;
using namespace std;

class Item : public Drawable, public Transformable {
public:
    Item();
    void setPosition(Vector2f position);
    void setString(String label);
    virtual void draw (RenderTarget& target, RenderStates states) const;
    FloatRect getGlobalBounds();
    void setSize(Vector2f size);
    float getOutlineThickness();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    bool contains (Vector2i aVector);
    String getString();
    void setCharacterSize(unsigned int size);
    void centerTextInBox();
    void setIsColored(bool aBoolean);
    void setOutlineThickness(float thickness);
private:
    TextBox text_box;
    sf::Text text;
};


#endif //TYPINGINSFML_ITEM_H
