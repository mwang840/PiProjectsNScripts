typedef struct card {
    int rank;
    char suit;
    struct card *next;
} theCard;

theCard *createDeck();
theCard *add(int rank, char suit);
theCard *shuffle(theCard *cards);
void revealHand(theCard *cards);
int totalHand(theCard *cards);
int countHand(theCard *cards);
void removeCard(theCard *cards);
theCard *deal(theCard *cards);