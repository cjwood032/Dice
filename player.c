#include "player.h"
#include "dice.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
const char *Names[10] = {"Bill", "Karen", "Ada", "Buzz", "Brian","Sophie","Edward","Marie","Susan","Paul"};
 
void make_player(struct player *player, _Bool option)
{
    char input;
    while(input!='C'&&input!='H'&&option)
    {
        puts ("Is this player human or a computer?\nH for human, C for computer");
        scanf("%c",&input);
        fflush(stdin);
    }
    if (toupper(input)=='H'||!option)
    {
        input='X';
        char name[20];
        player->human=1;
        puts("Enter player's name:");
        scanf("%s", name);
        fflush(stdin);
        strcpy(player->name,name);
    }
    else if(toupper(input)=='C')
    {
        srand(time(NULL));
        player->human=0;
        int index =rand()%10;
        strcpy(player->name,Names[index]);
    }
    input='X';
}
void player_turn (struct player *player)
{
    int *pdice = NULL;
    int *pkeep = NULL;
    int dice[5]={0,0,0,0,0};
    int score;
    pdice = dice;
    pkeep=player->dice;
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
        count-=select_dice(count, pdice, pkeep);
    }
    score = final_score(player->dice);
    player->score= score;
    if(toupper(player->name[strlen(player->name)-1])=='S')
    {
        printf("\n%s' final score was: %d\n",player->name, score);    
    }
    else
    {
        printf("\n%s's final score was: %d\n",player->name, score);
    }
}
void computer_turn (struct player *player)
{
    int *pdice = NULL;
    int *pkeep = NULL;
    int dice[5]={0,0,0,0,0};
    int score;
    pdice = dice;
    pkeep=player->dice;
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
        count-=compute_dice(count, pdice, pkeep);
        sleep(1);
    }
    score = final_score(player->dice);
    player->score= score;
    if(toupper(player->name[strlen(player->name)-1])=='S')
    {
        printf("\n%s' final score was: %d\n",player->name, score);    
    }
    else
    {
        printf("\n%s's final score was: %d\n",player->name, score);
    }
}