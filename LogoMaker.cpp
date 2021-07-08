//
// Created by jonng on 5/30/2021.
//
#include "LogoMaker.h"

void LogoMaker::run() {
    main_window.create({1080, 720}, "Logo Maker");
    main_window.setFramerateLimit(60);
    main_window.setIcon(logo_maker_icon.getSize().x, logo_maker_icon.getSize().y, logo_maker_icon.getPixelsPtr());
    reset();
    
    while(main_window.isOpen()) {
        sf::Event anEvent;
        while(main_window.pollEvent(anEvent)) {
            if(anEvent.type == sf::Event::Closed)
                main_window.close();


            //EVENT HANDLERS || objects.addEventHandler(main_window,anEvent);
            logo_menu_bar.addEventHandler(main_window, anEvent);
            logo_text_entry.addEventHandler(main_window, anEvent);
            font_style_chooser.addEventHandler(main_window, anEvent);
            text_opacity_slider.addEventHandler(main_window, anEvent);
            mirror_opacity_slider.addEventHandler(main_window, anEvent);
            text_x_slider.addEventHandler(main_window, anEvent);
            text_y_slider.addEventHandler(main_window, anEvent);
            mirror_x_slider.addEventHandler(main_window, anEvent);
            mirror_y_slider.addEventHandler(main_window, anEvent);
            font_size_slider.addEventHandler(main_window, anEvent);
            mirror_skew_slider.addEventHandler(main_window, anEvent);
            color_selector.addEventHandler(main_window, anEvent);
            //EVENT HANDLERS ^^


            DynamicCursor::setCursor(main_window);
            DynamicCursor::resetCursorRequests();
        }


        //UPDATE FUNCTIONS || objects.update();
        logo_text_entry.update();
        text_opacity_slider.update();
        mirror_opacity_slider.update();
        text_x_slider.update();
        text_y_slider.update();
        mirror_x_slider.update();
        mirror_y_slider.update();
        font_size_slider.update();
        mirror_skew_slider.update();
        //UPDATE FUNCTIONS ^^

        //SET LOGO vv
        logo_demo.setString(logo_text_entry.getString());
        logo_demo.setFontSize((unsigned int)font_size_slider.getActualValue());
        logo_demo.setMirrorSkew(mirror_skew_slider.getActualValue());
        logo_demo.setFont(font_style_chooser.getFontChoice());
        logo_demo.setTextColor(color_selector.getChosenColor(ColorSelector::TEXT));
        logo_demo.setMirrorColor(color_selector.getChosenColor(ColorSelector::MIRROR));
        logo_demo.setTextOpacity((sf::Uint8) text_opacity_slider.getActualValue());
        logo_demo.setMirrorOpacity((sf::Uint8) mirror_opacity_slider.getActualValue());
        logo_demo.setSceneColor(color_selector.getChosenColor(ColorSelector::SCENE));
        logo_demo.setTextPositionFromBottomLeft({text_x_slider.getActualValue() - logo_demo.getTextGlobalBounds().width / 2,
                                                 text_y_slider.getActualValue() + logo_demo.getTextGlobalBounds().height / 2});
        logo_demo.setMirrorPositionFromBottomLeft(
                {mirror_x_slider.getActualValue() - logo_demo.getMirrorGlobalBounds().width / 2,
                 mirror_y_slider.getActualValue() + logo_demo.getMirrorGlobalBounds().height / 2});
        //SET LOGO ^^


        main_window.clear({22, 22, 22});


        //DRAW OBJECTS || main_window.draw(object);
        main_window.draw(logo_demo);
        main_window.draw(logo_text_entry);
        main_window.draw(text_opacity_slider);
        main_window.draw(mirror_opacity_slider);
        main_window.draw(text_x_slider);
        main_window.draw(text_y_slider);
        main_window.draw(mirror_x_slider);
        main_window.draw(mirror_y_slider);
        main_window.draw(font_size_slider);
        main_window.draw(mirror_skew_slider);
        main_window.draw(logo_menu_bar);
        main_window.draw(font_style_chooser);
        main_window.draw(color_selector);
        //DRAW OBJECTS ^^


        main_window.display();

        statusActivity();
    }
}

void LogoMaker::createSaveFile(const std::string& filePath) {
    ofstream saveFile;
    saveFile.open(filePath);
    saveFile.clear();
    saveFile << logo_text_entry.getString() << std::endl;
    saveFile << font_style_chooser.getFontChoice() << std::endl;
    saveFile << to_string(font_size_slider.getActualValue()) << std::endl;
    saveFile << to_string(text_x_slider.getActualValue()) << std::endl;
    saveFile << to_string(text_y_slider.getActualValue()) << std::endl;
    saveFile << to_string(text_opacity_slider.getActualValue()) << std::endl;
    saveFile << to_string(mirror_x_slider.getActualValue()) << std::endl;
    saveFile << to_string(mirror_y_slider.getActualValue()) << std::endl;
    saveFile << to_string(mirror_opacity_slider.getActualValue()) << std::endl;
    saveFile << to_string(mirror_skew_slider.getActualValue()) << std::endl;
    saveFile << to_string(color_selector.getChosenColor(ColorSelector::TEXT).r) << " " << to_string(color_selector.getChosenColor(ColorSelector::TEXT).g) << " " << to_string(color_selector.getChosenColor(ColorSelector::TEXT).b) << " " << std::endl;
    saveFile << to_string(color_selector.getChosenColor(ColorSelector::MIRROR).r) << " " << to_string(color_selector.getChosenColor(ColorSelector::MIRROR).g) << " " << to_string(color_selector.getChosenColor(ColorSelector::MIRROR).b) << " " << std::endl;
    saveFile << to_string(color_selector.getChosenColor(ColorSelector::SCENE).r) << " " << to_string(color_selector.getChosenColor(ColorSelector::SCENE).g) << " " << to_string(color_selector.getChosenColor(ColorSelector::SCENE).b) << " " << std::endl;
    saveFile.close();
}

