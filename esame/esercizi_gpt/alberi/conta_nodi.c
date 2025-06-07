#include "alberi_utils.h"

int contaNodi(IntTree t){
    if(t == NULL){
        return 0;
    } else{
        return 1 + contaNodi(t->left) + contaNodi(t->right);
    }
}

int main() {
    IntTree root = creaNodo(5);
    root->left = creaNodo(3);
    root->right = creaNodo(8);
    root->left->left = creaNodo(1);
    root->left->right = creaNodo(4);

    printf("Numero nodi: %d\n", contaNodi(root));  // atteso: 5

    liberaAlbero(root);
    return 0;
}
