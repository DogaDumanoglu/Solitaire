//
// Created by dumanoglu on 15.11.2020.
//

#ifndef UNTITLED1_STOCK_H
#define UNTITLED1_STOCK_H
#include "Cards.h"
#include <array>

class Stock {
public:
    std::array<Cards,24> stockArray;
    void setStock(Cards card);
    int numberOfCardsInStock=0;
    static Stock setCardsToStock(Stock stock, std::array<Cards,52>deckArray);

};


#endif //UNTITLED1_STOCK_H
