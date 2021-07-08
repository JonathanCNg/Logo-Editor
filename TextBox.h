//
// Created by jonng on 4/11/2021.
//

#ifndef TYPINGINSFML_TEXTBOX_H
#define TYPINGINSFML_TEXTBOX_H
#include <SFML/Graphics.hpp>

class TextBox : public sf::RectangleShape{
public:
    TextBox();
    bool contains(sf::Vector2i aVector);
};


#endif //TYPINGINSFML_TEXTBOX_H
