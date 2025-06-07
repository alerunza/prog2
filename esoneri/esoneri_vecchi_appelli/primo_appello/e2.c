#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // Per la funzione isdigit()
#include <string.h>

/*
crea una funzione in c che, data una stringa, crea un array dove toglie i 
numeri dall'array che le viene passato
e li sostituisce con le lettere maiuscole 'A''B', ovvero:

ciao1c2a4o2 diventa ciaoAcBaAoB (sostituisce consecutivamente i numeri con A e B)

crea un main con una stringa che richiami una funzione per risolvere il problema, 
la quale dovrà usare la malloc. 
La funzione chiamata avrà come input un puntatore all'array e 
il numero di elementi.
*/

// Funzione che sostituisce i numeri con lettere maiuscole
char* sostituisciNumeri(const char* str, int lunghezza) {

    if(str == NULL){
        return NULL;
    }

    char* newStr = (char*)malloc(sizeof(char) * (lunghezza + 1));

    if(newStr == NULL){
        return NULL;
    }

    int A = 1;
    for (int i = 0; i < lunghezza; i++)
    {
        if(isdigit(str[i])){
            if(A){
                newStr[i] = 'A';
                A = 0;
            } else{
                newStr[i] = 'B';
                A = 1;
            }
        } else{
            newStr[i] = str[i];
        }
    }
    
    /* int consecutive = 0; */
/*     for (int i = 0; i < lunghezza; i++)
    {
        if(isdigit(str[i])){
            newStr[i] = 'A' + (consecutive % 2);
            consecutive++;
        } else{
            newStr[i] = str[i];
        }
    } */

    newStr[lunghezza] = '\0';

    return newStr;
}

int main() {

    char str[] = "ciao1c2a4o2";

    char *cambiaStr = sostituisciNumeri(str, 11);

    if(cambiaStr != NULL){
        printf("PRIMA: %s\nDOPO: %s\n", str, cambiaStr);

        free(cambiaStr);
    }
}
