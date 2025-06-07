#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} IntNode, *IntList;

// Stampa lista
void stampa(IntList l) {
    while (l != NULL) {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}

// Lunghezza lista
int length(IntList l) {
    int len = 0;
    while (l != NULL) {
        len++;
        l = l->next;
    }
    return len;
}

// Somma elementi
int somma(IntList l) {
    int somma = 0;
    while (l != NULL) {
        somma += l->data;
        l = l->next;
    }
    return somma;
}

// Inserimento in testa
IntList inserisciTesta(IntList l, int val) {
    IntList nuovo = malloc(sizeof(IntNode));
    nuovo->data = val;
    nuovo->next = l;
    return nuovo;
}

// Inserimento in coda
IntList inserisciCoda(IntList l, int val) {
    IntList nuovo = malloc(sizeof(IntNode));
    nuovo->data = val;
    nuovo->next = NULL;

    if (l == NULL) return nuovo;

    IntList tmp = l;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = nuovo;
    return l;
}

// Rimozione di un elemento (prima occorrenza)
IntList rimuovi(IntList l, int val) {
    IntList curr = l, prev = NULL;
    while (curr != NULL) {
        if (curr->data == val) {
            if (prev == NULL)
                l = curr->next;
            else
                prev->next = curr->next;
            free(curr);
            return l;
        }
        prev = curr;
        curr = curr->next;
    }
    return l;
}

// Deallocazione lista
void libera(IntList l) {
    while (l != NULL) {
        IntList tmp = l;
        l = l->next;
        free(tmp);
    }
}
