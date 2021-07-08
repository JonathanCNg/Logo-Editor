//
// Created by jonng on 5/30/2021.
//

#ifndef FINALPROJECTCS8_LOGOMAKER_H
#define FINALPROJECTCS8_LOGOMAKER_H
#include <fstream>
#include "TextInput.h"
#include "LogoDemo.h"
#include "LogoMenuBar.h"
#include "LogoTextEntry.h"
#include "DropdownMenu.h"
#include "ColorSelector.h"
#include "FontStyleChooser.h"
#include "FontSizeSlider.h"
#include "TextXSlider.h"
#include "TextYSlider.h"
#include "TextOpacitySlider.h"
#include "MirrorXSlider.h"
#include "MirrorYSlider.h"
#include "MirrorOpacitySlider.h"
#include "MirrorSkewSlider.h"
#include "LogoMakerIcon.h"
#include <ctime>
#include <cstdlib>

class LogoMaker {
public:
    void run();
private:
    sf::RenderWindow main_window;
    LogoMakerIcon logo_maker_icon;
    LogoMenuBar logo_menu_bar;
    LogoTextEntry logo_text_entry;
    LogoDemo logo_demo;
    FontStyleChooser font_style_chooser;
    FontSizeSlider font_size_slider;
    TextXSlider text_x_slider;
    TextYSlider text_y_slider;
    TextOpacitySlider text_opacity_slider;
    MirrorXSlider mirror_x_slider;
    MirrorYSlider mirror_y_slider;
    MirrorOpacitySlider mirror_opacity_slider;
    MirrorSkewSlider mirror_skew_slider;
    ColorSelector color_selector;
    void createSaveFile(const std::string& filePath);
    void loadSaveFile(const std::string& filePath);
    void reset();
    void statusActivity();
};


#endif //FINALPROJECTCS8_LOGOMAKER_H
