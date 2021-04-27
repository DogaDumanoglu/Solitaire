//
// Created by dumanoglu on 16.11.2020.
//

#include "Foundation.h"
#include "ArrayOperations.h"
#include <array>

void Foundation::setCardsToFoundation(Cards cards) {
    ArrayOperations::slideElementsToEnd(foundationArray);
    this->foundationArray[0]=cards;
}
