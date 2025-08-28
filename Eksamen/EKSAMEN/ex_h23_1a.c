/**
 *   Løsning til eksamen i GrProg (i C), desember 2023, oppgave 1A.
 *
 *   @file     EX_H23_1A.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <string.h>
//                      1         2         3         4         5
//            01234567890123456789012345678901234567890123456789012345
char txt[] = "LEICESTER-LEEDS-BIRMINGHAM-IPSWICH-NOTTINGHAM-ASTONVILLA";


int main() {
    int i = 35,  j = i/6,  k = i%8;

    while (txt[i] != '\0')  {
        if (txt[i] == 'T') printf("%c ", txt[i-2]);
        ++i;
    }
    printf("\n");

    for (i = 10;  txt[i] != 'P';  i+= k)
        printf("%c ", txt[i]);
    printf("\n");

    i = 19;
    do {
       printf("%c ", txt[++i]);
    }  while (txt[i-k] != txt[i+k]);
    printf("\n");

    char* t = &txt[0], *s = t+35;
    while (*t++ != *s--)
        printf("%c ", txt[j++]);
    printf("\n");


    t = strstr(txt, "HAM");
    while (t)  {
        printf("%c%c%c%c ", *(t-4),*(t-3),*(t-2),*(t-1));
        t++;  t = strstr(t, "HAM");
    }
    printf("\n");

    return 0;
}



//   Utskrift:    N O A
//                L D B M G M
//                I N G
//                S T E
//                MING TING
