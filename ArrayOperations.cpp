//
// Created by dumanoglu on 17.11.2020.
//

#include "ArrayOperations.h"
#include "Cards.h"
#include <array>

array<Cards,24>ArrayOperations::deleteArray(array<Cards,24> arr){
    array<Cards,24>deleteArray;
    for(int i=0;i<arr.size()-1;i++){
        deleteArray[i]=arr[i+1];
    }
    deleteArray[23]=Cards();
    return deleteArray;

}
array<Cards,24>ArrayOperations::reverseArray(array<Cards,24> arr){
    array<Cards,24>reverseArray;
    int count=0;
    for(int i=23;i>=0;i--){
        if(arr[i].cardNumber!=0){
            reverseArray[count]=arr[i];
            count++;
        }

    }
    reverseArray[0].openCard();
    return reverseArray;

}

void ArrayOperations::slideElementsToEnd(array<Cards, 24> &arr) {
    if(arr[23].cardNumber==0){
        for(int i=22;i>=0;i--)
        {
            arr[i+1] = arr[i]; //move all element to the right except last one
        }
        arr[0]=Cards();
    }
}


