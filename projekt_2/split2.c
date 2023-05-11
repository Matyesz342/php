#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fajl_beolvas_sor.h"

#define MAX_LINE_LENGTH 100

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    char *delimiter = "*";
    char *string1;
    char *string2;
    char *username = malloc(MAX_LINE_LENGTH);
    char *password = malloc(MAX_LINE_LENGTH);

    for (int i = 0; i < 3; i++)
    {

        printf("Adja meg a felhasznalo nevet: ");
        scanf("%s", username);
        printf("Adja meg a jelszavat: ");
        scanf("%s", password);
        

        // megnyitjuk a fájlt olvasásra
        file = fopen("password.txt", "r");
        if (file == NULL) {
            printf("Hiba: nem sikerült megnyitni a fájlt.\n");
            exit(1);
        }

        // beolvassuk a sorokat és feldolgozzuk őket
        while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
            // eltávolítjuk az utolsó karaktert (a sortörést)
            line[strcspn(line, "\n")] = '\0';

            // először lemásoljuk a teljes sort egy ideiglenes változóba
            char *temp;//[MAX_LINE_LENGTH];
            //strncpy(temp, line, MAX_LINE_LENGTH);
            temp = line;
            char *temp2;
            temp2 = alakit(temp, strcspn(temp, "\n"));
            //printf("%s\n",temp2);
            // kiválasztjuk a * karakter utáni részt
            token = strtok(temp2, delimiter);
            if (token == NULL) {
                printf("Hiba: a * karakter hiányzik a sorban.\n");
                continue;
            }
            string2 = strdup(token);

            // kiválasztjuk a * karakter előtti részt
            token = strtok(NULL, delimiter);
            if (token == NULL) {
                printf("Hiba: a * karakter hiányzik a sorban.\n");
                free(string2);
                continue;
            }
            string1 = strdup(token);

            /*printf("string1: %s\n", string1);
            printf("password: %s\n", password);
            printf("string2: %s\n", string2);
            printf("username: %s\n", username);*/
            if (strcmp(string1,password) == 0 && (strcmp(string2,username) == 0))
            {
                printf("Udvozoljuk!\n");
                free(string1);
                free(string2);
                free(username);
                free(password);
                goto vege;
            }

            // felszabadítjuk az ideiglenes stringeket
            free(string1);
            free(string2);
        }

        // bezárjuk a fájlt
        fclose(file);
        free(username);
        free(password);
        printf("Hibas felhasznalo nev vagy jelszo!\n");
    }
    vege:
    return 0;
}
