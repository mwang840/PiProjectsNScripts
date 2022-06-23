#include "card.h"
#include <stdlib.h> // for drand48
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
 
/* This main() is constructed just for testing purposes. See
 * play_game() below for actually connecting together the pieces */
void playGame();
int countPile(theCard *cards);
void showPile(theCard *pile);
void revealHand(theCard *cards);
theCard *deal(theCard *cards);
theCard *createDeck();
theCard *shuffle(theCard *pile);
int totalHand(theCard *cards);
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
    theCard card3={4,'C',NULL}, card2={1,'H',NULL}, card1={12,'S',NULL};
    card1.next=&card2; card2.next=&card3; // Why &card2 and &card3?
    theCard *deck=&card1;
    printf("Cards in deck: %d\n",countPile(deck));
    showPile(deck);
    return 0;
 }

// organize all the helper functions to play a complete game
void play_game(void) {
    int score = 0;
    int dealerScore = 0;
    int totalPile = 0;
    theCard *bigDeck = createDeck();
    
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
        }
    }
    return;
}
