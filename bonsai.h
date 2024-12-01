// bonsai.h
#ifndef BONSAI_H
#define BONSAI_H

#include "plant.h"
#include <string>
#include <iostream>

class Bonsai : public Plant {
    public:
        // constructors
        Bonsai();
        Bonsai(float, float, float);

        void generateArt() override;

        // Grow
        int Water() override;
        int Sun() override;
        int Fertilize() override;
        int Grow() override;
        int Prune() override;

        std::string getType() const override { return "Bonsai"; } // new method

    private:
        std::string ascii[10]; 

};

#endif