#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
    int data;
    IntList next;
};

// Funzione per stampare la lista
void stampaLista(IntList l) {
    while (l != NULL) {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}

// Funzione per liberare la memoria della lista
void liberaLista(IntList l) {
    while (l != NULL) {
        IntList temp = l;
        l = l->next;
        free(temp);
    }
}

// Funzione di supporto per creare una lista da un array
IntList creaListaDaArray(int a[], int n) {
    if (n <= 0) return NULL;
    IntList head = NULL, tail = NULL;
    for (int i = 0; i < n; i++) {
        IntList nuovo = (IntList)malloc(sizeof(IntNode));
        nuovo->data = a[i];
        nuovo->next = NULL;
        if (head == NULL) {
            head = tail = nuovo;
        } else {
            tail->next = nuovo;
            tail = nuovo;
        }
    }
    return head;
}

// Inserisci qui la tua funzione eliminaTerzultimo
int eliminaTerzultimo(IntList *lsPtr) {
    if (lsPtr == NULL) return -1;
    if (*lsPtr == NULL || (*lsPtr)->next == NULL || (*lsPtr)->next->next == NULL) return 0;

    IntList conta = *lsPtr;
    int contaNodi = 0;

    while (conta != NULL) {
        contaNodi++;
        conta = conta->next;
    }

    if (contaNodi < 3) return 0;

    if (contaNodi == 3) {
        IntList eliminaNodo = *lsPtr;
        *lsPtr = (*lsPtr)->next;
        free(eliminaNodo);
        return 1;
    }

    conta = *lsPtr;
    for (int i = 0; i < (contaNodi - 4); i++) {
        conta = conta->next;
    }

    IntList eliminaNodo = conta->next;
    conta->next = eliminaNodo->next;
    free(eliminaNodo);
    return 1;
}

// MAIN DI TEST
int main() {
    IntList lista;
    int esito;

    // Caso 1: lsPtr == NULL
    esito = eliminaTerzultimo(NULL);
    printf("Caso 1 (lsPtr NULL): esito = %d\n", esito);

    // Caso 2: lista vuota
    lista = NULL;
    esito = eliminaTerzultimo(&lista);
    printf("Caso 2 (lista vuota): esito = %d\n", esito);
    stampaLista(lista);
    liberaLista(lista);

    // Caso 3: [25]
    int a3[] = {25};
    lista = creaListaDaArray(a3, 1);
    esito = eliminaTerzultimo(&lista);
    printf("Caso 3 ([25]): esito = %d\n", esito);
    stampaLista(lista);
    liberaLista(lista);

    // Caso 4: [25, 50]
    int a4[] = {25, 50};
    lista = creaListaDaArray(a4, 2);
    esito = eliminaTerzultimo(&lista);
    printf("Caso 4 ([25, 50]): esito = %d\n", esito);
    stampaLista(lista);
    liberaLista(lista);

    // Caso 5: [10, 8, 12, 3]
    int a5[] = {10, 8, 12, 3};
    lista = creaListaDaArray(a5, 4);
    esito = eliminaTerzultimo(&lista);
    printf("Caso 5 ([10, 8, 12, 3]): esito = %d\n", esito);
    stampaLista(lista);
    liberaLista(lista);

    // Caso 6: [1,2,3,4,5]
    int a6[] = {1,2,3,4,5};
    lista = creaListaDaArray(a6, 5);
    esito = eliminaTerzultimo(&lista);
    printf("Caso 6 ([1,2,3,4,5]): esito = %d\n", esito);
    stampaLista(lista);
    liberaLista(lista);

    return 0;
}