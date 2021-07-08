//
// Created by jonng on 4/11/2021.
//

#include "TextInput.h"

TextInput::TextInput() {
    setPosition({10.f,10.f});
    disable();
};

void TextInput::enable() {
    is_enabled = true;
    the_cursor.enable();
    the_typer.enable();
}

void TextInput::disable() {
    is_enabled = false;
    the_cursor.disable();
    the_typer.disable();
}

bool TextInput::isEnabled() {
    return is_enabled;
}

void TextInput::setPosition(Vector2f aVector) {
    the_typer.setPosition({aVector.x + the_box.getGlobalBounds().height/7, aVector.y});
    the_box.setPosition(aVector.x, aVector.y);
    the_cursor.setLeftX(aVector.x + the_box.getGlobalBounds().height/7);
    the_cursor.setTopY(aVector.y);
    the_cursor.setPosition(the_typer.getLastXPos(),the_cursor.getTopY());
}

void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(the_box);
    window.draw(the_typer);
    window.draw(the_cursor);
}

void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    if(MouseEvents<sf::RenderWindow>::mouseClicked(window, event) && MouseEvents<sf::RectangleShape>::mouseClicked(the_box,window))
        enable();
    else if (MouseEvents<sf::RenderWindow>::mouseClicked(window, event))
        disable();

    if (is_enabled) {
        if(event.type == Event::TextEntered) {
            if (event.text.unicode == 13)
                disable();
            else {
                the_typer.addEventHandler(window, event); //Adds and deletes text
            }
        }
    }

    if(getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
        DynamicCursor::enableCursorRequest(sf::Cursor::Text);

//    if(KeyboardShortcuts::isUndo()) {
//        std::cout << "undo!";
//        History::theHistory.pop();
//    }
}

void TextInput::update() {
    if(is_enabled) {
        the_cursor.setPosition({the_typer.getLastXPos(), the_cursor.getTopY()});
        the_cursor.update(); //Allows "blinking"
    }
    while(the_box.getGlobalBounds().left+the_box.getGlobalBounds().width-the_box.getGlobalBounds().height/7 < the_typer.getLastXPos())
        the_typer.popTail();
}

std::string TextInput::getString() {
    return the_typer.getString();
}

void TextInput::setSize(sf::Vector2f size) {
    float scale = static_cast<float>(size.y)/static_cast<float>(the_box.getSize().y);
    the_box.setSize(size);
    the_typer.setCharacterSize(static_cast<unsigned int>(static_cast<float>(the_typer.getCharacterSize())*scale));
    the_cursor.setCharacterSize(static_cast<unsigned int>(static_cast<float>(the_cursor.getCharacterSize())*scale));
}

void TextInput::setOutlineThickness(float thickness) {
    the_box.setOutlineThickness(thickness);
}

void TextInput::setString(std::string aString) {
    the_typer.setString(aString);
}

FloatRect TextInput::getGlobalBounds() {
    return the_box.getGlobalBounds();
}