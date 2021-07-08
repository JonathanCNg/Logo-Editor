//
// Created by jonng on 6/3/2021.
//

#include "DynamicCursor.h"

bool DynamicCursor::please_enable[13] = {false};
sf::Cursor::Type DynamicCursor::enabled_cursor = sf::Cursor::Arrow;
sf::Cursor DynamicCursor::cursor;
int DynamicCursor::NUM_FONTS = 13;

DynamicCursor::DynamicCursor() {
    resetCursorRequests();
    enabled_cursor = sf::Cursor::Arrow;
}

void DynamicCursor::setCursor(sf::RenderWindow& window) {
    //First checks for priority status cursor requests...
    if(!activateCursor(sf::Cursor::Hand, window)) {
        //...if none, it checks the rest...
        for(int i = 0; i < NUM_FONTS; ++i) {
            if(activateCursor(i, window))
                return;
        }
        //...if none, activates default arrow cursor
        if(enabled_cursor != sf::Cursor::Arrow && cursor.loadFromSystem(sf::Cursor::Arrow)) {
            window.setMouseCursor(cursor);
            enabled_cursor = convertToCursorType(sf::Cursor::Arrow);
        }
    }
}

void DynamicCursor::enableCursorRequest(sf::Cursor::Type cursorType) {
    please_enable[cursorType] = true;
}

void DynamicCursor::resetCursorRequests() {
    for (int i = 0; i < NUM_FONTS; ++i) {
        please_enable[i] = false;
    }
}

sf::Cursor::Type DynamicCursor::convertToCursorType(int anInt) {
    assert(anInt >= 0 && anInt < NUM_FONTS);
    switch(anInt) {
        case 0: return sf::Cursor::Arrow;
        case 1: return sf::Cursor::ArrowWait;
        case 2: return sf::Cursor::Wait;
        case 3: return sf::Cursor::Text;
        case 4: return sf::Cursor::Hand;
        case 5: return sf::Cursor::SizeHorizontal;
        case 6: return sf::Cursor::SizeVertical;
        case 7: return sf::Cursor::SizeTopLeftBottomRight;
        case 8: return sf::Cursor::SizeBottomLeftTopRight;
        case 9: return sf::Cursor::SizeAll;
        case 10: return sf::Cursor::Cross;
        case 11: return sf::Cursor::Help;
        case 12: return sf::Cursor::NotAllowed;
    }
}

bool DynamicCursor::activateCursor(int cursorType, sf::RenderWindow &window) {
    if(please_enable[cursorType] && cursor.loadFromSystem(convertToCursorType(cursorType))) {
        window.setMouseCursor(cursor);
        enabled_cursor = convertToCursorType(cursorType);
        return true;
    }
    return false;
}

