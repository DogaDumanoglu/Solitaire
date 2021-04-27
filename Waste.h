//
// Created by dumanoglu on 18.11.2020.
//

#ifndef UNTITLED1_WASTE_H
#define UNTITLED1_WASTE_H
#include <array>
#include "Cards.h"
#include "Stock.h"

class Waste {
public:
    static void setCardsToWaste(Stock &stock,array<Cards,24>&wasteArray);
};


#endif //UNTITLED1_WASTE_H
