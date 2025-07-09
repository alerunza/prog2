#include <stdio.h>
#include <stdlib.h>

#include <ctype.h> //isdigit()

/*
Dato un array di caratteri ac, con n elementi, restituisce un nuovo
array (di lunghezza n) ottenuto da ac eliminando tutte le occorrenze
delle cifre ('0'...'9'), trasformando tutte le occorrenze delle lettere
minuscole 'k' e 'h' nelle corrispondenti lettere maiuscole, e riempiendo
le eventuali posizioni rimaste libere alla fine del nuovo array con delle 
occorrenze del carattere '#'.


'56akhra45' diventa 'aKHra####'

*/

//funzione chiamata
char *change(char *ac, int n){
	
    if(ac == NULL){
        return NULL;
    }

    char *newAC = (char *)malloc(sizeof(char) * (n + 1));

    if(newAC == NULL){
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < n && ac[i] != '\0'; i++)
    {
        if(!isdigit(ac[i])){
            if(ac[i] == 'k' || ac[i] == 'h'){
                newAC[j] = toupper(ac[i]);
                j++;
            } else{
                newAC[j] = ac[i];
                j++;
            }
        }
    }

    for (int i = j; i < n; i++){
        newAC[i] = '#';
        j++;
    }

    newAC[j] = '\0'; // terminatore

    return newAC;
}

/*
Inizializza un array ac di N caratteri e scrive sullo schermo la 
sequenza di caratteri ottenuti in ac eliminando tutte le occorrenze 
delle cifre ('0'...'9') trasformando tutte le occorrenze delle lettere
minuscole 'k' e 'h' nelle corrispondenti lettere maiuscole, e agguingendo
al fondo tante occorrenze del carattere '#' quante ne servono per arrivare
ad una sequenza di n caratteri.
*/

#define N 9

int main(){
    //0h1k2a3b
    char str[] = "56akhra45";

    char *cambio = change(str, N);

    if(cambio != NULL){
        printf("PRIMA: %s\nDOPO: %s\n", str, cambio);
        
        free(cambio);
        cambio = NULL;
    }
}