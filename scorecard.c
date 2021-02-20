#define TOPBONUS 35
#define FULLHOUSE 25
#define SMSTRAIGHT 30
#define LGSTRAIGHT 40
#define YAHTZEE 50
#define YAHTZEEBONUS 100
#include "scorecard.h"
#include "player.h"
#include "dice.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define DICE card->playerinfo->dice
#define ACES card->Aces
#define TWOS card->Twos
#define THREES card->Threes
#define FOURS card->Fours
#define FIVES card->Fives
#define SIXES card->Sixes
#define ACES_SCORE card->aces_score
#define TWOS_SCORE card->twos_score
#define THREES_SCORE card->threes_score
#define FOURS_SCORE card->fours_score
#define FIVES_SCORE card->fives_score
#define SIXES_SCORE card->sixes_score
#define TOP_SUB card->top_subtotal
#define TOP_BONUS card->TopBonus
#define TOP_BONUS_SCORE card->top_bonus
#define TOP_TOTAL card->top_total
#define TRIPS card->Trips
#define TRIPS_SCORE card->trips_total
#define QUADS card->Quads
#define QUADS_SCORE card->quads_total
#define FULLH card->FullHouse
#define FULLH_SCORE card->full_house_score
#define SMSTR card->SmStraight
#define SMSTR_SCORE card->sm_straight_score
#define LGSTR card->LgStraight
#define LGSTR_SCORE card->lg_straight_score
#define YAHT card->Yahtzee
#define YAHT_SCORE card->yahtzee_score
#define CHANCE card->Chance
#define CHANCE_SCORE card->chance_score
#define YTZBONUS card->YahtzeeBonus
#define XTRAYTZ card->yahtzee_bonuses
#define YTZBONUS_SCORE card->yahtzee_bonus_score
#define TOP_COMPLETED (ACES && TWOS && THREES && FOURS && FIVES && SIXES)
#define BOT_COMPLETED (TRIPS && QUADS && FULLH && SMSTR && LGSTR && YAHT && CHANCE) 
#define GRAND_TOTAL card->grand_total
#define BOT_TOTAL card->lower_total
#define ADD_DICE (DICE[0]+DICE[1]+DICE[2]+DICE[3]+DICE[4])
#define CHECK3 _Bool found = 0; \
        for(int x =0; x<3; x++)\
        {\
        if(DICE[x]==DICE[x+1]&&DICE[x]==DICE[x+2])\
            found=1;\
        }
#define CHECK4 _Bool found = 0; \
        for(int x =0; x<2; x++)\
        {\
        if(DICE[x]==DICE[x+1]&&DICE[x]==DICE[x+2]&&DICE[x]==DICE[x+3])\
            found=1;\
        }        
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

    

