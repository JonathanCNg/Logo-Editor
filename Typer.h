//
// Created by jonng on 3/18/2021.
//

#ifndef TYPINGINSFML_TYPER_H
#define TYPINGINSFML_TYPER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LinkedList.h"
#include "TextChar.h"
#include "Fonts.h"
using namespace std;
using namespace sf;
class Typer : public Drawable, public Transformable{
public:
    Typer();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void setPosition(Vector2f startingPoint);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    float getLastXPos();
    void enable();
    void disable();
    int getCharacterSize();
private:
    void setCharacterPosition();
    LinkedList<TextChar> typer_input;
    Vector2f starting_point;
    TextChar a_char;
    bool is_enabled;
public:
    std::string getString();
    void setCharacterSize(unsigned int sizeValue);
    void setString(std::string aString);
    TextChar popTail();
};


#endif //TYPINGINSFML_TYPER_H
