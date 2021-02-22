
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
#define ROLLED card->playerinfo->rolled
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
            {\
                found=1;\
            }\
        }
#define CHECK4 _Bool found = 0; \
        for(int x =0; x<2; x++)\
        {\
            if(DICE[x]==DICE[x+1]&&DICE[x]==DICE[x+2]&&DICE[x]==DICE[x+3])  {\
                found=1;\
            }\
        }
#define CHECKH _Bool found = 0; \
        if(((DICE[0]==DICE[1]&&DICE[1]==DICE[2])&&(DICE[3]==DICE[4]))||((DICE[2]==DICE[3]&&DICE[4]==DICE[2])&&(DICE[0]==DICE[1])))\
        {\
            found=1;\
        }   
#define CHECKY _Bool found =0; \
        if(DICE[0]==DICE[1]&&DICE[2]==DICE[3]&&DICE[3]==DICE[4]&&DICE[4]==DICE[0])\
        {\
        found =1;\
        }
#define CHECKSM _Bool found =0;\
    if (DICE[0]+1==DICE[1]&&DICE[1]+1==DICE[2]&&DICE[2]+1==DICE[3]||DICE[1]+1==DICE[2]&&DICE[2]+1==DICE[3]&&DICE[3]+1==DICE[4])\
    {\
    found=1;\
    }
#define CHECKLG _Bool found =0;\
    if (DICE[0]+1==DICE[1]&&DICE[1]+1==DICE[2]&&DICE[2]+1==DICE[3]&&DICE[3]+1==DICE[4])\
    {\
    found=1;\
    }


int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

    

