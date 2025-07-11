IntList eliminaTerzultimo(IntList l) {
    if (l == NULL) return l;

    // Conto i nodi
    int count = 0;
    for (IntList temp = l; temp != NULL; temp = temp->next) {
        count++;
    }
    if (count < 3) return l; // meno di 3 nodi, niente da fare

    int target = count - 3; // indice (0-based) del terzultimo nodo

    if (target == 0) {
        // terzultimo è il primo nodo
        IntList del = l;
        l = l->next;
        free(del);
        return l;
    }

    // scorro fino a nodo prima di quello da eliminare
    IntList curr = l;
    for (int i = 0; i < target - 1; i++) {
        curr = curr->next;
    }
    IntList del = curr->next;
    curr->next = del->next;
    free(del);
    return l;
}
