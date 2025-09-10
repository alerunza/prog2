#include <stdio.h>
#define MAX 5

int main() {
  int scrivi;
  FILE *fp;
  int i, x;

  printf("\nVuoi scrivere o leggere? 1: scrivere, 0: leggere ");
  scanf("%d", &scrivi);

  if (scrivi) {
    fp = fopen("numeri.txt", "w");
    if (fp) {
      for (i = 0; i < MAX; i++) {
        printf("Inserisci numero %d: ", i + 1);
        scanf("%d", &x);
        fprintf(fp, "%d\n", x);
      }
      fclose(fp);
    }
  } else {
    fp = fopen("numeri.txt", "r");
    if (fp) {
      printf("\nHo letto i numeri:\n");
      for (i = 0; i < MAX; i++) {
        fscanf(fp, "%d", &x);
        printf("%d ", x);
      }
      fclose(fp);
    } else {
      printf("\nFile non trovato\n");
    }
  }
}
