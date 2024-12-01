#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include "plant.h"
#include <string>

class Sunflower : public Plant {
    public:
        // constructors
        Sunflower();
        Sunflower(float w, float f, float s);
        // inherited virtual functions
        void generateArt() override;
        int Grow() override;
        int Prune() override;
        int Water() override;
        int Sun() override;
        int Fertilize() override;
        std::string getType() const override { return "Sunflower"; } // new method

    private:
        std::string ascii[10];
};

#endif