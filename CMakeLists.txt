cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME FinalProjectCS8)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp LogoMaker.cpp LogoMaker.h SliderSelector.cpp SliderSelector.h Fonts.cpp Fonts.h InsertionPointCursor.cpp InsertionPointCursor.h Label.cpp Label.h MouseEvents.cpp MouseEvents.h TextBox.cpp TextBox.h TextInput.cpp TextInput.h Typer.cpp Typer.h TextChar.cpp TextChar.h LinkedList.cpp LinkedList.cpp Node.h Node_iterator.cpp Node_iterator.h LogoDemo.cpp LogoDemo.h ItemList.cpp ItemList.h Menu.cpp Menu.h MenuBar.cpp MenuBar.h Item.cpp Item.h LogoTextEntry.cpp LogoTextEntry.h DropdownMenu.cpp DropdownMenu.h HelperFunctions.cpp HelperFunctions.h ColorSelector.cpp ColorSelector.h Button.cpp Button.h DynamicCursor.cpp DynamicCursor.h FontStyleChooser.cpp FontStyleChooser.h LogoMenuBar.cpp LogoMenuBar.h FontSizeSlider.cpp FontSizeSlider.h TextXSlider.cpp TextXSlider.h TextYSlider.cpp TextYSlider.h TextOpacitySlider.cpp TextOpacitySlider.h MirrorXSlider.cpp MirrorXSlider.h MirrorYSlider.cpp MirrorYSlider.h MirrorOpacitySlider.cpp MirrorOpacitySlider.h MirrorSkewSlider.cpp MirrorSkewSlider.h LogoMakerIcon.cpp LogoMakerIcon.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()