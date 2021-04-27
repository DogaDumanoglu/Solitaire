//
// Created by dumanoglu on 14.11.2020.
//

#include "Output.h"
#include<algorithm>
#include <fstream>
#include <array>

void Output:: writeValid(string output,string writeValid){
    ofstream ofile;
    ofile.open(output, ios::out | ios::app);
    if(writeValid==""){
        ofile<<endl;
        ofile<<"****************************************"<<endl;
        ofile<<endl;}
    else if(writeValid=="end"){
        ofile<<"****************************************"<<endl;
    }
    else{
        ofile<<endl;
        ofile<<"Invalid Move !"<<endl;
        ofile<<endl;
        ofile<<"****************************************"<<endl;
        ofile<<endl;
    }
}


void Output::writeOutput(string output,array<Cards,24>&stockArray,array<Cards, 24> &wasteArray, Foundation &foundationDiamond, Foundation &foundationHeart,Foundation &foundationSpades, Foundation &foundationClubs,string &commands,int &usedCards,array<Piles,7> &tableau) {
    ofstream ofile;
    ofile.open(output, ios::out | ios::app);
    if(stockArray[0].cardNumber!=0){
      ofile<<"@@@ ";
    }
    else{
        ofile<<"___ ";
    }
    int a=0+usedCards;
    for(int i=2-usedCards;i>=0;i--) {
        if (wasteArray[i].cardNumber == 0) {
            a++;
            continue;
        }
        else{
            ofile<<wasteArray[i].cardName+" ";
        }

      }
    for(int j=a;j>0;j--){
        if(usedCards==3&&j==3&&wasteArray[0].cardNumber!=0){
            ofile<<wasteArray[0].cardName+" ";
        }
        else{
            ofile<<"___ ";
        }

    }

      ofile<<"        ";

    if(foundationHeart.foundationArray[0].cardNumber!=0){
        ofile<<foundationHeart.foundationArray[0].cardName<<" ";
    }
    else{
        ofile<<"___ ";
    }
    if(foundationDiamond.foundationArray[0].cardNumber!=0){
        ofile<<foundationDiamond.foundationArray[0].cardName<<" ";
    }
    else{
        ofile<<"___ ";
    }
    if(foundationSpades.foundationArray[0].cardNumber!=0){
        ofile<<foundationSpades.foundationArray[0].cardName<<" ";
    }
    else{
        ofile<<"___ ";
    }
    if(foundationClubs.foundationArray[0].cardNumber!=0){
        ofile<<foundationClubs.foundationArray[0].cardName<<" ";
    }
    else{
        ofile<<"___ ";
    }
    ofile<<endl<<endl;
    int max=0;

    for(int j=0;j<=6;j++){
        max=std::max(max,tableau[j].numberOfCardsInPile);
    }
    for(int j=0;j<max;j++){
        for(int i=0;i<=6;i++){
            int notEmptyIndexes=tableau[i].numberOfCardsInPile-(j+1);//en alt
            if(notEmptyIndexes>=0){
                if(tableau[i].arr[notEmptyIndexes].close){
                    ofile<<"@@@"<<"   ";
                }
                else{
                    ofile<<tableau[i].arr[notEmptyIndexes].cardName<<"   ";
                }

            }
            else{
                ofile<<"   "<<"   ";
            }
        }
        ofile<<endl;
    }
    ofile<<endl;
    ofile<<commands;
    ofile<<endl;
}
void Output::writeWinOrLose(string output,string win, Foundation &foundationDiamond, Foundation &foundationHeart,Foundation &foundationSpades, Foundation &foundationClubs) {
    ofstream ofile;
    ofile.open(output, ios::out | ios::app);
    if(win=="win"){
        if (foundationDiamond.foundationArray[0].cardNumber != 0 && foundationHeart.foundationArray[0].cardNumber != 0 &&
            foundationClubs.foundationArray[0].cardNumber != 0 && foundationSpades.foundationArray[0].cardNumber != 0) {
            ofile << endl << "You Win!" << endl << endl;
            ofile << "Game Over!" << endl;
        }
    }
    else if(win=="lose")  {
        ofile << "Game Over!" << endl;
    }

}