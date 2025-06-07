#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */

/**
 * @brief Date una stringa s e due indici i, j validi per s (cioè tali da fare riferimento
 * a caratteri della stringa), restituisce una nuova stringa che nella posizione 0 contiene s[j],
 * nella posizione 1 contiene  s[j-1], eccetera terminando con i caratteri trovati nelle
 * posizioni s[i+1], s[i] (se i > j, restituisce la stringa vuota). Si noti che nella stringa
 * risultato i caratteri sono riportati in ordine inverso rispetto alla stringa originaria.
 *
 * ESEMPI: 
 * (1) dati "eccocosafare", 4, 7 restituisce “asoc”.
 * (2) dati "eccocosafare”, 8,3 restituisce “”.
 */
char *extract(char *s, int i, int j)  {

    if(i > j){
        return "";
    }
    
    int len = (j - i) + 1;
    char *newS = (char*)malloc(len + 1);
    for(int z = 0; z < len; z++){
        newS[z] = s[j - z];
    }
    
    newS[len] = '\0'; //terminatore
    
    return newS;

}

/**
 * @brief Inizializza una stringa str e due indici first, last validi per str,
 * e scrive sullo schermo la stringa restituita da extract(str,first,last).
 */
int main() {

    char *str = "eccocosafare"; /* INSERIRE QUI LA STRINGA */ ;
    int first  = 4; /* INSERIRE QUI UN INDICE VALIDO PER str */ ;
    int last  = 7; /* INSERIRE QUI UN INDICE VALIDO PER str */ ;

    char* risultato = extract(str, first, last);
    
    printf("%s\n", risultato);

    return 0;
}
