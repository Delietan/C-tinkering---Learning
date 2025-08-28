
#include <stdio.h>

int main() {
    printf("Test 123 \n");

    int postnummer,
        mobilnummer,
        alder;
    
    //Yes
    postnummer = 7072,
    mobilnummer = 48600709,
    alder = 31;

    //Skriver ut personalia
    printf("Navn:        Martinus Nordgård\n");
    printf("Adresse:     Jarveien 32A\n");
    printf("Sted:        %i, Heimdal\n", postnummer);
    printf("Mobilnr:     %i\n", mobilnummer);
    printf("Alder:       %i\n\n", alder);

    return 0;
};