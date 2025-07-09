int nfoglie(CharTree tree) {
    if (tree == NULL) // caso base
        return 0;

    if (tree->left == NULL && tree->right == NULL) //foglia trovata
        return 1;

    return nfoglie(tree->left) + nfoglie(tree->right);
}