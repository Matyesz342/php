#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog1.h"

#define LSIZ 128 
#define RSIZ 6 

char * alakit(string element, int length)
{
    static char new[100];
    char tmp;
    int ascii;
    int numbers[] = {5,-14,31,-9,3};
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        tmp = element[i];
        ascii = tmp;
        switch (counter)
        {
        case 0:
            ascii = ascii - numbers[counter];
            counter++;
            tmp = ascii;
            new[i]=tmp;
            break;
        case 1:
            ascii = ascii - numbers[counter];
            counter++;
            tmp = ascii;
            new[i]=tmp;
            break;
        case 2:
            ascii = ascii - numbers[counter];
            counter++;
            tmp = ascii;
            new[i]=tmp;
            break;
        case 3:
            ascii = ascii - numbers[counter];
            counter++;
            tmp = ascii;
            new[i]=tmp;
            break;
        case 4:
            ascii = ascii - numbers[counter];
            counter = 0;
            tmp = ascii;
            new[i]=tmp;
            break;
        }
    }
    

    return new;
}

/*int main(void) 
{
    string username;
    char ps[1000];
    char line[RSIZ][LSIZ];
	char fname[20];
    FILE *fptr = NULL; 
    int i = 0;
    int tot = 0;
    printf("\n\n Read the file and store the lines into an array :\n");
	printf("------------------------------------------------------\n"); 
	printf(" Input the filename to be opened : ");
	scanf("%s",fname);	

    fptr = fopen(fname, "r");
    while(fgets(line[i], LSIZ, fptr)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    fclose(fptr);
    size_t size = sizeof(line) / sizeof(line[0]);
    string element;
    char *newelement;
    char usernm[1000];
    string password, psw;
    int c = 0;
	for (int i = 0; i < 3; i++)
    {
        printf("Adja meg a felhasznalo nevet: ");
        scanf("%s", username);
    
        for (int j = 0; j < size; j++)
        {
            element = line[j];
            size_t size0 = sizeof(element) / sizeof(element[0]);
            newelement = alakit(element,strlen(element));
            for (int i = 0; i < strlen(newelement); i++)
            {
                if (strcmp(*(newelement+i), "*") == 0 && i == strlen(username))
                {
                    while (c < i)
                    {
                        //usernm = *(newelement;
                        c++;
                    }
                }
                
                printf("%c ",*(newelement+i));
            }
            printf("\n");
            
            /*if (strcmp(username, line[j]) == 0)
            {
                printf("\nUdvozoljuk!\n");
                return 0;
            }
        }
        printf("\nHibas felhasznalonev!\n");
        
    }
    return 0;
}*/