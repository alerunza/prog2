IntList eliminaUltimo(IntList l) {
    if (l == NULL) return NULL;
    if (l->next == NULL) {  // lista con un solo nodo
        free(l);
        return NULL;
    }

    IntList curr = l;
    IntList prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    // curr è ultimo nodo
    prev->next = NULL;
    free(curr);
    return l;
}
