//
// Created by jonng on 3/18/2021.
//

#include "Typer.h"

Typer::Typer() {
    setPosition({10.f,0.f});
    a_char.setFont(Fonts::getFont(Fonts::MILKY_NICE));
    a_char.setFillColor(sf::Color::White);
    a_char.setCharacterSize(40);
    disable();
}

void Typer::addEventHandler(sf::RenderWindow& window, sf::Event anEvent) {
    if(is_enabled) {
        if (anEvent.type == Event::TextEntered) {
//            History::theHistory.push(typer_input);
            if (anEvent.text.unicode >= 32 && anEvent.text.unicode <= 126) {
                a_char.setString(static_cast<char>(anEvent.text.unicode));
                typer_input.addBack(a_char);
                setCharacterPosition();
            }
            else if (anEvent.text.unicode == 8) {
                if (!typer_input.isEmpty()) {
                        typer_input.popTail();
                }
            }
        }
    }
}

void Typer::setPosition(Vector2f startingPoint) {
    starting_point = startingPoint;
    if (typer_input.head != nullptr) {
        typer_input.head->data.setPosition(starting_point);
        if (typer_input.head != typer_input.tail)
            for (Node<TextChar>* walker = typer_input.head->next; walker != nullptr; walker = walker->next) {
                walker->data.setPosition(walker->prev->data.getPosition().x + walker->prev->data.getGlobalBounds().width + walker->prev->data.getLetterSpacing(), starting_point.y);
            }
    }
}

void Typer::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    for (Node<TextChar>* walker = typer_input.head; walker != nullptr; walker = walker->next) {
        window.draw(walker->data);
    }
}

void Typer::setCharacterPosition() {
    if ((typer_input.head != nullptr) && (typer_input.head == typer_input.tail)) {
        typer_input.tail->data.setPosition(starting_point);
    }
    else {
        typer_input.tail->data.setPosition(typer_input.tail->prev->data.getPosition().x + typer_input.tail->prev->data.getGlobalBounds().width + typer_input.tail->prev->data.getLetterSpacing(), starting_point.y);
    }
}

float Typer::getLastXPos() {
    if (typer_input.head != nullptr)
        return typer_input.tail->data.getGlobalBounds().left + typer_input.tail->data.getGlobalBounds().width;
    else
        return starting_point.x;
}

void Typer::enable() {
    is_enabled = true;
}

void Typer::disable() {
    is_enabled = false;
}

int Typer::getCharacterSize() {
    return a_char.getCharacterSize();
}

std::string Typer::getString() {
    std::string temp("");
    for (Node<TextChar>* walker = typer_input.head; walker != nullptr; walker = walker->next) {
        temp += walker->data.getString();
    }
    return temp;
}

void Typer::setCharacterSize(unsigned int sizeValue) {
    a_char.setCharacterSize(sizeValue);
    for (Node<TextChar>* walker = typer_input.head; walker != nullptr; walker = walker->next) {
        walker->data.setCharacterSize(sizeValue);
    }
}

void Typer::setString(std::string aString) {

//    if(typer_input.head != nullptr) {
//        for (Node<TextChar>* walker = typer_input.head->next; walker != nullptr; walker = walker->next) {
//            typer_input.popHead();
//        }
//        if(typer_input.head == typer_input.tail)
//            typer_input.popHead();
//    }
    typer_input.clear();
    for(int i = 0; i < aString.length() && i < 100; ++i) {
        a_char.setString(aString[i]);
        typer_input.addBack(a_char);
        setCharacterPosition();
    }
}

TextChar Typer::popTail() {
    return typer_input.popTail();
}
