//
// Created by jonng on 4/11/2021.
//

#ifndef TYPINGINSFML_TEXTCHAR_H
#define TYPINGINSFML_TEXTCHAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
class TextChar : public sf::Text{
public:
    TextChar();
    TextChar(std::string aString);
    TextChar(char aChar);
    friend bool operator == (const TextChar& char1, const TextChar& char2);
    friend std::ostream& operator << (std::ostream& outs, const TextChar& aTextChar);
};


#endif //TYPINGINSFML_TEXTCHAR_H
