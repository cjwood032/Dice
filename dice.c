#include "dice.h"
#include <string.h>
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
            {
                sum+=arr[i];
            }
    }
    return sum;
}
void display_dice(int num, int arr[])
{
    int i=0;
    while (arr[i]!=0&&i<num)
    {
        if (i==0)
            printf("Die #%d: %d", i+1,arr[i]);
        else
            printf("\tDie #%d: %d", i+1,arr[i]);
        i++;
    }
    
}
int select_dice(int num, int *inb, int *outb)
{
    int keep = 0;
    char buffer[100];
    while (!keep)
    {
        if (num<5)
        {
            printf("\nyour dice\t");
            display_dice(5-num,outb);
        }
        printf("\nRolled dice\t");
        display_dice(num,inb);
        if (num>1)
        {
            while (keep==0)
            {
                do
                {
                    puts("\nHow many would you like to keep?");
                    fgets(buffer,101,stdin);
                }
                while (!atoi(buffer));
                keep = atoi(buffer);
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
                    outb[5-num+i]=inb[i];
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
                    if (found==1)
                    {
                        found = 0;
                    }


                do
                {
                    printf("select %d of %d, enter a number >5 if you want to change the number of dice you want to keep\n",i+1,keep);
                    fgets(buffer,101,stdin);
                }
                while (!atoi(buffer));
                pull = atoi(buffer);
                    if (pull>5)
                        {
                            keep=0;
                            break;
                        }
                    for (int j=0; j<keep;j++)
                    {
                        if(pulled[j]==pull&&pull!=0)
                        {
                            found =1;
                            printf("you can't select the same die more than once!\n");
                            break;

                        }
                    }
                    if (pull-1>=num||pull<=0)
                    {
                        found =1;
                        printf("please select an available die!\n");
                    }
                    if (!found)
                        {
                            valid =1;
                        }
                }
                outb[5-num+i]=inb[pull-1];
                pulled[i]=pull;

            }
        }
        else
        {//if it's the last die there is no choice.
            keep=1;
            outb[4]=inb[0];
        }
    }
    return keep;

}
int compute_dice(int num, int *inb, int *outb)
{
    int keep = 0;
    int lowest = 6;
    int threes = 0;
    _Bool found_threes = 0;
    if (num<5)
    {
        printf("\ntheir dice\t");
        display_dice(5-num,outb);
    }
    printf("\nRolled dice\t");
    display_dice(num,inb);
    if (num>1)
    {
        // iterate through get lowest 
        for (int i = 0;i<num;i++)
        {
            if(inb[i]==3)
            {
                outb[5-num+threes]=3;
                threes++;
                found_threes=1;
            }
            else if (inb[i]<lowest) 
            {
                lowest = inb[i];
            }
        }
        if(found_threes)
        {
            keep = threes;
        }
        else
        {
            outb[5-num]=lowest;
            keep=1;
        }
    }
    else
    {
        keep=1;
        outb[4]=inb[0];
    }
    return keep;

}

int swap_dice(int *inb, int inL, int *outb,int outL,int swapped)
{
    int move = 0;
    _Bool valid =0;
    char direction;
    
    char buffer[100];
    printf("rolled\t");
    display_dice(inL,inb);
    if(outL)
    {
        printf("\nheld\t");
        display_dice(outL,outb);
    }
    
    
    while(!valid)
    {
        int i = 1;
        printf("\nwhat would you like to swap\nMove from (R)olled or (H)eld or would you like to (S)top?\n");
        fgets(buffer,101,stdin);              
        direction=buffer[0];
        while(direction!='R'&&direction!='H'&&direction!='S'&&direction==' ')//clear buffer in case of 
        {
            direction=buffer[i++];
        }
        
        if (direction=='R'||direction=='H'||direction=='S')
        {
            valid=1;
        }           
    }
    if(direction=='R')
    {
        do
        {
            puts("Which die?");
            fgets(buffer,101,stdin);
        }
        while(!atoi(buffer));
        move=atoi(buffer)-1;
        if(move<inL)
        {
            outb[outL]=inb[move];
            printf("%i pulled %d\n",move,outb[outL]);
            for (int count = move;count<inL-1;count++) //move the dice
            {
                inb[count] = inb[count+1];
            }
            inL--;
            outL++;
            swapped++;
        }

    }
    else if(direction=='H')
    {
        direction=' ';
        do
        {
            puts("Which die?");
            fgets(buffer,101,stdin);
        }
        while(!atoi(buffer));
        move=atoi(buffer)-1;
        if(move<outL)
        {
            inb[inL]=outb[move];
            for (int count = move;count<outL-1;count++) //move the dice
            {
                outb[count] = outb[count+1];
            }
            inL++;
            outL--;
            swapped--;
        }
    }
    else if(direction=='S')
    {
        return swapped;
    }
    return swap_dice(inb,inL,outb,outL,swapped);
}