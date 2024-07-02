#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int letters[2][26] = {
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
    {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}};
int calc_score(string players, int length);

int main(int argc, char *argv[])
{
    int score1, score2;
    string players[2];
    for (int n = 1; n < 3; n++)
    {
        players[n - 1] = get_string("Player %d: ", n);
    }

    score1 = calc_score(players[0], strlen(players[0]));
    score2 = calc_score(players[1], strlen(players[1]));

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }

    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }

    else
    {
        printf("Tie!\n");
    }
}

int calc_score(string player, int length)
{
    int score = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (toupper(player[i]) == (char) letters[0][j])
            {
                score += letters[1][j];
            }
        }
    }
    return score;
}
