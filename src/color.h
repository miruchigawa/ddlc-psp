#ifndef COLOR_H
#define COLOR_H

unsigned int changeOpacity(unsigned int color, unsigned int opacity) {
    color &= 0x00FFFFFF;
    color |= ((unsigned int)opacity << 24);
    return color;
}

#endif
