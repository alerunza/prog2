#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 256
#define MAXN 1024

struct Studente {
  char nome[32];
  float media;
};

static void flushln() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

static void scrivi_testo() {
  char nome[MAXL], riga[MAXL];
  int n, i;
  printf("nome file: ");
  scanf("%255s", nome);
  flushln();
  printf("quante righe: ");
  scanf("%d", &n);
  flushln();
  FILE *f = fopen(nome, "w");
  if (!f) {
    printf("errore\n");
    return;
  }
  for (i = 0; i < n; i++) {
    printf("riga %d: ", i + 1);
    fgets(riga, sizeof(riga), stdin);
    riga[strcspn(riga, "\n")] = 0;
    fputs(riga, f);
    fputc('\n', f);
  }
  fclose(f);
}

static void leggi_testo() {
  char nome[MAXL], riga[MAXL];
  printf("nome file: ");
  scanf("%255s", nome);
  flushln();
  FILE *f = fopen(nome, "r");
  if (!f) {
    printf("errore\n");
    return;
  }
  while (fgets(riga, sizeof(riga), f))
    printf("%s", riga);
  fclose(f);
}

static void append_testo() {
  char nome[MAXL], riga[MAXL];
  printf("nome file: ");
  scanf("%255s", nome);
  flushln();
  FILE *f = fopen(nome, "a");
  if (!f) {
    printf("errore\n");
    return;
  }
  printf("riga da aggiungere: ");
  fgets(riga, sizeof(riga), stdin);
  riga[strcspn(riga, "\n")] = 0;
  fputs(riga, f);
  fputc('\n', f);
  fclose(f);
}

static void copia_file() {
  char src[MAXL], dst[MAXL];
  char buf[4096];
  size_t n;
  printf("sorgente: ");
  scanf("%255s", src);
  printf("destinazione: ");
  scanf("%255s", dst);
  flushln();
  FILE *in = fopen(src, "rb");
  if (!in) {
    printf("errore\n");
    return;
  }
  FILE *out = fopen(dst, "wb");
  if (!out) {
    printf("errore\n");
    fclose(in);
    return;
  }
  while ((n = fread(buf, 1, sizeof(buf), in)) > 0)
    fwrite(buf, 1, n, out);
  fclose(in);
  fclose(out);
}

static void scrivi_int_bin() {
  char nome[MAXL];
  int n, i, a[MAXN];
  printf("nome file: ");
  scanf("%255s", nome);
  printf("quanti interi (<=%d): ", MAXN);
  scanf("%d", &n);
  flushln();
  if (n < 0 || n > MAXN) {
    printf("range\n");
    return;
  }
  for (i = 0; i < n; i++) {
    printf("a[%d]: ", i);
    scanf("%d", &a[i]);
  }
  FILE *f = fopen(nome, "wb");
  if (!f) {
    printf("errore\n");
    return;
  }
  fwrite(a, sizeof(int), n, f);
  fclose(f);
}

static void leggi_int_bin() {
  char nome[MAXL];
  int a[MAXN], i, n;
  printf("nome file: ");
  scanf("%255s", nome);
  flushln();
  FILE *f = fopen(nome, "rb");
  if (!f) {
    printf("errore\n");
    return;
  }
  n = (int)fread(a, sizeof(int), MAXN, f);
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  fclose(f);
}

static void scrivi_struct_bin() {
  char nome[MAXL];
  int n, i;
  struct Studente v[MAXN];
  printf("nome file: ");
  scanf("%255s", nome);
  printf("quanti studenti (<=%d): ", MAXN);
  scanf("%d", &n);
  flushln();
  if (n < 0 || n > MAXN) {
    printf("range\n");
    return;
  }
  for (i = 0; i < n; i++) {
    printf("nome: ");
    fgets(v[i].nome, sizeof(v[i].nome), stdin);
    v[i].nome[strcspn(v[i].nome, "\n")] = 0;
    printf("media: ");
    scanf("%f", &v[i].media);
    flushln();
  }
  FILE *f = fopen(nome, "wb");
  if (!f) {
    printf("errore\n");
    return;
  }
  fwrite(v, sizeof(struct Studente), n, f);
  fclose(f);
}

