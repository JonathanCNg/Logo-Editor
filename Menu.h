//
// Created by jonng on 5/9/2021.
//

#ifndef TYPINGINSFML_MENU_H
#define TYPINGINSFML_MENU_H
#include "ItemList.h"

class Menu : public sf::Drawable, public sf::Transformable {
public:
    enum StatusMessage {
        NEW_PROJECT, OPEN_PROJECT, SAVE_PROJECT, QUIT,
        EXPORT_AS_JPG, EXPORT_AS_PNG,
        VISIT_WEBSITE, NO_STATUS,

        TOTAL_STATUS_MESSAGE_COUNT
    };
    Menu();
    Menu(String title);
    void setMenuTitle(String title);
    void addItem(StatusMessage itemName);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(RenderTarget& target, RenderStates states) const;
    void setButtonSize(Vector2f size);
    void setItemSize(Vector2f size);
    void setPosition(Vector2f position);
    void setCharacterSize(unsigned int size);
    FloatRect getButtonGlobalBounds();
    bool isExpanded();
    void expand();
    void collapse();
    Menu::StatusMessage getStatusMessage();
    static Menu::StatusMessage convertToStatusEnum(std::string statusMessage);
    const static int ACTIVE_STATUS_MESSAGE_COUNT = TOTAL_STATUS_MESSAGE_COUNT-1;
    static StatusMessage convertToStatusEnum(int statusMessage);
    void resetStatusMessage();
    static std::string convertToStatusString(int statusMessage);
private:
    void setStatusMessage(Menu::StatusMessage status);
    void setStatusMessage(std::string status);
    ItemList item_list;
    Item displayed_item;
    StatusMessage status_message;
    const static std::string status_conversion[TOTAL_STATUS_MESSAGE_COUNT];
};


#endif //TYPINGINSFML_MENU_H
