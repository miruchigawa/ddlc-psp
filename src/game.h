typedef enum {
    Splash,
    MainMenu
} State;

typedef struct {
    State state;
} Game;


extern Game game;
