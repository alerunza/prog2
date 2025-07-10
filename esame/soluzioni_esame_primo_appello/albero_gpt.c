#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode IntTreeNode, *IntTree;
struct treeNode {
   IntTree left;
   int data;
   IntTree right;
   IntTree parent;
};

int sumX(IntTree tree) {
    if (tree == NULL) return 0;

    if (tree->left == NULL && tree->right == NULL) {
        IntTree parent = tree->parent;
        if (parent != NULL) {
            if ((parent->left == tree && parent->right == NULL) ||
                (parent->right == tree && parent->left == NULL)) {
                return tree->data;
            }
        } else {
            return 0;
        }
    }

    return sumX(tree->left) + sumX(tree->right);
}

IntTree newNode(int value, IntTree parent) {
    IntTree node = (IntTree)malloc(sizeof(IntTreeNode));
    node->data = value;
    node->left = node->right = NULL;
    node->parent = parent;
    return node;
}

int main() {
    IntTree root = newNode(1, NULL);
    root->left = newNode(2, root);
    root->right = newNode(3, root);

    root->left->left = newNode(4, root->left);
    root->left->right = newNode(5, root->left);
    root->right->right = newNode(7, root->right);

    root->left->right->left = newNode(10, root->left->right);

    int somma = sumX(root);
    printf("Somma foglie figlie uniche: %d\n", somma); // 17

    return 0;
}
