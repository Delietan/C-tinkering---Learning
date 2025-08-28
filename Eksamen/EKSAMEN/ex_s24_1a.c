/**
 *   Løsning til eksamen i GrProg (i C), august 2024, oppgave 1A.
 *
 *   @file     EX_S24_1A.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <string.h>
//                      1         2         3         4         5
//            012345678901234567890123456789012345678901234567890123456
char txt[] = "Agios Georgios Agios Nikolaos Agios Gordios Agios Nikitas";


int main() {
  char* t;
  int i = 38, j = i % 24;

  while (txt[i] != '\0')  {
    if (txt[i] == 'i') printf("%c ", txt[i-1]);
    ++i;
  }
  printf("\n");

  while (txt[j++] != 'k')
    printf("%c ", txt[j]);
  printf("\n");

  t = &txt[i-j-10];
  while (*t != 'A')
    printf("%c ", *t--);
  printf("\n");

  t = txt;
  while (*t != '\0')  {
    if (!strncmp(t, "os ", 3)) printf("%c ", *(t+3));
    t++;
  }
  printf("\n");

  t = txt;
  while (t = strstr(t, "Agios"))
    printf("%c ", *((t++)+8));
  printf("\n");

  return 0;
}



//   Utskrift:    d g N k
//                Agios Nik
//                kiN soig
//                G A N A G A N
//                o k r k
