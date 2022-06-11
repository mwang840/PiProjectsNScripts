#include <stdio.h>
#include <stdlib.h>

struct Prisoner {
    struct Prisoner *next;
    struct Prisoner *prev;
    int age;
    char *name;
};

void push(char *name, int age, char *prisonId, int sentence, char *crime);
struct Prisoner *pop();
int remove(char *prisonId);
void sentence(char *name);
void printlist();