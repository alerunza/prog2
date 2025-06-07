#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} IntNode, *IntList;

// Stampa lista ricorsiva
void stampaRic(IntList l) {
    if (l != NULL) {
        printf("%d ", l->data);
        stampaRic(l->next);
    }
}

// Lunghezza lista ricorsiva
int lengthRic(IntList l) {
    if (l == NULL) return 0;
    return 1 + lengthRic(l->next);
}

// Somma elementi ricorsiva
int sommaRic(IntList l) {
    if (l == NULL) return 0;
    return l->data + sommaRic(l->next);
}

// Inserimento in coda ricorsivo
IntList inserisciCodaRic(IntList l, int val) {
    if (l == NULL) {
        IntList nuovo = malloc(sizeof(IntNode));
        nuovo->data = val;
        nuovo->next = NULL;
        return nuovo;
    }
    l->next = inserisciCodaRic(l->next, val);
    return l;
}

// Rimozione elemento ricorsiva (prima occorrenza)
IntList rimuoviRic(IntList l, int val) {
    if (l == NULL) return NULL;
    if (l->data == val) {
        IntList tmp = l->next;
        free(l);
        return tmp;
    }
    l->next = rimuoviRic(l->next, val);
    return l;
}

// Deallocazione ricorsiva
void liberaRic(IntList l) {
    if (l != NULL) {
        liberaRic(l->next);
        free(l);
    }
}
