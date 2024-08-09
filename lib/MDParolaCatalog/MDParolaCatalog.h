#ifndef MDPAROLACATALOG_H
#define MDPAROLACATALOG_H

#include <MD_Parola.h>
#include <MD_MAX72xx.h>

// Define the number of devices and hardware interface
#define MAX_DEVICES 4
#define CS_PIN 5
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

class MDParolaCatalog
{
public:
    MDParolaCatalog();
    void begin();
    void run(String message);
    void clear();
    void runAnimation();

private:
    MD_Parola P;
};

#endif // MDPAROLACATALOG_H
