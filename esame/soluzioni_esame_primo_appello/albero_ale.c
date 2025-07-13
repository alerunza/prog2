typedef struct treeNode IntTreeNode, *IntTree;
struct treeNode {
   IntTree left;
   int data;
   IntTree right;
   IntTree parent; // puntatore al padre (vale NULL nella radice);
};

int sumX(IntTree tree) {
    if(tree == NULL){
        return 0;
    }

    if(tree->left == NULL && tree->right == NULL){ // controlla se è una foglia
        if(tree->parent == NULL){ // controlla se è l'unico nodo (radice senza padre)
            return tree->data;

        }
        // controlla se è una foglia figlia unica del proprio genitore
        if((tree->parent->left == tree && tree->parent->right == NULL) || (tree->parent->right == tree && tree->parent->left == NULL)){
            return tree->data;
        } else{
            return 0;
        }
    }

    return sumX(tree->left) + sumX(tree->right);
}