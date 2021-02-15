#include "player.h"
#include "dice.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
void make_player(struct player *player)
{
    char input;
    while(input!='C'&&input!='H')
    {
        puts ("Is this player human or a computer?\n H for human, C for computer");
        scanf("%c",&input);
        fflush(stdin);
    }
    if (toupper(input)=='H')
    {
        input='X';
        char name[20];
        player->human=1;
        puts("Enter player's name:");
        scanf("%s", name);
        fflush(stdin);
        strcpy(player->name,name);
    }
    else 
    {
        player->human=0;
    }    
}
void player_turn (struct player *player)
{
    int dice[5]={0,0,0,0,0};
    int kept[5]={0,0,0,0,0};
    int *pdice = NULL;
    int *pkeep = NULL;
    int score;
    pdice = dice;
    pkeep=kept;
    int count = 5;
    while (count>0)
    {
        if(toupper(player->name[strlen(player->name)-1])=='S')
        {
            printf("\n%s' turn!\n",player->name);
        }
        else
        {
            printf("\n%s's turn!\n",player->name);
        }
        roll(count, pdice);
        count-=select(count, pdice, pkeep);
    }
    score = final_score(kept);
    player->score= score;
    for (int i = 0; i< 5; i++)
    {
        player->dice[i]=kept[i];
    }
    if(toupper(player->name[strlen(player->name)-1])=='S')
    {
        printf("\n%s' final score was: %d\n",player->name, score);    
    }
    else
    {
        printf("\n%s's final score was: %d\n",player->name, score);
    }
}