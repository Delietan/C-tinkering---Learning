/**
 * @author Martinus Nordgård
 * @date 27. sept
 * @file oppg13.c
 */

#include <stdio.h>

const int HOYDEN = 4; ///<
const float PI = 3.14159;  ///<
/**
 * Hovedprogrammet starter her:
 */


int main () {
    int radius;

    printf("Skriv er tall mellom 5 og 20: ");
    scanf("%i", &radius);

    printf("Brukeren skrev %i", radius);

    for (int i = 1; i <= radius; i++) {
        printf("\nVolum for radius %2i: %11f", i, i * i * HOYDEN * PI);
    };

    return 0;
}