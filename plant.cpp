#include "plant.h"

// constructors
Plant::Plant() {
    waterC = 1.0;
    fertilizerC = 1.0;
    sunlightC = 1.0;
}

Plant::Plant(float w, float f, float s) {
    setC(w, f, s);
}

void Plant::setC(float w, float f, float s) {
    waterC = w;
    fertilizerC = f;
    sunlightC = s;
}

void Plant::setL(float w, float f, float s) {
    waterL = w;
    fertilizerL = f;
    sunlightL = s;
}

void setWC(float w) {
    waterC = w;
}
void setFC(float f) {
    fertilizerC = f;
}
void setSC(float s) {
    sunlightC = c;
}
void setWL(float w) {
    waterL = w;
}
void setFL(float f) {
    fertilizerL = f;
}
void setSL(float s) {
    sunlightL = s;
}


