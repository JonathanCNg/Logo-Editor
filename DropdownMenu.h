//
// Created by jonng on 5/2/2021.
//

#ifndef TYPINGINSFML_DROPDOWNMENU_H
#define TYPINGINSFML_DROPDOWNMENU_H
#include "Item.h"
#include "ItemList.h"
#include "MouseEvents.h"

class DropdownMenu : public sf::Drawable, public sf::Transformable {
public:
    DropdownMenu();
    void addItem(String itemName);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(RenderTarget& target, RenderStates states) const;
    void setSize(Vector2f size);
    void setPosition(Vector2f position);
    void setCharacterSize(unsigned int size);
    std::string getDisplayedItem();
    void setDisplayedItem(std::string displayedItem);
    void setOutlineThickness(float thickness);
private:
    ItemList item_list;
    Item displayed_item;
    sf::Text arrow;
//    States item_list_states;
//    bool is_expanded;
};


#endif //TYPINGINSFML_DROPDOWNMENU_H
