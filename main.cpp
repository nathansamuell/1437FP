#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

#include "plant.h"
#include "bonsai.h"
#include "tulip.h"
#include "sunflower.h"
#include "constants.h"

void initGame(std::string &playerName);

int main() {
    std::string playerInput;
    std::string playerName;
    std::vector<Plant*> plants;

    system(Constants::CLEAR_SCREEN);
    initGame(playerName);
    system(Constants::CLEAR_SCREEN);
    std::cout << Constants::HEADER;

    bool exitGame = false;

    do {
        std::cout << "Choose an option (1: Start a new plant, 2: Operate on an existing plant, 0: Exit): ";
        int mainChoice;
        std::cin >> mainChoice;

        if (mainChoice == 0) {
            std::cout << "Exiting the game. Goodbye!" << std::endl;
            exitGame = true;
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
                std::cin.ignore();
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
                std::cout << i + 1 << ": " << plants[i]->getType() << std::endl; // use getType
            }
            int plantIndex;
            std::cin >> plantIndex;

            if (plantIndex < 1 || plantIndex > plants.size()) {
                std::cout << "Invalid choice. Please choose again." << std::endl;
                continue; // Skip to the next iteration
            }

            Plant* selectedPlant = plants[plantIndex - 1];
            std::string plantType = selectedPlant->getType(); // use getType

            int actionChoice = -1;
            do {
                std::cout << "What would you like to do with your " << plantType << "? (1: Water, 2: Sun, 3: Fertilize, 4: Grow, 5: Prune, 0: Exit): ";
                std::cin >> actionChoice;

                int result = 0;
                if (actionChoice == 0) {
                    std::cout << "Exiting the game. Goodbye!" << std::endl;
                    exitGame = true;
                    break; // Exit the loop
                } else if (actionChoice == 1) {
                    result = selectedPlant->Water();
                } else if (actionChoice == 2) {
                    result = selectedPlant->Sun();
                } else if (actionChoice == 3) {
                    result = selectedPlant->Fertilize();
                } else if (actionChoice == 4) {
                    result = selectedPlant->Grow();
                } else if (actionChoice == 5) {
                    result = selectedPlant->Prune();
                } else {
                    std::cout << "Invalid action. Please choose again." << std::endl;
                }

                if (result == 1) {
                    std::cout << "Your plant has died." << std::endl;
                    delete selectedPlant;
                    plants.erase(plants.begin() + plantIndex - 1);
                    break;
                } else if (result == 2) {
                    std::cout << "Your plant has reached its maximum growth!" << std::endl;
                }
            } while (actionChoice != 0);

            if (exitGame) {
                break; // Exit the main loop if the user chose to exit
            }
        } else {
            std::cout << "Invalid choice. Please choose again." << std::endl;
        }
    } while (!exitGame);

    // cleanup
    for (Plant* plant : plants) {
        delete plant;
    }

    return 0;
}

void initGame(std::string &playerName) {
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
}