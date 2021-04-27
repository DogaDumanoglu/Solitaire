//
// Created by dumanoglu on 18.11.2020.
//

#include "Waste.h"
#include "ArrayOperations.h"
#include <array>

void Waste::setCardsToWaste(Stock &stock, array<Cards, 24> &wasteArray) {
    array<Cards,24>deleteArray;
    array<Cards,3>tempArray;
    if(stock.stockArray[0].cardNumber!=0){
        if(stock.stockArray[2].cardNumber==0){
            if(stock.stockArray[1].cardNumber==0){
                tempArray[0]=stock.stockArray[0];
            }
            else{
            for(int i=0;i<2;i++){
                tempArray[1-(i%2)]=stock.stockArray[i];}
            }
        }

        else{
        for(int i=0;i<3;i++){
            tempArray[2-(i%3)]=stock.stockArray[i];
        }
        }
        for(int j=0;j<3;j++){
            for(int i=23;i>=0;i--){
                wasteArray[i+1]=wasteArray[i];}
            wasteArray[0]=Cards();}

        for(int i=0;i<3;i++){
            tempArray[i].openCard();
            wasteArray[i]=tempArray[i];
            stock.stockArray=ArrayOperations::deleteArray(stock.stockArray);

        }
        for(int i=0;i<3;i++){
        tempArray[i]=Cards();}
    }
    else{

        stock.stockArray = ArrayOperations::reverseArray(wasteArray);
        wasteArray = deleteArray;
    }
}

