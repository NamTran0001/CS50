#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int point[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int getpoint(string s) {
    int total = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] = toupper(s[i]);
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            total += point[s[i] - 'A'];
        }
        i++;
    }
    return total;
}
int main(void) {
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    int score1 = getpoint(player1);
    int score2 = getpoint(player2);
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
    return 0;
}
