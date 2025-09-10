#include <stdio.h>
#define MAX 5

int main() {
  int scrivi;
  FILE *fp;
  int numeri[MAX];
  int i;

  printf("\nVuoi scrivere o leggere? 1: scrivere, 0: leggere ");
  scanf("%d", &scrivi);

  if (scrivi) {
    fp = fopen("numeri.dat", "wb");
    if (fp) {
      for (i = 0; i < MAX; i++) {
        printf("Inserisci numero %d: ", i + 1);
        scanf("%d", &numeri[i]);
      }
      fwrite(numeri, sizeof(int), MAX, fp);
      fclose(fp);
    }
  } else {
    fp = fopen("numeri.dat", "rb");
    if (fp) {
      fread(numeri, sizeof(int), MAX, fp);
      printf("\nHo letto:\n");
      for (i = 0; i < MAX; i++) {
        printf("%d ", numeri[i]);
      }
      printf("\n");
      fclose(fp);
    } else {
      printf("\nFile non trovato\n");
    }
  }
}
