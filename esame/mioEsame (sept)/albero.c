int sommaTaglio(IntTree tree, int taglio) {
  if (tree == NULL || taglio < 0)
    return 0;

  int count = 0, sum = 0;

  if (count < taglio) {
    if (tree->left == NULL && tree->right == NULL) {
      sum += tree->data + 100;

      return sum;
    }
  } else {
    if (count % 2 == 0) { // pari
      return tree->data + sommaTaglio(tree->left, taglio) +
             sommaTaglio(tree->right, taglio);
    }
  }

  return sum + sommaTaglio(tree->left, taglio) +
         sommaTaglio(tree->right, taglio);
}
