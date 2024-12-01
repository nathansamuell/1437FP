#include "tulip.h"

// constructors
Tulip::Tulip() : Plant(3, 1, 2) {
    setL(6, 6, 6);
    this->generateArt();
}

Tulip::Tulip(float s, float f, float w) : Plant(s, f, w) {
    setL(6, 6, 6);
    this->generateArt();
}

int Tulip::Water() {
    waterL += 2;
    if(waterL > 10) {
        waterL = 10;
    }
    return Grow();
}

int Tulip::Sun() {
    sunlightL += 2;
    if(sunlightL > 10) {
        sunlightL = 10;
    }
    return Grow();
}

int Tulip::Fertilize() {
    fertilizerL += 2;
    if(fertilizerL > 10) {
        fertilizerL = 10;
    }
    return Grow();
}

int Tulip::Grow() {
    if (growthStage >= 9) {
        std::cout << "Your Tulip has reached its maximum growth!" << std::endl;
        std::cout << ascii[growthStage] << std::endl;
        return 2;
    }

    age++;
    waterL -= waterC;
    fertilizerL -= fertilizerC;
    sunlightL -= sunlightC;

    if(waterL < 0 || fertilizerL < 0 || sunlightL < 0) {
        hp--;
        std::cout << "Oh no! Your Tulip is out of a key nutrient!" << std::endl;
    } else {
        growthStage++;
        std::cout << "Your Tulip has grown!\n" << std::endl;
    }

    std::cout << ascii[growthStage] << std::endl;

    if(hp == 0) {
        std::cout << "Oh no! Your Tulip has died." << std::endl;
        return 1;
    }

    return 0;
}

int Tulip::Prune() {
    if (age % 2 == 0) {  // Tulips can be pruned more frequently than bonsai
        growthStage--;
        if(waterC > 0 && fertilizerC > 0 && sunlightC > 0) {
            waterC--;
            fertilizerC--;
            sunlightC--;
        } else {
            std::cout << "Cannot prune! Tulip is already at maximum efficiency!" << std::endl;
            return 1;
        }
        if (growthStage < 0) {
            growthStage = 0;
            std::cout << "Cannot prune! Tulip is too small!" << std::endl;
            return 1;
        }
        return 0;
    }
    std::cout << "Cannot prune! Tulip was pruned too recently!" << std::endl;
    return 1;
}

void Tulip::generateArt() {
    ascii[0] = 
        Constants::BRIGHT_GREEN + "       ||\n" + Constants::RESET;
    ascii[1] = 
        Constants::BRIGHT_GREEN + "       ||\n"
        "       ||\n" + Constants::RESET;
    ascii[2] = 
        Constants::BRIGHT_GREEN + "       ||\n"
        "       ||\n"
        "       ||\n" + Constants::RESET;
    ascii[3] = 
        Constants::BRIGHT_GREEN + "       ||\n"
        "       ||\n"
        "       ||\n" + 
        Constants::BRIGHT_MAGENTA + "       ,\n" + Constants::RESET;
    ascii[4] = 
        Constants::BRIGHT_GREEN + "       ||\n"
        "       ||\n"
        "       ||\n";
    ascii[5] = 
        Constants::BRIGHT_MAGENTA + "       ,\n"
        "     /\\^/\n" + Constants::RESET + 
        Constants::BRIGHT_GREEN + "       ||\n";
}