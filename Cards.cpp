//
// Created by dumanoglu on 14.11.2020.
//

#include "Cards.h"
#include <array>
Cards::Cards(string cardName, string cardType, int cardNumber,string cardColor) {
this->cardName=std::move(cardName);
this->cardType=std::move(cardType);
this->cardNumber=cardNumber;//all card closed at the begining
this->cardColor=std::move(cardColor);
}
void Cards::openCard() {
    this->close=false;
}

Cards::Cards() {

}
