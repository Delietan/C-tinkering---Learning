/**
 * Oblig nr. 1 - Oppgave om innlesning og utskrift,
 *               med diverse utfordringer knyttet til
 *               minne og buffer management.
 * 
 * @file oblig1.c
 * @author Martinus Nordgård, Student NTNU
 * @date 11. sept 2025
 * 
 */


#include <stdio.h>              // printf(), scanf() og fgets()


const int STRLEN = 80;          ///< Maks tekstlengde i array

/**
 * Hovedprogrammet starter her:
 * 
 */

int main()
{
    char bok1[STRLEN], bok2[STRLEN];
    char sjanger[2];
    int sideAntall[2], antallLest = 0;


//  Leser inn detaljer som bok 1:
//  Fgets brukes i stedet for gets og scanf.
//  Scanf kan kun lese inn et ord, da den avbryter innlesning ved første blanke.
//  Gets kan være utrygg, da den kan lese inn tekst som er større enn det er plass
//  til i arrayen, og dermed sprenger bufferen.

    printf("Bok 1:\n");
    printf("\tNavn: ");
    fgets(bok1, STRLEN, stdin);                 //  Maks 80 tegn, minus 1 fordi den
    printf("\tAntall sider: ");                 //  siste er reservert til "\0"
    scanf("%i", &sideAntall[0]);
    printf("\tSjanger (B - Biografi, F - Fiksjon, T - Thriller): ");
    scanf(" %c", &sjanger[0], antallLest++);    //  "Blank" forran %c så den ikke leser inn
                                                //  "\n" som ligger igjen i bufferen.
                                                //  Bruker "antallLest++" for å loggføre
                                                //  antall innlesninger.




//  Tømmer input-bufferen
    getchar();      
    
    
//  Leser inn detaljer som bok 2:
    printf("Bok 2:\n");
    printf("\tNavn: ");
    fgets(bok2, STRLEN, stdin);
    printf("\tAntall sider: ");
    scanf("%i", &sideAntall[1]);
    printf("\tSjanger (B - Biografi, F - Fiksjon, T - Thriller): ");
    scanf(" %c", &sjanger[1], antallLest++); 

//  Tømmer input-bufferen - Ikke nødvendig, men greit med alt som er gjort :)
    getchar(); 


    printf("\nDin bok: %s", bok1);
    printf("Sjanger: %c\n\n", sjanger[0]);
    
    printf("Din bok: %s", bok2);
    printf("Sjanger: %c\n\n", sjanger[1]);
    
    printf("Antall bøker lest: %i\n", antallLest);
    printf("Sider lest totalt: %i\n\n", sideAntall[0] + sideAntall[1]);

    return 0;
};