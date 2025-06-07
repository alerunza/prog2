#include "alberi_utils.h"

int sommaNodi(IntTree t){
    if(t == NULL){
        return 0;
    } else{
        return t->data + sommaNodi(t->left) + sommaNodi(t->right);
    }
}

int main() {
    IntTree root = creaNodo(5);
    root->left = creaNodo(3);
    root->right = creaNodo(8);
    root->left->left = creaNodo(1);
    root->left->right = creaNodo(4);

    printf("Somma dei nodi: %d\n", sommaNodi(root)); // atteso: 5+3+8+1+4 = 21

    liberaAlbero(root);
    return 0;
}
