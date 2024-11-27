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
        int Grow() override;

    private:
        std::string ascii[10]; 

};


#endif