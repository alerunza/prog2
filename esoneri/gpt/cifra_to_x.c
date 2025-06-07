#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
 * ESERCIZIO:
 * Scrivere una funzione `char* cifraToX(char* str, int len)` che,
 * data una stringa `str` di lunghezza `len`, restituisce una nuova stringa
 * dove ogni cifra ('0'-'9') è sostituita dal carattere 'X'.
 *
 * Tutti gli altri caratteri (lettere, simboli, spazi) restano invariati.
 *
 * - Usare malloc per allocare dinamicamente la nuova stringa.
 * - Usare isdigit() per verificare se un carattere è una cifra.
 * - Se l'input è NULL, restituire NULL.
 *
 * Esempio:
 * Input:  "Paolo123 va al 7-eleven!"
 * Output: "PaoloXXX va al X-eleven!"
 *
 * Scrivere anche un main che prova la funzione con una stringa di esempio
 * e stampa il risultato prima e dopo.
 */

char* cifraToX(char* str, int len){
    if(str == NULL){
        return NULL;
    }

    char *newStr = (char *)malloc(sizeof(char) * (len + 1));

    if(newStr == NULL){
        return NULL;
    }

    for (int i = 0; i < len; i++){
        if(isdigit(str[i])){
            newStr[i] = 'X';
        } else{
            newStr[i] = str[i];
        }
    }

    newStr[len] = '\0';

    return newStr;
}

int main() {

    char str[] = "Paolo123 va al 7-eleven!";

    char *result = cifraToX(str, strlen(str));

    if(result != NULL){
        printf("PRIMA: %s\nDOPO: %s\n", str, result);

        free(result);
    }

    return 0;
}
