void rimuoviPenultimo(IntList *lsPtr) {
    if(*lsPtr == NULL || (*lsPtr)->next == NULL){
        return;
    }

    if((*lsPtr)->next->next == NULL{
        IntList temp = *lsPtr;
        *lsPtr = *lsPtr->next;
        free(temp);
        return;
    }

    IntList prev = NULL;
    IntList curr = *lsPtr;

    while(curr->next->next != NULL){
        prev = curr;
        curr = curr->next;
    }

    IntList pen = curr;
    prev->next = curr->next;

    free(pen);
}