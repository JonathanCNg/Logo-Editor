//
// Created by jonng on 6/5/2021.
//

#include "LogoMenuBar.h"

LogoMenuBar::LogoMenuBar() {
    Menu fileMenu("File");
    fileMenu.setButtonSize({45,30});
    fileMenu.setItemSize({140,30});
    fileMenu.addItem(Menu::NEW_PROJECT);
    fileMenu.addItem(Menu::OPEN_PROJECT);
    fileMenu.addItem(Menu::SAVE_PROJECT);
    fileMenu.addItem(Menu::QUIT);

    Menu renderMenu("Render");
    renderMenu.setButtonSize({75,30});
    renderMenu.setItemSize({140,30});
    renderMenu.addItem(Menu::EXPORT_AS_JPG);
    renderMenu.addItem(Menu::EXPORT_AS_PNG);

    Menu editMenu("Help");
    editMenu.setButtonSize({50,30});
    editMenu.setItemSize({140,30});
    editMenu.addItem(Menu::VISIT_WEBSITE);

    addMenu(fileMenu);
    addMenu(renderMenu);
    addMenu(editMenu);
}
