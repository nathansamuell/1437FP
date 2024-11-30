#include "bonsai.h"

// constructors

Bonsai::Bonsai() : Plant(2, 4, 3) {
    this->generateArt();
    setL(8, 8, 8);
}

Bonsai::Bonsai(float s, float f, float w)
 : Plant(s, f, w) {
    setL(10, 10, 10);
    this->generateArt();
}


Bonsai::~Bonsai() {
    return;
};

int Bonsai::Grow() {
    // FIXME: add grow stuff
    age++;
    waterL -= waterC;
    fertilizerL -= fertilizerC;
    sunlightL -= sunlightC;
    if(waterL < 0 || fertilizerL < 0 || sunlightL < 0) {
        hp--;
        std::cout << "Oh no! Your Bonsai is out of a key nutrient!" << std::endl;
    } else if(growthStage != 10){
        growthStage++;
        std::cout << "Your bonsai has grown!\n" << std::endl;
        std::cout << ascii[growthStage];
    } else {
        std::cout << "Your bonsai has reached it's maximum growth!\nEnter your name to save the tree: ";
        std::string name;
        std::getline(std::cin, name);
        std::ofstream file("plants.txt", std::ios::app);
        file << ascii[growthStage];
        return 2;

    }
    if(hp == 0) {
        std::cout << "Oh no! Your Bonsai has died." << std::endl;
        return 1;
    }

    return 0;
}

void Bonsai::generateArt() {
    ascii[0] = 
        "    *\n"
        "   / \\\n"
        "  /   \\\n"
        " /     \\\n"
        "/   .   \\\n"
        " \\_____/\n\n";

    
    ascii[1] = 
        "     /\\\n"
        "    /  \\\n"
        "   /    \\\n"
        "  /  |   \\\n"
        " /   |    \\\n"
        "|    +     |\n"
        " \\________/\n\n";

    ascii[2]= 
        "     _____\n"
        "    /  /\\  \\\n"
        "   /  /  \\   \\\n"
        "  /  /____\\  \\\n"
        " /___________\\\n"
        " |  rich earth |\n"
        "   |   |   |\n";

    ascii[3] = 
        "     _____\n"
        "   _/  /\\  \\__\n"
        "  /  /\\    /   \\\n"
        " /  /  \\  /     \\\n"
        "|__________+______|\n"
        " | nutrient soil |\n"
        "   |   |    |\n\n";

    ascii[4] = 
    "     _____\n"
    "   _/  /\\  \\__\n"
    "  /  /\\    /   \\\n"
    " /  /  \\  /     \\\n"
    "|__________+______|\n"
    "    _____\n"
    "   /     \\\n"
    "  (       )\n"
    "  (  [ ]  )\n"
    "   \\_____/ \n\n";

    ascii[5] = 
        "     _____\n"
        "   _/  /\\  \\__\n"
        "  /  /\\    /   \\\n"
        " /  /  \\  /     \\\n"
        "|__________+______|\n"
        "    _____\n"
        "   /     \\\n"
        "  (       )\n"
        "  (  [ ]  )\n"
        "   \\_____/ \n\n";

    ascii[6] = 
        "       _____\n"
        "     _/  /\\  \\__\n"
        "    /  /\\    /   \\\n"
        "   /  /  \\  /     \\\n"
        "  |__________+______|\n"
        "    _______\n"
        "   /         \\\n"
        "  (           )\n"
        "  (   [===]   )\n"
        "   \\_________/ \n";

    ascii[7] = 
        "       _____\n"
        "     _/  /\\  \\__\n"
        "    /  /\\    /   \\\n"
        "   /  /  \\  /     \\\n"
        "  |__________+______|\n"
        "   _________\n"
        "  /           \\\n"
        " (             )\n"
        " (   {~~~~~}   )\n"
        "  \\___________/ \n";

    ascii[8] = 
        "       _____\n"
        "     _/ /|\\  \\__\n"
        "    /  /   \\    \\\n"
        "   /  / |   \\    \\\n"
        "  |__________+______|\n"
        "   ____________\n"
        "  /            \\\n"
        " (              )\n"
        " (   {#####}    )\n"
        "  \\____________/ \n";

    ascii[9] = 
        "       _____\n"
        "     _/ /|\\  \\__\n"
        "    /  /   \\    \\\n"
        "   /  / |   \\    \\\n"
        "  |__________+______|\n"
        "   ____________\n"
        "  /            \\\n"
        " (              )\n"
        " (   {^^^^^}    )\n"
        "  \\____________/ \n"
        "    ^^^^^^^^^^^\n\n";
}