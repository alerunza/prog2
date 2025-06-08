#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    struct treeNode *left;
    int data;
    struct treeNode *right;
} IntTreeNode, *IntTree;

// Visita in-order (sx, radice, dx)
void stampaInOrder(IntTree t) {
    if (t != NULL) {
        stampaInOrder(t->left);
        printf("%d ", t->data);
        stampaInOrder(t->right);
    }
}

// Visita pre-order (radice, sx, dx)
void stampaPreOrder(IntTree t) {
    if (t != NULL) {
        printf("%d ", t->data);
        stampaPreOrder(t->left);
        stampaPreOrder(t->right);
    }
}

// Visita post-order (sx, dx, radice)
void stampaPostOrder(IntTree t) {
    if (t != NULL) {
        stampaPostOrder(t->left);
        stampaPostOrder(t->right);
        printf("%d ", t->data);
    }
}

// Conta tutti i nodi
int contaNodi(IntTree t) {
    if (t == NULL) return 0;
    return 1 + contaNodi(t->left) + contaNodi(t->right);
}

// Conta solo le foglie
int contaFoglie(IntTree t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 1;
    return contaFoglie(t->left) + contaFoglie(t->right);
}

// Conta nodi interni (con almeno un figlio)
int contaInterni(IntTree t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 0;
    return 1 + contaInterni(t->left) + contaInterni(t->right);
}

// Somma dei dati dei nodi
int sommaNodi(IntTree t) {
    if (t == NULL) return 0;
    return t->data + sommaNodi(t->left) + sommaNodi(t->right);
}

// Altezza dell'albero
int altezza(IntTree t) {
    if (t == NULL) return 0;
    int sx = altezza(t->left);
    int dx = altezza(t->right);
    int max = (sx > dx) ? sx : dx;
    return 1 + max;
}

// Ricerca di un valore (presente? restituisce 1/0)
int cerca(IntTree t, int val) {
    if (t == NULL) return 0;
    if (t->data == val) return 1;
    return cerca(t->left, val) || cerca(t->right, val);
}

// Massimo valore (in un albero binario normale, non BST: visita completa)
int massimo(IntTree t) {
    if (t == NULL) return -2147483648; // INT_MIN
    int sx = massimo(t->left);
    int dx = massimo(t->right);
    int max = (sx > dx) ? sx : dx;
    return (t->data > max) ? t->data : max;
}

// Minimo valore (visita completa)
int minimo(IntTree t) {
    if (t == NULL) return 2147483647; // INT_MAX
    int sx = minimo(t->left);
    int dx = minimo(t->right);
    int min = (sx < dx) ? sx : dx;
    return (t->data < min) ? t->data : min;
}

// Mirror dell’albero
void mirror(IntTree t) {
    if (t == NULL) return;
    IntTree tmp = t->left;
    t->left = t->right;
    t->right = tmp;
    mirror(t->left);
    mirror(t->right);
}

// Dealloca tutto l’albero
void liberaAlbero(IntTree t) {
    if (t != NULL) {
        liberaAlbero(t->left);
        liberaAlbero(t->right);
        free(t);
    }
}
