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
    for (;i<=5;i++)
    {
        arr[i]=0;
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
    if (num>1)
    {
        while (keep==0)
        {
            puts("\nHow many would you like to keep?\n");
            scanf("%d",&keep);
            if (keep>num||keep==0)
            {
                puts("you must take at least one and cannot take more dice than are available.\n");
                keep=0;
            }
        }
        if (keep==num)
        {
            for(int i =0; i<keep; i++)
            {
                outb[5-num+i]=inb[i-1];
            }
            return keep;
        }
        int pulled[5]={0,0,0,0,0};
        for (int i =0; i<keep; i++)
        {
            int pull=0;
            _Bool valid =0;
            _Bool found = 0;
            while (!valid)
            {
                printf("select %d of %d, or -1 if you want to change the number of dice you want to keep\n",i+1,keep);
                scanf("%d",&pull);
                if (pull==-1)
                    select(num, *&inb, *&outb);
                for (int j=0; j<keep;j++)
                {
                    printf("array: %d\n",pulled[j]);
                    if(pulled[j]==pull)
                    {
                        found =1;
                        printf("you can't select the same die more than once!\n");
                        break;
                        
                    }
                }
                if (!found)
                    valid =1;
            }
            outb[5-num+i]=inb[pull-1];
            pulled[i]=pull;
            
        }
    }
    else
    {
        keep=1;
        outb[4]=inb[0];
    }
    return keep;

}