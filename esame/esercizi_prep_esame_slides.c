// DEFINIZIONE BASE ALBERO BINARIO
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode TreeNode, *Tree;
struct treeNode {
    int data;
    Tree left;
    Tree right;
};

// 1. P-IN / P-OUT saranno commentati in ciascuna funzione

// 2. Ricorsive: findMinBST, extractMinBST, removeBST
int findMinBST(Tree tree) {
    if (tree == NULL) exit(-1);
    if (tree->left == NULL) return tree->data;
    return findMinBST(tree->left);
}

int extractMinBST(Tree* treePtr) {
    if (*treePtr == NULL) exit(-1);
    if ((*treePtr)->left == NULL) {
        int min = (*treePtr)->data;
        Tree temp = *treePtr;
        *treePtr = (*treePtr)->right;
        free(temp);
        return min;
    }
    return extractMinBST(&(*treePtr)->left);
}

Tree removeBST(Tree tree, int value) {
    if (tree == NULL) return NULL;
    if (value < tree->data) tree->left = removeBST(tree->left, value);
    else if (value > tree->data) tree->right = removeBST(tree->right, value);
    else {
        if (tree->left == NULL) {
            Tree temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            Tree temp = tree->left;
            free(tree);
            return temp;
        } else {
            int min = extractMinBST(&tree->right);
            tree->data = min;
        }
    }
    return tree;
}

// 3. Versione alternativa: massimo del sottoalbero sinistro
int extractMaxBST(Tree* treePtr) {
    if (*treePtr == NULL) exit(-1);
    if ((*treePtr)->right == NULL) {
        int max = (*treePtr)->data;
        Tree temp = *treePtr;
        *treePtr = (*treePtr)->left;
        free(temp);
        return max;
    }
    return extractMaxBST(&(*treePtr)->right);
}

Tree altRemoveBST(Tree tree, int value) {
    if (tree == NULL) return NULL;
    if (value < tree->data) tree->left = altRemoveBST(tree->left, value);
    else if (value > tree->data) tree->right = altRemoveBST(tree->right, value);
    else {
        if (tree->left == NULL) {
            Tree temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            Tree temp = tree->left;
            free(tree);
            return temp;
        } else {
            int max = extractMaxBST(&tree->left);
            tree->data = max;
        }
    }
    return tree;
}

// 4. Conta nodi
int countNodes(Tree tree) {
    if (tree == NULL) return 0;
    return 1 + countNodes(tree->left) + countNodes(tree->right);
}

int countNodesIter(Tree tree) {
    if (tree == NULL) return 0;
    int count = 0;
    Tree stack[100];
    int top = -1;
    stack[++top] = tree;
    while (top >= 0) {
        Tree curr = stack[top--];
        count++;
        if (curr->right) stack[++top] = curr->right;
        if (curr->left) stack[++top] = curr->left;
    }
    return count;
}

// 5. Conta foglie
int countLeaves(Tree tree) {
    if (tree == NULL) return 0;
    if (tree->left == NULL && tree->right == NULL) return 1;
    return countLeaves(tree->left) + countLeaves(tree->right);
}

int countLeavesIter(Tree tree) {
    if (tree == NULL) return 0;
    int count = 0;
    Tree stack[100];
    int top = -1;
    stack[++top] = tree;
    while (top >= 0) {
        Tree curr = stack[top--];
        if (curr->left == NULL && curr->right == NULL) count++;
        if (curr->right) stack[++top] = curr->right;
        if (curr->left) stack[++top] = curr->left;
    }
    return count;
}

// 6. Conta nodi interni
int countInnerNodes(Tree tree) {
    if (tree == NULL || (tree->left == NULL && tree->right == NULL)) return 0;
    return 1 + countInnerNodes(tree->left) + countInnerNodes(tree->right);
}

int countInnerNodesIter(Tree tree) {
    if (tree == NULL) return 0;
    int count = 0;
    Tree stack[100];
    int top = -1;
    stack[++top] = tree;
    while (top >= 0) {
        Tree curr = stack[top--];
        if (curr->left != NULL || curr->right != NULL) count++;
        if (curr->right) stack[++top] = curr->right;
        if (curr->left) stack[++top] = curr->left;
    }
    return count;
}

// 7. Altezza
int height(Tree tree) {
    if (tree == NULL) return -1;
    int hl = height(tree->left);
    int hr = height(tree->right);
    return 1 + (hl > hr ? hl : hr);
}

int heightIter(Tree tree) {
    if (tree == NULL) return -1;
    int maxHeight = -1;
    typedef struct { Tree node; int depth; } StackItem;
    StackItem stack[100];
    int top = -1;
    stack[++top] = (StackItem){tree, 0};
    while (top >= 0) {
        StackItem curr = stack[top--];
        if (curr.depth > maxHeight) maxHeight = curr.depth;
        if (curr.node->right) stack[++top] = (StackItem){curr.node->right, curr.depth + 1};
        if (curr.node->left) stack[++top] = (StackItem){curr.node->left, curr.depth + 1};
    }
    return maxHeight;
}

