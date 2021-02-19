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
    printf("------------------------------------------------------------------\n");
    printf("||\tLOWER SECTION\t|\tHOW TO SCORE\t|\tSCORE\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tthree of a kind\t|\tsum of all dice\t|\t");
    TRIPS ? printf("%d\t||\n",TRIPS_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tfour of a kind\t|\tsum of all dice\t|\t");
    QUADS ? printf("%d\t||\n",QUADS_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tfull house\t|\t%d\t|\t",FULLHOUSE);
    FULLH ? printf("%d\t||\n",FULLH_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tsmall staight\t|\t%d\t|\t",SMSTRAIGHT);
    SMSTR ? printf("%d\t||\n",SMSTR_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tlarge straight\t|\t%d\t|\t",LGSTRAIGHT);
    LGSTR ? printf("%d\t||\n",LGSTR) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tyahtzee\t\t|\t%d\t|\t",YAHTZEE);
    YAHT ? printf("%d\t||\n",YAHT_SCORE) :printf("X\t||\n");
    printf("------------------------------------------------------------------\n");
    printf("||\tYahtzee bonus\t|\t%d\t|\t",YAHTZEEBONUS);
    YTZBONUS ? printf("%d\t||\n",YTZBONUS_SCORE) :printf("X\t||\n");
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
        printf("Aces score: %d\n",count);
        break;
    case 2:
        TWOS = 1;
        TWOS_SCORE = count * selection;
        printf("twos score: %d\n",TWOS_SCORE);
        break;
    case 3:
        THREES = 1;
        THREES_SCORE = count * selection;
        printf("threes score: %d\n",THREES_SCORE);
        break;
    case 4:
        FOURS = 1;
        FOURS_SCORE = count * selection;
        printf("fours score: %d\n",FOURS_SCORE);
        break;
    case 5:
        FIVES = 1;
        FIVES_SCORE = count * selection;
        printf("fives score: %d\n",FIVES_SCORE);
    break;
    case 6:
        SIXES = 1;
        SIXES_SCORE = count * selection;
        printf("sixes score: %d\n",SIXES_SCORE);
    break;
    }
}
void total_top(struct scorecard *card)
{
    if (ACES && TWOS && THREES && FOURS && FIVES && SIXES)
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
void score_dice(struct scorecard *card)
{
    display_scorecard(card);
    scanf("what would you like to score?\n");

}

