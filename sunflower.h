#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "plant.h"

class Sunflower : public Plant {
    public:
        // constructors
        Sunflower();
        Sunflower(float w, float f, float s);

        // inherited virtual functions
        void generateArt() override;
        int Grow() override;
        int Prune() override;

    private:
        std::string ascii[10];
};

#endif
