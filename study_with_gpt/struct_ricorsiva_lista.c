#include <stdio.h>
#include <stdlib.h>

// Definizione struct ricorsiva
typedef struct Nodo {
    int valore;
    struct Nodo* next;
} Nodo;

// Funzione per creare un nodo
Nodo* crea_nodo(int valore) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovo == NULL) return NULL;
    nuovo->valore = valore;
    nuovo->next = NULL;
    return nuovo;
}

// Stampa la lista
void stampa_lista(Nodo* head) {
    while (head != NULL) {
        printf("%d -> ", head->valore);
        head = head->next;
    }
    printf("NULL\n");
}

// Liberazione memoria
void libera_lista(Nodo* head) {
    while (head != NULL) {
        Nodo* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Nodo* lista = crea_nodo(10);
    lista->next = crea_nodo(20);
    lista->next->next = crea_nodo(30);

    stampa_lista(lista);
    libera_lista(lista);

    return 0;
}
