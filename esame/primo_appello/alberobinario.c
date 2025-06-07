typedef struct treeNode {
    struct treeNode *left;
    int data;
    struct treeNode *right;
} IntTreeNode, *IntTree;

void mirror(IntTree tree) {
    if (tree == NULL) return;

    IntTree tmp = tree->left;
    tree->left = tree->right;
    tree->right = tmp;

    mirror(tree->left);
    mirror(tree->right);
}
