void reverse (IntList *plst) {
    if(*plst == NULL){
        return;
    }
    
    IntList curr = *plst; /* curr avrà il primo nodo che ha il valore 1 */
    IntList prev = NULL;
    IntList succ = NULL;
    
    while(curr != NULL){
        succ = curr -> next; // Su succ abbiamo il SECONDO blocco memorizzato 
        curr -> next = prev; // curr -> next lo facciamo diventare null
        prev = curr; // in prev metto il PRIMO blocco
        curr = succ; // in curr che ha il PRIMO blocco mettiamo il SECONDO
        
    }
    *plst = prev;
}