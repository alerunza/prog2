#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 
Date una stringa s, la sua lunghezza n>=0 e un numero m tale che m>=0,
restituisce una stringa che, nella posizione 0 contiene s[n-1]; nella posizione
1 contiene s[n-2]; eccetera, terminando con i caratteri trovati nelle posizioni
s[n-min(n,m)+1], s[n-min(n,m)] (se m==0, restituisce la stringa vuota).

Si noti che nella stringa risultato i caratteri sono riportati in ordine diverso 
rispetto alla stringa originaria.

"eccocosafare" 12, 5, diventa "erafa"
"eccocosafare", 12, 0, diventa ""
*/



/* char* trasforma(char* str, int n, int m){

    if(m == 0){
        return "";
    }

    if(str == NULL){
        return NULL;
    }
    
    //minimo per s[n-min(n,m)+1]
    int min = 0;
    if (m > n)
    {
        min = n;
    } else{
        min = m;
    }

    char *newStr = (char *)malloc(sizeof(char) * (min + 1));

    int j = 0;
    for (int i = (n - 1); i >= (n - min); i--)
    {
        newStr[j++] = str[i];
    }

    newStr[j] = '\0';

    return newStr;
}
 */

 char* trasforma(char* str, int n, int m){

    if(m == 0){
        return "";
    }

    if(str == NULL){
        return NULL;
    }

    char *newStr = (char *)malloc(sizeof(char) * (m + 1));

    if(newStr == NULL){
        return NULL;
    }

    int j = 0, k = n - 1;

    for (int i = 0; i < m; i++)
    {
        newStr[j++] = str[k--];
    }

    newStr[j] = '\0';

    return newStr;
}


int main(){

    char str[] = "eccocosafare";

    char *trans = trasforma(str, strlen(str), 5);

    printf("PRIMA: %s\nDOPO: %s\n", str, trans);
}