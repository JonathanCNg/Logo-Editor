//
// Created by jonng on 5/9/2021.
//

#ifndef TYPINGINSFML_MENUBAR_H
#define TYPINGINSFML_MENUBAR_H
#include "Menu.h"

class MenuBar : public LinkedList<Menu>, public sf::Drawable, public sf::Transformable {
public:

    MenuBar();
    void addMenu(Menu aMenu);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(RenderTarget& target, RenderStates states) const;
    void setHeight(float height);
    void resetStatusMessage();
    Menu::StatusMessage getStatusMessage();
//    void update();
private:
    bool is_active;
    sf::RectangleShape the_bar;
    Menu::StatusMessage status_message;
};


#endif //TYPINGINSFML_MENUBAR_H
