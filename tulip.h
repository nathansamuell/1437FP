// tulip.h
#ifndef TULIP_H
#define TULIP_H
#include "plant.h"
#include <string>
#include <iostream>

class Tulip : public Plant {
    public:
        // constructors
        Tulip();
        Tulip(float, float, float);
        void generateArt() override;
        // Grow
        int Grow() override;
        int Prune() override;
        int Water() override;
        int Sun() override;
        int Fertilize() override;

        std::string getType() const override { return "Tulip"; } // new method

    private:
        std::string ascii[10];
};

#endif