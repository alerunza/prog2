
#ifndef ALBERI_UTILS_H
#define ALBERI_UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode IntTreeNode, *IntTree;
struct treeNode {
    IntTree left;
    int data;
    IntTree right;
};

// Crea un nodo
IntTree creaNodo(int val) {
    IntTree nuovo = (IntTree)malloc(sizeof(IntTreeNode));
    nuovo->data = val;
    nuovo->left = NULL;
    nuovo->right = NULL;
    return nuovo;
}

// Dealloca tutto l'albero
void liberaAlbero(IntTree t) {
    if (t != NULL) {
        liberaAlbero(t->left);
        liberaAlbero(t->right);
        free(t);
    }
}

// Stampa In-Order
void stampaInOrder(IntTree t) {
    if (t != NULL) {
        stampaInOrder(t->left);
        printf("%d ", t->data);
        stampaInOrder(t->right);
    }
}
#endif
