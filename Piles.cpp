//
// Created by dumanoglu on 14.11.2020.
//

#include "Piles.h"
#include <algorithm>
#include <utility>
#include <array>
#include "ArrayOperations.h"
void Piles::setInitialCards(Cards card){
    Piles::arr[Piles::numberOfCardsInPile]=std::move(card);
    this->numberOfCardsInPile++;

}

Piles::Piles(int pileNum){
    Piles::pileNum=pileNum;

}
void Piles::setCardsToPile(Piles* pile,std::array<Cards,52>deckArray){
    int index=51-pile->pileNum;
    pile->setInitialCards(deckArray[index]);
    int subtract=6;
    for(int i=0;i<pile->pileNum;i++){
        index=index-subtract--;
        pile->setInitialCards(deckArray[index]);

    }
    pile->arr=ArrayOperations::reverseArray(pile->arr);
}

Piles::Piles() {

}
