#include "liste_utils.h"

int contaOccorrenze(IntList l, int val){
    if(l == NULL){
        return 0;
    } else{
        if(l->data == val){
            return 1 + contaOccorrenze(l->next, val);
        } else{ //come se fosse != val
            return contaOccorrenze(l->next, val);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2};
    IntList lista = creaLista(arr, 6);

    stampaLista(lista);  // [1 -> 2 -> 3 -> 2 -> 4 -> 2]

    int quanti = contaOccorrenze(lista, 2);
    printf("Occorrenze del valore 2: %d\n", quanti);  // atteso: 3

    libera(lista);
    return 0;
}
