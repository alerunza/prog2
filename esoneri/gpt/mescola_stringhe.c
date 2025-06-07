#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * ESERCIZIO:
 * Scrivere una funzione `char* mescolaStringhe(char* s1, char* s2)` che,
 * date due stringhe `s1` e `s2` (terminate da '\0'), restituisce una nuova
 * stringa ottenuta alternando un carattere da s1 e uno da s2.
 *
 * Se una delle due stringhe è più lunga, i caratteri rimanenti vanno 
 * aggiunti in fondo al risultato.
 *
 * - Usare malloc per creare dinamicamente la nuova stringa.
 * - Restituire NULL se uno dei due input è NULL.
 *
 * Esempi:
 * s1 = "ABC", s2 = "12345" → ritorna "A1B2C345"
 * s1 = "ciao", s2 = "XY"   → ritorna "cXiYaO"
 *
 * Scrivere anche un main che prova la funzione con un esempio.
 */

char* mescolaStringhe(char* s1, char* s2){
    if(s1 == NULL || s2 == NULL){
        return NULL;
    }

    int lenS1 = strlen(s1), lenS2 = strlen(s2);
    int lenTot = lenS1 + lenS2;

    char *combineSS = (char *)malloc(sizeof(char) * (lenTot + 1));

    if(combineSS == NULL){
        return NULL;
    }

    int i = 0, j = 0, k = 0;
    for (; i < lenS1 && j < lenS2; i++, j++)
    {
        combineSS[k++] = s1[i];
        combineSS[k++] = s2[j];
    }

    while(i < lenS1){
        combineSS[k++] = s1[i++];
    }

    while(j < lenS2){
        combineSS[k++] = s2[j++];
    }

    combineSS[lenTot] = '\0';

    return combineSS;
}

int main() {

    char s1[] = "ABC";
    char s2[] = "12345";

    char* risultato = mescolaStringhe(s1, s2);

    if (risultato != NULL) {
        printf("PRIMA: %s + %s\nDOPO: %s\n", s1, s2, risultato);
        free(risultato);
    }

    return 0;
}
