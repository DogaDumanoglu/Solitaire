//
// Created by dumanoglu on 14.11.2020.
//

#ifndef UNTITLED1_PILES_H
#define UNTITLED1_PILES_H


#include <array>
#include "Cards.h"

class Piles {
public:
    int numberOfCardsInPile=0;
    std::array<Cards,24> arr;
    void setInitialCards(Cards card);
    Piles(int pileNum);
    int pileNum=0;
    Piles();
    static void setCardsToPile(Piles* pile,std::array<Cards,52>deckArray);
};


#endif //UNTITLED1_PILES_H
