#include "dice.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
extern void roll(int num, int *arr)
{
    srand(time(NULL));
    int i =0;
    for (; i<=num-1;i++)
    {
        arr[i]=rand()%6 + 1;
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
void display_dice(int arr[])
{
    int i=0;
    while (arr[i]!=0&&i<5)
    {
        if (i==0)
            printf("%d", arr[i]);
        else
            printf("\t%d", arr[i]);
        i++;
    }
}