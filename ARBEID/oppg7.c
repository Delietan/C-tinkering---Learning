#include <stdio.h>

int main () 
{
    int tall1 = 5, 
        tall2 = 7,
        tall3 = 2,
        sum = tall1 + tall2 + tall3,
        kvadratSum = tall1 * tall1 + tall2 * tall2 + tall3 * tall3;
    
    float flyt1 = 5.3,
        flyt2 = 8.6,
        gjsnittSum = sum / 3.0,
        gjsnittKvadrat = kvadratSum / 3.0;

    printf("\nSummen av %i, %i og %i er %i\n\n", tall1, tall2, tall3, sum);

    printf("Gjennomsnittet av %i, %i og %i er %f\n\n", tall1, tall2, tall3, gjsnittSum);

    printf("Kvadratsummen av %i er %i\n\n", sum, kvadratSum);

    printf("Gjennomsnittlig kvadratsum av %i er %f\n\n", kvadratSum, gjsnittKvadrat);

    printf("Gjennomsnittet av %f og %f er %f \n\n", flyt1, flyt2, (flyt1+ flyt2) / 2 );


}