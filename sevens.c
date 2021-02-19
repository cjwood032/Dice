/*
threes is a game where you roll 5 dice any number of times trying to get the lowest score possible.
you must keep at least one die each roll, and threes are worth 0pts, everything else has face value
Psuedocode
1. roll 5 dice, display to user
2. user chooses which to keep >=1, those are added to a different array
3. roll remaining dice
4. continue until all dice are kept.
5. compare the score to the existing score, keeping the lower
*/

#include <stdio.h>
#include "dice.h"
#include <stdlib.h>
#include <unistd.h>
#include "player.h"
#include <time.h>
int main() 
{
    int number=0;  
    int count=0;
    int score=0;
    int remaining=0;
    puts("New game of sevens!\nHow many players?");
    scanf("%i", &number);
    remaining=number;
    fflush(stdin);
    struct player players[number];
    struct player *p=NULL;
    int dice[2]={0};
    int *pdice = dice;
    for (int i =0;i<number;i++)
    {
        struct player pl = players[i];
        p=&pl;
        make_player(p);
        p->score=0;
        players[i]=*p;
    }
    while (remaining >1)
    {
        struct player pl = players[count];
        p=&pl;
        if (pl.score!=7)
        {
            sleep(1);
            roll(2,pdice);
            printf("%s last roll totaled: %d\n",pl.name,pl.score);
            pl.score=score = dice[0]+dice[1];
            printf("%s roll: %d+%d=%d\n",pl.name,dice[0],dice[1],score);
            if (score==7)
            {
                printf("%s is out!\n",pl.name);
                if(--remaining==1)
                {
                    printf("Leaving %d player\n",remaining);
                }
                else
                {
                    printf("Leaving %d players\n",remaining);
                }
            }
        }
        players[count]=pl;
        if (count==number-1)
        {
            count=0;
        }
        else
        {
            count++;
        }
    }
    printf("Good game!\n");
   return 0;
}