void LogoMaker::loadSaveFile(const std::string& filePath) {
    ifstream openFile;
    openFile.open(filePath);
    if (openFile.is_open()) {
        std::string logoText, fontStyle;
        float inputNum[17];
        /*
         * 0 font size
         * 1 text x
         * 2 text y
         * 3 text opacity
         * 4 mirror x
         * 5 mirror y
         * 6 mirror opacity
         * 7 mirror skew
         * 8 text color r
         * 9 text color g
         * 10 text color b
         * 11 mirror color r
         * 12 mirror color g
         * 13 mirror color b
         * 14 scene color r
         * 15 scene color g
         * 16 scene color b
         */
        getline(openFile, logoText);
        getline(openFile, fontStyle);
        for (int i = 0; i < 17; ++i) {
            openFile >> inputNum[i];
        }
        logo_text_entry.setString(logoText);
        font_style_chooser.setFontChoice(fontStyle);
        font_size_slider.setActualValue(inputNum[0]);
        text_x_slider.setActualValue(inputNum[1]);
        text_y_slider.setActualValue(inputNum[2]);
        mirror_x_slider.setActualValue(inputNum[4]);
        mirror_y_slider.setActualValue(inputNum[5]);
        mirror_skew_slider.setActualValue(inputNum[7]);
        color_selector.setTextColor({static_cast<Uint8>(inputNum[8]),static_cast<Uint8>(inputNum[9]),static_cast<Uint8>(inputNum[10]),static_cast<Uint8>(inputNum[3])});
        color_selector.setMirrorColor({static_cast<Uint8>(inputNum[11]),static_cast<Uint8>(inputNum[12]),static_cast<Uint8>(inputNum[13]),static_cast<Uint8>(inputNum[6])});
        color_selector.setSceneColor({static_cast<Uint8>(inputNum[14]),static_cast<Uint8>(inputNum[15]),static_cast<Uint8>(inputNum[16])});
        openFile.close();
    }
}

void LogoMaker::reset() {
    logo_text_entry.reset();
    font_style_chooser.reset();
    font_size_slider.reset();
    text_x_slider.reset();
    text_y_slider.reset();
    mirror_x_slider.reset();
    mirror_y_slider.reset();
    mirror_skew_slider.reset();
    color_selector.reset();
    logo_text_entry.enable();
}

void LogoMaker::statusActivity() {
    if(logo_menu_bar.getStatusMessage() != Menu::NO_STATUS) {
//            std::cout << "Status: " << Menu::convertToStatusString(logo_menu_bar.getStatusMessage()) << std::endl;
        if(logo_menu_bar.getStatusMessage() == Menu::NEW_PROJECT)
            reset();
        else if (logo_menu_bar.getStatusMessage() == Menu::OPEN_PROJECT)
            loadSaveFile("../Files/saveFile.txt");
        else if(logo_menu_bar.getStatusMessage() == Menu::SAVE_PROJECT)
            createSaveFile("../Files/saveFile.txt");
        else if (logo_menu_bar.getStatusMessage() == Menu::QUIT)
            main_window.close();
        else if (logo_menu_bar.getStatusMessage() == Menu::EXPORT_AS_JPG) {
            std::time_t t = std::time(0);   // from internet https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
            std::tm* now = std::localtime(&t);
            sf::Vector2u windowSize = main_window.getSize();
            sf::Texture texture;
            texture.create(windowSize.x, windowSize.y);
            texture.update(main_window);
            sf::Image screenshot, croppedScreenshot;
            screenshot = texture.copyToImage();
            croppedScreenshot.create(665,300);
            for(int height = 0; height < 300; ++height) {
                for (int width = 0; width < 665; ++width) {
                    croppedScreenshot.setPixel(width,height,screenshot.getPixel(width+50,height+55));
                }
            }
            std::string dateAndTime = to_string(now->tm_mon + 1) + to_string(now->tm_mday) + to_string(now->tm_year - 100) + '-' + to_string(now->tm_hour) + to_string(now->tm_min) + to_string(now->tm_sec);
            croppedScreenshot.saveToFile("../Files/Logo" + dateAndTime + ".jpg");
        }
        else if (logo_menu_bar.getStatusMessage() == Menu::EXPORT_AS_PNG) {
            std::time_t t = std::time(0);   // from internet https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
            std::tm* now = std::localtime(&t);
            sf::Vector2u windowSize = main_window.getSize();
            sf::Texture texture;
            texture.create(windowSize.x, windowSize.y);
            texture.update(main_window);
            sf::Image screenshot, croppedScreenshot;
            screenshot = texture.copyToImage();
            croppedScreenshot.create(665,300);
            for(int height = 0; height < 300; ++height) {
                for (int width = 0; width < 665; ++width) {
                    croppedScreenshot.setPixel(width,height,screenshot.getPixel(width+50,height+55));
                }
            }
            std::string dateAndTime = to_string(now->tm_mon + 1) + to_string(now->tm_mday) + to_string(now->tm_year - 100) + '-' + to_string(now->tm_hour) + to_string(now->tm_min) + to_string(now->tm_sec);
            croppedScreenshot.saveToFile("../Files/Logo" + dateAndTime + ".png");
        }
        else if (logo_menu_bar.getStatusMessage() == Menu::VISIT_WEBSITE) {
            system("start https://www.jonathanng.info");
        }

        logo_menu_bar.resetStatusMessage();
    }
}
