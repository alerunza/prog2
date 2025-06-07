#include <stdio.h>
#define MAX 20
int main() {
    int scrivi; // il programma deve, a scelta dell’utente,
    // leggere o scrivere un file
    FILE *fp;
    char datiS[MAX];
    int datiN;
    printf("\n vuoi leggere o scrivere? 1: scrivere, 0:leggere ");
    scanf("%d", &scrivi);

    if (scrivi) {
        fp = fopen("dati.txt", "w"); // chiedo accesso in w al file
        if (fp) { // se ottenuto
            fprintf(fp, "nome: Anna id: 123\n"); // scrivo
            fclose(fp); // rilascio il file
        }
    } else {
        fp = fopen("dati.txt", "r"); // chiedo accesso in r al file
        if (fp) { // se ottenuto
            fscanf(fp, "nome: %s id: %d\n", datiS, &datiN); // leggo
            printf("\nHo letto: %s %d\n", datiS, datiN);
            fclose(fp); // rilascio il file
        } else{
            printf("\nFile Vuoto\n");
        }
    }
}