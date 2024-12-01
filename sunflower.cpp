#include "sunflower.h"

// Constructors
Sunflower::Sunflower() : Plant(1, 1, 1) {
    setL(8, 8, 8);
    this->generateArt();
    // for (int i = 0; i < 10; i++) {
    //     std::cout << ascii[i] << std::endl;
    // }
}

Sunflower::Sunflower(float s, float f, float w) : Plant(s, f, w) {
    setL(6, 6, 6);
    this->generateArt();
}

int Sunflower::Grow() {
    age++;
    waterL -= waterC;
    fertilizerL -= fertilizerC;
    sunlightL -= sunlightC;
    
    if(waterL < 0 || fertilizerL < 0 || sunlightL < 0) {
        hp--;
        std::cout << "Oh no! Your Sunflower is out of a key nutrient!" << std::endl;
    } else if(growthStage != 10) {
        growthStage++;
        std::cout << "Your Sunflower has grown!\n" << std::endl;
        std::cout << ascii[growthStage];
    } else {
        std::cout << "Your Sunflower has reached it's maximum growth!\nEnter your name to save the flower: ";
        std::string name;
        std::getline(std::cin, name);
        std::ofstream file("plants.txt", std::ios::app);
        file << ascii[growthStage];
        return 2;
    }
    
    if(hp == 0) {
        std::cout << "Oh no! Your Sunflower has died." << std::endl;
    }
    
    return 0;
}

int Sunflower::Prune() {
    if (age % 2 == 0) {  // Sunflowers can be pruned more frequently than bonsai
        growthStage--;
        return 1;
    }
    return 0;
}

