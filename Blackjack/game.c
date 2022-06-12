#include "card.h"
#include <stdlib.h> // for drand48
#include <stdio.h>
 
/* This main() is constructed just for testing purposes. See
 * play_game() below for actually connecting together the pieces */
void playGame();
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
    theCard *bigDeck = createDeck();
    
    for(int i = 0; i < 7; ++i){
        bigDeck = shuffle(bigDeck);
    }
    theCard *user;
    theCard *dealer;
    user = deal(bigDeck);
    user->next = deal(bigDeck);
    dealer = deal(bigDeck);
    printf("Current hand is " + user->rank + user->suit);
    return;
}
