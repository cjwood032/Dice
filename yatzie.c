#include <stdio.h>
#include "dice.h"
#include <stdlib.h>
#include <unistd.h>
#include "player.h"
#include "scorecard.h"
int main(){
    
    int number=0;
    int winners =0;
    int low_score=31;
    puts("New game of not Yahtzee!\nHow many players?");
    scanf("%i", &number);
    fflush(stdin);
    struct scorecard cards[number];
    struct scorecard *pcard = NULL;
    struct player *player = NULL;
    for (int i =0;i<number;i++)
    {
        struct scorecard sc = cards[i];
        pcard=&sc;
        
        init_card(pcard);
        cards[i]=*pcard;
    }
    for (int i =0;i<number;i++)
    {
        struct scorecard sc = cards[i];
        pcard=&sc;
        player= sc.playerinfo;
        if (sc.playerinfo->human)
        {
            
            player_turn(player);
        }
        else
        {
            computer_turn(player);   
        }
        if (pcard->playerinfo->score < low_score)
        {
            low_score=pcard->playerinfo->score;
            printf("New low score of %i\n", low_score);
            sleep(1);
        }
        cards[i]=sc;
    }
    for (int i =0; i<number; i++)
    {
        struct scorecard sc = cards[i];
        if(sc.playerinfo->score==low_score)
        {
            winners++;
            if (winners==1)
            {
                printf("%s",sc.playerinfo->name);
            }
            else 
            {
                printf(" and %s", sc.playerinfo->name);
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
