//
// Created by jonng on 4/11/2021.
//

#ifndef TYPINGINSFML_TEXTINPUT_H
#define TYPINGINSFML_TEXTINPUT_H
#include "Typer.h"
#include "TextBox.h"
#include "Label.h"
#include "InsertionPointCursor.h"
#include "MouseEvents.h"
#include "DynamicCursor.h"

class TextInput : public sf::Drawable, public sf::Transformable{
    /*
     * This is TextInput.cpp from my previous project, stripped down to exclude the label and newline functionality. It adds a character cap.
     */
public:
    TextInput();
private:
    TextBox the_box;
    Typer the_typer;
    InsertionPointCursor the_cursor;
    bool is_enabled;
public:
    void enable();
    void disable();
    bool isEnabled();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void setPosition(Vector2f aVector);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
    std::string getString();
    void setSize(sf::Vector2f size);
    void setOutlineThickness(float thickness);
    void setString(std::string aString);
    FloatRect getGlobalBounds();
};


#endif //TYPINGINSFML_TEXTINPUT_H
