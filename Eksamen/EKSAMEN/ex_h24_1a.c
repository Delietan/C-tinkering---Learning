/**
 *   Løsning til eksamen i GrProg (i C), desember 2024, oppgave 1A.
 *
 *   @file     EX_H24_1A.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <string.h>


char txt[]    = "Brokke-Valle-Dalen-Morgedal-Seljord-Notodden-Kongsberg";
char txt2[30] = "Norge";


int main() {
  char *t = txt, *t2;
  int   n = 1;

  printf("%i\n", !strncmp(txt+20, txt2+1, 4));

  while (*t != '\0')
    if (*t++ == 'e') {  printf("%i ", n);  n *= 2;  }
  printf("\n");

  t = txt;
  while (*t != '\0')  {
    if (*t == 'o') printf("%c ", *(t+1));  ++t;
  }
  printf("\n");

  t = txt+3;
  while ((t = strstr(t, "al")) != NULL)  {
    printf("%c ", *(t+3));  t += 2;
  }
  printf("\n");

  n = 0;   t = txt+19;   t2 = txt+31;
  while (*t != *t2)  {
    txt2[n++] = *t++;  txt2[n++] = *t2--;
  }
  txt2[n] = '\0';
  printf("%s\n", txt2);

  return 0;
}



//   Utskrift:    1
//                1 2 4 8 16 32 64
//                k r r t d n
//                e n S
//                MjolregSe-dl
