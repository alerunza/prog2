#include <stdio.h>
#include <stdlib.h>

#define MAXT 30
#define MAXN 30

// Struct con typedef
typedef struct {
    char titolo[MAXT];
    int pagine;
    char autore[MAXN];
    float prezzo;
} Libro;

// Enum
typedef enum {FUMETTO, ROMANZO, SAGGIO} Categoria;

// Union base
typedef union {
    int i;
    float f;
    char c;
} Valore;

// Union etichettata
typedef enum {INTERO, CARATTERE} Tipo;

typedef struct {
    Tipo tipo;
    union {
        int i;
        char c;
    } dato;
} ValoreEtichettato;

void stampa_valore(ValoreEtichettato v) {
    if (v.tipo == INTERO)
        printf("Intero: %d\n", v.dato.i);
    else
        printf("Char: %c\n", v.dato.c);
}

int main() {
    Libro l1 = {"Il Signore degli Anelli", 1178, "Tolkien", 39.90};
    printf("Libro:\nTitolo: %s\nPagine: %d\nAutore: %s\nPrezzo: %.2f\n\n", l1.titolo, l1.pagine, l1.autore, l1.prezzo);

    Valore v;
    v.i = 10;
    printf("Valore int: %d\n", v.i);
    v.f = 3.14;
    printf("Valore float (sovrascrive int): %.2f\n", v.f);
    v.c = 'A';
    printf("Valore char (sovrascrive float): %c\n\n", v.c);

    ValoreEtichettato ve1 = {INTERO, .dato.i = 123};
    ValoreEtichettato ve2 = {CARATTERE, .dato.c = 'X'};
    stampa_valore(ve1);
    stampa_valore(ve2);

    return 0;
}
