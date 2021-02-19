#include <stdio.h>
#include "dice.h"
#include <stdlib.h>
#include <unistd.h>
#include "player.h"
#include "scorecard.h"
int main()
{    
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
        // hard code attempt pass
        player->dice[0]=1;
        player->dice[1]=1;
        player->dice[2]=3;
        player->dice[3]=5;
        player->dice[4]=4;
        
        
        //roll(5,player->dice);
        printf("[ ");
        
        for (int j =0; j<5; j++)
        {
             if (i==0)
            printf("%d ",player->dice[j]);
        else
            printf(", %d",player->dice[j]);
        }
        printf("]\n");
        //score_top(1,pcard);
        printf("ACES %d\n",sc.Aces);
        score_top(2,pcard);
        score_top(3,pcard);
        //score_top(4,pcard);
        score_top(5,pcard);
        score_top(6,pcard);
        display_scorecard(pcard);
        
        

       /*
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
        */
        cards[i]=sc;
    }
    
    
    return 0;
}
