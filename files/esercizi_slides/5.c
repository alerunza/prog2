#include <stdio.h>

struct Studente {
  char nome[20];
  float media;
};

int main() {
  int scrivi;
  FILE *fp;
  struct Studente s;

  printf("\nVuoi scrivere o leggere? 1: scrivere, 0: leggere ");
  scanf("%d", &scrivi);

  if (scrivi) {
    fp = fopen("studente.dat", "wb");
    if (fp) {
      printf("Nome: ");
      scanf("%s", s.nome);
      printf("Media voti: ");
      scanf("%f", &s.media);
      fwrite(&s, sizeof(struct Studente), 1, fp);
      fclose(fp);
    }
  } else {
    fp = fopen("studente.dat", "rb");
    if (fp) {
      fread(&s, sizeof(struct Studente), 1, fp);
      printf("\nHo letto: %s %.2f\n", s.nome, s.media);
      fclose(fp);
    } else {
      printf("\nFile non trovato\n");
    }
  }
}
