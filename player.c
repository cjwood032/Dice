#include "player.h"
#include "dice.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
void makeplayer(struct player *player)
{
    char input;
    while(input!='C'&&input!='H')
    {
        puts ("Is this player human or a computer?\n H for human, C for computer");
        scanf("%c",&input);
    }
    if (toupper(input)=='H')
    {
        char name[20];
        player->human=1;
        puts("Enter player's name:");
        scanf("%s",name);
        strcpy(player->name,name);
    }
    else 
    {
        player->human=0;
    }    
}
void playerturn (struct player *player)
{
    int dice[5]={0,0,0,0,0};
    int kept[5]={0,0,0,0,0};
    int *pdice = NULL;
    int *pkeep = NULL;
    pdice = dice;
    pkeep=kept;
    int count = 5;
    while (count>0)
    {
        roll(count, pdice);
        count-=select(count, pdice, pkeep);
    }
    if(toupper(player->name[strlen(player->name)-1])=='S')
        printf("\n%s' final score was: %d\n",player->name, final_score(kept));    
    else
        printf("\n%s's final score was: %d\n",player->name, final_score(kept));
}