#include <stdio.h>
#include <stdlib.h>

// Esempio base: allocazione di un singolo int
void esempio_singolo() {
    int *p = (int *)malloc(sizeof(int));
    if (p == NULL) {
        printf("Allocazione fallita\n");
        return;
    }

    *p = 42;
    printf("Valore allocato: %d\n", *p);

    free(p);
    p = NULL;
}

// Esempio: array dinamico
void esempio_array() {
    int n;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Allocazione fallita\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i * i;
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;
}

int main() {
    esempio_singolo();
    esempio_array();
    return 0;
}
