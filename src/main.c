#include <QuickGame.h>
#include "game.h"
#include "scene/splash.h"

QGTimer time;

void init(void) {
    QuickGame_Timer_Start(&time);
    QuickGame_Graphics_Set2D();
    Init_Game_Settings();
    init_splash();
}

void update(double delta) {
    QuickGame_Input_Update();

    switch (Get_Game_State()) {
    case Splash:
        update_splash(delta);
        break;
    }
}

void draw(void) {
    QuickGame_Graphics_Start_Frame();
    QuickGame_Graphics_Clear();
    
    switch (Get_Game_State()) {
    case Splash:
        render_splash();
        break;
    }


    QuickGame_Graphics_End_Frame(true);
}

int main(void) {
    QuickGame_Init();
    
    init(); 

    while (QuickGame_Running()) {
        update(QuickGame_Timer_Delta(&time));
        draw();
    }

    QuickGame_Terminate();
    return 0;
}
