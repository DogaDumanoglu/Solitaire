//
// Created by dumanoglu on 14.11.2020.
//

#ifndef UNTITLED1_CARDS_H
#define UNTITLED1_CARDS_H
#include<iostream>
#include <array>
using namespace std;


class Cards {
public:
    string cardName;
    int cardNumber=0;
    bool close=true;
    string cardType;
    string cardColor;
public:
    Cards(string cardName,string cardType,int cardNumber,string cardColor);
    void openCard();
    Cards();
};


#endif //UNTITLED1_CARDS_H
