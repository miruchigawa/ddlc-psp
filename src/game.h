#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

typedef enum {
    Splash,
    MainMenu
} State;

typedef struct {
    State state;
} Game;

void Init_Game_Settings(void);
State Get_Game_State(void);
void Set_Game_State(State state);

#endif
