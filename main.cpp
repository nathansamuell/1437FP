// include statements
#include <iostream>
#include <stdlib.h>
#include "plant.h"
#include "bonsai.h"
#include "tulip.h"
#include "sunflower.h"
#include "constants.h"

void initGame();
void recordGame();

int main() {
    system(Constants::CLEAR_SCREEN);
    initGame();
    Bonsai testB = Bonsai();
    // Tulip testT = Tulip();
    // Sunflower testS = Sunflower();
    return 0;
}

void initGame() {
    std::cout << Constants::HEADER;
}