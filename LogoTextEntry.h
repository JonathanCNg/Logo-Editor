//
// Created by jonng on 5/30/2021.
//

#ifndef FINALPROJECTCS8_LOGOTEXTENTRY_H
#define FINALPROJECTCS8_LOGOTEXTENTRY_H
#include "Label.h"
#include "TextInput.h"

class LogoTextEntry: public sf::Drawable, public sf::Transformable {
public:
    LogoTextEntry();
    void setPosition(sf::Vector2f position);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    std::string getString();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void setBoxSize(sf::Vector2f size);
    bool boxContains(sf::Vector2i position);
    void enable();
    void disable();
    void setString(const std::string& labelString);
    void reset();
private:
    Label the_label;
    TextInput the_text_input;
//    static TextInput the_text_input;
//    static std::string cows;
};


#endif //FINALPROJECTCS8_LOGOTEXTENTRY_H
