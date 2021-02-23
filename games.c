#include <stdio.h>
#include "sevens.h"
#include "threes.h"
#include "yatzie.h"
int main() 
{
    int choice=0;
    while(choice <4)
    {
        printf("Welcome to the dice games!\n");
        printf("What would you like to play?\n 1. Threes\n 2. Sevens\n 3.Yatzie\nenter number choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            threes();
            choice =5;
        }
        else if(choice==2)
        {
            sevens();
            choice =5;
        }
        else if (choice ==3)
        {
            yatzie();
            choice =5;
        }
        else
        {
            printf("please enter a valid choice\n");
        }
    }
    return 0;
}