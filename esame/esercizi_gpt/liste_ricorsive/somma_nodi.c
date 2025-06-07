#include "liste_utils.h"

int sommaRic(IntList l){
    if(l == NULL){
        return 0;
    } else{
        return l->data + sommaRic(l->next);
    }
}

int main() {
    int arr[] = {3, 5, 7, 2};
    IntList lista = creaLista(arr, 4);

    stampaLista(lista); // [3 -> 5 -> 7 -> 2]

    int somma = sommaRic(lista);
    printf("Somma ricorsiva: %d\n", somma); // atteso: 17

    libera(lista);
    return 0;
}
