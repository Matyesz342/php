#include <stdio.h>
#include <string.h>

int main() {
    char input[100];  // az adatsor tárolására szolgáló karaktertömb
    char before_star[50];  // a * karakter előtti rész tárolására szolgáló karaktertömb
    char after_star[50];  // a * karakter utáni rész tárolására szolgáló karaktertömb
    int star_index;  // a * karakter indexe

    printf("Kérem, adja meg az adatsort: ");
    fgets(input, 100, stdin);  // beolvassuk az adatsort a standard bemenetről

    star_index = strchr(input, '*') - input;  // meghatározzuk a * karakter indexét

    strncpy(before_star, input, star_index);  // lemásoljuk a * karakter előtti részt
    before_star[star_index] = '\0';  // lezárjuk a stringet

    strcpy(after_star, input + star_index + 1);  // lemásoljuk a * karakter utáni részt

    printf("A * előtti rész: %s\n", before_star);
    printf("A * utáni rész: %s\n", after_star);

    return 0;
}
