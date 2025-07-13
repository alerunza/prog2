int count(CharTree tree, int m, int n) {
    if (tree == NULL)
        return 0;

    if (m <= 0 && n >= 0)
        return tree->data + count(tree->left, m - 1, n - 1) + count(tree->right, m - 1, n - 1);
    else
        return count(tree->left, m - 1, n - 1) + count(tree->right, m - 1, n - 1);
}