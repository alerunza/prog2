/* INSERIRE QUI EVENTUALI #include <...> */

#include <stdlib.h>
#include <stdio.h>

typedef struct node IntNode, *IntList;

struct node {
    int data;
    IntList next;
};

/**
 * Data una sequenza di interi rappresentata da un array `a` di lunghezza `n`,
 * restituisce una lista contenente solo i numeri **dispari positivi**, **raddoppiati**.
 * 
 * La lista mantiene l’ordine originale degli elementi nell’array.
 * 
 * Non considera l’eventualità che la malloc fallisca.
 * Se n <= 0 o a == NULL, restituisce NULL.
 * 
 * ESEMPI:
 * - a == NULL, n == 5      → NULL
 * - a == [2, -3, 5, 4, 7], n == 5  → [10, 14]
 * - a == [1, 2, 3], n == 3  → [2, 6]
 * - a == [2, 4, 6], n == 3  → NULL
 */
IntList raddoppiaDispariPositivi(int *a, int n){
    if((a == NULL || n <= 0)){
        return NULL;
    }

    IntList head = NULL, tail = NULL;

    for (int i = 0; i < n; i++){
        if(a[i] % 2 != 0 && a[i] > 0){

            IntList newA = (IntList)malloc(sizeof(IntNode));

            if(newA == NULL){
                return NULL;
            }

            newA->data = a[i] * 2;
            newA->next = NULL;

            if(head == NULL){
                head = tail = newA;
            } else{
                tail->next = newA;
                tail = newA;
            }
        }
    }

    return head;
}

/**
 * Stampa la lista su una sola riga, separando gli elementi con uno spazio.
 */
void stampa(IntList l){
    while(l != NULL){
        printf("%d ", l->data);
        l = l->next;
    }
}

/**
 * Libera la memoria occupata dalla lista.
 */
void libera(IntList l){
    while(l != NULL){
        IntList temp = l;
        l = l->next;
        free(temp);
    }
}

/**
 * Invoca raddoppiaDispariPositivi su un array esempio,
 * stampa la lista risultante e poi la libera.
 */
int main() {

    /* int a[5] = {2, -3, 5, 4, 7}; */
    int a[3] = {2, 4, 6};

    IntList newA = raddoppiaDispariPositivi(a, 3);

    stampa(newA);
    libera(newA);

    return 0;
}
