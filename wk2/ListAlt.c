#include <stdlib.h>

struct list {
    struct node *head;
};

struct node {
    int data;
    struct node *next;
};

int doListLength(struct node *n) {
    if (n == NULL) return 0;
    return 1 + doListLength(n->next);
}

int listLength(struct list *l) {
    return doListLength(l->head);
}
