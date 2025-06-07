#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * ESERCIZIO:
 * Scrivere una funzione `CharList stringToList(char* str);` che, data una stringa `str`,
 * costruisce e restituisce una lista collegata di caratteri, in cui ogni nodo
 * contiene un carattere della stringa, nell'ordine originale.
 */

typedef struct charNode {
    char c;
    struct charNode* next;
} CharNode;

typedef CharNode* CharList;

CharList stringToList(char* str) {
    if (str == NULL || strlen(str) == 0) {
        return NULL;
    }

    CharList head = NULL;
    CharList tail = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        CharNode* nuovo = (CharNode*)malloc(sizeof(CharNode));
        if (nuovo == NULL) {
            return NULL;
        }

        nuovo->c = str[i];
        nuovo->next = NULL;

        if (head == NULL) {
            head = nuovo;
            tail = nuovo;
        } else {
            tail->next = nuovo;
            tail = nuovo;
        }
    }

    return head;
}

void stampaLista(CharList lista) {
    while (lista != NULL) {
        printf("'%c' -> ", lista->c);
        lista = lista->next;
    }
    printf("NULL\n");
}

void liberaLista(CharList lista) {
    while (lista != NULL) {
        CharNode* temp = lista;
        lista = lista->next;
        free(temp);
        temp = NULL;
    }
}

int main() {
    char str[] = "esonerone";

    CharList lista = stringToList(str);

    printf("Stringa: %s\n", str);
    printf("Lista:   ");
    stampaLista(lista);

    liberaLista(lista);
    return 0;
}