void init_card(struct scorecard *card)
{
    struct player *p;
    p = card->playerinfo;
    make_player(p);
    card->playerinfo = p;
    char *name = p->name;
    card->playerinfo =malloc(sizeof(struct player));
    strcpy(card -> playerinfo->name,name);
    ROLLED[0]=0;
    ROLLED[1] =0;
    ROLLED[2] =0;
    ROLLED[3]=0;
    ROLLED[4]=0;
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
    free(card->playerinfo);
    
}
void display_scorecard(struct scorecard *card)
{
    printf("\n------------------------------------------------------------------\n");
    printf("||\t\t\t\t%s\t\t\t\t||\n",card->playerinfo->name);
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
    LGSTR ? printf("%d\t||\n",LGSTR_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tyahtzee\t\t|\t%d points\t|\t",YAHTZEE);
    YAHT ? printf("%d\t||\n",YAHT_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tchance\t\t|\tsum of all dice\t|\t");
    CHANCE ? printf("%d\t||\n",CHANCE_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tYahtzee bonuses\t|\textra yahtzees\t|\t");
    YAHT ? printf("%d\t||\n",XTRAYTZ) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tYahtzee bonus\t|\t%d points\t|\t",YAHTZEEBONUS);
    BOT_COMPLETED ? printf("%d\t||\n",YTZBONUS_SCORE) :printf("X\t||\n");
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
        YTZBONUS=0;
        ACES_SCORE = count;
        break;
    case 2:
        TWOS = 1;
        YTZBONUS=0;
        TWOS_SCORE = count * selection;
        break;
    case 3:
        THREES = 1;
        YTZBONUS=0;
        THREES_SCORE = count * selection;
        break;
    case 4:
        FOURS = 1;
        YTZBONUS=0;
        FOURS_SCORE = count * selection;
        break;
    case 5:
        FIVES = 1;
        YTZBONUS=0;
        FIVES_SCORE = count * selection;
    break;
    case 6:
        SIXES = 1;
        YTZBONUS=0;
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
        if (BOT_COMPLETED)
        {
            GRAND_TOTAL=TOP_TOTAL+BOT_TOTAL;
        }
    }
}
void score_bot(char str[],struct scorecard *card)
{
    if(strcmp(str, "three")==0)
    {
        qsort(DICE, 5, sizeof(int), cmpfunc);
        CHECK3
        TRIPS=1;
        YTZBONUS=0;
        if(found)
        {
            TRIPS_SCORE=ADD_DICE;
        }
        else
        {
            TRIPS_SCORE=0;
        }
    }
    else if(strcmp(str, "four")==0)
    {
        qsort(DICE, 5, sizeof(int), cmpfunc);
        CHECK4
        QUADS=1;
        YTZBONUS=0;
        if(found)
        {
            QUADS_SCORE=ADD_DICE;
        }
        else
        {
            QUADS_SCORE=0;
        }
    }
    else if(strcmp(str, "house")==0)
    {
        qsort(DICE, 5, sizeof(int), cmpfunc);
        CHECKH
        FULLH=1;
        YTZBONUS=0;
        if(found)
        {
            FULLH_SCORE=FULLHOUSE;
        }
        else
        {
            FULLH_SCORE=0;
        }
    }
    else if (strcmp(str, "small")==0)
    {
        SMSTR=1;
        YTZBONUS=0;
        qsort(DICE, 5, sizeof(int), cmpfunc);
        CHECKSM
        if(found)
        {
            SMSTR_SCORE=SMSTRAIGHT;
        }
        else
        {
            SMSTR_SCORE=0;
        }
    }
    else if (strcmp(str, "large")==0)
    {
        LGSTR=1;
        YTZBONUS=0;
        qsort(DICE, 5, sizeof(int), cmpfunc);
        CHECKLG
        if(found)
        {
            LGSTR_SCORE=LGSTRAIGHT;
        }
        else
        {
            LGSTR_SCORE=0;
        }
    }
    else if (strcmp(str,"yahtzee")==0)
    {
        
        CHECKY
        if (found&&!YAHT)
        {
            YAHT=1;
            YAHT_SCORE=YAHTZEE;
        }
        else if (found && YAHT)
        {
            XTRAYTZ++;
            YTZBONUS=1;
            printf("You got a bonus, now score the dice!\n");
            sleep(2);
            score_dice(card);
        }
        else
        {
            YAHT=1;
            YAHT_SCORE=0;
            YTZBONUS=1;
            YTZBONUS_SCORE=0;
        }
    }
    else if(strcmp(str, "chance")==0)
    {
        CHANCE=1;
        CHANCE_SCORE=ADD_DICE;
    }
    if(BOT_COMPLETED)
    {
        total_bot(card);
    }
    display_scorecard(card);
}
void total_bot(struct scorecard *card)
{
    if(BOT_COMPLETED)
    {
        YTZBONUS_SCORE=YAHTZEEBONUS*XTRAYTZ;
        BOT_TOTAL= THREES_SCORE+FOURS_SCORE+FULLH_SCORE+SMSTR_SCORE+LGSTR_SCORE+YAHT_SCORE+CHANCE_SCORE+YTZBONUS_SCORE;
        if (TOP_COMPLETED)
        {
            GRAND_TOTAL=TOP_TOTAL+BOT_TOTAL;
        }
    }
}
void score_dice(struct scorecard *card)
{
    display_scorecard(card);
    char input[10];
    printf("what would you like to score?\n");
    printf("Enter the number if you want to score aces(1)-sixes(6) for the top section\n");
    printf("or three, four, house, small, large, yahtzee, or chance for the bottom\n");
    scanf("%s",input);
    if(strlen(input)==1)
    {
        int choice = atoi(input);
        if((choice ==1&&!ACES)||(choice ==2&&!TWOS)||(choice ==3&&!THREES)||(choice ==4&&!FOURS)||(choice ==5&&!FIVES)||(choice ==6&&!SIXES))
        {
            score_top(choice,card);
        }
        else
        {
            printf("\nPlease select a valid choice.\n");
            sleep(2);
            score_dice(card);
        }
    }
    else //bottom
    {
        if( (strcmp(input,"three")==0&&!THREES)||(strcmp(input,"four")==0&&!FOURS)||(strcmp(input,"house")==0&&!FULLH)||(strcmp(input,"small")==0&&!SMSTR)||(strcmp(input,"large")==0&&!LGSTR)||((strcmp(input,"yahtzee")==0&&!YAHT)||(strcmp(input,"yahtzee")==0&&YAHT_SCORE&&!YTZBONUS))||(strcmp(input,"chance")==0&&!CHANCE) )
        {
            score_bot(input,card);
        }
        else
        {
            printf("\nPlease select a valid choice.\n");
            sleep(2);
            score_dice(card);
        }
    }

}

