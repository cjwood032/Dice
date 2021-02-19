#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
struct scorecard 
{
    struct player;
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
    int top_total;
    _Bool ThreeOaK;
    int threeOaK_total;
    _Bool FourOaK;
    int fourOaK_total;
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




}
#endif