//
// Created by dumanoglu on 14.11.2020.
//

#ifndef UNTITLED1_OUTPUT_H
#define UNTITLED1_OUTPUT_H
#include <array>
#include "Piles.h"
#include "Foundation.h"

using namespace  std;
class Output {
public:
    static void writeValid(string output,string writevalid);
    static void writeOutput(string output,array<Cards,24>&stockArray,array<Cards,24>&wasteArray,Foundation &foundationDiamond,Foundation &foundationHeart,Foundation &foundationSpades,Foundation &foundationClubs,string &commands,int &usedCards,array<Piles,7> &tableau);
    static void writeWinOrLose(string output,string win, Foundation &foundationDiamond, Foundation &foundationHeart,Foundation &foundationSpades, Foundation &foundationClubs);
};


#endif //UNTITLED1_OUTPUT_H
