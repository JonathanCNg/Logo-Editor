//
// Created by jonng on 4/11/2021.
//

#ifndef TYPINGINSFML_INSERTIONPOINTCURSOR_H
#define TYPINGINSFML_INSERTIONPOINTCURSOR_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"

class InsertionPointCursor : public sf::Text {
public:
    InsertionPointCursor();
    void enable();
    void disable();
    void update();
    float getLeftX() const;
    void setLeftX(float leftX);
    float getTopY() const;
    void setTopY(float topY);

private:
    sf::Clock the_clock;
    float top_y;
    float left_x;
    bool is_enabled;
};


#endif //TYPINGINSFML_INSERTIONPOINTCURSOR_H
