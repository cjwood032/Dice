#include <stdio.h>
#include "dice.h"
#include <stdlib.h>
#include <unistd.h>
#include "player.h"
#include "scorecard.h"
#define DICE card->playerinfo->dice
#define ROLLED card->playerinfo->rolled
#define TOP_COMPLETED (card.Aces&&card.Twos&&card.Threes&&card.Fours&&card.Fives&&card.Sixes) 
#define BOT_COMPLETED (card.Trips&&card.Quads&&card.FullHouse&&card.SmStraight&&card.LgStraight&&card.Yahtzee&&card.Chance)
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
        
        if (roll_count==3)
        {
            for (;holding<5;holding++)
            { 
                DICE[holding]= ROLLED[--rolling];
            }
            printf("\n\nfinal roll\t");
            display_dice(holding,DICE);
        }
        while (swap!='Y'&&swap!='N'&&roll_count!=3)
        {
            printf("\nyou rolled %d dice\n",rolling);
        display_dice(rolling,ROLLED);
        if(holding)
        {
            printf("\nyour %d held dice\n",holding);
            display_dice(holding,DICE);
        }
            printf("\nWould you like to swap dice (Y/N) or take (A)ll the remaining?\n");
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
    int low_score = 31;
    int completed_cards = 0;
    int turn_counter=0;
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
    while (completed_cards<number)
    {
        struct scorecard card = cards[turn_counter];
        pcard = &card;
        player = card.playerinfo;
        if(!TOP_COMPLETED||!BOT_COMPLETED)
        {
            turn(pcard);
            if(TOP_COMPLETED&&BOT_COMPLETED)
            {
                completed_cards++;
            }
            cards[turn_counter] = card;
        }
        if (turn_counter==number-1)
        {
            turn_counter=0;
        }
        else
        {
            turn_counter++;
        }
    }

    return 0;
}
