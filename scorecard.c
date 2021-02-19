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

void init_card(struct scorecard *card)
{
    struct player *p = NULL;
    p = card->playerinfo;
    make_player(p);
    card->playerinfo = p;
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