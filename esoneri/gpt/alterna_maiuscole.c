#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
 * ESERCIZIO:
 * Scrivere una funzione `char* alternaMaiuscoleMinuscole(char* str, int len)` che, 
 * data una stringa di `len` caratteri, restituisce una nuova stringa ottenuta così:
 *
 * - ogni lettera alfabetica (sia maiuscola che minuscola) viene convertita in minuscola 
 *   se si trova in posizione PARI (indice 0, 2, 4, ...),
 *   e in MAIUSCOLA se si trova in posizione DISPARI (indice 1, 3, 5, ...).
 * - i caratteri NON alfabetici restano invariati;
 * - usare `malloc` per creare la nuova stringa (lunghezza len + 1 per '\0');
 * - usare le funzioni `isalpha()`, `tolower()`, `toupper()` della libreria ctype.h;
 * - se l'input è NULL, restituire NULL.
 *
 * Esempio:
 * Input:  "C1a0OsAfARe!"
 * Output: "c1A0oSaFaRe!"
 *
 * Scrivere anche un main che inizializza una stringa, chiama la funzione e stampa
 * il risultato prima e dopo la trasformazione.
 */

char* alternaMaiuscoleMinuscole(char* str, int len){

    if(str == NULL){
        return NULL;
    }

    char *newStr = (char *)malloc(sizeof(char) * (len + 1));

    if(newStr == NULL){
        return NULL;
    }

    for (int i = 0; i < len; i++){
        if(isalpha(str[i])){ // isalpha = carattere alfabeto
            if(i % 2 == 0){
                newStr[i] = tolower(str[i]);
            } else{
                newStr[i] = toupper(str[i]);
            }
        } else{
            newStr[i] = str[i];
        }
    }

    newStr[len] = '\0';

    return newStr;
}

int main() {
    char str[] = "C1a0OsAfARe!";

    char *result = alternaMaiuscoleMinuscole(str, strlen(str));

    if(result != NULL){
        printf("PRIMA: %s\nDOPO: %s\n", str, result);

        free(result);
    }

    return 0;
}
