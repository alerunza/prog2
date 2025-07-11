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
IntList raddoppiaDispariPositivi(int *a, int n);

/**
 * Stampa la lista su una sola riga, separando gli elementi con uno spazio.
 */
void stampa(IntList l);

/**
 * Libera la memoria occupata dalla lista.
 */
void libera(IntList l);

/**
 * Invoca raddoppiaDispariPositivi su un array esempio,
 * stampa la lista risultante e poi la libera.
 */
int main() {

    /* INSERIRE QUI IL CODICE */

}
