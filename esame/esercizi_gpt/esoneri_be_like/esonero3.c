#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;

struct node {
    int data;
    IntList next;
};

/**
 * Modifica *lsPtr eliminando il **secondo elemento dispari** (se esiste) dalla lista.
 *
 * Ritorna:
 * - -1 se lsPtr == NULL
 * -  0 se lista vuota o meno di due dispari
 * -  1 se ha eliminato il secondo dispari
 */
int eliminaSecondoDispari(IntList *lsPtr){
    if(lsPtr == NULL){
        return -1;
    }

    if(*lsPtr == NULL){ // lista vuota
        return 0;
    }

    IntList prev = NULL, curr = *lsPtr;

    int contaDispari = 0;

    while(curr != NULL){
        if(curr->data % 2 != 0){
            contaDispari++;

            if(contaDispari == 2){
                if(prev == NULL){
                    *lsPtr = curr->next;
                } else{
                    prev->next = curr->next;
                }
                free(curr);
                return 1;
            }
        }
        prev = curr;
        curr = curr->next;
    }

    return 0;
}

/**
 * Aggiunge in fondo un nodo con valore val
 */
IntList append(IntList l, int val){
    IntList nuovo = (IntList)malloc(sizeof(IntNode));
    nuovo->data = val;
    nuovo->next = NULL;

    if (l == NULL) return nuovo;

    IntList curr = l;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = nuovo;
    return l;
}

/**
 * Stampa la lista su una riga
 */
void stampa(IntList l){
    while(l != NULL){
        printf("%d ", l->data);
        l = l->next;
    }
}

/**
 * Libera la memoria della lista
 */
void libera(IntList l){
    while(l != NULL){
        IntList temp = l;
        l = l->next;
        free(temp);
    }
}

int main() {
    IntList l = NULL;

    l = append(l, 5);
    l = append(l, 8);
    l = append(l, 7);
    l = append(l, 1);

    printf("Prima: ");
    stampa(l);

    int esito = eliminaSecondoDispari(&l);
    printf("\nDopo: ");
    stampa(l);
    printf("\nEsito: %d\n", esito);

    libera(l);
    return 0;
}
