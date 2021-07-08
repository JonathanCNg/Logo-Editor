//
// Created by jonng on 5/9/2021.
//

#include "Menu.h"

const std::string Menu::status_conversion[Menu::TOTAL_STATUS_MESSAGE_COUNT] = {"New Project","Open Project","Save Project","Quit","Export as JPG","Export as PNG","Visit Website"};

Menu::Menu() : Menu("[Title]") { }
Menu::Menu(String title) {
    setMenuTitle(title);
    item_list.setIsExpanded(false);
    setPosition({0,0});
    setCharacterSize(17);
    displayed_item.setOutlineThickness(0.f);
    item_list.setOutlineThickness(1.f);
    setStatusMessage(NO_STATUS);
}
void Menu::setMenuTitle(String title) {
    displayed_item.setString(title);
}
void Menu::addItem(StatusMessage itemName) {
    switch (itemName) {
        case NEW_PROJECT:
            item_list.addItem("New Project"); return;
        case OPEN_PROJECT:
            item_list.addItem("Open Project"); return;
        case SAVE_PROJECT:
            item_list.addItem("Save Project"); return;
        case QUIT:
            item_list.addItem("Quit"); return;
        case EXPORT_AS_JPG:
            item_list.addItem("Export as JPG"); return;
        case EXPORT_AS_PNG:
            item_list.addItem("Export as PNG"); return;
        case VISIT_WEBSITE:
            item_list.addItem("Visit Website"); return;
        default:
            exit(16);
    }
}
void Menu::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    //Open/close menu
    if(MouseEvents<sf::RenderWindow>::mouseClicked(window,event) && MouseEvents<Item>::mouseClicked(displayed_item,window) && !item_list.isExpanded()) {
        expand();
        return;
    }

    if (item_list.isExpanded()) {
        //Highlighting
        item_list.addEventHandler(window, event);

        //Selecting
        if(MouseEvents<sf::RenderWindow>::mouseClicked(window,event)) {
            for (ItemList::iterator iter = item_list.begin(); iter != item_list.end(); ++iter) {
                if ((*iter).contains(sf::Mouse::getPosition(window))) {
                    setStatusMessage((*iter).getString());
                }
            }
            item_list.setIsExpanded(false);
        }
        if(MouseEvents<sf::RenderWindow>::mouseReleased(window,event)) {
            for (ItemList::iterator iter = item_list.begin(); iter != item_list.end(); ++iter) {
                if ((*iter).contains(sf::Mouse::getPosition(window))) {
                    setStatusMessage((*iter).getString());
                    item_list.setIsExpanded(false);
                }
            }
        }
    }
    else
        displayed_item.setIsColored(false);
}
void Menu::draw(RenderTarget& target, RenderStates states) const {
    target.draw(displayed_item);
    if(item_list.isExpanded())
        target.draw(item_list);
}
void Menu::setButtonSize(Vector2f size) {
    displayed_item.setSize(size);
}
void Menu::setItemSize(Vector2f size) {
    item_list.setSize(size);
}
void Menu::setPosition(Vector2f position) {
    displayed_item.setPosition(position);
    item_list.setPosition({displayed_item.getGlobalBounds().left + displayed_item.getOutlineThickness(),displayed_item.getGlobalBounds().top + displayed_item.getGlobalBounds().height});
}
void Menu::setCharacterSize(unsigned int size) {
    displayed_item.setCharacterSize(size);
    item_list.setCharacterSize(size);
}
FloatRect Menu::getButtonGlobalBounds() {
    return displayed_item.getGlobalBounds();
}

bool Menu::isExpanded() {
    return item_list.isExpanded();
}

void Menu::expand() {
    item_list.setIsExpanded(true);
    displayed_item.setIsColored(true);
}

void Menu::collapse() {
    item_list.setIsExpanded(false);
}
void Menu::setStatusMessage(Menu::StatusMessage status) {
    status_message = status;
}

Menu::StatusMessage Menu::getStatusMessage() {
    return status_message;
}

Menu::StatusMessage Menu::convertToStatusEnum(std::string statusMessage) {
    for (int i = 0; i < TOTAL_STATUS_MESSAGE_COUNT; ++i) {
        if(Menu::status_conversion[i] == statusMessage)
            return convertToStatusEnum(i);
    }
    exit(19);
}

Menu::StatusMessage Menu::convertToStatusEnum(int statusMessage) {
    switch (statusMessage) {
        case 0: return NEW_PROJECT;
        case 1: return OPEN_PROJECT;
        case 2: return SAVE_PROJECT;
        case 3: return QUIT;
        case 4: return EXPORT_AS_JPG;
        case 5: return EXPORT_AS_PNG;
        case 6: return VISIT_WEBSITE;
        default:
            exit(19);
    }
}

void Menu::setStatusMessage(std::string status) {
    setStatusMessage(convertToStatusEnum(status));
}

void Menu::resetStatusMessage() {
    status_message = NO_STATUS;
}

std::string Menu::convertToStatusString(int statusMessage) {
    return status_conversion[statusMessage];
}
