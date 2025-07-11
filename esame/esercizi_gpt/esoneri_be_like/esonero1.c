/* INSERIRE QUI EVENTUALI #include <...> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node CharNode, *CharList;

struct node {
    char data;
    CharList next;
};

/**
 * Data una stringa s, restituisce una lista di caratteri che contiene
 * tutte e sole le cifre (0-9) presenti nella stringa s, invertendone
 * simbolicamente il significato ('0'→'9', '1'→'8', ..., '9'→'0').
 *
 * Non considera l'eventualità che la malloc fallisca.
 * Se s == NULL o s == "", restituisce NULL.
 *
 * ESEMPI:
 * (1) s == NULL        → NULL
 * (2) s == ""          → NULL
 * (3) s == "a3b8"      → ['6', '1']
 * (4) s == "Pi2025"    → ['7','9','7','4']
 */
CharList digitsToInvertedList(char *s) {

    //quando mettere il * a s (parametro) -> chiedere
    if(s == NULL || strlen(s) == 0){
        return NULL;
    }

    CharList head = NULL, tail = NULL;

    for (int i = 0; s[i] != '\0'; i++){
        if(isdigit(s[i])){
            CharList newS = (CharList)malloc(sizeof(CharNode));

            if(newS == NULL){
                return NULL;
            }

            newS->data = '9' - (s[i] - '0');
            newS->next = NULL;

            if(head == NULL){
                head = newS;
                tail = newS;
            } else{
                tail->next = newS;
                tail = newS;
            }
        }
    }

    return head;
}

/**
 * Stampa tutti i caratteri della lista sulla stessa riga, separati da uno spazio.
 */
void stampa(CharList s) {

    while(s != NULL){
        printf("%c ", s->data);
        s = s->next;
    }
}

/**
 * Libera la memoria occupata dalla lista.
 */
void libera(CharList s) {

    while (s != NULL){
        CharList temp = s;
        s = s->next;
        free(temp);
    }
}

/**
 * Invoca digitsToInvertedList sulla stringa "Pi2025",
 * stampa la lista risultante su una riga,
 * poi libera la memoria occupata.
 */
int main() {

    char *str = "Pi2025";

    CharList listaConvertita = digitsToInvertedList(str);

    stampa(listaConvertita);
    libera(listaConvertita);

    return 0;
}
