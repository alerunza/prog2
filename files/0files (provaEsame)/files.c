#include <stdio.h>
#include <stdlib.h>

/* 
Scrivere una funzione di confronto tra 2 file di testo, tale funzione
riceve in input i due filename e confronta i file carattere per carattere.

La funzione restituisce:

    -1 se vi sono errori nell'apertura dei file;
    0 (zero) se i due file sono identici;
    1 se sono diversi e i due ultimi parametri contengono numero riga e carattere a cui si trova la differenza.

creare anche un main() di richiamo della funzione, che stampa il risultato.


*/


int compare(char* fname1, char* fname2, long* line, long* charpos) {
    FILE *file1, *file2;
    int ch1, ch2;
    *line = 1;
    *charpos = 1;

    // Apriamo i file in modalità lettura
    file1 = fopen(fname1, "r");
    file2 = fopen(fname2, "r");

    // Se uno dei file non può essere aperto, restituisce -1
    if (file1 == NULL || file2 == NULL) {
        if (file1) fclose(file1);
        if (file2) fclose(file2);
        return -1;
    }

    // Confronta i file carattere per carattere
    while ((ch1 = fgetc(file1)) != EOF && (ch2 = fgetc(file2)) != EOF) {
        // Se troviamo una differenza
        if (ch1 != ch2) {
            fclose(file1);
            fclose(file2);
            return 1; // Restituisce 1 se i file sono diversi
        }

        // Aggiorna i contatori di linea e posizione
        if (ch1 == '\n') {
            (*line)++;
            *charpos = 1;
        } else {
            (*charpos)++;
        }
    }

    // Se uno dei file non è terminato mentre l'altro sì, i file sono diversi
    if (ch1 != ch2) {
        fclose(file1);
        fclose(file2);
        return 1;
    }

    // Chiudi i file
    fclose(file1);
    fclose(file2);

    // Se non ci sono differenze, restituisce 0
    return 0;
}

int main() {
    char* file1 = "file1.txt";
    char* file2 = "file2.txt";
    long line, charpos;
    
    int result = compare(file1, file2, &line, &charpos);

    if (result == -1) {
        printf("Errore nell'apertura dei file.\n");
    } else if (result == 0) {
        printf("I file sono identici.\n");
    } else if (result == 1) {
        printf("I file sono diversi. Differenza trovata alla riga %ld, carattere %ld.\n", line, charpos);
    }

    return 0;
}
