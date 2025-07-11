IntList eliminaSecondoDispari(IntList l) {
    IntList curr = l, prev = NULL;
    int count = 0;

    while (curr != NULL) {
        if (curr->data % 2 != 0) {  // nodo dispari
            count++;
            if (count == 2) {       // siamo al secondo dispari
                if (prev == NULL) {
                    // Il secondo dispari è il primo nodo (caso raro)
                    l = curr->next;
                } else {
                    prev->next = curr->next;
                }
                free(curr);
                return l;            // ritorna la testa modificata
            }
        }
        prev = curr;
        curr = curr->next;
    }
    return l;  // se non trova il secondo dispari ritorna lista originale
}
