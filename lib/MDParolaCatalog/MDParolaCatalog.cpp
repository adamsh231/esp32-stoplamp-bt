#include "MDParolaCatalog.h"

MDParolaCatalog::MDParolaCatalog() : P(HARDWARE_TYPE, CS_PIN, MAX_DEVICES) {}

void MDParolaCatalog::begin()
{
    P.begin();
    P.setIntensity(0); // Set the intensity (brightness) of the display (0-15):
    P.displayClear();
    P.displayText("Hello world!", PA_CENTER, 70, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
    P.displayReset();
}

void MDParolaCatalog::run(String message)
{
    if (P.displayAnimate())
    {
        P.displayText(message.c_str(), PA_CENTER, 70, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        P.displayReset();
    }
}
