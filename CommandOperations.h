//
// Created by dumanoglu on 17.11.2020.
//

#ifndef UNTITLED1_COMMANDOPERATIONS_H
#define UNTITLED1_COMMANDOPERATIONS_H


#include "Foundation.h"
#include "Piles.h"
#include <array>

class CommandOperations {
public:
    static bool moveToFoundationPileOrWaste(array<Cards,24>& arr, Foundation &foundationDiamond, Foundation &foundationHeart, Foundation &foundationSpades, Foundation &foundationClubs);
    static bool movePile(int initialPileNum,int cardIndex,int destinationPileNum,array<Piles,7> &tableau);
    static bool moveWaste(array<Cards,24>&wasteArray,int destinationPileNum,array<Piles,7> &tableau);
};


#endif //UNTITLED1_COMMANDOPERATIONS_H