// 8. isComplete (verifica se l’albero è completo)
bool isComplete(Tree tree) {
    if (tree == NULL) return true;
    Tree queue[100];
    int front = 0, rear = 0;
    bool encounteredNull = false;
    queue[rear++] = tree;
    while (front < rear) {
        Tree current = queue[front++];
        if (current == NULL) {
            encounteredNull = true;
        } else {
            if (encounteredNull) return false;
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }
    return true;
}

// 9. isAlmostComplete: tutte le foglie a profondità h o h−1, foglie a sinistra
bool isAlmostComplete(Tree tree) {
    if (tree == NULL) return true;
    int h = height(tree);
    Tree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = tree;
    int level = 0;
    bool mustBeLeaf = false;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            Tree current = queue[front++];
            if (mustBeLeaf && (current->left || current->right)) return false;
            if (current->left) queue[rear++] = current->left;
            else mustBeLeaf = true;
            if (current->right) queue[rear++] = current->right;
            else mustBeLeaf = true;
        }
        level++;
    }
    return true;
}

// 10. isPseudoAlmostComplete: consente buchi purché a destra
bool isPseudoAlmostComplete(Tree tree) {
    if (tree == NULL) return true;
    Tree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = tree;
    bool seenNullChild = false;
    while (front < rear) {
        Tree current = queue[front++];
        if (current->left) {
            if (seenNullChild) return false;
            queue[rear++] = current->left;
        } else {
            seenNullChild = true;
        }
        if (current->right) {
            if (seenNullChild) return false;
            queue[rear++] = current->right;
        } else {
            seenNullChild = true;
        }
    }
    return true;
}

// 11. isDegenerate: ogni nodo ha al massimo un figlio
bool isDegenerate(Tree tree) {
    if (tree == NULL) return true;
    if (tree->left && tree->right) return false;
    return isDegenerate(tree->left ? tree->left : tree->right);
}

// 12. isCompletelyUnbalancedToTheLeft
bool isCompletelyUnbalancedToTheLeft(Tree tree) {
    if (tree == NULL) return true;
    if (tree->right) return false;
    return isCompletelyUnbalancedToTheLeft(tree->left);
}

// 13. isCompletelyUnbalanced: ogni nodo ha solo un figlio
bool isCompletelyUnbalanced(Tree tree) {
    if (tree == NULL) return true;
    if (tree->left && tree->right) return false;
    if (!tree->left && !tree->right) return true;
    return isCompletelyUnbalanced(tree->left ? tree->left : tree->right);
}

// 14. isBST (ricorsiva)
bool isBST(Tree tree, int min, int max) {
    if (tree == NULL) return true;
    if (tree->data <= min || tree->data >= max) return false;
    return isBST(tree->left, min, tree->data) && isBST(tree->right, tree->data, max);
}

bool isBSTwrapper(Tree tree) {
    return isBST(tree, -1000000, 1000000);
}

Tree newNode(int val) {
    Tree node = (Tree)malloc(sizeof(TreeNode));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    Tree root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->left = newNode(25);
    root->right->right = newNode(35);

    printf("Min BST: %d\n", findMinBST(root));

    printf("Node count (rec): %d\n", countNodes(root));
    printf("Node count (iter): %d\n", countNodesIter(root));

    printf("Leaf count (rec): %d\n", countLeaves(root));
    printf("Leaf count (iter): %d\n", countLeavesIter(root));

    printf("Inner node count (rec): %d\n", countInnerNodes(root));
    printf("Inner node count (iter): %d\n", countInnerNodesIter(root));

    printf("Height (rec): %d\n", height(root));
    printf("Height (iter): %d\n", heightIter(root));

    printf("isComplete: %d\n", isComplete(root));
    printf("isAlmostComplete: %d\n", isAlmostComplete(root));
    printf("isPseudoAlmostComplete: %d\n", isPseudoAlmostComplete(root));
    printf("isDegenerate: %d\n", isDegenerate(root));
    printf("isCompletelyUnbalancedToTheLeft: %d\n", isCompletelyUnbalancedToTheLeft(root));
    printf("isCompletelyUnbalanced: %d\n", isCompletelyUnbalanced(root));
    printf("isBST: %d\n", isBSTwrapper(root));

    root = removeBST(root, 10);
    printf("Removed 10 (min from right) - new count: %d\n", countNodes(root));

    root = altRemoveBST(root, 30);
    printf("Removed 30 (max from left) - new count: %d\n", countNodes(root));

    return 0;
}