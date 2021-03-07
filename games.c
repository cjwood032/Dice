#include <stdio.h>
#include "sevens.h"
#include "threes.h"
#include "yatzie.h"
#include <stdlib.h>
int main() 
{
    char choice[100];
    do
    {
        if(!choice)
        {
            printf("Welcome to the dice games!\n");
        }
        printf("What would you like to play?\n 1. Threes\n 2. Sevens\n 3. Yatzie\n 4. exit program\nenter number choice:");

        fgets(choice,101,stdin);
        if(atoi(choice)==1)
        {
            threes();
        }
        else if(atoi(choice)==2)
        {
            sevens();
        }
        else if (atoi(choice) ==3)
        {
            yatzie();
        }
        else
        {
            break;
        }
        
    }
    while(choice);
    return 0;
}