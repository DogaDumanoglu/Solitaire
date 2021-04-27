//
// Created by dumanoglu on 17.11.2020.
//

#ifndef UNTITLED1_ARRAYOPERATIONS_H
#define UNTITLED1_ARRAYOPERATIONS_H


#include "Cards.h"
#include <array>

class ArrayOperations {
public:
    static array<Cards,24>deleteArray(array<Cards,24> arr);
    static array<Cards,24>reverseArray(array<Cards,24> arr);
    static void slideElementsToEnd(array<Cards,24> &arrDestination);
};


#endif //UNTITLED1_ARRAYOPERATIONS_H
