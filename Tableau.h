//
// Created by dumanoglu on 17.11.2020.
//

#ifndef UNTITLED1_TABLEAU_H
#define UNTITLED1_TABLEAU_H


#include "Output.h"
#include <array>

class Tableau {
public:
    static std::array<Piles,7> setPilesToTableau(std::array<Piles,7> tableau, std::array<Cards,52>deckArray);
};


#endif //UNTITLED1_TABLEAU_H
