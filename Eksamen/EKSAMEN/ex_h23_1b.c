/**
 *   Løsning til eksamen i GrProg (i C), desember 2023, oppgave 1B.
 *
 *   @file     EX_H23_1B.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>


char tekst[][6] = { "Jada", "Neida" };


struct Person  {
  char fNavn[40], eNavn[40];
  int  alder;
};


void H23Funk1(const struct Person person)  {
  printf("%s, %s (%i)", person.eNavn, person.fNavn, person.alder);
}


bool H23Funk2(const struct Person person)  {
  return (person.alder < 20  ||  person.alder >= 51);
}


bool H23Funk3(const struct Person* person)  {
  return (strstr(person->eNavn, "e")  &&  strstr(person->fNavn, "a"));
}


struct Person H23Funk4(const struct Person* p1, const struct Person* p2)  {
  struct Person p;
  strcpy (p.fNavn, p1->fNavn);  strcpy (p.eNavn, p2->eNavn);
  p.alder = p1->alder + p2->alder;
  strcat(p.fNavn, "-");  strcat(p.fNavn, tekst[H23Funk2(p)]);
  return p;
}


char H23Funk5(const struct Person p1, const struct Person* p2)  {
  if (!strncmp(&(p1.fNavn[2]), &(p2->fNavn[1]), 3))  {
     if (p1.alder-31 >=  p2->alder)  {
        return ((strlen(p2->eNavn) < strlen(p1.eNavn)) ? 'S' : 'J');
     } else
        return 'T';
  } else  return 'F';
}


int main()  {
  struct Person person1 = { "Anne",  "Andersen", 19 },
                person2 = { "Frank", "Frantzen", 53 },
                person3 = { "Ida",   "Iversen",  20 },
                person4 = { "Marit", "Mentzoni", 22 },
                person5 = { "Sanne", "Syversen", 51 };

  H23Funk1(person2);   printf(" og ");   H23Funk1(person4);   printf("\n");

  printf("%i %i %i\n", H23Funk2(person1), H23Funk2(person3), H23Funk2(person5));

  printf("%i %i\n", H23Funk3(&person1), H23Funk3(&person2));

  H23Funk1(H23Funk4(&person3, &person4));   printf("\n");

  printf("%c\n", H23Funk5(person5, &person1));

  return 0;
}



//  Utskrift:  Frantzen, Frank (53) og Mentzoni, Marit (22)
//             1 0 1
//             0 1
//             Mentzoni, Ida-Jada (42)
//             J
