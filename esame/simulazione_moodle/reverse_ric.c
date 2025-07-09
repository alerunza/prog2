void reverse (IntList *plst) {
    if(*plst == NULL || (*plst)->next == NULL){
        return;
    }else{
        IntList rest = (*plst)->next;
        
        reverse(&rest);
        
        (*plst)->next->next = *plst;
        (*plst)->next = NULL;
        *plst = rest;
    }
}