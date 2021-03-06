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
#include "threes.h"
void threes() 
{
    
    int number=0;
    char buffer[100];
    int winners =0;
    int low_score=31;
    puts("New game of threes!"); 
    do
    {
        puts("How many players?");
        fgets(buffer,101,stdin);
    }
    while(!atoi(buffer));
    number=atoi(buffer);
    struct player players[number];
    struct player *p=NULL;
    for (int i =0;i<number;i++)
    {
        struct player pl = players[i];
        p=&pl;
        make_player(p,1);
        players[i]=*p;
    }
    for (int i =0;i<number;i++)
    {
        struct player pl = players[i];
        p=&pl;
        if (pl.human)
        {
            player_turn(p);
        }
        else
        {
            computer_turn(p);   
        }
        if (pl.score < low_score)
        {
            low_score=pl.score;
            printf("New low score of %i\n", low_score);
            sleep(1);
        }
        players[i]=pl;
    }
    for (int i =0; i<number; i++)
    {
        struct player pl = players[i];
        if(pl.score==low_score)
        {
            winners++;
            if (winners==1)
            {
                printf("%s",pl.name);
            }
            else 
            {
                printf(" and %s", pl.name);
            }

        }
    }
    if (winners ==1)
        {
            printf(" is the winner!\n");
        }
        else
        {
            printf(" drew the game!\n");
        }
}
