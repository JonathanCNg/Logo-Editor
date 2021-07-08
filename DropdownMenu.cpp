//
// Created by jonng on 5/2/2021.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu() {
    item_list.setIsExpanded(false);
    setPosition({0,0});
    setCharacterSize(20);
    arrow.setString("V");
    arrow.setFont(Fonts::getFont(Fonts::MILKY_NICE));
    arrow.setScale(1,0.4f);
    arrow.setCharacterSize(25);
    arrow.setFillColor(sf::Color::White);
}
void DropdownMenu::addItem(String itemName) {
    item_list.addItem(itemName);
}
void DropdownMenu::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    //Open/close menu
    if(MouseEvents<sf::RenderWindow>::mouseClicked(window,event) && MouseEvents<Item>::mouseClicked(displayed_item,window) && !item_list.isExpanded()) {
        item_list.setIsExpanded(true);
        return;
    }

    if (item_list.isExpanded()) {
        //Highlighting
        item_list.addEventHandler(window, event);

        //Selecting
        if(MouseEvents<sf::RenderWindow>::mouseClicked(window,event)) {
            for (ItemList::iterator iter = item_list.begin(); iter != item_list.end(); ++iter) {
                if ((*iter).contains(sf::Mouse::getPosition(window))) {
                    displayed_item.setString((*iter).getString());
                }
            }
            item_list.setIsExpanded(false);
        }
        if(MouseEvents<sf::RenderWindow>::mouseReleased(window,event)) {
            for (ItemList::iterator iter = item_list.begin(); iter != item_list.end(); ++iter) {
                if ((*iter).contains(sf::Mouse::getPosition(window))) {
                    displayed_item.setString((*iter).getString());
                    item_list.setIsExpanded(false);
                }
            }
        }
    }
}
void DropdownMenu::draw(RenderTarget& target, RenderStates states) const {
    target.draw(displayed_item);
    if(item_list.isExpanded())
        target.draw(item_list);
    target.draw(arrow);
}
void DropdownMenu::setSize(Vector2f size) {
    displayed_item.setSize(size);
    item_list.setSize(size);
}
void DropdownMenu::setPosition(Vector2f position) {
    displayed_item.setPosition(position);
    arrow.setPosition({position.x+displayed_item.getGlobalBounds().width-arrow.getGlobalBounds().width-10.f,position.y+(displayed_item.getGlobalBounds().height-arrow.getGlobalBounds().height)/2-4.f});
    item_list.setPosition({displayed_item.getGlobalBounds().left + displayed_item.getOutlineThickness(),displayed_item.getGlobalBounds().top + displayed_item.getGlobalBounds().height});
}
void DropdownMenu::setCharacterSize(unsigned int size) {
    displayed_item.setCharacterSize(size);
    item_list.setCharacterSize(size);
}

std::string DropdownMenu::getDisplayedItem() {
    return displayed_item.getString();
}

void DropdownMenu::setDisplayedItem(std::string displayedItem) {
    displayed_item.setString(displayedItem);
}

void DropdownMenu::setOutlineThickness(float thickness) {
    displayed_item.setOutlineThickness(thickness);
    item_list.setOutlineThickness(thickness);
}
