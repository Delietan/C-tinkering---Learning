/**
 *   Løsning til eksamen i GrProg (i C), august 2024, oppgave 1B.
 *
 *   @file     EX_S24_1B.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>


char txt[][3] = { "us", "er" };


struct Maleri  {
  char tittel[40];
  int  bredde, hoyde;
};


void S24Funk1(const struct Maleri m)  {
  printf("%s: %ix%i    ", m.tittel, m.bredde, m.hoyde);
}


bool S24Funk2(const struct Maleri m, const int len)  {
  return (m.bredde >= len  ||  m.hoyde >= len);
}


bool S24Funk3(const struct Maleri* m)  {
  return (strstr(m->tittel, txt[1])  ||  strstr(m->tittel, txt[0]));
}


struct Maleri S24Funk4(const struct Maleri* m1, const struct Maleri* m2)  {
  struct Maleri m;
  strncpy (m.tittel, m1->tittel, 5);     strcat (m.tittel, m2->tittel+4);
  m.bredde = m2->bredde - m1->bredde;    m.hoyde = m2->hoyde - m1->hoyde;
  return m;
}


char S24Funk5(const struct Maleri m1, const struct Maleri* m2)  {
 int n1 = strlen(m1.tittel), n2 = strlen(m2->tittel);
 char *t1 = m1.tittel+n1-2,  *t2 = m2->tittel+n2-2;

 if (n1 != n2)  {
    if (!strcmp(t1, txt[0])  &&  strcmp(t2, txt[0]))  {
       if (m2->bredde > m1.bredde)
          return 'S';
       else return 'M';
    } else return 'A';
 } else return 'I';
}


int main()  {
  struct Maleri m1 = { "Bacchus",       85,  98 },
                m2 = { "Narcissus",     95, 113 },
                m3 = { "Annunciation", 205, 285 },
                m4 = { "Musicians",    119,  92 },
                m5 = { "Lute Player",  205,  98 };

  S24Funk1(m1);   S24Funk1(m2);   S24Funk1(m4);   printf("\n");

  printf("%i %i %i\n", S24Funk2(m3, 260), S24Funk2(m5, 260), S24Funk2(m1, 99));

  printf("%i %i %i\n", S24Funk3(&m3), S24Funk3(&m2), S24Funk3(&m4));

  S24Funk1(S24Funk4(&m4, &m5));   printf("\n");

  printf("%c\n", S24Funk5(m2, &m1));

  return 0;
}



//  Utskrift:  Bacchus: 85x98    Narcissus: 95x113    Musicians: 119x92
//             1 0 0
//             0 1 1
//             Music Player 86x6
//             A
