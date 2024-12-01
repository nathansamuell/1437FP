// include statements
#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>

#include "plant.h"
#include "bonsai.h"
#include "tulip.h"
#include "sunflower.h"
#include "constants.h"

std::string initGame(std::string &playerName);
void recordGame();

int main() {
    std::string playerName;
    std::string playerInput;
    
    system(Constants::CLEAR_SCREEN);
    playerInput = initGame(playerName);
    system(Constants::CLEAR_SCREEN);
    std::cout << Constants::HEADER;

    // New do-while loop for plant selection and interaction
    do {
        // std::cout << "Choose a plant (1: Bonsai, 2: Sunflower, 3: Tulip, 0: Exit): ";
        // int plantChoice;
        // std::cin.ignore();
        // std::cin >> plantChoice;

        // if (plantChoice == 0) {
        //     std::cout << "Exiting the game. Goodbye!" << std::endl;
        //     break; // Exit the loop
        // } else if (plantChoice == 1) {
        //     playerInput = "Bonsai";
        // } else if (plantChoice == 2) {
        //     playerInput = "Sunflower";
        // } else if (plantChoice == 3) {
        //     playerInput = "Tulip";
        // } else {
        //     std::cout << "Invalid choice. Please choose again. Press enter to continue." << std::endl;
        //     std::cin.get();
        //     continue; // Skip to the next iteration
        // }

        // Interaction loop for the chosen plant
        int actionChoice = -1;
        do {
            std::cout << "What would you like to do with your " << playerInput << "? (1: Water, 2: Sun, 3: Fertilize, 4: Grow, 0: Exit ";
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
    } while (true);

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