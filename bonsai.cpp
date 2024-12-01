#include "bonsai.h"

// constructors

Bonsai::Bonsai() : Plant(2, 4, 3) {
    setL(8, 8, 8);
    this->generateArt();
}

Bonsai::Bonsai(float s, float f, float w)
 : Plant(s, f, w) {
    setL(8, 8, 8);
    this->generateArt();
}

int Bonsai::Water() {
    waterL += 2;
    if(waterL > 10) {
        waterL = 10;
    }
    int returnval = Grow();
    return returnval;
}

int Bonsai::Sun() {
    sunlightL += 2;
    if(sunlightL > 10) {
        sunlightL = 10;
    }
    int returnval = Grow();
    return returnval;
}

int Bonsai::Fertilize() {
    fertilizerL += 2;
    if(fertilizerL > 10) {
        fertilizerL = 10;
    }
    int returnval = Grow();
    return returnval;
}

int Bonsai::Grow() {
    if (growthStage >= 9) {
        std::cout << "Your bonsai has reached its maximum growth!" << std::endl;
        std::cout << ascii[growthStage] << std::endl;
        return 2;
    }

    age++;
    waterL -= waterC;
    fertilizerL -= fertilizerC;
    sunlightL -= sunlightC;

    if(waterL < 0 || fertilizerL < 0 || sunlightL < 0) {
        hp--;
        std::cout << "Oh no! Your Bonsai is out of a key nutrient!" << std::endl;
    } else {
        growthStage++;
        std::cout << "Your bonsai has grown!\n" << std::endl;
    }

    std::cout << ascii[growthStage] << std::endl;

    if(hp == 0) {
        std::cout << "Oh no! Your Bonsai has died." << std::endl;
        return 1;
    }

    return 0;
}

int Bonsai::Prune() {
    if (age % 3 == 0) {
        growthStage--;
        if(waterC > 0 && fertilizerC > 0 && sunlightC > 0) {
            waterC--;
            fertilizerC--;
            sunlightC--;
        } else {
            std::cout << "Cannot prune! Bonsai is already at maximum efficiency!" << std::endl;
            return 1;
        }
        if (growthStage < 0) {
            growthStage = 0;
            std::cout << "Cannot prune! Bonsai is too small!" << std::endl;
            return 1;
        } else 
        return 0;
    }
    std::cout << "Cannot prune! Bonsai was pruned too recently!" << std::endl;
    return 1;
}

void Bonsai::generateArt() {
    using namespace Constants;

    ascii[0] = 
        GREEN + "    *\n"
        "   / \\\n"
        "  /   \\\n"
        " /     \\\n"
        "/   .   \\\n" +
        BROWN + " \\_____/\n\n" + RESET;

    ascii[1] = 
        GREEN + "     /\\\n"
        "    /  \\\n"
        "   /    \\\n"
        "  /  |   \\\n"
        " /   |    \\\n" + 
        BROWN + "|    +     |\n"
        " \\________/\n\n" + RESET;

    ascii[2]= 
        GREEN + "     _____\n"
        "    /  /\\  \\\n"
        "   /  /  \\   \\\n"
        "  /  /____\\  \\\n"
        " /___________\\\n" +
        BROWN + " |  #@####*#$## |\n"
        "   |   |   |\n" + RESET;

    ascii[3] = 
        GREEN + "     _____\n"
        "   _/  /\\  \\__\n"
        "  /  /\\    /   \\\n"
        " /  /  \\  /     \\\n"
        "|__________+______|\n" +
        BROWN + " |   *   *   |\n"
        "   |  *  *  |\n\n" + RESET;

    ascii[4] = 
        GREEN + "     _____\n"
        "   _/  /\\  \\__\n"
        "  /  /\\    /   \\\n"
        " /  /  \\  /     \\\n"
        "|__________+______|\n" +
        BROWN + "    __" + DARK_BROWN + "//" + BROWN + "___\n"
        "   |  *  *  |\n"
        "   |  *  *  |\n"
        "   \\________/ \n\n" + RESET;

    ascii[5] = 
        GREEN + "     _____\n"
        "   _/  /\\  \\__\n"
        "  /  /\\    /   \\\n"
        " /  /  \\  /     \\\n"
        "|__________+______|\n" +
        BROWN + "    __" + DARK_BROWN + "//" + BROWN + "___\n"
        "   |  *  *  |\n"
        "   |  *  *  |\n"
        "   \\________/ \n\n" + RESET;

    ascii[6] = 
        GREEN + "     _____\n"
        "   _/  /\\  \\__\n"
        "  /  /\\    /   \\\n"
        " /  /  \\  /     \\\n"
        "|__________+______|\n" +
        BROWN + "    ___" + DARK_BROWN + "//" + BROWN + "____\n"
        "   |  *  *  |\n"
        "   |  *  *  |\n"
        "   \\________/ \n\n" + RESET;

    ascii[7] = 
        GREEN + "     _____\n"
        "   _/  /\\  \\__\n"
        "  /  /\\    /   \\\n"
        " /  /  \\  /     \\\n"
        "|__________+______|\n" +
        BROWN + "   ____" + DARK_BROWN + "//" + BROWN + "____\n"
        "   |  *  *  |\n"
        "   |  *  *  |\n"
        "   \\________/ \n" + RESET;

    ascii[8] = 
        GREEN + "     _____\n"
        "   _/  /\\  \\__\n"
        "  /  /\\    /   \\\n"
        " /  /  \\  /     \\\n"
        "|__________+______|\n" +
        BROWN + "   _____" + DARK_BROWN + "//" + BROWN + "___\n"
        "   |  *  *  |\n"
        "   |  *  *  |\n"
        "   \\________/ \n" + RESET;

    ascii[9] = 
        GREEN + "     _____\n"
        "   _/  /\\  \\__\n"
        "  /  /\\    /   \\\n"
        " /  /  \\  /     \\\n"
        "|__________+______|\n" +
        BROWN + "   _____" + DARK_BROWN + "//" + BROWN + "___\n"
        "   |  *  *  |\n"
        "   |  *  *  |\n"
        "   \\________/ \n" + RESET;
}