#include <iostream>
#include <fstream>
#include "Cards.h"
#include "Piles.h"
#include "Output.h"
#include "Stock.h"
#include "Foundation.h"
#include "Tableau.h"
#include "CommandOperations.h"
#include "ArrayOperations.h"
#include "Waste.h"
#include <string.h>
#include <array>
using namespace std;
int main(int argc,char*argv[]) {
    Foundation foundationHeart;
    Foundation foundationDiamond;
    Foundation foundationSpades;
    Foundation foundationClubs;
    std::array<Piles,7> tableau;
    Stock stock;
    ifstream deckFile;
    string cards;
    string color;
    Cards card;
    std::array<Cards,52> deckArray;
    std::array<Cards,24> wasteArray;
    int count=0;
    deckFile.open(argv[1]);
    if (deckFile.is_open()) {
        while (!deckFile.eof()) {
            while (getline(deckFile, cards)) {
                string cardName=cards.substr(0,3);
                string cardType=cards.substr(0,1);
                int cardNumber=stoi(cards.substr(1,3));
                if(cardType=="H"||cardType=="D"){
                    color="red";
                    card=Cards(cardName,cardType,cardNumber,color);
                }
                else{
                    color="black";
                    card=Cards(cardName,cardType,cardNumber,color);
                }

                deckArray[count]=card;

                count++;}
        }
    }
    deckFile.close();
    tableau=Tableau::setPilesToTableau(tableau,deckArray);
    stock=Stock::setCardsToStock(stock,deckArray);
    ifstream commandFile;
    string commands;
    int usedCards=0;
    commandFile.open(argv[2]);
    if(commandFile.is_open()){
        while(!commandFile.eof()){
            while(getline(commandFile,commands)){
                const char* commandCharArray=commands.c_str();
                Output::writeOutput(argv[3],stock.stockArray,wasteArray,foundationDiamond,foundationHeart,foundationSpades,foundationClubs,commands,usedCards,tableau);
                if(strncmp(commandCharArray,"move to foundation pile",23)==0){
                    int pileNum=stoi(commands.substr(24,25));
                    bool valid=CommandOperations::moveToFoundationPileOrWaste(tableau[pileNum].arr,foundationDiamond,foundationHeart,foundationSpades,foundationClubs);
                    if(valid){
                        tableau[pileNum].arr=ArrayOperations::deleteArray(tableau[pileNum].arr);
                        tableau[pileNum].numberOfCardsInPile--;
                        Output:: writeValid(argv[3],"");}
                    else{
                        Output:: writeValid(argv[3],"Invalid Move !");
                    }



                }
                else if(strncmp(commandCharArray,"open",4)==0&&strncmp(commandCharArray,"open from stock",15)!=0){
                    int pileNum=stoi(commands.substr(5,6));
                    tableau[pileNum].arr[0].openCard();
                    Output:: writeValid(argv[3],"");
                }
                else if(strncmp(commandCharArray,"move pile",9)==0){
                    int initialPileNum=stoi(commands.substr(10,11));
                    int cardIndex=stoi(commands.substr(12,13));
                    int destinationPileNum=stoi(commands.substr(14,15));
                    bool valid=CommandOperations::movePile(initialPileNum,cardIndex,destinationPileNum,tableau);
                    if(valid){
                        for (int j = cardIndex;j>=0; j--) {
                            tableau[initialPileNum].arr = ArrayOperations::deleteArray(tableau[initialPileNum].arr);
                            tableau[initialPileNum].numberOfCardsInPile--;
                            tableau[destinationPileNum].numberOfCardsInPile++;
                        }
                        Output:: writeValid(argv[3],"");
                    }
                    else{
                        Output:: writeValid(argv[3],"Invalid Move !");
                    }
                }
                else if(strncmp(commandCharArray,"exit",4)==0){
                    Output:: writeValid(argv[3],"");
                    Output::writeWinOrLose(argv[3],"lose",foundationDiamond,foundationHeart,foundationSpades,foundationClubs);
                    exit(0);
                }
                else if(strncmp(commandCharArray,"open from stock",15)==0){
                    Waste::setCardsToWaste(stock,wasteArray);
                    usedCards=0;
                    Output:: writeValid(argv[3],"");
                }
                else if(strncmp(commandCharArray,"move waste",10)==0){
                    int destinationPileNum=stoi(commands.substr(11,12));
                    bool valid=CommandOperations::moveWaste(wasteArray,destinationPileNum,tableau);
                    if(valid){
                        wasteArray=ArrayOperations::deleteArray(wasteArray);
                        tableau[destinationPileNum].numberOfCardsInPile++;
                        usedCards++;
                        Output:: writeValid(argv[3],"");
                    }
                    else{
                        Output:: writeValid(argv[3],"Invalid Move !");
                    }

                }
                else if(strncmp(commandCharArray,"move to foundation waste",24)==0){
                    bool valid=CommandOperations::moveToFoundationPileOrWaste(wasteArray,foundationDiamond,foundationHeart,foundationSpades,foundationClubs);
                    if(valid){
                        wasteArray=ArrayOperations::deleteArray(wasteArray);
                        usedCards++;
                        Output:: writeValid(argv[3],"");}
                    else{
                        Output:: writeValid(argv[3],"Invalid Move !");
                    }


                }

            }

        }
        Output::writeOutput(argv[3],stock.stockArray,wasteArray,foundationDiamond,foundationHeart,foundationSpades,foundationClubs,commands,usedCards,tableau);
        Output:: writeValid(argv[3],"end");
        Output::writeWinOrLose(argv[3],"win",foundationDiamond,foundationHeart,foundationSpades,foundationClubs);
    }

    commandFile.close();



}
