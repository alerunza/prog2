
/*
crea una funzione che dato un array ne duplichi i numeri

abc1c diventa abc11c

crea un main con una stringa che richiami una funzione per risolvere il problema, 
la quale dovrà usare la malloc. La funzione chiamata avrà come input un 
puntatore all'array e il numero di elementi.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // Per la funzione isdigit()
#include <string.h>

// Funzione che duplica i numeri in una stringa
char* duplicaNumeri(const char* str, int lunghezza) {

    if(str == NULL){
        return NULL;
    }

    int numeri = 0;
    for (int i = 0; i < lunghezza; i++)
    {
        if(isdigit(str[i])){
            numeri++;
        }
    }

    char *newStr = (char *)malloc(sizeof(char) * (lunghezza + numeri + 1));

    if(newStr == NULL){
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < lunghezza; i++)
    {
        if(isdigit(str[i])){
            newStr[j++] = str[i];
            newStr[j++] = str[i]; //duplica numero
        } else{
            newStr[j++] = str[i];
        }
    }

    newStr[j] = '\0';

    return newStr;
}

int main() {
    char str[] = "abc1c";

    char *cambio = duplicaNumeri(str, strlen(str));

    printf("PRIMA: %s\nDOPO: %s\n", str, cambio);
}