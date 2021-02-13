#include "dice.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
 void roll(int num, int *arr)
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
            printf("Die #%d: %d", i+1,arr[i]);
        else
            printf("\tDie #%d: %d", i+1,arr[i]);
        i++;
    }
    
}
 int select(int num, int *inb, int *outb)
{
    int keep = 0;
    if (num<5)
    {
        printf("\nyour dice\t");
        display_dice(outb);
    }
    printf("\nRolled dice\t");
    display_dice(inb);
    while (keep==0)
    {
        puts("\nHow many would you like to keep?\n");
        scanf("%d",&keep);
        if (keep>num)
        {
            puts("you cannot take more dice than are available.\n");
            keep=0;
        }
    }
    int pulled[keep];
    for (int i =1; i<=keep; i++)
    {
        int pull;
        printf("select %d of %d, or -1 if you want to change the number of dice you want to keep\n",i,keep);
        scanf("%d",&pull);
        if (pull==-1)
            select(num, *&inb, *&outb);
        else 
        {
            outb[5-num]=inb[pull-1];

        }
    }
    return keep;

}