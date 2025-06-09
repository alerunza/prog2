void rimuoviPenultimo(IntList *lsPtr) {
    if (*lsPtr == NULL || (*lsPtr)->next == NULL)
        return;

    IntList *curr = *lsPtr;
    IntList *prev = NULL;

    while((*curr)->next != NULL) {
        prev = curr;
        curr = &(*curr)->next;
    }

    if(*prev != NULL) { // Controllo della lista non vuota
        IntList tmp = *prev;
        *prev = *curr;
        free(tmp);
    }
 /*  if (curr->next == NULL) {
        IntList tmp = *lsPtr;
        *lsPtr = (*lsPtr)->next;
        free(tmp);
        return;
    }

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    IntList penultimo = curr;
    prev->next = curr->next;
    free(penultimo);*/ 
}

void rimuoviPenultimo(IntList *lsPtr) {
    if (*lsPtr == NULL || (*lsPtr)->next == NULL)
        return;

    if ((*lsPtr)->next->next == NULL) {
        IntList tmp = *lsPtr;
        *lsPtr = (*lsPtr)->next;
        free(tmp);
        return;
    }

    IntList prev = NULL;
    IntList curr = *lsPtr;

    while (curr->next->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    IntList penultimo = curr;
    prev->next = curr->next;
    free(penultimo);
}
