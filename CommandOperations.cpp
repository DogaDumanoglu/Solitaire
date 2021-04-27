//
// Created by dumanoglu on 17.11.2020.
//

#include "CommandOperations.h"
#include "Foundation.h"
#include "ArrayOperations.h"
#include <array>


bool CommandOperations::moveToFoundationPileOrWaste(array<Cards,24>&arr,Foundation &foundationDiamond,Foundation &foundationHeart,Foundation &foundationSpades,Foundation &foundationClubs) {
    if(arr[0].cardType=="D"){
        if(foundationDiamond.foundationArray[0].cardNumber+1==arr[0].cardNumber){
            foundationDiamond.setCardsToFoundation(arr[0]);
            return true;
            }
    }
    else if(arr[0].cardType=="H"){
        if(foundationHeart.foundationArray[0].cardNumber+1==arr[0].cardNumber ){
            foundationHeart.setCardsToFoundation(arr[0]);
            return true;}
    }
    else if(arr[0].cardType=="S"){
        if(foundationSpades.foundationArray[0].cardNumber+1==arr[0].cardNumber) {
            foundationSpades.setCardsToFoundation(arr[0]);
            return true;
        }

    }

    else if(arr[0].cardType=="C"){
        if(foundationClubs.foundationArray[0].cardNumber+1==arr[0].cardNumber) {
            foundationClubs.setCardsToFoundation(arr[0]);
            return true;
        }

    }
    return false;
}
bool CommandOperations::movePile(int initialPileNum,int cardIndex,int destinationPileNum,array<Piles,7> &tableau){
    if(tableau[destinationPileNum].arr[0].cardNumber-1==tableau[initialPileNum].arr[cardIndex].cardNumber
    &&tableau[destinationPileNum].arr[0].cardColor!=tableau[initialPileNum].arr[cardIndex].cardColor
    ||tableau[destinationPileNum].arr[0].cardNumber==0&&tableau[initialPileNum].arr[cardIndex].cardNumber==13) {
        for (int j = cardIndex;j>=0; j--) {
            ArrayOperations::slideElementsToEnd(tableau[destinationPileNum].arr);
            tableau[destinationPileNum].arr[0] = tableau[initialPileNum].arr[j];
        }
        return true;
    }
    return false;
}
bool CommandOperations::moveWaste(array<Cards,24>&wasteArray,int destinationPileNum,array<Piles,7> &tableau){
    if(tableau[destinationPileNum].arr[0].cardNumber-1==wasteArray[0].cardNumber
       &&tableau[destinationPileNum].arr[0].cardColor!=wasteArray[0].cardColor
       ||tableau[destinationPileNum].arr[0].cardNumber==0&&wasteArray[0].cardNumber==13){
        ArrayOperations::slideElementsToEnd(tableau[destinationPileNum].arr);
        tableau[destinationPileNum].arr[0]=wasteArray[0];
        return true;
    }
    return false;

}

