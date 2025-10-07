#include <stdlib.h>

#include "Set.h"

struct node {
    int value;
    struct node *next;
};

// typedef struct set *Set;
struct set {
    struct node *head;
    int size;
};

// Creates a new empty set
Set SetNew(void) {
    Set s = malloc(sizeof(struct set));
    s->head = NULL;

    return s;
}

// Frees memory allocated to the set
void SetFree(Set s) {
    struct node *next;
    for (struct node *curr = s->head; curr != NULL; curr = next) {
        next = curr->next;
        free(curr);
    }
    free(s);
}

// Inserts an element into the set
void SetInsert(Set s, int elem) {
    if (SetContains(s, elem)) return;

    struct node *new = malloc(sizeof(struct node));
    new->value = elem;
    new->next = s->head;
    s->head = new;
}

// Deletes an element from the set
void SetDelete(Set s, int elem) {}

// Returns true if the given element is in the set, and false otherwise
bool SetContains(Set s, int elem) {}

// Returns the number of elements in the set
int SetSize(Set s) {
    return s->size;
}