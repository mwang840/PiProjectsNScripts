#include <stdio.h>
#include <stdlib.h>
#include "prison.h"

void push(char *name, int age, char *prisonId, int sentence, char *crimes);
int remove(char *prisonId);
void sentence(char *name);
void printlist();

int main(){
    printf("Hello");
    return 0;
}

void printlist(Prisoner *p){
    Prison *temp = p;
    while(temp != NULL){
        printf("Prisoner name is %s, is %d years old, has an id of %s, is in jail for %d years due to the crimes of %s he committed", temp->name, temp->age, temp->prisonId, temp->sentence, temp->crimes);
        temp = temp->next;
    }
}