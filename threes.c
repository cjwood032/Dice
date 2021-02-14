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
#include "player.h"
int main() 
{
    int players=0;
    puts("New game of threes!\nHow many players");
    struct player p1;
    struct player *p=NULL;
    p=&p1;
    makeplayer(p);
    playerturn(p);
    return 0;
}
