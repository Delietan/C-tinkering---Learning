/**
 *   Løsning til eksamen i GrProg (i C), august 2025, oppgave 1B.
 *
 *   @file     EX_S25_1B.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>


char navn[][10] = { "Oxford", "Watford", "Luton", "Fulham", "Tottenham" };
int  dato[]     = { 18, 18, 21, 19, 19 };

struct Lag  {
  char nvn[20];
  int  dato;
};

struct Lag lag[5];

void S25Funk1()  {
  for (int i = 4;  i >= 0;  i--) {
      strcpy(lag[4-i].nvn, navn[i]);
      lag[4-i].dato = dato[i];
  }
}

void S25Funk2(const struct Lag s)  {
  printf("%s-%i  ", s.nvn, s.dato);
}

bool S25Funk3(const int i)  {
  return (strstr(lag[i].nvn, "ford") != NULL);
}

void S25Funk4(const struct Lag* lag1, const struct Lag* lag2)  {
  if (lag1->dato == lag2->dato  &&  !strncmp(lag1->nvn+3, lag2->nvn+6, 3))
     printf("Jada\n");  else  printf("Neida\n");
}

void S25Funk5()  {
  struct Lag l;
  for (int i = -1;  i <= 1;  i++)  {
      l = lag[0];
      for (int j = 0;  j < 4;  j++)
          lag[j] = lag[j+1];
      lag[4] = l;
  }
}

int S25Funk6(const char c1, const char c2)  {
  int n = 0;
  for (int i = 0;  i <= 4;  i++)  {
      if (strchr(lag[i].nvn, c1) != NULL) n++;
      if (strchr(lag[i].nvn, c2) != NULL) n++;
  }
  return n;
}


int main()  {

  S25Funk1();  S25Funk2(lag[4]);  S25Funk2(lag[2]);  printf("\n");

  printf("%i %i %i\n", S25Funk3(2), S25Funk3(4), S25Funk3(3));

  S25Funk4(&lag[1], &lag[0]);

  S25Funk5();   S25Funk2(lag[0]);  S25Funk2(lag[2]);  printf("\n");

  printf("%i %i\n", S25Funk6('a', 'o'),  S25Funk6('r', 'm'));

  return 0;
}



//  Utskrift:  Oxford-18  Luton-21
//             0 1 1
//             Jada
//             Watford-18  Tottenham-19
//             7 4
