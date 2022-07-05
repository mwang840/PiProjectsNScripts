#include <stdio.h>
#include <stdlib.h>
#include "prison.h"

void push(char *name, int age, char *prisonId, int sentence, char *crimes);
char *remove(char *prisonId);
void sentence(char *name);
void printlist(struct Prisoner *p);
void printInReverse(struct Prisoner *p);
int totalPrisoners(struct Prisoner *head);


int main(){
    printf("Hello");
    return 0;
}

//Prints the list in the forward direction (next)
void printlist(struct Prisoner *p){
    struct Prisoner *temp = p;
    struct Prisoner *last;
    while(temp != NULL){
        printf("Prisoner name is %s, is %d years old, has an id of %s, is in jail for %d years due to the crimes of %s he committed", temp->name, temp->age, temp->prisonId, temp->sentence, temp->crimes);
        last = temp;
        temp = temp->next;
    }
}

//Same thing but its in reverse order (prev)
void printInReverse(struct Prisoner *p){
    struct Prisoner *temp = p;
    struct Prisoner *first;
    while(temp != NULL){
        printf("Prisoner name is %s, is %d years old, has an id of %s, is in jail for %d years due to the crimes of %s he committed", temp->name, temp->age, temp->prisonId, temp->sentence, temp->crimes);
        first = temp;
        temp = temp->prev;
    }
}

char *remove(char *id){
    struct Prisoner tempPrison = (struct Prisoner*)malloc(sizeof(struct Prisoner));
    if(id== NULL || id == ""){
        return NULL;
    }
    while(tempPrison != NULL){
        if(tempPrison->prisonId == id){
            struct Prisoner *removed = tempPrison;
        }
        tempPrison = tempPrison->next;
    }
    return removed->prisonId;
}

//Gets total prisoners in the prison
int totalPrisoners(struct Prisoner *head){
    int convicts = 0;
    struct Prisoner *currentPrisoner = head;
    while(currentPrisoner != NULL){
        convicts++;
        currentPrisoner = currentPrisoner->next;
    }
    
}