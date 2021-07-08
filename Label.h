//
// Created by jonng on 4/11/2021.
//

#ifndef TYPINGINSFML_LABEL_H
#define TYPINGINSFML_LABEL_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
class Label : public sf::Text {
public:
    Label();
    Label(std::string labelText);
};


#endif //TYPINGINSFML_LABEL_H
