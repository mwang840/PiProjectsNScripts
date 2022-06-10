#include <stdio.h>

struct Prisoner {
    Prisoner *next;
    Prisoner *prev;
    int age;
    char *name;
};

void push(char *name, int age, char *prisonId);
Prisoner pop();
int remove(char *prisonId);
void sentence(char *name);