void init_card(struct scorecard *card)
{
    struct player *p = NULL;
    p = card->playerinfo;
    make_player(p);
    card->playerinfo = p;
    ACES =0;
    TWOS=0;
    THREES=0;
    FOURS=0;
    FIVES=0;
    SIXES=0;
    TOP_BONUS=0;
    TRIPS =0;
    QUADS =0;
    FULLH =0;
    SMSTR =0;
    LGSTR =0;
    YAHT=0;
    CHANCE=0;
    YTZBONUS=0;
    XTRAYTZ=0;
    YTZBONUS_SCORE=0;

}
void display_scorecard(struct scorecard *card)
{
    printf("------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tUPPER SECTION\t|\tHOW TO SCORE\t|\tSCORE\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tAces(1 pip)\t|\tsum of aces\t|\t");
    ACES ? printf("%d\t||\n",ACES_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tTwos(2 pip)\t|\tsum of twos\t|\t");
    TWOS ? printf("%d\t||\n",TWOS_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tThrees(3 pip)\t|\tsum of threes\t|\t");
    THREES ? printf("%d\t||\n",THREES_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tFours(4 pip)\t|\tsum of fours\t|\t");
    FOURS ? printf("%d\t||\n",FOURS_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tFives(5 pip)\t|\tsum of fives\t|\t");
    FIVES ? printf("%d\t||\n",FIVES_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tSixes(6 pip)\t|\tsum of sixes\t|\t");
    SIXES ? printf("%d\t||\n",SIXES_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tsubtotal\t|\tsum of top\t|\t");
    TOP_COMPLETED ? printf("%d\t||\n",TOP_SUB) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\ttop bonus\t|\tif sum >= 63 \t|\t");
    TOP_BONUS ? printf("%d\t||\n",TOP_BONUS_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\ttotal score\t|\tsub + bonus\t|\t");
    TOP_COMPLETED ? printf("%d\t||\n",TOP_TOTAL) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tLOWER SECTION\t|\tHOW TO SCORE\t|\tSCORE\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tthree of a kind\t|\tsum of all dice\t|\t");
    TRIPS ? printf("%d\t||\n",TRIPS_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tfour of a kind\t|\tsum of all dice\t|\t");
    QUADS ? printf("%d\t||\n",QUADS_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tfull house\t|\t%d points\t|\t",FULLHOUSE);
    FULLH ? printf("%d\t||\n",FULLH_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tsmall staight\t|\t%d points\t|\t",SMSTRAIGHT);
    SMSTR ? printf("%d\t||\n",SMSTR_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tlarge straight\t|\t%d points\t|\t",LGSTRAIGHT);
    LGSTR ? printf("%d\t||\n",LGSTR) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tyahtzee\t\t|\t%d points\t|\t",YAHTZEE);
    YAHT ? printf("%d\t||\n",YAHT_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tchance\t\t|\tsum of all dice\t|\t");
    CHANCE ? printf("%d\t||\n",CHANCE_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tYahtzee bonus\t|\t%d points\t|\t",YAHTZEEBONUS);
    YTZBONUS ? printf("%d\t||\n",YTZBONUS_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tBottom score\t|\tsum of bottom\t|\t");
    BOT_COMPLETED ? printf("%d\t||\n",BOT_TOTAL) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tTotal score\t|\tgrand total\t|\t");
    BOT_COMPLETED&&TOP_COMPLETED ? printf("%d\t||\n",GRAND_TOTAL) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------\n");
}
void score_top(int selection, struct scorecard *card)
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (DICE[i] == selection)
        {
            count++;
        }
    }
    switch (selection)
    {
    case 1:
        ACES = 1;
        ACES_SCORE = count;
        break;
    case 2:
        TWOS = 1;
        TWOS_SCORE = count * selection;
        break;
    case 3:
        THREES = 1;
        THREES_SCORE = count * selection;
        break;
    case 4:
        FOURS = 1;
        FOURS_SCORE = count * selection;
        break;
    case 5:
        FIVES = 1;
        FIVES_SCORE = count * selection;
    break;
    case 6:
        SIXES = 1;
        SIXES_SCORE = count * selection;
    break;
    }
    if TOP_COMPLETED
    {
        total_top(card);
    }
    display_scorecard(card);
}
void total_top(struct scorecard *card)
{
    if TOP_COMPLETED
    {
        TOP_BONUS = 1;
        TOP_SUB = ACES_SCORE + TWOS_SCORE + THREES_SCORE + FOURS_SCORE + FIVES_SCORE + SIXES_SCORE;
        if (TOP_SUB >= 63)
        {
            TOP_BONUS_SCORE = TOPBONUS;
        }
        else
        {
            TOP_BONUS_SCORE = 0;
        }
        TOP_TOTAL = TOP_SUB + TOP_BONUS_SCORE;
    }
}
void score_bot(char str[],struct scorecard *card)
{
    if(strcmp(str, "three")==0)
    {
        qsort(DICE, 5, sizeof(int), cmpfunc);
        CHECK3
        TRIPS=1;
        if(found)
        {
            TRIPS_SCORE=ADD_DICE;
        }
    }
    else if(strcmp(str, "four")==0)
    {
        qsort(DICE, 5, sizeof(int), cmpfunc);
        CHECK4
        QUADS=1;
        if(found)
        {
            QUADS_SCORE=ADD_DICE;
        }
    }
    else if(strcmp(str, "chance")==0)
    {
        CHANCE=1;
        CHANCE_SCORE=ADD_DICE;
    }
    display_scorecard(card);
}
void score_dice(struct scorecard *card)
{
    display_scorecard(card);
    scanf("what would you like to score?\n");

}

