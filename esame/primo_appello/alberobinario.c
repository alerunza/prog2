typedef struct treeNode IntTreeNode, *IntTree;
struct treeNode {
    IntTree left;
    int data;
    IntTree right;
};

void mirror(IntTree tree) {
    if (tree == NULL) return;

    IntTree tmp = tree->left;
    tree->left = tree->right;
    tree->right = tmp;

    mirror(tree->left);
    mirror(tree->right);
}
