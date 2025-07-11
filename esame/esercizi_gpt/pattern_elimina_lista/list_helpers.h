#ifndef LIST_HELPERS_H
#define LIST_HELPERS_H

typedef struct node {
    int data;
    struct node* next;
} IntNode, *IntList;

// Funzioni di utilità lista
IntList creaLista(int* arr, int n);
void stampaLista(IntList l);
void liberaLista(IntList l);

// Funzioni di rimozione nodi
int eliminaUltimo(IntList* head);
int eliminaPenultimo(IntList* head);
int eliminaTerzultimo(IntList* head);

#endif