void Sunflower::generateArt() {
    // Seed/Sprout stage
    ascii[0] = 
        Constants::DARK_BROWN + "   .\n"
        "   '" + Constants::RESET;

    // Initial stem
    ascii[1] = 
        Constants::BRIGHT_GREEN + "   \\|\n"
        "    |\n"
        "    |" + Constants::RESET + 
        Constants::DARK_BROWN + "\n    '" + Constants::RESET;

    // Small stem with leaves
    ascii[2] = 
        Constants::BRIGHT_GREEN + "   \\|/\n"
        "    |\n"
        "    |\n"
        "    |" + Constants::RESET +
        Constants::DARK_BROWN + "\n   _'_" + Constants::RESET;

    // Growing stem with initial branches
    ascii[3] = 
        Constants::BRIGHT_GREEN + "    \\|/\n"
        "    /|\\\n"
        "     |\n"
        "     |\n"
        "     |)" + Constants::RESET +
        Constants::DARK_BROWN + "\n    /|\\\n"
        "   /_|_\\" + Constants::RESET;

    // Taller stem with more branches
    ascii[4] = 
        Constants::BRIGHT_GREEN + "     \\|/\n"
        "     /|\\\n"
        "      |\n"
        "      |)\n"
        "      |" + Constants::RESET +
        Constants::DARK_BROWN + "\n     /|\\\n"
        "    //|\\\\\n"
        "   /___|_\\" + Constants::RESET;

    // Initial flower bud
    ascii[5] = 
        Constants::BRIGHT_YELLOW + "          .-.'-.          \n"
        "       .-(  " + Constants::DARK_BROWN + "oOo" + Constants::BRIGHT_YELLOW + "  )-.      \n"
        "      /   '.   .'   \\     \n" + 
        Constants::BRIGHT_GREEN + "," + Constants::BRIGHT_YELLOW + "     \\.--.     .--./     \n" +
        Constants::BRIGHT_GREEN + "|\\" + Constants::BRIGHT_YELLOW + "     (   :   :   )      \n" +
        Constants::BRIGHT_GREEN + "\\.\\\/" + Constants::BRIGHT_YELLOW + "    '--'   '--'       \n" +
        Constants::BRIGHT_GREEN + ".. ;/|     |   |          \n"
        "-`'. :/     \\ /           \n"
        "--. `. /     ;            \n"
        " `'-,_'/    /|            \n"
        "      '((  /./_           \n"
        "        \\\\; ..-'          \n"
        "         \\.'`--.          \n"
        "          \\ .--'          \n"
        "           )'`            \n"
        "         //-'             \n"
        "        //                \n"
        "       //                 " +
        Constants::DARK_BROWN + "                        " + Constants::RESET;

    // Opening flower
    ascii[6] = 
        Constants::BRIGHT_YELLOW + "          .-.'-.          \n"
        "       .-(  " + Constants::DARK_BROWN + "oOOo" + Constants::BRIGHT_YELLOW + "  )-.     \n"
        "      /   '.   .'   \\     \n" +
        Constants::BRIGHT_GREEN + "," + Constants::BRIGHT_YELLOW + "     \\.--.  " + Constants::DARK_BROWN + "o" + Constants::BRIGHT_YELLOW + "  .--./     \n" +
        Constants::BRIGHT_GREEN + "|\\" + Constants::BRIGHT_YELLOW + "     (   :" + Constants::DARK_BROWN + "oOo" + Constants::BRIGHT_YELLOW + ":   )      \n" +
        Constants::BRIGHT_GREEN + "\\.\\\/" + Constants::BRIGHT_YELLOW + "    '--'   '--'       \n" +
        Constants::BRIGHT_GREEN + ".. ;/|    .'''.           \n"
        "-`'. :/  -(   )-          \n"
        "--. `. / /'-.-;           \n"
        " `'-,_';//  /|            \n"
        "      '((  /./_           \n"
        "        \\\\; ..-'          \n"
        "         \\.'`--.          \n"
        "          \\ .--'          \n"
        "           )'`            \n"
        "         //-'             \n"
        "        //                \n"
        "       //                 " +
        Constants::DARK_BROWN + "                      " + Constants::RESET;

    // Blooming flower
    ascii[7] = 
        Constants::BRIGHT_YELLOW + "          .-.'  '.-       \n"
        "       .-(  " + Constants::DARK_BROWN + "\\  /" + Constants::BRIGHT_YELLOW + "   )-.    \n"
        "      /   '.." + Constants::DARK_BROWN + "oOo" + Constants::BRIGHT_YELLOW + "..'   \\   \n" +
        Constants::BRIGHT_GREEN + "," + Constants::BRIGHT_YELLOW + "     \\.--.." + Constants::DARK_BROWN + "oOOOOo" + Constants::BRIGHT_YELLOW + ".--./    \n" +
        Constants::BRIGHT_GREEN + "|\\" + Constants::BRIGHT_YELLOW + "     (   :" + Constants::DARK_BROWN + "oOOOo" + Constants::BRIGHT_YELLOW + ":   )    \n" +
        Constants::BRIGHT_GREEN + "\\.\\\/" + Constants::BRIGHT_YELLOW + "    '--'" + Constants::DARK_BROWN + "oOOOo" + Constants::BRIGHT_YELLOW + "'--'     \n" +
        Constants::BRIGHT_GREEN + ".. ;/|    " + Constants::BRIGHT_YELLOW + ".''" + Constants::DARK_BROWN + "oOo" + Constants::BRIGHT_YELLOW + "''.       \n" +
        Constants::BRIGHT_GREEN + "-`'. :/|" + Constants::BRIGHT_YELLOW + "'-(   /   )-      \n" +
        Constants::BRIGHT_GREEN + "--. `. / //" + Constants::BRIGHT_YELLOW + "'-._.-;         \n" +
        Constants::BRIGHT_GREEN + " `'-,_';//   /|           \n"
        "      '((   /./_          \n"
        "        \\\\; ..-'          \n"
        "         \\.'`--.          \n"
        "          \\ .--'          \n"
        "           )'`            \n"
        "         //-'             \n"
        "        //                \n"
        "       //                 " +
        Constants::DARK_BROWN + "                        " + Constants::RESET;

    // Full bloom with detailed center
    ascii[8] = 
        Constants::BRIGHT_YELLOW + "          .-.'  '.-.      \n"
        "       .-(   " + Constants::DARK_BROWN + "\\  /" + Constants::BRIGHT_YELLOW + "   )-.   \n"
        "      /   '.." + Constants::DARK_BROWN + "oOOo" + Constants::BRIGHT_YELLOW + "..'   \\  \n" +
        Constants::BRIGHT_GREEN + "," + Constants::BRIGHT_YELLOW + "     \\.--.." + Constants::DARK_BROWN + "oOOOOOo" + Constants::BRIGHT_YELLOW + ".--./   \n" +
        Constants::BRIGHT_GREEN + "|\\  ," + Constants::BRIGHT_YELLOW + "  (   :" + Constants::DARK_BROWN + "oOOOOo" + Constants::BRIGHT_YELLOW + ":   )   \n" +
        Constants::BRIGHT_GREEN + "\\.\\/|" + Constants::BRIGHT_YELLOW + "  /'--'" + Constants::DARK_BROWN + "oOOOOo" + Constants::BRIGHT_YELLOW + "'--'\\   \n" +
        Constants::BRIGHT_GREEN + ".. ;/|" + Constants::BRIGHT_YELLOW + " \\   .''" + Constants::DARK_BROWN + "oOo" + Constants::BRIGHT_YELLOW + "''.   /  \n" +
        Constants::BRIGHT_GREEN + "-`'. :/|'" + Constants::BRIGHT_YELLOW + "-(   /  \\   )-'  \n" +
        Constants::BRIGHT_GREEN + "--. `. / //" + Constants::BRIGHT_YELLOW + "'-'.__.'-;     \n" +
        Constants::BRIGHT_GREEN + " `'-,_';//      ,  /|     \n"
        "      '((       |\\/./_    \n"
        "        \\\\  . |\\; ..-'    \n"
        "         \\\\ |\\: .'`--.    \n"
        "          \\\\, .' .--'     \n"
        "           ))'_,-'`       \n"
        "          //-'            \n"
        "         //               \n"
        "        //                " +
        Constants::DARK_BROWN + "                       " + Constants::RESET;

    // Mature flower in full glory
    ascii[9] = 
        Constants::BRIGHT_YELLOW + "             .-.'  '.-.    \n"
        "          .-(   " + Constants::DARK_BROWN + "\\  /" + Constants::BRIGHT_YELLOW + "   )-. \n"
        "         /   '.." + Constants::DARK_BROWN + "oOOo" + Constants::BRIGHT_YELLOW + "..'   \\\n" +
        Constants::BRIGHT_GREEN + " ," + Constants::BRIGHT_YELLOW + "       \\.--.." + Constants::DARK_BROWN + "oOOOOOOo" + Constants::BRIGHT_YELLOW + ".--./\n" +
        Constants::BRIGHT_GREEN + " |\\  ," + Constants::BRIGHT_YELLOW + "   (   :" + Constants::DARK_BROWN + "oOOOOOOo" + Constants::BRIGHT_YELLOW + ":   )\n" +
        Constants::BRIGHT_GREEN + "_\\.\\/|" + Constants::BRIGHT_YELLOW + "   /'--'" + Constants::DARK_BROWN + "oOOOOOOo" + Constants::BRIGHT_YELLOW + "'--'\\\n" +
        Constants::BRIGHT_GREEN + "'-.. ;/|" + Constants::BRIGHT_YELLOW + " \\   .''" + Constants::DARK_BROWN + "oOOo" + Constants::BRIGHT_YELLOW + "''.   /\n" +
        Constants::BRIGHT_GREEN + ".--`'. :/|" + Constants::BRIGHT_YELLOW + "'-(   /  \\   )-' \n" +
        Constants::BRIGHT_GREEN + " '--. `. / //" + Constants::BRIGHT_YELLOW + "'-'.__.'-;    \n" +
        Constants::BRIGHT_GREEN + "   `'-,_';//      ,  /|    \n"
        "        '((       |\\/./_   \n"
        "          \\\\  . |\\; ..-'   \n"
        "           \\\\ |\\: .'`--.   \n"
        "            \\\\, .' .--'    \n"
        "             ))'_,-'`      \n"
        "            //-'           \n"
        "           //              \n"
        "          //               " +
        Constants::DARK_BROWN + "                         " + Constants::RESET;
}
