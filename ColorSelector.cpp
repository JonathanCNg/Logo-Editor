//
// Created by jonng on 6/2/2021.
//

#include "ColorSelector.h"

ColorSelector::ColorSelector() {
    //LABEL
    the_label.setString("Color Selector");

    //BUTTONS
    invert_color_button.setString("INVERT");
    color_target = TEXT;
    change_target_button.setString("TEXT");

    //COLOR
    sf::VertexArray temp(sf::TrianglesFan,8);
    color_cube = temp;
    color_cube[0].color = sf::Color::White;
    color_cube[1].color = sf::Color::Yellow;
    color_cube[2].color = sf::Color::Red;
    color_cube[3].color = sf::Color::Magenta;
    color_cube[4].color = sf::Color::Blue;
    color_cube[5].color = sf::Color::Cyan;
    color_cube[6].color = sf::Color::Green;
    color_cube[7].color = sf::Color::Yellow;

    //RING
    ring.setFillColor(sf::Color::Transparent);

    //CONTAINER
    container.setOutlineColor(sf::Color::White);
    container.setOutlineThickness(1.f);
    setContainerColor({55,55,55});

    //CHOOSING
    actively_choosing_color = false;

    //MISC
    setWidth(260.f);
    setPosition({765.f,349.f});
    randomlyAssignColors();
}

void ColorSelector::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(the_label);
    window.draw(container);
    window.draw(color_cube);
    window.draw(ring);
    window.draw(invert_color_button);
    window.draw(change_target_button);
}

float ColorSelector::getRadius() const {
    return radius;
}

void ColorSelector::setRadius(float radius) {
    ColorSelector::radius = radius;
    ring.setRadius(radius*0.85f);
    ring.setOutlineThickness(radius*0.15f);
    setCenterPosition(center_position);
}

const sf::Vector2f &ColorSelector::getCenterPosition() const {
    return center_position;
}

void ColorSelector::setCenterPosition(const sf::Vector2f &centerPosition) {
    ColorSelector::center_position = centerPosition;
    color_cube[0].position = centerPosition;
    color_cube[1].position = sf::Vector2f(centerPosition.x + (float)cos(M_PI_2) * radius, centerPosition.y + (float)sin(M_PI_2) * radius);
    color_cube[2].position = sf::Vector2f(centerPosition.x + (float)cos(M_PI / 6) * radius, centerPosition.y + (float)sin(M_PI / 6) * radius);
    color_cube[3].position = sf::Vector2f(centerPosition.x + (float)cos(-M_PI / 6) * radius, centerPosition.y + (float)sin(-M_PI / 6) * radius);
    color_cube[4].position = sf::Vector2f(centerPosition.x + (float)cos(-M_PI_2) * radius, centerPosition.y + (float)sin(-M_PI_2) * radius);
    color_cube[5].position = sf::Vector2f(centerPosition.x + (float)cos(-M_PI * 5 / 6) * radius, centerPosition.y + (float)sin(-M_PI * 5 / 6) * radius);
    color_cube[6].position = sf::Vector2f(centerPosition.x + (float)cos(M_PI * 5 / 6) * radius, centerPosition.y + (float)sin(M_PI * 5 / 6) * radius);
    color_cube[7].position = sf::Vector2f(centerPosition.x + (float)cos(M_PI_2) * radius, centerPosition.y + (float)sin(M_PI_2) * radius);

    ring.setPosition(center_position.x - radius * 0.85f, center_position.y - radius * 0.85f);
}

void ColorSelector::setDark() {
    color_cube[0].color = sf::Color::Black;
}

void ColorSelector::setLight() {
    color_cube[0].color = sf::Color::White;
}

void ColorSelector::invertBrightness() {
    if (color_cube[0].color == sf::Color::White)
        setDark();
    else
        setLight();
}

void ColorSelector::setContainerColor(sf::Color color) {
    ring.setOutlineColor(color);
    container.setFillColor(color);
}

void ColorSelector::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //BUTTONS
    if(MouseEvents<sf::RenderWindow>::mouseClicked(window, event) && MouseEvents<Button>::mouseClicked(invert_color_button, window))
        invertBrightness();
    invert_color_button.addEventHandler(window, event);
    if(MouseEvents<sf::RenderWindow>::mouseClicked(window, event) && MouseEvents<Button>::mouseClicked(change_target_button, window))
        switchTarget();
    change_target_button.addEventHandler(window,event);

    //CIRCLE
    sf::Vector2i aPosition = sf::Mouse::getPosition(window);
    if(circleContains(aPosition)) {
        DynamicCursor::enableCursorRequest(sf::Cursor::Cross);
        if(MouseEvents<ColorSelector>::mouseClicked(window, event))
            actively_choosing_color = true;
        if(actively_choosing_color && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2u windowSize = window.getSize();
            sf::Texture texture;
            texture.create(windowSize.x, windowSize.y);
            texture.update(window);
            sf::Image screenshot = texture.copyToImage();
            if(color_target == TEXT)
                chosen_color[TEXT] = screenshot.getPixel(aPosition.x, aPosition.y);
            else if (color_target == MIRROR)
                chosen_color[MIRROR] = screenshot.getPixel(aPosition.x, aPosition.y);
            else if (color_target == SCENE)
                chosen_color[SCENE] = screenshot.getPixel(aPosition.x, aPosition.y);
        }
    }
    if(MouseEvents<ColorSelector>::mouseReleased(window, event))
        actively_choosing_color = false;
}