static void leggi_struct_bin() {
  char nome[MAXL];
  struct Studente v[MAXN];
  int i, n;
  printf("nome file: ");
  scanf("%255s", nome);
  flushln();
  FILE *f = fopen(nome, "rb");
  if (!f) {
    printf("errore\n");
    return;
  }
  n = (int)fread(v, sizeof(struct Studente), MAXN, f);
  for (i = 0; i < n; i++)
    printf("%s %.2f\n", v[i].nome, v[i].media);
  fclose(f);
}

static void random_access_int() {
  char nome[MAXL];
  int i, val, op;
  printf("file binario di int: ");
  scanf("%255s", nome);
  printf("indice da leggere/scrivere: ");
  scanf("%d", &i);
  printf("0=leggi, 1=scrivi(+sovrascrive): ");
  scanf("%d", &op);
  flushln();
  FILE *f = fopen(nome, op ? "rb+" : "rb");
  if (!f) {
    printf("errore\n");
    return;
  }
  if (fseek(f, (long)i * sizeof(int), SEEK_SET) != 0) {
    printf("seek\n");
    fclose(f);
    return;
  }
  if (op == 0) {
    if (fread(&val, sizeof(int), 1, f) != 1) {
      printf("EOF\n");
    } else
      printf("val=%d\n", val);
  } else {
    printf("nuovo valore: ");
    scanf("%d", &val);
    if (fwrite(&val, sizeof(int), 1, f) != 1)
      printf("errore\n");
    else
      printf("ok\n");
  }
  fclose(f);
}

static void info_size() {
  char nome[MAXL];
  long sz, pos;
  printf("nome file: ");
  scanf("%255s", nome);
  flushln();
  FILE *f = fopen(nome, "rb");
  if (!f) {
    printf("errore\n");
    return;
  }
  fseek(f, 0, SEEK_END);
  sz = ftell(f);
  fseek(f, 0, SEEK_SET);
  pos = ftell(f);
  printf("size=%ld bytes, pos=%ld\n", sz, pos);
  fclose(f);
}

static void numerazione_righe() {
  char iname[MAXL], oname[MAXL], riga[MAXL];
  int n = 1;
  printf("input: ");
  scanf("%255s", iname);
  printf("output: ");
  scanf("%255s", oname);
  flushln();
  FILE *in = fopen(iname, "r");
  if (!in) {
    printf("errore\n");
    return;
  }
  FILE *out = fopen(oname, "w");
  if (!out) {
    printf("errore\n");
    fclose(in);
    return;
  }
  while (fgets(riga, sizeof(riga), in))
    fprintf(out, "%03d: %s", n++, riga);
  fclose(in);
  fclose(out);
}

static void converti_cifre() {
  char iname[MAXL], oname[MAXL];
  int c;
  const char *w[] = {"zero",   "uno", "due",   "tre",  "quattro",
                     "cinque", "sei", "sette", "otto", "nove"};
  printf("input: ");
  scanf("%255s", iname);
  printf("output: ");
  scanf("%255s", oname);
  flushln();
  FILE *in = fopen(iname, "r");
  if (!in) {
    printf("errore\n");
    return;
  }
  FILE *out = fopen(oname, "w");
  if (!out) {
    printf("errore\n");
    fclose(in);
    return;
  }
  while ((c = fgetc(in)) != EOF) {
    if (c >= '0' && c <= '9')
      fputs(w[c - '0'], out);
    else
      fputc(c, out);
  }
  fclose(in);
  fclose(out);
}

int main() {
  for (;;) {
    int s;
    printf("\n1 scrivi testo\n2 leggi testo\n3 append testo\n4 copia file\n5 "
           "scrivi int bin\n6 leggi int bin\n7 scrivi struct bin\n8 leggi "
           "struct bin\n9 random access int\n10 info size file\n11 numerazione "
           "righe\n12 converti cifre in parole\n0 esci\nscelta: ");
    if (scanf("%d", &s) != 1) {
      flushln();
      continue;
    }
    flushln();
    if (s == 0)
      break;
    if (s == 1)
      scrivi_testo();
    else if (s == 2)
      leggi_testo();
    else if (s == 3)
      append_testo();
    else if (s == 4)
      copia_file();
    else if (s == 5)
      scrivi_int_bin();
    else if (s == 6)
      leggi_int_bin();
    else if (s == 7)
      scrivi_struct_bin();
    else if (s == 8)
      leggi_struct_bin();
    else if (s == 9)
      random_access_int();
    else if (s == 10)
      info_size();
    else if (s == 11)
      numerazione_righe();
    else if (s == 12)
      converti_cifre();
    else
      printf("scelta non valida\n");
  }
  return 0;
}
