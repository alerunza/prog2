// indirizzo.h
#ifndef INDIRIZZO_H
#define INDIRIZZO_H

#define N1 50
#define N2 10
#define N3 30

enum tag_paese { UK, ITALIA };

typedef struct _indUK {
    int number;
    char street[N1];
    int floor;
    char pcode[N2];
    char town[N3];
} indUK;

enum tag_strada { VIA, PIAZZA, CORSO };

typedef struct _indITA {
    int civico;
    enum tag_strada strada;
    char nomestrada[N1];
    char citta[N3];
} indITA;

typedef struct {
    enum tag_paese nazione;
    union {
        indUK address;
        indITA indirizzo;
    } n;
} X, X2, *PTRX;

#endif