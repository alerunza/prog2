#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Per usare "bool", "true", "false"

// Definizione dell'albero binario di ricerca
typedef struct treeNode IntTreeNode, *IntTree;
struct treeNode {
    int data;
    IntTree left;
    IntTree right;
};

// Funzione di ricerca ricorsiva in un BST
bool searchBST(IntTree tree, int value) {
    if (tree == NULL) {
        return false;
    } else if (value < tree->data) {
        return searchBST(tree->left, value);
    } else if (value > tree->data) {
        return searchBST(tree->right, value);
    } else {
        return true;
    }
}

// Funzione di utilità per creare un nuovo nodo
IntTree newNode(int value) {
    IntTree node = (IntTree)malloc(sizeof(IntTreeNode));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// MAIN per testare la funzione
int main() {
    // Creo il BST manualmente:
    //         20
    //        /  \
    //      10    30
    IntTree root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);

    // Test di ricerca
    printf("Cerco 10: %d\n", searchBST(root, 10));  // Output: 1
    printf("Cerco 25: %d\n", searchBST(root, 25));  // Output: 0
    printf("Cerco 30: %d\n", searchBST(root, 30));  // Output: 1
    printf("Cerco 5 : %d\n", searchBST(root, 5));   // Output: 0

    return 0;
}