void ColorSelector::setPosition(sf::Vector2f position) {
    the_label.setPosition(position);
    container.setPosition({the_label.getPosition().x,the_label.getPosition().y+the_label.getGlobalBounds().height*2});
    setCenterPosition({container.getGlobalBounds().left + container.getGlobalBounds().width/2, container.getGlobalBounds().top + container.getGlobalBounds().width/2});
    change_target_button.setPosition({container.getGlobalBounds().left + (container.getGlobalBounds().width - invert_color_button.getGlobalBounds().width) / 2 - invert_color_button.getGlobalBounds().width*0.55f, container.getGlobalBounds().top + container.getGlobalBounds().height - invert_color_button.getGlobalBounds().height - (((container.getGlobalBounds().top + container.getGlobalBounds().height - center_position.y - radius*0.85f) - invert_color_button.getGlobalBounds().height)*0.6f)});
    invert_color_button.setPosition({container.getGlobalBounds().left + (container.getGlobalBounds().width - invert_color_button.getGlobalBounds().width) / 2 + invert_color_button.getGlobalBounds().width*0.55f, container.getGlobalBounds().top + container.getGlobalBounds().height - invert_color_button.getGlobalBounds().height - (((container.getGlobalBounds().top + container.getGlobalBounds().height - center_position.y - radius*0.85f) - invert_color_button.getGlobalBounds().height)*0.6f)});
}

void ColorSelector::setWidth(float width) {
    container.setSize({width, width * 1.2f});
    setRadius(width * 0.5f);
    invert_color_button.setSize({container.getGlobalBounds().width * 0.4f, container.getGlobalBounds().height * 0.11f});
    change_target_button.setSize({container.getGlobalBounds().width * 0.4f, container.getGlobalBounds().height * 0.11f});
    setPosition(container.getPosition());
}

bool ColorSelector::circleContains(sf::Vector2i position) {
    double distance = pow(pow((float)position.x - center_position.x, 2) + pow((float)position.y - center_position.y, 2), 0.5);
    return (radius*0.83f - distance >= 0);
}

bool ColorSelector::containerContains(sf::Vector2i position) {
    return container.getGlobalBounds().contains(static_cast<sf::Vector2f>(position));
}

sf::Color ColorSelector::getChosenColor(ColorSelector::ColorTarget target) {
    return chosen_color[target];
}

void ColorSelector::switchTarget() {
    if(color_target == TEXT) {
        color_target = MIRROR;
        change_target_button.setString("MIRROR");
    }
    else if (color_target == MIRROR) {
        color_target = SCENE;
        change_target_button.setString("SCENE");
    }
    else if (color_target == SCENE) {
        color_target = TEXT;
        change_target_button.setString("TEXT");
    }
}

void ColorSelector::randomlyAssignColors() {
    enum Colors {
        RED, GREEN, BLUE, MAGENTA, CYAN, YELLOW, COLOR_COUNT
    };
    sf::Color colors[COLOR_COUNT] = {sf::Color::Red,sf::Color::Green,sf::Color::Blue,sf::Color::Magenta,sf::Color::Cyan,sf::Color::Yellow};
    int colorChoice[TARGET_COUNT];

    colorChoice[TEXT] = rand()%6;
    chosen_color[TEXT] = colors[colorChoice[TEXT]];

    do {
        colorChoice[MIRROR] = rand()%6;
    } while(colorChoice[MIRROR] == colorChoice[TEXT]);
    chosen_color[MIRROR] = colors[colorChoice[MIRROR]];

    do {
        colorChoice[SCENE] = rand()%6;
    } while(colorChoice[SCENE] == colorChoice[TEXT] || colorChoice[SCENE] == colorChoice[MIRROR]);
    chosen_color[SCENE] = colors[colorChoice[SCENE]];
}

void ColorSelector::setTextColor(sf::Color textColor) {
    chosen_color[TEXT] = textColor;
}

void ColorSelector::setMirrorColor(sf::Color mirrorColor) {
    chosen_color[MIRROR] = mirrorColor;
}

void ColorSelector::setSceneColor(sf::Color sceneColor) {
    chosen_color[SCENE] = sceneColor;
}

void ColorSelector::reset() {
    randomlyAssignColors();
}
