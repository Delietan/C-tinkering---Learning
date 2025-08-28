/**
 *   Løsning til eksamen i GrProg (i C), august 2025, oppgave 1A.
 *
 *   @file     EX_S25_1A.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <string.h>   //  strchr(s, c) - returnerer peker til første forekomst
                      //                 av 'c' i stringen 's', evt. NULL.

char txt[]    = "Cancelada-AgiaMarina-Trogir-Lokken-Bornholm-Kragero-Risor";


int main() {
  char *t = txt, *t2, *t3, *t4;

  while (*t)  {
    if (*t == 'i') printf("%c ", *(t+1));
    t++;
  }
  printf("\n");

  t = txt;   t = strchr(t, 'o');
  while (t != NULL) {
    printf("%c ", *(t-1));
    t = strchr(++t, 'o');
  }
  printf("\n");

  t = txt;
  for (int i = 0;  i < 5;  i++, t++) t = strchr(t, '-');
  while (*t != '-') printf("%c", *t++);
  printf("\n");

  t = txt+6;  t2 = txt+52;
  while (t < t2)  {
    printf("%c %c ", *t, *t2);
    t += 4;  t2 -= 8;
  }
  printf("\n");

  t = txt+22;  t2 = txt+37;  t3 = &txt[49];  t4 = &txt[strlen(txt)-1];
  printf("%c %c %c %c ", *t, *t2, *t3, *t4);
  while (*t == *t2  &&  *t3 == *t4)  {
    t++;  t2--;  t3++;  t4--;
  }
  printf("%c %c %c %c\n", *t, *t2, *t3, *t4);

  return 0;
}



//   Utskrift:    a n r s
//                r L B h r s
//                Kragero
//                a R A K M o n L
//                r r r r g B - s
