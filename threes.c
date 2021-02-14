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
#include "player.h"
int main() 
{
    
    int number=0;
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
        player_turn(p);
        if (pl.score < low_score)
        {
            low_score=pl.score;
            printf("New low score of %i\n", low_score);
        }
    }
    

    return 0;
}
