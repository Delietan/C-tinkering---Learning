/**
 * Min løsning på oppgave 22
 * @author Martinus Nordgård
 * @date 1. okt 2025
 * @file oppg22.c
 */

 #include <stdio.h>

 // Deklarasjon av funksjon
 void lagFirkant(int bredde, int hoyde);

 /**
  * Hovedprogrammet starter her
  *
  */

 int main()
 {
     int bredde = 0;
    int hoyde = 0;

    printf("\tHvilken bredde vil de ha?\n\tJeg vil så meget ha bredde: ");
    scanf ("%i", &bredde);

    printf("\tHvilken høyde vil de ha?\n\tJeg vil så meget ha høyde: ");
    scanf ("%i", &hoyde);

    printf("\tLets go:\n\n");
    lagFirkant(bredde,hoyde);
 }


 /**
  * Skriver en ramme av stjerner "*" med en gitt høyde og bredde
  * 
  * @param bredde - Firkantens bredde
  * @param høyde  - Firkantens høyde
  * 
  */
 void lagFirkant(int bredde, int hoyde){
    // øverst
    for (int i=0 ; i<bredde; i++){printf("*");}
    printf("\n");

    //alt i mellom
    for (int i=0 ; i<hoyde-2; i++){ 
        printf("*");
            for (int i=0 ; i<bredde-2; i++){printf(" ");} 
        printf("*\n");}

    //nederst
    for (int i=0 ; i<bredde; i++){printf("*");}
    printf("\n");
 };