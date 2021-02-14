#ifndef PLR_H_INCLUDED
#define PLR_H_INCLUDED
struct player 
{
    char name[20];
    int dice[5];
    int score;
    _Bool human;

};
void makeplayer(struct player *player);
void playerturn(struct player *player);

#endif// PLR_H_INCLUDED