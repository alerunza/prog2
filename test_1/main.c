// main.c
#include <stdio.h>
#include <string.h>
#include "indirizzo.h"

int main() {
    X personaUK, personaITA;

    // UK
    personaUK.nazione = UK;
    personaUK.n.address.number = 10;
    strcpy(personaUK.n.address.street, "Downing Street");
    personaUK.n.address.floor = 1;
    strcpy(personaUK.n.address.pcode, "SW1A");
    strcpy(personaUK.n.address.town, "London");

    printf("=== INDIRIZZO UK ===\n");
    printf("%d, %s, floor %d, %s, %s\n\n",
           personaUK.n.address.number,
           personaUK.n.address.street,
           personaUK.n.address.floor,
           personaUK.n.address.pcode,
           personaUK.n.address.town);

    // ITALIA
    personaITA.nazione = ITALIA;
    personaITA.n.indirizzo.civico = 5;
    personaITA.n.indirizzo.strada = CORSO;
    strcpy(personaITA.n.indirizzo.nomestrada, "Italia");
    strcpy(personaITA.n.indirizzo.citta, "Roma");

    printf("=== INDIRIZZO ITALIA ===\n");
    printf("%d, ", personaITA.n.indirizzo.civico);

    switch (personaITA.n.indirizzo.strada) {
        case VIA: printf("VIA "); break;
        case PIAZZA: printf("PIAZZA "); break;
        case CORSO: printf("CORSO "); break;
    }

    printf("%s, %s\n", personaITA.n.indirizzo.nomestrada, personaITA.n.indirizzo.citta);

    return 0;
}