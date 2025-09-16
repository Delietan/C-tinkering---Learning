/**
 * @author Martinus Nordgård
 * @file tinkering.c
 * @date 10 sept 2025
 */

 #include <stdio.h>
 #include <ctype.h>

const int STRLEN = 80;

int main()
{
    int tall;
    char tegn;
    char tekst[STRLEN];
    char tekst2[STRLEN];

    char tekstTest[] = "Mannemann";

    tegn = 'w';
    // tekst = "Saft";

    printf("Et tegn: %c", tegn);
    printf("\nEt tegn bare stort: %c", toupper(tegn));

    printf("\nSkriv et ord eller tekst: ");
    scanf(" %s", tekst);

    printf("\nTekst: %s", tekst);

    printf("\nTekst fra start: %s", tekstTest);

    return 0;
};