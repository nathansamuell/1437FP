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

// void Plant::setWC(float w) {
//     waterC = w;
// }
// void Plant::setFC(float f) {
//     fertilizerC = f;
// }
// void Plant::setSC(float s) {
//     sunlightC = s;
// }
// void Plant::setWL(float w) {
//     waterL = w;
// }
// void Plant::setFL(float f) {
//     fertilizerL = f;
// }
// void Plant::setSL(float s) {
//     sunlightL = s;
// }


