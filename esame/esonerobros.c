/* INSERIRE QUI EVENTUALI #include <...> */
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */

typedef struct node CharNode, *CharList;

struct node {
    char data;
    CharList next;
};


void stampaL(CharList s){
    while(s != NULL){
        printf("%c ", s->data);
        s = s->next;
    }
}

void freeL(CharList s){
    while(s != NULL){
        CharList temp = s;
        s = s->next;
        free(temp);
    }
}

/**
 * Data una stringa s, restituisce una lista di caratteri che contiene tutti
 * e soli i caratteri alfabetici maiuscoli (A - Z) trasformati in minuscoli
 * (a - z) della stringa s nell'ordine in cui occorrono in s.
 *
 * Non considera l'eventualità che la malloc fallisca.
 * Se s == NULL, restituisce NULL.
 *
 * ESEMPI:
 * (1) data s == NULL  restituisce NULL
 * (2) data s == "" restituisce NULL
 * (3) data s == "A" restituisce [a]
 * (4) data s == "AZbCuu12R" restituisce [a,z,c,r]
 */
CharList stringToList(char *s) {
    if(s == NULL || strlen(s) == 0){
        return NULL;
    }
    
    CharList head = NULL, tail = NULL;
    
    for(; *s != '\0'; s++){
        if(isupper(*s)){
            CharList newS = (CharList)malloc(sizeof(CharNode));
            
            if(newS == NULL){
                return NULL;
            }
            
            newS->data = tolower(*s);
            newS->next = NULL;
            
            if(head == NULL){
                head = tail = newS;
            } else{
                tail->next = newS;
                tail = newS;
            }
        }
    }
    
    return head;
}

/**
 * Invoca la funzione stringToList sulla stringa "Coordination@DisCoTec-2025",
 * stampa la lista restituita (in un formato a scelta, ma tutto su una sola riga),
 * e poi libera la memoria occupata dalla lista.
 */
int main() {

    char *s = "Coordination@DisCoTec-2025";
    
    CharList ciao = stringToList(s);
    
    stampaL(ciao);

    freeL(ciao);

    return 0;
}