//
// Created by jonng on 4/11/2021.
//

#ifndef TYPINGINSFML_MOUSEEVENTS_H
#define TYPINGINSFML_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>

template <class T>
class MouseEvents {
public:
    static bool mouseClicked(T& object, sf::RenderWindow& aWindow);
    static bool mouseClicked(sf::RenderWindow& window, sf::Event event);
//    static bool mouseDoubleClicked();
//    static bool mouseTripleClicked();
//    static bool draggedOver(T& object, sf::RenderWindow& main_window, sf::Event event);
    static bool hovered(T& object, sf::RenderWindow& window);
    static bool mouseReleased(T& object, sf::RenderWindow& aWindow);
    static bool mouseReleased(sf::RenderWindow& window, sf::Event event);

private:
    static sf::Clock the_clock;
//    static int clicks;
//    static void countClicks(sf::Event event);
};

#include "MouseEvents.cpp"
#endif //TYPINGINSFML_MOUSEEVENTS_H
