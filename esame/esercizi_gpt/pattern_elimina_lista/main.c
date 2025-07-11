#include <stdio.h>
#include "list_helpers.h"

int main() {
    int arr[] = {1,2,3,4,5};
    IntList l = creaLista(arr, 5);
    
    stampaLista(l);
    
    eliminaUltimo(&l);
    stampaLista(l);
    
    eliminaPenultimo(&l);
    stampaLista(l);
    
    eliminaTerzultimo(&l);
    stampaLista(l);
    
    liberaLista(l);
    return 0;
}

//utilizzo: gcc main.c list_helpers.c -o prog