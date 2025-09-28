/**
 * Min løsning på oppgave 20
 * @author Martinus Nordgård
 * @file oppg20.c
 * @date 28. sept
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdbool.h>

 const int MAXTLFLEN = 80;

 /**
  * Hovedprogrammet starter her:
  */

  int main () 
  {
    char tlfnrArray[MAXTLFLEN];
    bool feil = false;

    printf("Skriv tlfnr (8): ");
    gets(tlfnrArray);
    printf("\tTelefonnummer er registrert som:\n\t%s", tlfnrArray);

    printf("\n\t");

    for (int i = 0; i < strlen(tlfnrArray); i++){
        switch(tlfnrArray[i]){
            case '1':  printf("en")    ; break;
            case '2':  printf("to")    ; break;
            case '3':  printf("tre")   ; break;
            case '4':  printf("fire")  ; break;
            case '5':  printf("fem")   ; break;
            case '6':  printf("seks")  ; break;
            case '7':  printf("syv")   ; break;
            case '8':  printf("åtte")  ; break;
            case '9':  printf("ni")    ; break;
            case '0':  printf("null")  ; break;
            case ' ':                  ; break;
            default:   printf("Ulovlig verdi"); feil = true; break;

        }
        if (feil) break;

        if (i+1 != strlen(tlfnrArray)) {
            printf("-");
        } else {
            printf(" ");
        }
    }
  };