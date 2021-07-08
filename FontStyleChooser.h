//
// Created by jonng on 6/5/2021.
//

#ifndef FINALPROJECTCS8_FONTSTYLECHOOSER_H
#define FINALPROJECTCS8_FONTSTYLECHOOSER_H
#include "DropdownMenu.h"
#include "Label.h"
class FontStyleChooser : public sf::Drawable, public sf::Transformable {
public:
    FontStyleChooser();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void setPosition(sf::Vector2f position);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    std::string getFontChoice();
    void setFontChoice(const std::string& fontChoice);
    void reset();
private:
    Label font_label;
    DropdownMenu font_dropdown_menu;
};


#endif //FINALPROJECTCS8_FONTSTYLECHOOSER_H
