//
// Created by jonng on 5/2/2021.
//

#ifndef TYPINGINSFML_ITEMLIST_H
#define TYPINGINSFML_ITEMLIST_H
#include "Item.h"
#include "LinkedList.h"
class ItemList : public LinkedList<Item>, public Drawable, public Transformable {
public:
    ItemList();
    void addItem(String itemName);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(RenderTarget& target, RenderStates states) const;
    void setSize(Vector2f size);
    void setPosition(Vector2f position);
    void setCharacterSize(unsigned int size);
    void setIsExpanded(bool aBoolean);
    bool isExpanded() const;
    void setOutlineThickness(float thickness);
private:
    Item an_item;
//    States item_list_states;
    bool is_expanded;
};


#endif //TYPINGINSFML_ITEMLIST_H
