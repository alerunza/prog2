IntList eliminaPenultimo(IntList l) {
    if (l == NULL || l->next == NULL) return l; // meno di 2 nodi

    IntList prev = NULL;
    IntList curr = l;
    IntList next = curr->next;

    while (next->next != NULL) { // fino a penultimo
        prev = curr;
        curr = next;
        next = next->next;
    }
    // curr è penultimo nodo
    if (prev == NULL) {
        // penultimo è il primo nodo (lista di 2 elementi)
        l = next; 
    } else {
        prev->next = next;
    }
    free(curr);
    return l;
}
