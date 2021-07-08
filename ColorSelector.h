//
// Created by jonng on 6/2/2021.
//

#ifndef FINALPROJECTCS8_COLORSELECTOR_H
#define FINALPROJECTCS8_COLORSELECTOR_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Button.h"
#include "DynamicCursor.h"
#include "Label.h"
class ColorSelector : public sf::Drawable, public sf::Transformable {
public:
    enum ColorTarget {
        TEXT, MIRROR, SCENE,
        TARGET_COUNT
    };
    ColorSelector();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    float getRadius() const;
    const sf::Vector2f &getCenterPosition() const;
    void setContainerColor(sf::Color color);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
//    void enable();
//    void disable();
//    bool isEnabled() const;
    void setPosition(sf::Vector2f position);
    void setWidth(float width);
    bool circleContains(sf::Vector2i position);
    bool containerContains(sf::Vector2i position);
    sf::Color getChosenColor(ColorTarget target);
    void switchTarget();
    void setTextColor(sf::Color textColor);
    void setMirrorColor(sf::Color mirrorColor);
    void setSceneColor(sf::Color sceneColor);
    void reset();
private:
    void setDark();
    void setLight();
    void invertBrightness();
    void setRadius(float radius);
    void setCenterPosition(const sf::Vector2f &centerPosition);
    void randomlyAssignColors();
    Label the_label;
    sf::RectangleShape container;
    sf::CircleShape ring;
    sf::VertexArray color_cube;
    Button change_target_button, invert_color_button;
    float radius;
    sf::Vector2f center_position;
//    bool is_enabled;
    bool actively_choosing_color;
    sf::Color chosen_color[TARGET_COUNT];
    ColorTarget color_target;
};
#endif //FINALPROJECTCS8_COLORSELECTOR_H
