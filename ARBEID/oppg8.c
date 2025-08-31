/**
 *  @AUTHOR : MARTINUS NORDGÅRD
 *  @TITTEL : OPPGAVE 8
 * 
 * 
 */

#include <stdio.h> // for prinf()

/**
 * Hovedprogrammet
 */

int main () 
{
    const int ANTALL = 17;

    int tall1 = 5,
        tall2 = 8,
        tall3 = 13,
        svar;

        svar = tall1 * tall2 / tall3;
        printf("1 - Summen er %i\n\n", svar);

        svar = (tall1 + ANTALL) * tall2 / tall1;
        printf("2 - Summen er %i\n\n", svar);

        svar = tall1 + ANTALL + tall3 - tall2;
        printf("3 - Summen er %i\n\n", svar);

        svar = ((ANTALL + ANTALL + tall3) / tall1) + tall1 * tall1;
        printf("4 - Summen er %i\n\n", svar);

        svar = ((ANTALL * ANTALL * tall3) / tall1) + tall1 * tall1;
        printf("5 - Summen er %i\n\n", svar);



        svar += tall1;
        printf("6 - Summen er %i\n\n", svar);

        svar -= tall1;
        printf("7 - Summen er %i\n\n", svar);

        svar *= tall1;
        printf("8 - Summen er %i\n\n", svar);

        svar /= tall1;
        printf("9 - Summen er %i\n\n", svar);

        svar += tall1 + tall2;
        printf("10 - Summen er %i\n\n", svar);

        svar++;
        svar++;
        svar++;
        printf("11 - Tall1 er nå %i\n\n", tall1);
        tall1++;
        tall1++;
        tall1++;
        printf("12 - Tall1 er nå %i\n\n", tall1);
        printf("13 - Tall2 er nå %i\n\n", tall2);
        tall2--;
        tall2--;
        tall2--;
        tall2--;
        printf("14 - Tall2 er nå %i\n\n", tall2);
        printf("15 - Summen er %i\n\n", svar);
        printf("16 - Summen av tall1 ganger tall2 minus ANTALL er %i\n\n", (tall1 * tall2) - ANTALL);

}