typedef struct node IntNode, *IntList;
struct node {
    int data;
    IntList next;
};

/**
 * Modifica *lsPtr togliendo da *lsPtr il suo terzultimo nodo,
 * se esiste (ovvero se la lista contiene almeno tre elementi),
 * e liberando la memoria da esso occupata.
 * restituisce :
 * -1 se lsPtr == NULL;
 * 0 se lista vuota o in caso di fallimento
 * 1 in caso di successo
 * 
 * ESEMPI
se lsPtr == NULL, dopo l’esecuzione lsPtr == NULL e ritorna -1.
se *lsPtr == NULL, dopo l’esecuzione *lsPtr == NULL e ritorna 0.
se *lsPtr == [25], dopo l’esecuzione *lsPtr == [25] e ritorna 0.
se *lsPtr == [25, 50], dopo l’esecuzione *lsPtr == [25, 50] e ritorna 0.
se *lsPtr == [10, 8, 12, 3], dopo l’esecuzione *lsPtr == [10, 12, 3] e restituisce 1.

 */
int eliminaTerzultimo(IntList *lsPtr) {
    
    if(*lsPtr==NULL) return -1;
    
    if(*lsPtr==NULL) return 0;
    
    int count=0;     //int count=0
    IntList temp=*lsPtr;
   
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    
    if(count<3) return 0;
    
    int trz = count-3;
    
    if(trz==0){
        IntList del=*lsPtr;
        *lsPtr=(*lsPtr)->next;
        free(del);
        return 1;
    }
    
    temp=*lsPtr;
    for(int i=0; i<trz-1; i++){
        temp=temp->next;
    }
    
    IntList del=temp->next;
    if(del!=NULL){
        temp->next=del->next;
        free(del);
        return 1;
    }
    return 0;
}