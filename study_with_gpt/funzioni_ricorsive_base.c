#include <stdio.h>

// Fattoriale ricorsivo
int fattoriale(int n) {
    if (n <= 1) return 1;
    return n * fattoriale(n - 1);
}

// Fattoriale iterativo
int fattoriale_iter(int n) {
    int risultato = 1;
    for (int i = 1; i <= n; i++) {
        risultato *= i;
    }
    return risultato;
}

// Stampa da 1 a n (ricorsione in testa)
void stampa_crescente(int n) {
    if (n > 0) {
        stampa_crescente(n - 1);
        printf("%d ", n);
    }
}

// Stampa da n a 1 (ricorsione in coda)
void stampa_decrescente(int n) {
    if (n > 0) {
        printf("%d ", n);
        stampa_decrescente(n - 1);
    }
}

int main() {
    int n = 5;
    printf("Fattoriale ricorsivo di %d: %d\n", n, fattoriale(n));
    printf("Fattoriale iterativo di %d: %d\n\n", n, fattoriale_iter(n));

    printf("Stampa crescente fino a %d: ", n);
    stampa_crescente(n);
    printf("\n");

    printf("Stampa decrescente da %d: ", n);
    stampa_decrescente(n);
    printf("\n");

    return 0;
}
