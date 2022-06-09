#include "card.h"
#include <stdio.h>
#include <stdlib.h>//Needed for the shuffle method

//Counts the number of cards in a pile
int countPile(theCard *cards){
    int piles = 0;
    while(cards != NULL){
        piles++;
        cards = cards->next;
    }
    return piles;
}
//Reveals the top card of the pile
void revealHand(theCard *cards){
    printf("The hand has a suit of: %c with a rank of %d\n", cards->suit, cards->rank);
}
//Adds the card to the end of the list
theCard *add(int rank, char suit){
    //Checks if the suit matches the basic qualifications of a card (C,H,S,D)
    if(suit != 'C' && suit != 'H' && suit != 'S' && suit !='D'){
        retun NULL;
    }
    //Otherwise make a new card
    theCard *newCard = malloc(sizeof(theCard));
    newCard ->rank = rank;
    newCard -> suit = suit;
    newCard->next = NULL;
    return newCard;
}

//Clears up the cards in a pile
void removeCards(theCard *cards){
    theCard *otherCard;
    while(otherCard != NULL){
        otherCard = cards;
        cards = cards->next;
        free(otherCard);
    }
}

//Deals out the cards in a pile (assuming the card is not NULL)
theCard *deal(theCard *cards){
    theCard *pile = cards;
    if(pile == NULL){
        return NULL;
    }
    theCard *head = pile;
    theCard *prev;
    while(pile != NULL){
        prev = head;
        head = head->next;
    }
    prev ->next = NULL;        
    return head;
}

//Creates the deck of cards
theCard *createDeck(){
    theCard *deck = NULL;
    theCard *head = NULL;
    //Sets up an array of suits
    char suits[5] = {'C', 'S', 'D', 'H'};
    //walks over the length of the suits array and over the ranks
    for(int i = 0; i < strlen(suits) - 1; ++i){
        for(int j = 0; j < 13; ++j){
            if(head == NULL){
                deck = add(j, suits[i]);
                head = deck;
            }
            else{
                deck = head;
                theCard *followers = add(j, suits[i]);
                while(deck != NULL){
                    deck = deck->next;
                }
                deck->next = followers;
            }
        }
    }
}
//Returns the total rank of the cards
int totalHand(theCard *cards){
    int totalRank = 0;
    if(cards == NULL){
        return 0;
    }
    else{
        while(cards != NULL){
            if(cards->rank > 10){
                totalRank+= 10;
            }
            else{
                totalRank+= cards->rank;
            }
            cards = cards ->next;
        }
    }
    return totalRank;
}

//Shuffles the cards in a deck
theCard *shuffle(theCard *cards){
    int totalSize = totalHand(cards);
    theCard *newDeck = cards;
    for(int i = 0; i < totalSize/2; ++i){
        cards = cards->next;
    }
    theCard *rand = cards->next;
    rand->next = 0;
    theCard *otherHalf = 0;
    while(newDeck != otherHalf){
        theCard *temp;
        newDeck = createDeck();
    }
    return rand;
}