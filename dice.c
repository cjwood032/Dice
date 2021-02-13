#include "dice.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
void roll(int num, int **arr[])
{
    srand(time(NULL));
    for (int i=0; i<=num;i++)
    {
        **arr[i]=rand()%6 + 1;
    }
}
int final_score(int arr[])
{
    int sum=0;
    for(int i=0; i<5; i++)
    {
        if(arr[i]!=3)
            sum+=arr[i];
    }
    return sum;
}
void display_board(int arr[])
{
    int i=0;
    while (arr[i]!=0)
    {
        if (i==1)
            printf("%d", arr[i]);
        else
            printf("\t%d", arr[i]);
    }
}