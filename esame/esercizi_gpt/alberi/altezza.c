#include "alberi_utils.h"

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

int main() {
    IntTree root = creaNodo(5);
    root->left = creaNodo(3);
    root->right = creaNodo(8);
    root->left->left = creaNodo(1);
    root->left->right = creaNodo(4);

    printf("Altezza dell'albero: %d\n", altezza(root)); // atteso: 3

    liberaAlbero(root);
    return 0;
}
