/* INSERIRE QUI EVENTUALI #include <...> */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */

typedef struct node CharNode, *CharList;

struct node {
    char data;
    CharList next;
};

void stampaLista(CharList l){
    while(l != NULL){
        printf("%c ", l->data);
        l = l->next;
    }
}

void liberaLista(CharList l){
    while(l != NULL){
        CharList temp = l;
        l = l->next;
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
    
    CharList head = NULL;
    CharList tail = NULL;
    
    for(int i = 0; s[i] != '\0'; i++){
        if(isalpha(s[i]) && isupper(s[i])){
            
            CharList newNode = (CharList)malloc(sizeof(CharNode));
            if(newNode == NULL){
                return NULL;
            }
        
            newNode->data = tolower(s[i]);
            newNode->next = NULL;
            if(head == NULL){
                head = newNode;
                tail = newNode;
            } else{
                tail->next = newNode;
                tail = newNode;
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

    char *str = "Coordination@DisCoTec-2025";
    
    CharList list = stringToList(str);
    
    stampaLista(list);
    
    liberaLista(list);

    return 0;
}
