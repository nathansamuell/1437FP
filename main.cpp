// include statements
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <stdlib.h>

#include "plant.h"
#include "bonsai.h"
#include "tulip.h"
#include "sunflower.h"
#include "constants.h"

std::string initGame(std::string &playerName);
void recordGame();

int main() {
    std::string playerInput;
    std::string playerName;
    std::vector<Plant*> plants;

    system(Constants::CLEAR_SCREEN);
    playerInput = initGame(playerName);
    system(Constants::CLEAR_SCREEN);
    std::cout << Constants::HEADER;

    do {
        std::cout << "Choose an option (1: Start a new plant, 2: Operate on an existing plant, 0: Exit): ";
        int mainChoice;
        std::cin.ignore();
        std::cin >> mainChoice;

        if (mainChoice == 0) {
            std::cout << "Exiting the game. Goodbye!" << std::endl;
            break; // Exit the loop
        } else if (mainChoice == 1) {
            std::cout << "Choose a plant (1: Bonsai, 2: Sunflower, 3: Tulip): ";
            int plantChoice;
            std::cin.ignore();
            std::cin >> plantChoice;

            bool plantExists = false;
            for (Plant* plant : plants) {
                if ((plantChoice == 1 && dynamic_cast<Bonsai*>(plant)) ||
                    (plantChoice == 2 && dynamic_cast<Sunflower*>(plant)) ||
                    (plantChoice == 3 && dynamic_cast<Tulip*>(plant))) {
                    plantExists = true;
                    break;
                }
            }

            if (plantExists) {
                std::cout << "You already have this type of plant. Please choose a different one." << std::endl;
                continue; // Skip to the next iteration
            } else if (plantChoice == 1) {
                playerInput = "Bonsai";
                plants.push_back(new Bonsai());
            } else if (plantChoice == 2) {
                playerInput = "Sunflower";
                plants.push_back(new Sunflower());
            } else if (plantChoice == 3) {
                playerInput = "Tulip";
                plants.push_back(new Tulip());
            } else {
                std::cout << "Invalid choice. Please choose again. Press enter to continue." << std::endl;
                std::cin.get();
                continue; // Skip to the next iteration
            }
        } else if (mainChoice == 2) {
            if (plants.empty()) {
                std::cout << "No plants available. Please start a new plant first." << std::endl;
                continue; // Skip to the next iteration
            }

            std::cout << "Choose a plant to operate on: " << std::endl;
            for (size_t i = 0; i < plants.size(); ++i) {
                std::cout << i + 1 << ": " << typeid(*plants[i]).name() << std::endl;
            }
            int plantIndex;
            std::cin >> plantIndex;

            if (plantIndex < 1 || plantIndex > plants.size()) {
                std::cout << "Invalid choice. Please choose again." << std::endl;
                continue; // Skip to the next iteration
            }

            Plant* selectedPlant = plants[plantIndex - 1];
            playerInput = typeid(*selectedPlant).name();

            int actionChoice = -1;
            do {
                std::cout << "What would you like to do with your " << playerInput << "? (1: Water, 2: Sun, 3: Fertilize, 4: Grow, 0: Exit): ";
                std::cin >> actionChoice;

                if (actionChoice == 0) {
                    std::cout << "Would you like to save your game? (y/n): ";
                    std::string gameSave;
                    std::cin >> gameSave;

                    std::cout << "Exiting the game. Goodbye!" << std::endl;
                    break; // Exit the loop
                } else if (actionChoice == 1) {
                    std::cout << "You watered your " << playerInput << "." << std::endl;
                } else if (actionChoice == 2) {
                    std::cout << "You gave some sun to your " << playerInput << "." << std::endl;
                } else if (actionChoice == 3) {
                    std::cout << "You fertilized your " << playerInput << "." << std::endl;
                } else if (actionChoice == 4) {
                    std::cout << "You let your " << playerInput << " grow." << std::endl;
                } else {
                    std::cout << "Invalid choice. Please choose again." << std::endl;
                }
            } while (actionChoice != 0);
        } else {
            std::cout << "Invalid choice. Please choose again." << std::endl;
        }
    } while (true);

    // cleanup
    for (Plant* plant : plants) {
        delete plant;
    }

    return 0;
}

std::string initGame(std::string &playerName) {
    std::string playerInput;
    
    std::cout << Constants::HEADER;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);
    system(Constants::CLEAR_SCREEN);
    std::cout << Constants::HEADER;
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
    system(Constants::CLEAR_SCREEN);
    std::cout << Constants::HEADER;
    
    while (true) {
        std::cout << "Choose a starter plant (Sunflower, Tulip, Bonsai): ";
        std::cin >> playerInput;

        if (playerInput == "Sunflower" || playerInput == "Tulip" || playerInput == "Bonsai") {
            break;
        } else {
            std::cout << "Invalid choice. Please choose again." << std::endl;
        }
    }
    return playerInput;
}

void recordGame() {

}