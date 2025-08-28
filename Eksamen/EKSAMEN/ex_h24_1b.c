/**
 *   Løsning til eksamen i GrProg (i C), desember 2024, oppgave 1B.
 *
 *   @file     EX_H24_1B.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>


char txt[][9] = { "Brokke", "Valle", "Dalen", "Morgedal" };
int  moh[]    = { 558, 312, 75, 433 };

struct Sted  {
  char nvn[20];
  int  moh;
};

struct Sted steder[4];

void H24Funk1()  {
  for (int i = 0;  i < 4;  i++) {
      strcpy(steder[i].nvn, txt[i]);
      steder[i].moh = moh[i];
  }
}

void H24Funk2(const struct Sted s)  {
  printf("%s-%i  ", s.nvn, s.moh);
}

void H24Funk3(struct Sted* s1, struct Sted* s2)  {
  struct Sted s = *s1;  *s1 = *s2;  *s2 = s;
}

void H24Funk4(const char* t)  {
  for (int i = 0;  i < 4;  i++)
      if (strstr(steder[i].nvn, t)) printf("T "); else printf("A ");
}

bool H24Funk5(const int n, const int nn)  {
  return (steder[n].moh > nn);
}

char H24Funk6(const char* c)  {
 return ((char)(*c+2));
}


int main()  {

  H24Funk1();  H24Funk2(steder[3]);  H24Funk2(steder[0]);  printf("\n");

  H24Funk3(&steder[2], &steder[1]);  H24Funk3(&steder[1], &steder[0]);
               H24Funk2(steder[1]);  H24Funk2(steder[2]);  printf("\n");

  H24Funk1();  H24Funk4("al");  printf("\n");

  printf("%i %i %i\n", H24Funk5(3, 400), H24Funk5(1, 400), H24Funk5(0, 400));

  for (char* t = steder[3].nvn;  *t;  t++) printf("%c ", H24Funk6(t));
  printf("\n");

  return 0;
}



//  Utskrift:  Morgedal-433  Brokke-558
//             Brokke-558  Valle-312
//             A T T T
//             1 0 1
//             O q t i g f c n

