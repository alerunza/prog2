#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOME 50
#define MAXFILE "output.txt"

typedef struct {
    char nome[MAXNOME];
    int eta;
} Persona;

typedef struct Nodo {
    Persona persona;
    struct Nodo* next;
} Nodo;

typedef Nodo* Lista;

// Crea un nodo
Nodo* crea_nodo(char* nome, int eta) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuovo) return NULL;
    strncpy(nuovo->persona.nome, nome, MAXNOME);
    nuovo->persona.eta = eta;
    nuovo->next = NULL;
    return nuovo;
}

// Inserisce in testa
void ins_testa(Lista* l, Nodo* nuovo) {
    nuovo->next = *l;
    *l = nuovo;
}

// Stampa su stdout
void stampa_lista(Lista l) {
    while (l) {
        printf("Nome: %s, Età: %d\n", l->persona.nome, l->persona.eta);
        l = l->next;
    }
}

// Scrive su file
void scrivi_su_file(Lista l, const char* filename) {
    FILE* f = fopen(filename, "w");
    if (!f) return;
    while (l) {
        fprintf(f, "%s %d\n", l->persona.nome, l->persona.eta);
        l = l->next;
    }
    fclose(f);
}

// Legge da file
void leggi_da_file(Lista* l, const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) return;
    char nome[MAXNOME];
    int eta;
    while (fscanf(f, "%s %d", nome, &eta) == 2) {
        Nodo* nuovo = crea_nodo(nome, eta);
        ins_testa(l, nuovo);  // inserimento in testa (ordine inverso)
    }
    fclose(f);
}

// Dealloca la lista
void dealloca_lista(Lista* l) {
    while (*l) {
        Nodo* tmp = *l;
        *l = (*l)->next;
        free(tmp);
    }
}

int main() {
    Lista mia_lista = NULL;
    ins_testa(&mia_lista, crea_nodo("Paolino", 20));
    ins_testa(&mia_lista, crea_nodo("Melissa", 21));
    ins_testa(&mia_lista, crea_nodo("Luca", 22));

    printf("Contenuto lista originale:\n");
    stampa_lista(mia_lista);

    scrivi_su_file(mia_lista, "output.txt");
    dealloca_lista(&mia_lista);

    printf("\nLeggo dal file:\n");
    leggi_da_file(&mia_lista, "output.txt");
    stampa_lista(mia_lista);
    dealloca_lista(&mia_lista);
    return 0;
}
