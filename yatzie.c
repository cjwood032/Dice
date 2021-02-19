#include <stdio.h>
#include "dice.h"
#include <stdlib.h>
#include <unistd.h>
#include "player.h"

int main(){
    
    int number=0;
    int winners =0;
    int low_score=31;
    puts("New game of threes!\nHow many players?");
    scanf("%i", &number);
    fflush(stdin);
    struct player players[number];
    struct player *p=NULL;
    for (int i =0;i<number;i++)
    {
        struct player pl = players[i];
        p=&pl;
        make_player(p);
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
    return 0;
}
