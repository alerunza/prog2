void invertiList(IntList *src) {
  IntList curr = *src, prev = NULL, next = NULL;
  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *src = prev;
}
