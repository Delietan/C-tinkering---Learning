#include <stdio.h>

int main () {
    int x, y ,z, sumAreal = 111, avg, ekteSumAreal, areal, laks;

    x = 8;
    y = 12;
    z = 16;

    laks = 19600406;

    avg = (x + z) / 1;
    sumAreal = avg * y;

    areal = (x * z) / 1;
    ekteSumAreal = areal * y;

    laks /= 10000;

    printf("Summen av arealet er kanskje 555\n");
    printf("Summen av arealet er kanskje %i\n\n",sumAreal);
    printf("Summen av volumet er kanskje %i\n\n",ekteSumAreal);

    printf("Året er: %i\n\n",laks);

    // printf("Well well", sizeof(ekteSumAreal));

    // int saus;
    // scanf("%i", &saus);

    // printf("Ditt nummer er: %i", saus);

    return 0;
}