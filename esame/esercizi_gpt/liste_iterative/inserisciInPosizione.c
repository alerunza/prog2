#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} IntNode, *IntList;

IntList creaLista(int a[], int len){
    IntList head = NULL;
    IntList tail = NULL;

    for (int i = 0; i < len; i++){
        IntList nuovo = (IntList)malloc(sizeof(IntNode));
        
        if(nuovo == NULL){
            return NULL;
        }

        nuovo->data = a[i];
        nuovo->next = NULL;

        if(head == NULL){
            head = tail = nuovo;
        } else{
            tail->next = nuovo;
            tail = nuovo;
        }
    }

    return head;
}

IntList inserisciInPosizione(IntList l, int val, int pos){
    IntList newInt = (IntList)malloc(sizeof(IntNode));
    
    if(newInt == NULL){
        return NULL;
    }

    newInt->data = val;
    newInt->next = NULL;

    //caso: testa o lista vuota
    if(pos == 0 || l == NULL){
        newInt->next = l;
        return newInt;
    }

    //lunghezza
    int len = 0;
    IntList temp = l;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }

    //se pos >= len, inseriamo in coda
    if(pos >= len){
        temp = l;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newInt;
        return l;
    }

    //caso: inserimento in mezzo
    temp = l;
    for (int i = 0; i < pos - 1; i++){
        temp = temp->next;
    }

    newInt->next = temp->next;
    temp->next = newInt;

    return l;
}

void stampaLista(IntList l) {
    printf("[");
    while (l != NULL) {
        printf("%d", l->data);
        if (l->next != NULL)
            printf(" -> ");
        l = l->next;
    }
    printf("]\n");
}

void libera(IntList l) {
    while (l != NULL) {
        IntList tmp = l;
        l = l->next;
        free(tmp);
    }
}


int main() {
    int arr[] = {10, 20, 30};
    IntList lista = creaLista(arr, 3);

    printf("Lista iniziale:\n");
    stampaLista(lista);

    // prova: inserisco 99 in posizione 1 → tra 10 e 20
    lista = inserisciInPosizione(lista, 99, 1);
    printf("Dopo inserimento in pos 1:\n");
    stampaLista(lista);

    // prova: inserisco in testa
    lista = inserisciInPosizione(lista, 5, 0);
    printf("Dopo inserimento in testa:\n");
    stampaLista(lista);

    // prova: inserisco oltre la lunghezza
    lista = inserisciInPosizione(lista, 100, 10);
    lista = inserisciInPosizione(lista, 16, 5);
    printf("Dopo inserimento in coda:\n");
    stampaLista(lista);

    libera(lista);
    return 0;
}
