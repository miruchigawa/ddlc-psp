cmake_minimum_required(VERSION 3.22)

project(ddlc)

add_executable(${PROJECT_NAME} 
    src/main.c src/game.c 
    src/scene/splash.c
)
add_subdirectory(./QuickGame QuickGame)

target_link_libraries(${PROJECT_NAME} PUBLIC QuickGame)
target_include_directories(${PROJECT_NAME} PUBLIC QuickGame/include)

create_pbp_file(
    TARGET ${PROJECT_NAME}
    ICON_PATH NULL
    BACKGROUND_PATH NULL
    PREVIEW_PATH NULL
    TITLE "Doki Doki Literature Club"
    VERSION 01.00
    BUILD_PRX ON
)
