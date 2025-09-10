#include <stdio.h>

struct Persona {
  char nome[20];
  int eta;
};

int main() {
  int scrivi;
  FILE *fp;
  struct Persona p;

  printf("\nVuoi scrivere o leggere? 1: scrivere, 0: leggere ");
  scanf("%d", &scrivi);

  if (scrivi) {
    fp = fopen("persona.txt", "w");
    if (fp) {
      printf("Nome: ");
      scanf("%s", p.nome);
      printf("Eta: ");
      scanf("%d", &p.eta);
      fprintf(fp, "%s %d\n", p.nome, p.eta);
      fclose(fp);
    }
  } else {
    fp = fopen("persona.txt", "r");
    if (fp) {
      fscanf(fp, "%s %d", p.nome, &p.eta);
      printf("\nHo letto: %s %d\n", p.nome, p.eta);
      fclose(fp);
    } else {
      printf("\nFile non trovato\n");
    }
  }
}
