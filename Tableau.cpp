//
// Created by dumanoglu on 17.11.2020.
//

#include "Tableau.h"
#include <array>
std::array<Piles, 7>
Tableau::setPilesToTableau(std::array<Piles, 7> tableau, std::array<Cards, 52> deckArray) {
    for(int i=0;i<7;i++){
        Piles pile=Piles(i);
        Piles::setCardsToPile(&pile,deckArray);
        tableau[i]=pile;
    }
    return tableau;
}
