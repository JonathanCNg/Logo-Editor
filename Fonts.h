//
// Created by Dave Smith on 2/23/21.
//

#ifndef GUI_FONTS_H
#define GUI_FONTS_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Fonts {
public:
    enum Styles {
        OPEN_SANS, GREAT_VIBES, ARCADE, THE_FLESH, MILKY_NICE,

        //ALWAYS set this to the last value in the enum
        FONT_COUNT};
    static sf::Font& getFont(Styles fontStyle);
private:
    static std::vector<sf::Font> fonts;
    static std::vector<bool> loaded_fonts;

    static void loadFonts();
    static void loadFont(Styles fontStyle);
    static std::string getFontPath(Styles fontStyle);
    static void loadFont(Styles fontStyle, std::string filepath);
};


#endif //GUI_FONTS_H
