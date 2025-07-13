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

    //primo caso
    if(lsPtr == NULL){
        return -1;
    }

    //secondo, terzo e quarto caso
    if(*lsPtr == NULL ||  (*lsPtr)->next == NULL || (*lsPtr)->next->next == NULL){
        return 0;
    }

    IntList conta = *lsPtr;
    int contaNodi = 0;

    while(conta != NULL){
        contaNodi++;
        conta = conta->next;
    }

    if(contaNodi < 3){
        return 0; //fallimento
    }

    if(contaNodi == 3){ //se il terzultimo è il primo nodo
        IntList eliminaNodo = *lsPtr;
        *lsPtr = (*lsPtr)->next;
        free(eliminaNodo);
        return 1; //successo
    }

    //va avanti fino al nodo prima del terzultimo
    conta = *lsPtr;
    for (int i = 0; i < (contaNodi - 4); i++){
        conta = conta->next;
    }

    IntList eliminaNodo = conta->next;
    conta->next = eliminaNodo->next;
    free(eliminaNodo);
    return 1;
}