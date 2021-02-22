#include <stdio.h>
#include "dice.h"
#include <stdlib.h>
#include <unistd.h>
#include "player.h"
#include "scorecard.h"
#define DICE card->playerinfo->dice
#define ROLLED card->playerinfo->rolled
void turn(struct scorecard *card)
{
   
    int rolling =5;
    int holding =0;
    int swapped;
    char swap = 'X';
    for(int roll_count = 1; roll_count<=3;roll_count++)
    {
        swapped=0;
        roll(rolling,ROLLED);
        printf("\nyou rolled %d dice\n",rolling);
        display_dice(rolling,ROLLED);
        if(holding)
        {
            printf("\nyour held %d dice\n",holding);
            display_dice(holding,DICE);
        }
        while (swap!='Y'&&swap!='N')
        {
            printf("\nWould you like to swap dice (Y/N) or take (A)ll the remaining?\n?");
            scanf("%c",&swap);
            if (swap=='Y')
            {
               swapped= swap_dice(ROLLED,rolling,DICE,holding,swapped);
               holding +=swapped;
               rolling-=swapped;
                if (holding==5)
                {
                    printf("if you're not rolling any more dice, we'll assume you're done\n");
                   roll_count=4;
                   break;
                }
            }
            else if(swap=='N'&&roll_count==3)//what happens if they say no without holding 5
            {
                if (holding<5)
                {
                    printf("You can't score less than 5 dice\nAutomatically taking remaining...\n");
                    for (;holding<5;holding++)
                    { 
                        DICE[holding]= ROLLED[--rolling];
                    }
                }
                roll_count=4;
                break;
            }
            else if (swap=='A')
            {
                for (;holding<5;holding++)
                { 
                    DICE[holding]= ROLLED[--rolling];
                }
                roll_count=4;
                break;
            }
        }
        swap='X';

    }
    score_dice(card);
}
int main()
{
    int number = 0;
    int winners = 0;
    int low_score = 31;
    int completed_cards = 0;
    puts("New game of not Yahtzee!\nHow many players?");
    scanf("%i", &number);
    fflush(stdin);
    struct scorecard cards[number];
    struct scorecard *pcard = NULL;
    struct player *player = NULL;
    for (int i = 0; i < number; i++)
    {
        struct scorecard sc = cards[i];
        pcard = &sc;
        init_card(pcard);
        cards[i] = *pcard;
    }
    for (int i = 0; i < number; i++)
    {
        struct scorecard sc = cards[i];
        pcard = &sc;
        player = sc.playerinfo;
        
        turn(pcard);
        // hard code attempt pass

        //roll(5,player->dice);
        /* Print dice
        printf("[ ");
        
        for (int j =0; j<5; j++)
        {
             if (j==0)
            printf("%d ",player->dice[j]);
        else
            printf(", %d",player->dice[j]);
        }
        printf("]\n");
        
       
        player->dice[0] = 1;
        player->dice[1] = 1;
        player->dice[2] = 1;
        player->dice[3] = 1;
        player->dice[4] = 1;

        score_dice(pcard);
        score_dice(pcard);
        score_dice(pcard);
        score_dice(pcard);
        /*
        player->dice[0] = 2;
        player->dice[1] = 2;
        player->dice[2] = 2;
        player->dice[3] = 5;
        player->dice[4] = 4;
        score_top(2, pcard);
        player->dice[0] = 3;
        player->dice[1] = 3;
        player->dice[2] = 3;
        player->dice[3] = 5;
        player->dice[4] = 4;
        score_top(3, pcard);
        player->dice[0] = 4;
        player->dice[1] = 4;
        player->dice[2] = 1;
        player->dice[3] = 5;
        player->dice[4] = 4;
        score_top(4, pcard);
        player->dice[0] = 5;
        player->dice[1] = 5;
        player->dice[2] = 1;
        player->dice[3] = 5;
        player->dice[4] = 4;
        score_top(5, pcard);
        player->dice[0] = 6;
        player->dice[1] = 6;
        player->dice[2] = 6;
        player->dice[3] = 6;
        player->dice[4] = 4;
        score_top(6, pcard);
        score_bot("three",pcard);
        score_bot("four",pcard);
       
        player->dice[0] = 6;
        player->dice[1] = 6;
        player->dice[2] = 6;
        player->dice[3] = 5;
        player->dice[4] = 4;
        score_bot("three",pcard);
        
        player->dice[0] = 5;
        player->dice[1] = 5;
        player->dice[2] = 5;
        player->dice[3] = 5;
        player->dice[4] = 5;
        
        score_bot("yahtzee",pcard);
        score_bot("house",pcard);
        score_bot("small",pcard);
        score_bot("large",pcard);
        score_bot("yahtzee",pcard);
        score_bot("chance",pcard);
        
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
        cards[i] = sc;
    }

    return 0;
}
