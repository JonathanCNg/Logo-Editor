//
// Created by jonng on 6/3/2021.
//

#ifndef FINALPROJECTCS8_DYNAMICCURSOR_H
#define FINALPROJECTCS8_DYNAMICCURSOR_H
#include <SFML/Graphics.hpp>
#include <assert.h>

class DynamicCursor {
public:
    DynamicCursor();
    static void setCursor(sf::RenderWindow& window);
    static void enableCursorRequest(sf::Cursor::Type cursorType);
    static void resetCursorRequests();
private:
    static sf::Cursor::Type convertToCursorType(int anInt);
    static bool please_enable[13];
    static sf::Cursor::Type enabled_cursor;
    static sf::Cursor cursor;
    static int NUM_FONTS;
    static bool activateCursor(int cursorType, sf::RenderWindow& window);
};


#endif //FINALPROJECTCS8_DYNAMICCURSOR_H
