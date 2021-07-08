//
// Created by jonng on 5/2/2021.
//

#include "ItemList.h"

ItemList::ItemList() {
//    item_list_states.disableState(States::IS_EXPANDED);
    is_expanded = false;
}
void ItemList::addItem(String itemName) {
    an_item.setString(itemName);
    addBack(an_item);
    if (tail != head) {
        tail->data.setPosition({tail->prev->data.getGlobalBounds().left+an_item.getOutlineThickness(), tail->prev->data.getGlobalBounds().top + tail->prev->data.getGlobalBounds().height});
    }
}
void ItemList::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    //Highlighting
    if (is_expanded) {
        for (Node<Item>* walker = head; walker != nullptr; walker = walker->next)
            walker->data.addEventHandler(window,event);
    }
}
void ItemList::draw(RenderTarget& target, RenderStates states) const {
    if(is_expanded) {
        for (Node<Item>* walker = head; walker != nullptr; walker = walker->next) {
            target.draw(walker->data);
        }
    }
}
void ItemList::setSize(Vector2f size) {
    an_item.setSize(size);
    for (Node<Item>* walker = head; walker != nullptr; walker = walker->next) {
        walker->data.setSize(size);
        if(walker != head) {
            walker->data.setPosition({walker->prev->data.getGlobalBounds().left+an_item.getOutlineThickness(), walker->prev->data.getGlobalBounds().top + walker->prev->data.getGlobalBounds().height});
        }
    }
}
void ItemList::setPosition(Vector2f position) {
    an_item.setPosition(position);
    if (head != nullptr) {
        head->data.setPosition({position.x,position.y+an_item.getOutlineThickness()});
        for (Node<Item>* walker = head; walker != nullptr; walker = walker->next) {
            if (walker != head) {
                walker->data.setPosition({walker->prev->data.getGlobalBounds().left+an_item.getOutlineThickness(), walker->prev->data.getGlobalBounds().top + walker->prev->data.getGlobalBounds().height});
            }
        }
    }
}
void ItemList::setCharacterSize(unsigned int size) {
    an_item.setCharacterSize(size);
    for (Node<Item>* walker = head; walker != nullptr; walker = walker->next) {
        walker->data.setCharacterSize(size);
        walker->data.centerTextInBox();
    }
}

void ItemList::setIsExpanded(bool aBoolean) {
    is_expanded = aBoolean;
}
bool ItemList::isExpanded() const {
    return is_expanded;
}

void ItemList::setOutlineThickness(float thickness) {
    an_item.setOutlineThickness(thickness);
    for (Node<Item>* walker = head; walker != nullptr; walker = walker->next) {
        walker->data.setOutlineThickness(thickness);
    }
}
