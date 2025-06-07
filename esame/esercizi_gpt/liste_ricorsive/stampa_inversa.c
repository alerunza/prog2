#include "liste_utils.h"

void stampaInversaRic(IntList l){
    if(l != NULL){
        stampaInversaRic(l->next);
        printf("%d ", l->data);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    IntList lista = creaLista(arr, 4);

    printf("Lista normale:\n");
    stampaLista(lista);  // [1 -> 2 -> 3 -> 4]

    printf("Lista stampata al contrario:\n");
    stampaInversaRic(lista);  // 4 3 2 1

    printf("\n");

    libera(lista);
    return 0;
}
