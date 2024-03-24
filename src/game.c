#include "game.h"

Game game_settings;

void Init_Game_Settings(void) {
    game_settings.state = Splash;
}

State Get_Game_State(void) {
    return game_settings.state;
}

void Set_Game_State(State state) {
    game_settings.state = state;
}
