//
// Created by Dave Smith on 2/23/21.
//

#include "Fonts.h"
std::vector<sf::Font> Fonts::fonts(Fonts::FONT_COUNT, sf::Font());
std::vector<bool> Fonts::loaded_fonts(Fonts::FONT_COUNT, false);

sf::Font& Fonts::getFont(Styles fontStyle)
{
    loadFont(fontStyle);
    return fonts[fontStyle];
}

void Fonts::loadFonts() {
    loadFont(OPEN_SANS, "../FontLibrary/OpenSans-Bold.ttf");
}

void Fonts::loadFont(Styles fontStyle, std::string filepath)
{
    if(!loaded_fonts[fontStyle])
    {
        if(!fonts[fontStyle].loadFromFile(filepath))
        {
            loaded_fonts[fontStyle] = true;
        }
    }
}

std::string Fonts::getFontPath(Fonts::Styles fontStyle)
{
    switch(fontStyle)
    {
        case OPEN_SANS: return "../FontLibrary/OpenSans-Bold.ttf";
        case GREAT_VIBES: return "../FontLibrary/GreatVibes-Regular.ttf";
        case ARCADE: return "../FontLibrary/Arcade.ttf";
        case THE_FLESH: return "../FontLibrary/The Flesh.ttf";
        case MILKY_NICE: return "../FontLibrary/MilkyNice.ttf";
    }
}

void Fonts::loadFont(Fonts::Styles fontStyle)
{
    loadFont(fontStyle, getFontPath(fontStyle));
}
