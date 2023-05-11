#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 1000

char alakit(char element,int j)
{
    char tmp;
    int ascii;
    int numbers[] = {5,-14,31,-9,3};
    tmp = element;
    ascii = tmp;
    char new;
    int counter = j % 5;
    ascii = (int)element;
    switch (counter)
    {
    case 1:
        ascii = ascii - numbers[counter];
        tmp = (char)ascii;
        new=tmp;
        break;
    case 2:
        ascii = ascii - numbers[counter];
        tmp = (char)ascii;
        new=tmp;
        break;
    case 3:
        ascii = ascii - numbers[counter];
        tmp =(char)ascii;
        new=tmp;
        break;
    case 4:
        ascii = ascii - numbers[counter];
        tmp = (char)ascii;
        new=tmp;
        break;
    case 0:
        ascii = ascii - numbers[counter];
        tmp = (char)ascii;
        new=tmp;
        break;
    }
    return new;
}

int main(void)
{
    char data[MAX_LINES] [MAX_LEN];

    FILE *file;

    file = fopen("password.txt", "r");

    if (file == NULL)
    {
        printf("Error opening password file\n");
        return 1;
    }
    int line = 0;

    while (!feof(file) && !ferror(file))
    {
        if (fgets(data[line], MAX_LEN, file) != NULL)
        {
            line++;
        }
        
    }
    /*while(fgets(data[line], MAX_LEN, file)) 
	{
        data[line][strlen(data[line]) - 1] = '\0';
        line++;
    }*/
    fclose(file);
    /*for (int i = 0; i < line; i++)
    {
        printf("%s\n",data[i]);
    }*/
    printf("%c\n",data[0][0]);
    int j = 0;
    char newdata[MAX_LINES] [MAX_LEN];
    /*newdata[0][0] = alakit(data[0][0], 1);
    printf("%c\n",newdata[0][0]);*/
    for (int i = 0; i < line; i++)
    {
        /*for (int j = 0; j < MAX_LEN; j++)
        {
            newdata[i][j] = alakit(data[i][j], j);
            printf("%c ", newdata[i][j]);
        }*/
        while (data[i][j] != ' ')
        {
            newdata[i][j] = alakit(data[i][j], j);
            printf("%c ", newdata[i][j]);
            j++;
        }
        
        printf("\n");
    }
    
    

    return 0;
}