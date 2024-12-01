#ifndef PLANT_H
#define PLANT_H

#include <vector>
#include <iostream>
#include <fstream>
#include "constants.h"

class Plant {  // base class to inherit from
    public:
        // constructors
        Plant();
        Plant(float, float, float);      // can set consumption values manually
        virtual void generateArt() = 0;  // not technically a constructor but

        // setters/getters
        // std::vector<float> getC() const;            // returns a vector of consumption rates
        // std::vector<float> getL() const;            // returns a vector of nutrient levels
        // float getWC() const {return waterC;};       // get each value individually
        // float getFC() const {return fertilizerC;};
        // float getSC() const {return sunlightC;};
        float getWL() const {return waterL;};
        float getFL() const {return fertilizerL;};
        float getSL() const {return sunlightL;};
        int getAge() const {return age;};
        int getHP() const {return hp;};
        int getStage() const {return growthStage;};
        void setC(float, float, float);             // update all rates
        void setL(float, float, float);             // update all levels
        // void setWC(float w);                        // update individually
        // void setFC(float f);
        // void setSC(float s);
        // void setWL(float w);
        // void setFL(float f);
        // void setSL(float s);

        // operators
        virtual int Grow() = 0; // virtual function to operate plants, will work differently for all of them each turn
        virtual int Prune() = 0;

    protected:
        int hp = 5;
        float waterC, fertilizerC, sunlightC;
        float waterL, fertilizerL, sunlightL = 0;
        int age = 0;
        int growthStage = 0;
};

#endif