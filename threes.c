/*
threes is a game where you roll 5 dice any number of times trying to get the lowest score possible.
you must keep at least one die each roll, and threes are worth 0pts, everything else has face value
Psuedocode
1. roll 5 dice, display to user
2. user chooses which to keep >=1, those are added to a different array
3. roll remaining dice
4. continue until all dice are kept.
5. compare the score to the existing score, keeping the lower
*/

#include <stdio.h>
#include "dice.h"
#include <stdlib.h>
int main() 
{
    int dice[5]={0,0,0,0,0};
    int kept[5]={0,0,0,0,0};
    int *pdice = NULL;
    int *pkeep = NULL;
    pdice = dice;
    pkeep=kept;
    int count = 5;
    roll(count, pdice);
    count-=select(count, pdice, pkeep);
    printf("Count is now=%d\n", count);
    return 0;
}