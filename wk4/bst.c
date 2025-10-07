#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int elem;
    struct node *left;
    struct node *right;
};

// returns the number of values in a binary search tree
int bstCountNodes(struct node *t) {
    if (t == NULL) return 0;
    return bstCountNodes(t->left) + bstCountNodes(t->right) + 1;
}

// returns the number of odd values in a binary search tree
int bstCountOdds(struct node *t) {
    if (t == NULL) return 0;

    if (t->elem % 2 == 1)
        return 1 + bstCountOdds(t->left) + bstCountOdds(t->right);

    return bstCountOdds(t->left) + bstCountOdds(t->right);
}

// count number of internal nodes in a given tree
// an internal node is a node with at least one child node
int bstCountInternal(struct node *t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 0;
    return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
}

// returns the level of the node containing a given key if such a node exists,
// otherwise the function returns -1
// (when a given key is not in the binary search tree)
// The level of the root node is zero.
int bstNodeLevel(struct node *t, int key) {
    if (t == NULL) return -1;
    if (t->elem == key) return 0;
    // if (key < t->elem) {
    //     int lvl = bstNodeLevel(t->left, key);
    //     if (lvl == -1) return -1;
    //     return 1 + lvl;
    // } else {
    //     int lvl = bstNodeLevel(t->right, key);
    //     if (lvl == -1) return -1;
    //     return 1 + lvl;
    // }
    int lvl = bstNodeLevel((key < t->elem) ? t->left : t->right, key);
    if (lvl == -1) return -1;
    return 1 + lvl;
}

// counts the number of values that are greater than a given value.
// This function should avoid visiting nodes that it doesn't have to visit
int bstCountGreater(struct node *t, int val) {
    if (t == NULL) return 0;

    int num = bstCountGreater(t->right, val);
    if (t->elem <= val) {
        num += bstCountGreater(t->left, val);
    } else {
        num += 1;
    }
    return num;
}

#define NOT_HEIGHT_BALANCED -99

// returns the height of a given binary tree if it is height - balanced,
// and NOT_HEIGHT_BALANCED otherwise.
// Height-balanced tree: We say that a basic binary tree is height-balanced if,
//      for every node, the absolute difference between the height of the left
//      subtree and the height of the right subtree is one or less. In other
//      words, every node needs to satisfy the following criteria:
//      abs(height(left) - height(right)) ≤ 1
static int abs(int a) {
    return (a >= 0) ? a : -a;
}
static int max(int a, int b) {
    return (a > b) ? a : b;
}
int isHeightBalanced(struct node *t) {
    if (t == NULL) return -1;

    int lHeight = isHeightBalanced(t->left);
    int rHeight = isHeightBalanced(t->right);

    if (lHeight == NOT_HEIGHT_BALANCED || rHeight == NOT_HEIGHT_BALANCED)
        return NOT_HEIGHT_BALANCED;

    if (abs(lHeight - rHeight) > 1) return NOT_HEIGHT_BALANCED;

    return 1 + max(lHeight, rHeight);
}

// challenging question!

// return the kth smallest node in the binary search tree
// return -1 if no such node exists (e.g. the 5th smallest number
// if a tree with only 3 nodes)
void doKthSmallest(struct node *t, int k, int *upTo, int *res) {
    if (t == NULL) return;

    doKthSmallest(t->left, k, upTo, res);

    (*upTo)++;
    if (*upTo == k) {
        *res = t->elem;
    }

    doKthSmallest(t->right, k, upTo, res);
}

int kthSmallest(struct node *t, int k) {
    int upTo = 0;
    int res;
    doKthSmallest(t, k, &upTo, &res);
    return res;
}
