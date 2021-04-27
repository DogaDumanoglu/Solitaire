//
// Created by dumanoglu on 15.11.2020.
//

#include "Stock.h"
#include <array>

#include <utility>
void Stock::setStock(Cards card){
    Stock::stockArray[Stock::numberOfCardsInStock]=std::move(card);
    this->numberOfCardsInStock++;
}

Stock Stock::setCardsToStock(Stock stock, std::array<Cards, 52> deckArray) {
    for(int i=23;i>=0;i--){
        stock.setStock(deckArray[i]);}
    return stock;

}