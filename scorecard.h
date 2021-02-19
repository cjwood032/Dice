#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
struct scorecard 
{
    struct player *playerinfo;
    _Bool Aces;
    int aces_score;
    _Bool Twos;
    int twos_score;
    _Bool Threes;
    int threes_score;
    _Bool Fours;
    int fours_score;
    _Bool Fives;
    int fives_score;
    _Bool Sixes;
    int sixes_score;
    int top_subtotal;
    _Bool TopBonus;
    int top_bonus;
    int top_total;
    _Bool Trips;
    int trips_total;
    _Bool Quads;
    int quads_total;
    _Bool FullHouse;
    int full_house_score;
    _Bool SmStraight;
    int sm_straight_score;
    _Bool LgStraight;
    int lg_straight_score;
    _Bool Yahtzee;
    int yahtzee_score;
    _Bool Chance;
    int chance_score;
    _Bool YahtzeeBonus;
    int yahtzee_bonuses;
    int yahtzee_bonus_score;
    int lower_total;
    int grand_total;
};

void init_card(struct scorecard *card);
void display_scorecard(struct scorecard *card);
void score_top(int selection, struct scorecard *card);
void total_top(struct scorecard *card);
void score_dice(struct scorecard *card);
#endif