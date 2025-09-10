#include <stdio.h>

int main() {
  FILE *in, *out;
  char c;
  char *parole[] = {"zero",   "uno", "due",   "tre",  "quattro",
                    "cinque", "sei", "sette", "otto", "nove"};

  in = fopen("input.txt", "r");
  out = fopen("output.txt", "w");

  if (!in || !out) {
    printf("Errore apertura file\n");
    return 1;
  }

  while ((c = fgetc(in)) != EOF) {
    if (c >= '0' && c <= '9') {
      fprintf(out, "%s", parole[c - '0']);
    } else {
      fputc(c, out);
    }
  }

  fclose(in);
  fclose(out);

  printf("Conversione completata!\n");
  return 0;
}
