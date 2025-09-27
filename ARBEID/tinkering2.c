#include <stdio.h> 


int main(){

    int i;
    char tekst[80];
    char liksomtekst[40] = "pa";
    printf("Laks\n");


    // for loop
    // for (i = 0; i < 10; i++) {
    //     printf("Sitron\n");
    //     printf("%i stykkvis. I ganget med i %i \n", i, i*i);
    //     }

    // printf("Alfabetet: ");
    // for (i = 0; i < 26; i++){
    //     tekst[i] = i+65;
    //     printf("%c", tekst[i]);
    // }
    // tekst[i] = '\0';

    // printf("\nAlfabetet igjen: %s", tekst);
    
    char tegn;
    int antallTegn = 0;

    printf("Skriv tegn, avslutt med '!':  ");
    scanf(" %c", &tegn);

    while (tegn != '!'){
        antallTegn++;
        scanf(" %c", &tegn);
    }
    printf("\nAntall tegn er: %i", antallTegn);
}