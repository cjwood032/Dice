#ifndef PLR_H_INCLUDED
#define PLR_H_INCLUDED
struct player 
{
    char name[20];
    int dice[5];
    int score;
    _Bool human;
};
void make_player(struct player *player);
void player_turn(struct player *player);
void computer_turn (struct player *player);
#endif// PLR_H_INCLUDED