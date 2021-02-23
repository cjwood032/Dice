# Dice
This is a collection of three games. The threes and sevens games allow for computer players as AI opponents. 
### Threes-
    Threes is played with 1 or more players each rolling 5 dice. The object of the game is to score as low as possible, with the following rules:
    1. You must keep at least 1 die per roll and may keep as many as you want.
    2. Once a die is held, it cannot be rerolled.
    3. The three-pip side is worth 0 points, all other sides are worth their face value.
    4. Lowest score wins, ties are possible.
### Sevens-
    Sevens is played with 2 or more players. The object of the game is to roll 2 dice and not have them add up to seven.
    1. A player who rolls a 7 is out.
    2. Play passes until only 1 player remains.
### Yatzie-
    Yatzie is a classic dice game, basic rules can be found https://www.dicegamedepot.com/yahtzee-rules/ or through other online sites.
    
## To run
1. Download the files.
2. Navigate to the project root folder with terminal.
3. run the games with ./games or open games.exe
4. If changes are desired the following command will rebuild the project using the GCC compiler:
    4a. Unix: gcc -g yatzie.c dice.c player.c scorecard.c threes.c sevens.c games.c -o games
    4b. Windows: gcc -g yatzie.c dice.c player.c scorecard.c threes.c sevens.c games.c -o games.exe
### good luck and have fun!