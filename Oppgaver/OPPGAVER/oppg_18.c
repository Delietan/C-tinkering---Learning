/**
 *   L�sningsforslag til oppgave nr 18.
 *
 *   @file	  OPPG_18.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf

/**
 *  Hovedprogrammet:
 */
int main()  {

    for (int i = 1;  i <= 100;  i++)  {  //  G�r gjennom alle aktuelle tall:
        printf("%3i - ", i);     //  Tallet skrives h�yrejustert p� 3 plasser.
        if (i % 2 )              //  Rest = 1, alts� oddetall.
           printf("Oddetall");
        else                     //  Ingen rest (0 - null), alts� partall.
           printf("Partall ");
        printf("  ");            //  2x blanke bort til neste kolonne.
        if (i % 5 == 0)          //  For hver femte, skrives linjeskift.
           printf("\n");
    }

    return 0;
}
