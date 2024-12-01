#ifndef PLANT_H
#define PLANT_H

#include <vector>
#include <iostream>
#include <fstream>
#include "constants.h"

class Plant {
    public:
        // constructors
        Plant();
        Plant(float, float, float);      // can set consumption values manually
        virtual void generateArt() = 0;  // not technically a constructor but

        // setters/getters
        float getWL() const {return waterL;};
        float getFL() const {return fertilizerL;};
        float getSL() const {return sunlightL;};
        int getAge() const {return age;};
        int getHP() const {return hp;};
        int getStage() const {return growthStage;};
        void setC(float, float, float);             // update all rates
        void setL(float, float, float);             // update all levels

        // operators
        virtual int Grow() = 0; // virtual function to operate plants, will work differently for all of them each turn
        virtual int Water() = 0;
        virtual int Sun() = 0;
        virtual int Fertilize() = 0;
        virtual int Prune() = 0;

        // new method to get the plant type
        virtual std::string getType() const = 0;

    protected:
        int hp = 5;
        float waterC, fertilizerC, sunlightC;
        float waterL, fertilizerL, sunlightL = 0;
        int age = 0;
        int growthStage = 0;
};

#endif