// include statements
#include <iostream>
#include <stdlib.h>
#include "plant.h"
#include "bonsai.h"
#include "constants.h"
#include <string>

void initGame();
void recordGame();

int main() {
    system(Constants::CLEAR_SCREEN);
    initGame();
    // Bonsai testBonsai = Bonsai();
    return 0;
}

void initGame() {
    std::cout << Constants::HEADER;
}