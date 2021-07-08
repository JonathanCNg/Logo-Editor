//
// Created by jonng on 5/9/2021.
//

#include "MenuBar.h"

MenuBar::MenuBar() {
    is_active = false;
    the_bar.setFillColor({66,66,66});
    the_bar.setPosition({0,0});
    the_bar.setSize({2000.f,30.f});
    the_bar.setOutlineThickness(1.f);
    the_bar.setOutlineColor(sf::Color::White);
    status_message = Menu::NO_STATUS;
}
void MenuBar::addMenu(Menu aMenu) {
    addBack(aMenu);
    if (head == tail) {
        head->data.setPosition({0,0});
    }
    else {
        tail->data.setPosition({tail->prev->data.getButtonGlobalBounds().left + tail->prev->data.getButtonGlobalBounds().width, 0});
    }
}
void MenuBar::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    is_active = false;
    Node<Menu>* activeMenu;

    //Checks if any menus are open & also reads statuses
    for (Node<Menu>* walker = head; walker != nullptr; walker = walker->next) {
        if(walker->data.isExpanded()) {
            is_active = true;
            activeMenu = walker;
        }
        if (walker->data.getStatusMessage() < Menu::ACTIVE_STATUS_MESSAGE_COUNT)
            status_message = walker->data.getStatusMessage();
    }

    //Allows switching to a different menu by hovering
    for (Node<Menu>* walker = head; walker != nullptr; walker = walker->next) {
        //Allows normal selecting and highlighting activity
        walker->data.addEventHandler(window, event);

        if(is_active && walker != activeMenu && walker->data.getButtonGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window))) {
            activeMenu = walker;
            for (Node<Menu>* walker2 = head; walker2 != nullptr; walker2 = walker2->next) {
                if(walker2 == activeMenu)
                    walker2->data.expand();
                else
                    walker2->data.collapse();
            }
        }
    }
}
void MenuBar::draw(RenderTarget& target, RenderStates states) const {
    target.draw(the_bar);
    for (Node<Menu>* walker = head; walker != nullptr; walker = walker->next) {
        target.draw(walker->data);
    }
}

void MenuBar::setHeight(float height) {
    for (Node<Menu>* walker = head; walker != nullptr; walker = walker->next) {
        walker->data.setButtonSize({walker->data.getButtonGlobalBounds().width,height});
    }
    the_bar.setSize({the_bar.getSize().x,height});
}

void MenuBar::resetStatusMessage() {
    status_message = Menu::NO_STATUS;
    for (Node<Menu>* walker = head; walker != nullptr; walker = walker->next) {
        walker->data.resetStatusMessage();
    }
}

Menu::StatusMessage MenuBar::getStatusMessage() {
    return status_message;
}

//void MenuBar::update() {
//
//}


