/**
 * @author Martinus Nordgård
 * @date 10 sept 2025
 * @file oppg12.c
 */

 #include <stdio.h>             // printf()

const int SAFT = 10;            ///< Maksimum liter med xxccvvbbxxccvvbbxxccvvbbxxccvvbb
 /**
  * Hovedprogrammet starter her
  */

int main()
{

    int saft;
    char tegn;
    char ord[SAFT];
    char tekst[SAFT];

    printf("\a");
    printf("Skriv inn et heltall: ");
    scanf("%i", &saft);
    printf("Du skrev %i", saft);

    printf("\nSkriv inn et tegn: ");
    scanf(" %c", &tegn);
    printf("Du skrev %c", tegn);

    printf("\nSkriv inn et tegn2: ");
    scanf(" %c", &tegn);
    printf("Du skrev %c", tegn);

    printf("\nSkriv inn litt tekst: \n");
    scanf("%s", ord);
    printf("Order du skrev er: -%s-", ord);

    printf("Skriv inn litt tekst. Denne bruker fgets: ");
    fgets(tekst, SAFT, stdin);
    printf("Innlest verdi: -%s-", tekst);
    
    return 0;
}