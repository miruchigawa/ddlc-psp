#include "splash.h"
#include <QuickGame.h>
#include "../color.h"

QGSprite_t splash_screen;
QGAudioClip_t splash_bgm;
bool bgmPlayed;
unsigned int opacity;

void init_splash() {
    opacity = 0x00; // Set opacity 0
    bgmPlayed = false;
    splash_bgm = QuickGame_Audio_Load("assets/audio/bgm/1.wav", false, false);
    QGTexInfo splash_texture = {.filename = "assets/images/splash.png", .flip=true};
    splash_screen = QuickGame_Sprite_Create_Contained(240, 135, 480, 270, splash_texture);

    splash_screen->color.color = changeOpacity(splash_screen->color.color, opacity);
}

void update_splash(double delta) {
    if (opacity < 255) {
        opacity += 2 + ((unsigned int)delta);
    }

    if (opacity > 255) opacity = 255;

    if (!bgmPlayed) {
        QuickGame_Audio_Play(splash_bgm, 0);
        bgmPlayed = true;
    } 
}

void render_splash() {
    QGColor color;
    color.color = 0xFFFFFF;
    QuickGame_Graphics_Set_Clear_Color(color);
    splash_screen->color.color = changeOpacity(splash_screen->color.color, opacity);
    QuickGame_Sprite_Draw(splash_screen);
}
