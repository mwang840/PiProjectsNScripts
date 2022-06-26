#include "card.h"
#include <stdlib.h> // for drand48
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
 
/* This main() is constructed just for testing purposes. See
 * play_game() below for actually connecting together the pieces */
// Don't be afraid of writing "scaffolding code" like this: yes, it will be
// removed at the end, but that doesn't make it a waste of effort!
int main(int argc, char *argv[]) {
    // the below "seeds" the random number generator with the first argument
    // given to the program. I.e. "./game 5" will always play with the same
    // shuffle, and "./game 99" will play with a different shuffle. Leave this
    // in your final code for testing.
    if(argc>1) {
        srand48(atol(argv[1]));
    }
    play_game();
    return 0;
 }

// organize all the helper functions to play a complete game
void play_game(void) {
    theCard *bigDeck = createDeck();
    int totalPile = 0;
    for(int i = 0; i < 7; ++i){
        bigDeck = shuffle(bigDeck);
    }
    theCard *user;
    theCard *dealer;
    user = deal(bigDeck);
    user->next = deal(bigDeck);
    dealer = deal(bigDeck);
    printf("Your hand\n");
    showPile(user);
    printf("Dealers hand is\n");
    showPile(dealer);
    printf("Hit or stand?\n");
    char *hitOrStand = (char *)malloc(sizeof(char) * 6);
    while(scanf("%s", hitOrStand)){
        if(strcmp(hitOrStand, "H") == 0 || strcmp(hitOrStand, "h") == 0 || strcmp(hitOrStand, "Hit") == 0 || strcmp(hitOrStand, "hit") == 0){
            //User pointer is now being refered as the temp pointer
            theCard *temp = user;
            while(temp != NULL){
                temp = temp->next;
            }
            temp->next = deal(bigDeck);
            totalPile = totalHand(temp);
            showPile(temp);
            if(totalPile> 21){
               printf("You lost. Booo!\n");
               return;
            }
            else if(totalPile == 21){
                break;
            }
            else{
                printf("Your total score is : %d\n ", totalPile);
                printf("Hit or stand?\n");
            }
        }
        else if(strcmp(hitOrStand, "S") == 0 || strcmp(hitOrStand, "s") ==0 || strcmp(hitOrStand, "Stand") == 0 || strcmp(hitOrStand, "stand") == 0){
            break;
        }
        printf("Now its the dealers turn boi\n");
        bool dealerTurn = true;
        while(dealerTurn){
            theCard *tempDealer = dealer;
            while(tempDealer != NULL){
                tempDealer = tempDealer->next;
            }
            tempDealer->next = deal(bigDeck);
            printf("Dealer hand is : ");
            showPile(tempDealer);
            printf("\n");
            int onlyDealer = totalHand(dealer);
            if(onlyDealer >= 17 && onlyDealer <= 21){
                if(onlyDealer > totalPile){
                    printf("You lost boi\n");
                    printf("Dealers total hand is %d", onlyDealer);
                    printf("Your hand is %d");
                    return;
                }
                else if(totalPile > onlyDealer){
                    printf("Congratulations you won!\n");
                    printf("Dealers total hand is %d", onlyDealer);
                    printf("Your hand is %d");
                    return;
                }
                else if(totalPile == onlyDealer){
                    printf("Sorry but according to the rules, equal pile means dealer wins.\n");
                    printf("Dealers and your total hand is %d", onlyDealer);
                    return;
                }
            }
        }
    }
    return;
}
