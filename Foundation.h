//
// Created by dumanoglu on 16.11.2020.
//

#ifndef UNTITLED1_FOUNDATION_H
#define UNTITLED1_FOUNDATION_H
#include <array>
#include "Cards.h"

class Foundation {
public:
    std::array<Cards,24> foundationArray;
    void setCardsToFoundation(Cards cards);

};


#endif //UNTITLED1_FOUNDATION_H
