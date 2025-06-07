#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    struct treeNode *left;
    int data;
    struct treeNode *right;
} IntTreeNode, *IntTree;

// Stampa in-order (sx, radice, dx)
void stampaInOrder(IntTree t) {
    if (t != NULL) {
        stampaInOrder(t->left);
        printf("%d ", t->data);
        stampaInOrder(t->right);
    }
}

// Conta nodi
int contaNodi(IntTree t) {
    if (t == NULL) return 0;
    return 1 + contaNodi(t->left) + contaNodi(t->right);
}

// Somma nodi
int sommaNodi(IntTree t) {
    if (t == NULL) return 0;
    return t->data + sommaNodi(t->left) + sommaNodi(t->right);
}

// Altezza albero
int altezza(IntTree t){
    if(t == NULL){
        return 0;
    } else{
        int sx = altezza(t->left);
        int dx = altezza(t->right);
        int max;

        if (sx > dx)
            max = sx;
        else
            max = dx;

        return 1 + max;
    }
}

// Mirror albero
void mirror(IntTree t) {
    if (t == NULL) return;
    IntTree tmp = t->left;
    t->left = t->right;
    t->right = tmp;
    mirror(t->left);
    mirror(t->right);
}

// Deallocazione albero
void liberaAlbero(IntTree t) {
    if (t != NULL) {
        liberaAlbero(t->left);
        liberaAlbero(t->right);
        free(t);
    }
}
