#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXA 100
#define MAXT 200
#define MAXL 1000000

typedef struct libro {
    char autore[MAXA];
    char titolo[MAXT];
    int pagine;
    double prezzo;
    struct libro* next;

} Libro, *Libroptr;

Libroptr crealibro(char* a, char* t, int pa, double pr){
    Libroptr ret = (Libroptr)malloc(sizeof(Libro));
    if(ret != NULL) {
        if(a) strcpy(ret->autore,a);
        if(t) strcpy(ret->titolo,t); 
        ret->pagine = pa;
        ret->prezzo = pr;
        ret->next = NULL;
    }
    return ret;
}

void stampalibro(Libroptr l) {
    if(l->autore) printf("Autore: %s\n",l->autore);
    if(l->titolo) printf("Titolo: %s\n",l->titolo);
    printf("Pagine: %d\n",l->pagine);
    printf("Prezzo: %.2f (euro)\n",l->prezzo);
}

void stampabiblioteca(Libroptr bib) {
    printf("Biblioteca:\n\n");
    while(bib != NULL) {
        stampalibro(bib);
        printf("\n");
        bib = bib->next;
    }
}

void addtesta(Libroptr l, Libroptr* bibp) {
    l->next = (*bibp);
    (*bibp) = l;
}

void rimuovicoda(Libroptr* bibp) {
    Libroptr cur = *bibp;
    Libroptr prev = NULL;
    
    if(cur == NULL) return; // caso di biblio vuota

    // vado in fondo
    while(cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }

    free(cur);
    if(prev) {
        prev->next = NULL;
    } else {
        *bibp = NULL;
    }
}

// Libro Biblioteca[MAXL];
Libroptr bib, l;

int main() {
    bib = NULL;
    l = crealibro("mioautore1","miotitolo1",124,16.5);
    addtesta(l,&bib);
    l = crealibro("mioautore2","miotitolo2",88,7.25);
    addtesta(l,&bib);
    l = crealibro("mioautore3","miotitolo3",12,2.25);
    addtesta(l,&bib);

    stampabiblioteca(bib);

    rimuovicoda(&bib);
    rimuovicoda(&bib);
    rimuovicoda(&bib);
    rimuovicoda(&bib);
    stampabiblioteca(bib);

   
    return 0;
}
