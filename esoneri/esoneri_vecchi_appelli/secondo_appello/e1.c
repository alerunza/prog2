#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* 
Date una stringa s e due indici i,j validi per s, restituisce una nuova stringa che nella
posizione 0 contiene s[j], nella posizione 1 contiene s[j-1], eccetera, terminando con i caratteri
trovati nelle posizioni s[i+1], s[i] (se i>j, restituisce la stringa vuota).
Si noti che nella stringa risultato i caratteri sono riportati in ordine inverso rispetto alla stringa originaria.


"eccocosafare", 4, 7 diventa "asoc"
"eccocosafare", 8, 3 diventa ""

*/


char* cambio(char *str, int i, int j){

    if(i > j){
        return "";
    }

    if(str == NULL){
        return NULL;
    }

    int len = (j - i) + 1;
    char *newStr = (char *)malloc(sizeof(char) * (len + 1));

    if(newStr == NULL){
        return NULL;
    }

    int index = 0;
    for (int k = j; i <= k; k--)
    {
        newStr[index++] = str[k];
    }

    newStr[index] = '\0';

    return newStr;
}

int main(){

    char str[] = "eccocosafare";

    char *cambia = cambio(str, 4, 7);

    printf("PRIMA: %s\nDOPO: %s\n", str, cambia);
}