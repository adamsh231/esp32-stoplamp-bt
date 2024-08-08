#include "MDParolaCatalog.h"

MDParolaCatalog::MDParolaCatalog() : P(HARDWARE_TYPE, CS_PIN, MAX_DEVICES) {}

const textEffect_t effects[] = {
    PA_PRINT, PA_SLICE, PA_MESH, PA_FADE, PA_WIPE,
    PA_WIPE_CURSOR, PA_OPENING, PA_OPENING_CURSOR, PA_CLOSING,
    PA_CLOSING_CURSOR, PA_RANDOM, PA_BLINDS, PA_DISSOLVE,
    PA_SCROLL_UP, PA_SCROLL_DOWN, PA_SCROLL_LEFT, PA_SCROLL_RIGHT,
    PA_SCROLL_UP_LEFT, PA_SCROLL_UP_RIGHT, PA_SCROLL_DOWN_LEFT,
    PA_SCROLL_DOWN_RIGHT, PA_SCAN_HORIZ, PA_SCAN_HORIZX,
    PA_SCAN_VERT, PA_SCAN_VERTX, PA_GROW_UP, PA_GROW_DOWN};

textPosition_t position[] = {PA_LEFT, PA_CENTER, PA_RIGHT};

void MDParolaCatalog::begin()
{
    P.begin();
    P.setIntensity(0); // Set the intensity (brightness) of the display (0-15):
    P.displayClear();
}

void MDParolaCatalog::run(String message)
{
    P.displayText(message.c_str(), position[random(ARRAY_SIZE(position))], 30, 0, effects[random(ARRAY_SIZE(effects))], effects[random(ARRAY_SIZE(effects))]);
    while (!P.displayAnimate())
        ;
}
