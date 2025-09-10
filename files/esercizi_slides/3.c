
#include <stdio.h>

int main() {
  int scrivi;
  FILE *fp;
  char frase[50];

  printf("\nVuoi aggiungere o leggere? 1: aggiungere, 0: leggere ");
  scanf("%d", &scrivi);

  if (scrivi) {
    fp = fopen("testo.txt", "a");
    if (fp) {
      printf("Scrivi una frase: ");
      scanf(" %[^\n]", frase);
      fprintf(fp, "%s\n", frase);
      fclose(fp);
    }
  } else {
    fp = fopen("testo.txt", "r");
    if (fp) {
      printf("\nContenuto del file:\n");
      while (fgets(frase, sizeof(frase), fp)) {
        printf("%s", frase);
      }
      fclose(fp);
    } else {
      printf("\nFile non trovato\n");
    }
  }
}
