#include <QuickGame.h>
#include "game.h"
#include "scene/splash.h"

QGTimer time;
Game game = {Splash};

void init() {
    QuickGame_Timer_Start(&time);
    QuickGame_Graphics_Set2D();
    init_splash();
}

void update(double delta) {
    QuickGame_Input_Update();

    switch (game.state) {
    case Splash:
        update_splash(delta);
        break;
    }
}

void draw() {
    QuickGame_Graphics_Start_Frame();
    QuickGame_Graphics_Clear();
    
    switch (game.state) {
    case Splash:
        render_splash();
        break;
    }


    QuickGame_Graphics_End_Frame(true);
}

int main() {
    QuickGame_Init();
    
    init(); 

    while (QuickGame_Running()) {
        update(QuickGame_Timer_Delta(&time));
        draw();
    }

    QuickGame_Terminate();
    return 0;
}
